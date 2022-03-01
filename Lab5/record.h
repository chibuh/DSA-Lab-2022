#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define SIZE 5

typedef struct card * Card;

typedef struct record
{
	int size;
	Card arr;
} Record;

struct card
{
	long long unsigned card_no;
	char bank_code[16];
	unsigned int expiry_month, expiry_year; 
	char first_name[50];
	char last_name[50];
};

extern Record initializeArray();
extern bool isFull(Record bank, int index);
extern Record insertCard(Record bank, Card temp, int index);
extern void printArray(Record bank, int num);
// extern Record insertion_sort(Record bank,int n);
extern void insertion_sort(Card temp,int n);
extern int * insertion_sortWithSize(Card temp,int n);
extern  void insertInOrder(Card temp,int n);