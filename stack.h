
#ifndef stack_h
#define stack_h

typedef struct Node
{
    char data;
    struct Node* next;
}Node;

typedef struct
{
    Node* top;
}Stack;


int CheckString(const char* string);
Node* start_Node(char data);
Stack* initilize_the_stack();
int make_empty(Stack* stack);
void stack_push(Stack* stack, char data);
char stack_pop(Stack* stack);
void stack_destroy(Stack* stack);


#endif /* stack_h */

