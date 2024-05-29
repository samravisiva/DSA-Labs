#include "linked_list.h"
#include <stdlib.h>

LIST createNewList(){
	LIST list = (LIST)malloc(sizeof(linked_list));
	if (list != NULL){
		list->count = 0;
		list->head = NULL;
	}
	return list;
	
}

NODE createNewNode(Element data){
	NODE newNode = (NODE)malloc(sizeof(node));
	if (newNode != NULL){
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}
//insert at beginning of list
void insertNodeIntoList(NODE newNode, LIST list){
	if (newNode == NULL || list == NULL)
		return;
	newNode->next = list->head;
	list->head = newNode;
	list->count++;
}

void removeFirstNode(LIST list){
	if (list == NULL || list->head == NULL)
		return;
	NODE temp = list->head;
	list->head = list->head->next;
	free(temp);
	list->count--;
}

void insertNodeAtEnd(NODE newNode, LIST list){
	if(newNode == NULL || list == NULL)
		return;
	if(list->head == NULL){
		list->head = newNode;
	}
	else
	{
		NODE current = list->head;
	
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newNode;
	newNode->next = NULL
	}
	list->count++
}