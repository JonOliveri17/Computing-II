/*
 Program: Daily6.c
 Author: Jonathan Oliveri
 Date; 02/08/2024
 Time Spent: 1 hour 30 minutes
 Purpose: Learn how to use LinkedList more in depth and learn how reverses work with the LinkedList
 */

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* LL_reverse(Node* head);


int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;

    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    
    head = LL_reverse(head);
    
    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}

Node* LL_reverse(Node *head)
{
    Node *previous = NULL;
    Node *current_value = head;
    Node *next = NULL;
    
    while(current_value != NULL)
    {
        printf("%d\n", current_value->data);
        next = current_value -> next;
        current_value->next = previous;
        previous = current_value;
        current_value = next;
    }
    head = previous;
    return head;
    
}
