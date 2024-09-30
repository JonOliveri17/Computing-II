/*
 Program: Daily6b.c
 Author: Jonathan Oliveri
 Date; 02/22/2024
 Time Spent: 1 hour 45 minutes
 Purpose: Be able to add integers together using head_insert and do it in the correct order
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
void head_insert(Node** head, int newdata);
void print_list(Node* head);
void destroy_list(Node* head);
Node* list_sum(Node* head1, Node* head2);

int main(int argc, char* argv[])
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;
    
    //create a list for the number 189
    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);
    
    //create a list for the number 11
    head_insert(&head2, 1);
    head_insert(&head2, 1);

    
    printf("The sum of ");
    print_list(head1);
    
    printf(" + ");
    print_list(head2);
    printf("\n");
    printf(" = ");
    head_sum = list_sum(head1, head2);
    print_list(head_sum);
    printf("\n");
    
    //clean up three lists
    destroy_list(head1); head1 = NULL;
    destroy_list(head2); head2 = NULL;
    destroy_list(head_sum); head_sum = NULL;
    
    return 0;
}

Node* LL_reverse(Node *head)
{
    Node* previous = NULL;
    Node* current_value = head;
    Node* next = NULL;
    
    while(current_value != NULL)
    {
        next = current_value -> next;
        current_value -> next = previous;
        previous = current_value;
        current_value = next;
    }
    head = previous;
    return head;
    
}

void head_insert(Node** head, int newdata)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = newdata;
    node -> next = *head;
    *head = node;
}

void print_list(Node* head)
{
   Node* temp = head;
    
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
   }

}

void destroy_list(Node* head)
{
    Node* temp;
    
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
}

Node* list_sum(Node* head1, Node* head2)
{
    head1 = LL_reverse(head1);
    head2 = LL_reverse(head2);
    
    Node* sum = NULL;
    int i = 0;
    
    while(head1 != NULL || head2 != NULL || i != 0)
    {
        int sum_of_numbers = i;
        
        if(head1 != NULL)
        {
            sum_of_numbers += head1 -> data;
            head1 = head1 -> next;
        }
        
        if(head2 != NULL)
        {
            sum_of_numbers += head2 -> data;
            head2 = head2 -> next;
        }
        i = sum_of_numbers / 10;
        sum_of_numbers %= 10;
        
        head_insert(&sum, sum_of_numbers);
        
    }
    return sum;
}
