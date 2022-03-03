#include "que.h"

Queue newQ()
{
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;

    return q;
}

bool isEmptyQ(Queue q)
{
    return !q.size;
}

Queue delQ(Queue q)   //Delete q.front queuenode
{
    Queue q1 = newQ();

    if(q.size<=1)   
    {
        return q1;
    }

    q1.front = q.front->next;
    q1.rear = q.rear;
    q1.size = q.size-1;

    return q1;
}

QueueNode front(Queue q)
{
	return (q.front);
}

Queue addQ(Queue q, QueueNode e)   //Add queuenode to q's rear
{
    Queue q1=newQ();

    q1.rear = e;
    
    if(q.size==0)   
    {
        q1.front = q1.rear;
        q1.size++;
        return q1;
    }

    q.rear->next = q1.rear;

    q1.front = q.front;
    q1.size = q.size+1;

    return q1;
}

int lengthQ(Queue q)
{
	return q.size;
}

QueueNode newNode(int value)
{
    QueueNode qn = (QueueNode)malloc(sizeof(struct queuenode));
    qn->element = value;
    qn->next=NULL;

    return qn;
}