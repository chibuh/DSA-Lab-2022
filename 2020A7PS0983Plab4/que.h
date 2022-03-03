#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queuenode * QueueNode;

struct queuenode {
    int element;
    QueueNode next;
};

typedef struct {
    QueueNode front;
    QueueNode rear;
    int size;
}Queue;

extern Queue newQ(); // returns an empty Queue

extern bool isEmptyQ(Queue q); // tests whether q is empty

extern Queue delQ(Queue q); // deletes the element from the front of the Queue;returns the modified Queue

extern QueueNode front(Queue q); // returns the element from the front of the Queue;

extern Queue addQ(Queue q , QueueNode e); // adds e to the rear of the Queue; returns the modified Queue

extern int lengthQ(Queue q); // returns the length of the Queue

extern QueueNode newNode(int value);  //convenience function adding QueueNode dynamically