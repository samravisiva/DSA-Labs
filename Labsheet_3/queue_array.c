#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 1000

struct Queue{
	Element data[QUEUE_SIZE];
	int front;
	int rear;
	int size;
};

Queue* createQueue(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if(q!= NULL){
		q->front = -1;
		q->size = 0;
		q->rear = -1;
	}
	return q;
}

bool enqueue(Queue* queue, Element element){
	if(queue->size == QUEUE_SIZE){
		return false;
	}
	else {
	queue->data[queue->rear]= element;
	queue->rear = (queue->rear)++ % QUEUE_SIZE;
	queue->size = queue->size +1;
	}
}