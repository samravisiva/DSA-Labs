#include <stdio.h>
#include <stdlib.h>
typedef struct node* NODE;
struct node{
	int ele;
	NODE next;
	};
typedef struct linked_list* LIST;
struct linked_list{
int count;
NODE head;
};
LIST createNewList()
{
LIST myList;
myList = (LIST) malloc(sizeof(struct linked_list));
myList->count=0;
myList->head=NULL;
return myList;

}
NODE createNewNode(int value)
	{
			NODE myNode;
			myNode = (NODE) malloc(sizeof(struct node));
			myNode->ele=value;
			myNode->next=NULL;
			return myNode;
	}
void insertAfter(int searchEle, NODE n1, LIST l1)
{
	if(l1->head==NULL)
		{
			l1->head = n1;
			n1->next = NULL;
			l1->count++;
		}
else
	{
NODE temp = l1->head;
NODE prev = temp;
while(temp!=NULL)
{
if (temp->ele == searchEle)
break;
prev = temp;
temp = temp->next;
}
if(temp==NULL)
{
printf("Element not found\n");
return;
}
else
{
if(temp->next == NULL)
{

temp->next = n1;
n1->next = NULL;
l1->count++;
}
else
{
prev = temp;
temp = temp->next;
prev->next = n1;
n1->next = temp;
l1->count++;
}
return;
}
}
return;
}
void printList(LIST l1)
{
NODE temp = l1->head;
printf("[HEAD] ->");
while(temp != NULL)
{
printf(" %d ->", temp->ele);
temp = temp->next;
}
printf(" [NULL]\n");
}


int main() {
    // Create a new linked list
    LIST myList = createNewList();

    // Insert some nodes into the list
    NODE node1 = createNewNode(10);
    insertAfter(-1, node1, myList); // Insert node1 as the first node

    NODE node2 = createNewNode(20);
    insertAfter(10, node2, myList); // Insert node2 after node1

    NODE node3 = createNewNode(30);
    insertAfter(20, node3, myList); // Insert node3 after node2

    NODE node4 = createNewNode(40);
    insertAfter(30, node4, myList); // Insert node4 after node3

    // Print the contents of the list
    printf("Linked List Contents:\n");
    printList(myList);

    // Free the allocated memory
    free(myList);
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}