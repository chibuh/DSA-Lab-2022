#include "multiq.h"
#include <sys/time.h>

MultiQ loadData(FILE* f){
	MultiQ mq = createMQ(10);
	int a,b;
	Task t;
	while(!feof(f)){

		fscanf(f,"%d,%d",&a,&b);
		fgetc(f);
		t.tid = a;
		t.p = b;
		mq = addMQ(mq,t);
	};

	return mq;
}

MultiQ testDel(MultiQ mq, int num){
    int x = 1;
	for(int i=0;i<num;i++){
		printf("%d)  %d\n",x,nextMQ(mq).tid);
		delNextMQ(mq);
        x++;
	}
	return mq;
}

int main(){

	struct timeval t1, t2;
	double elapsedTime;
	int deleteNo=10;
// starting timer
	gettimeofday(&t1, NULL);

	FILE* f = fopen("input10.txt","r");
	MultiQ mq = loadData(f);
	fclose(f);

// stop timer

	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total loading time is %f ms.\n",elapsedTime);


	gettimeofday(&t1, NULL);

	mq = testDel(mq,deleteNo);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for %d deletions is %f ms.\n",deleteNo,elapsedTime);

}