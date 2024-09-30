#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Node* start_Node(char data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("Malloc failed at line 30\n");
        exit(1);
    }
    node -> data = data;
    node -> next = NULL;
    return node;
}

Stack* initilize_the_stack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL)
    {
        printf("Malloc failed at line 43\n");
        exit(1);
    }
    stack -> top = NULL;
    return stack;
    
}

int make_empty(Stack* stack)
{
    return (stack -> top == NULL);
}

void stack_push(Stack* stack, char data)
{
    Node* node = start_Node(data);
    node -> next = stack -> top;
    stack -> top = node;
}

char stack_pop(Stack* stack)
{
    if(make_empty(stack))
    {
        printf("error, its empty!\n");
        exit(1);
    }
    Node* temp = stack -> top;
    char data = temp -> data;
    stack -> top = temp -> next;
    free(temp);
    return data;
}

void stack_destroy(Stack* stack)
{
    while (!make_empty(stack))
    {
        stack_pop(stack);
    }
}

int CheckString(const char* string)
{
    int i = 0;
    Stack* stack = initilize_the_stack();
    
    while(string[i] != '\0')
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            stack_push(stack, string[i]);
        }
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if(make_empty(stack))
            {
                stack_destroy(stack);
                return 0;
            }
            char top = stack_pop(stack);
            if((string[i] == ')' && top != '(') || (string[i] == ']' && top != '[') || (string[i] == '}' && top != '{'))
            {
                stack_destroy(stack);
                return 0;
            }
        }
        i++;
    }
    int result = make_empty(stack);
    stack_destroy(stack);
    return result;
    
}
