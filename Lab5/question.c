#include <stdio.h>
#include <time.h>
#include "record.h"
#include <string.h>
#include <stdlib.h>

#define InputFile "10"

int main()
{
    double time_spent = 0.0; 
    clock_t begin = clock();

	long long unsigned card_no;
	char bank_code[16], first_name[50], last_name[50];
	unsigned int expiry_month, expiry_year;

	Record bank = initializeArray();
    
	FILE* fp = fopen(InputFile,"r");

    int i = 0;
	while(fscanf(fp,"\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n",&card_no,bank_code,&expiry_month,&expiry_year,first_name,last_name)!=-1)
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

	printArray(bank,i);
	printf("%d\n",atoi(InputFile));

	int * x = insertion_sortWithSize(bank.arr,i);
	printf("Size of stack used %ld\n",&i-x);
	// bank = insertion_sort(bank,i);
	printArray(bank,i);
    
	free(bank.arr);

    clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time taken: %lf\n",time_spent);

	FILE *fp1; fp1 = fopen("observations.csv","a");
	fprintf(fp1,"%d,%f\n",atoi(InputFile),time_spent);
    fclose(fp1);
}