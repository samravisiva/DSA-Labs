#include "element.h"
#include "stack.h"
#include <stdlib.h>

#define STACK_SIZE 1000
struct Stack
{
	int top;
	Element data[STACK_SIZE];
};

Stack *newStack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s!= NULL)
		s->top = -1;
	return s;
}

bool push(Stack *s, Element e)
{
	if(s->top == STACK_SIZE - 1)
		return false;
	s->data[++(s->top)] = e;
	return true;
}

bool pop(Stack *s)
{
	if(isEmpty(s))
		return false;
	s->top--;
	return true;
}

bool isEmpty(Stack *s)
{
	return s->top == -1;
}

Element *top(Stack *s)
{
	if(isEmpty(s))
		return NULL;
	return &(s->data[s->top]);
}

void freeStack(Stack *s)
{
	free(s);
}