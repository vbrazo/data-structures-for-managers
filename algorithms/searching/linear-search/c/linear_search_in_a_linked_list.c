/**
* C program to create and traverse a Linked List
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
  int data;          // Data
  struct node *next; // Address
}*head;

void createList(int n);
void traverseList();

int main()
{
  int n;

  printf("Enter the total number of nodes: ");
  scanf("%d", &n);

  createList(n);

  printf("\nData in the list \n");
  traverseList();

  return 0;
}

/*
* Create a list of n nodes
*/
void createList(int n)
{
  struct node *newNode, *temp;
  int data, i;

  head = (struct node *)malloc(sizeof(struct node));

  // Terminate if memory not allocated
  if(head == NULL)
  {
    printf("Unable to allocate memory.");
    exit(0);
  }

  // Input data of node from the user
  printf("Enter the data of node 1: ");
  scanf("%d", &data);

  head->data = data; // Link data field with data
  head->next = NULL; // Link address field to NULL

  // Create n - 1 nodes and add to list
  temp = head;
  for(i=2; i<=n; i++)
  {
    newNode = (struct node *)malloc(sizeof(struct node));

    /* If memory is not allocated for newNode */
    if(newNode == NULL)
    {
      printf("Unable to allocate memory.");
      break;
    }

    printf("Enter the data of node %d: ", i);
    scanf("%d", &data);

    // Link data field of newNode
    newNode->data = data;
    newNode->next = NULL;

    // Link previous node with newNode
    temp->next = newNode;

    // Make current node as previous node
    temp = temp->next;
  }
}

/*
* Display entire list
*/
void traverseList()
{
  struct node *temp;

  if(head == NULL)
  {
    printf("List is empty.");
    return;
  }

  temp = head;
  while(temp != NULL)
  {
    printf("Data = %d\n", temp->data);
    temp = temp->next;
  }
}
