#include "stack.h"
#include "linked_list.h"
#include <stdbool.h>

Stack *newstack(){
	return createNewList();

}

bool push(Stack *s, Element e){
	if(stack == NULL)
		return false;
	NODE newNode = createNewNode(e);
	if (newNode == NULL)
		return false;
	insertNodeIntoList(newNode, stack);
	return true;
}

Element* top(Stack* s){
	if(isEmpty(s))
		return NULL;
	return &(s->head->data);
}

bool pop(Stack *s){
	if(isEmpty(s))
		return false;
	removeFirstNode(s);
	return true;
}

bool isEmpty(Stack* s){
	return s == NULL || s->head == NULL;
}

void freeStack(Stack* s){
	if(s == NULL)
		return;
	NODE current = stack->head;
	while(current!= NULL){
		NODE temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}