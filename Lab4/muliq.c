#include "multiq.h"

MultiQ createMQ(int n)
{
	MultiQ mq;
	mq.size = n;
	mq.quearr = (Queue*)malloc(sizeof(Queue)*n);  //creates n Queues array

    for (int i = 0; i < n; i++)
    {
        mq.quearr[i]= newQ();
    }
    
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t) //the Queue corresponding to priority p is mq[p-1]
{
	mq.quearr[t.p-1] = addQ(mq.quearr[t.p-1],newNode(t.tid));
	return mq;
}

Task nextMQ(MultiQ mq)
{
	Task dummyTask;
	dummyTask.tid = -1;
	dummyTask.p = -1;
    
    for (int i = mq.size-1; i >=-1; i--)
    {
        if(i==-1)   return dummyTask;
        if(!isEmptyQ(mq.quearr[i]))
        {
            Task tempTask;
            tempTask.p=i+1;
            tempTask.tid=front(mq.quearr[i])->element;
            return tempTask;
        }
    }
}

MultiQ delNextMQ(MultiQ mq)
{
    for (int i = mq.size-1; i >=-1; i--)
    {
        if(i==-1)   return mq;
        if(!isEmptyQ(mq.quearr[i]))
        {
            mq.quearr[i]=delQ(mq.quearr[i]);
            return mq;
        }
    }
}

bool isEmptyMQ(MultiQ mq)
{
    for (int i = mq.size-1; i >=-1; i--)
    {
        if(i==-1)   return true;
        if(!isEmptyQ(mq.quearr[i])) return false; 
    }
}

int sizeMQ(MultiQ mq)
{
    int items = 0;
    for (int i = mq.size-1; i >= 0; i--)
    {
        items+= mq.quearr[i].size;
    }    
    return items;
}

int sizeMQbyPriority(MultiQ mq, Priority p)
{
    if(p<1 || p>=mq.size)   return -1;
    return mq.quearr[p-1].size;
}

Queue getQueueFromMQ(MultiQ mq, Priority p)
{
    if(p<1 || p>=mq.size)   return newQ();
    return mq.quearr[p-1];    
}