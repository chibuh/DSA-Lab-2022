#include <stdio.h>
#include <time.h>
#include "record.h"
#include <string.h>
#include <stdlib.h>

int main()
{
int x = 80000;
while(x>11111)
{	
    double time_spent = 0.0; 
    clock_t begin = clock();

	long long unsigned card_no;
	char bank_code[16], first_name[50], last_name[50];
	unsigned int expiry_month, expiry_year;

	Record bank = initializeArray();


int i =0;
char str[100] = "1";
int size = x;
while(i<size)
{
	char ch = '0';    strncat(str, &ch, 1);
	FILE* fp = fopen(str,"r");

	while(fscanf(fp,"\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n",&card_no,bank_code,&expiry_month,&expiry_year,first_name,last_name)!=-1 && i<size)
	{
		Card temp = (Card)malloc(sizeof(struct card));
		temp->card_no = card_no;
		strcpy(temp->bank_code, bank_code);
		temp->expiry_month = expiry_month;
		temp->expiry_year = expiry_year;
		strcpy(temp->first_name,first_name);
		strcpy(temp->last_name, last_name);

		bank = insertCard(bank, temp, i);

		free(temp);

		i++;
	}
    fclose(fp);
}

	// printArray(bank,i);
	printf("%d\n",i);
	
	// *bank.arr = insertion_sort(&bank.arr,i);
	bank = insertion_sort(bank,i);
	// printArray(bank,i);

    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("time taken %lf \t",time_spent);

	FILE *fp; fp = fopen("observations.csv","a");
	fprintf(fp,"%d,%f\n",size,time_spent);
    fclose(fp);

	free(bank.arr);

	
	x=x-7973;
}
}