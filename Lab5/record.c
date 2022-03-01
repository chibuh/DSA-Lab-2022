#include "record.h"

Record initializeArray()
{
	Record bank;
	bank.size = SIZE;
	bank.arr = (Card)malloc(sizeof(struct card)*SIZE);
    
	return bank;
}

bool isFull(Record bank, int index)
{
	if(index>=bank.size)	return true;
	return false;
}

Record insertCard(Record bank, Card temp, int index)
{
	if(isFull(bank, index))
	{
		bank.size+=SIZE;
		bank.arr = (Card)realloc(bank.arr,sizeof(struct card)*(SIZE+bank.size));
	}
	bank.arr[index] = (*temp);
	return bank;
}

void printArray(Record bank, int num)
{
	if(bank.size==0 || num==0)	printf("No record found!");
	for (int i = 0; i < num; i++)
	{
		printf("%llu\t%s\t%u / %u\t%s\t%s\n",(bank.arr+i)->card_no,(bank.arr+i)->bank_code,(bank.arr+i)->expiry_month,(bank.arr+i)->expiry_year,(bank.arr+i)->first_name,(bank.arr+i)->last_name);
	}
}

void insertInOrder(Card temp,int n)  //call inside/after insertCard(bank,Card,n)
{
	struct card key = *(temp+n-1);

	int j = n-2;
	while(j >=0)
	{
		if((temp+j)->card_no < key.card_no)
		{
			*(temp+j+1) = key;
			return ;
		}

		*(temp+j+1) = *(temp+j);
		j--;
	}
	*(temp+j+1) = key;	
}

// Record insertion_sort(Record bank,int n)     //Iterative
// {
// 	for (int i = 1; i < n; i++)
// 	{
// 		struct card key = *(bank.arr+i);

// 		bool flag = true;
// 		for (int j = i-1; j >= 0 && flag; j--)
// 		{
// 			if((bank.arr+j)->card_no < key.card_no)
// 			{
// 				*(bank.arr+j+1) = key;
// 				flag=false;
// 				break;
// 			}
// 			*(bank.arr+j+1) = *(bank.arr+j);
// 		}
// 		if(flag)	*bank.arr = key;
// 	}

// 	return bank;	
// }


void insertion_sort(Card temp,int n)        //Recursive
{
	if (n<=1)	return ;	
	
	insertion_sort(temp,n-1);

	insertInOrder(temp,n);
}


int * insertion_sortWithSize(Card temp,int n)        //Recursive (returning stack size)
{
	if (n<=1)
	{
		return &n;
	} 	
	
	int * highestStack = insertion_sortWithSize(temp,n-1);

	insertInOrder(temp,n);

	return highestStack;
}