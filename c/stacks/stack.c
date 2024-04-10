#include <Stdio.h>
#include <stdlib.h>

typedef struct SN {
    int data;
    struct SN* next;
} StackNode;

typedef struct MyStack {
    StackNode* top;
} Stack;


Stack* stack = NULL;

void push(int data)
{
    if(stack == NULL)
    {
        printf("Stack is null! Can't push on non-existant stack\n");
        return;
    }
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop()
{
    if(stack && stack->top)
    {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        return temp->data;
    }
    return -1;
}

void printStack()
{
    if(stack != NULL)
    {
        StackNode* n = stack->top;
        while(n)
        {
            printf("%d\n", n->data);
            n = n->next;
        }
    }
}

int isEmpty()
{
    return !(stack && stack->top);
}

int peek()
{
    if(stack && stack->top)
    {
        return stack->top->data;
    }
    return -1;
}


int main()
{
    stack = (Stack*) malloc(sizeof(stack));
    stack->top = NULL;
    push(1);
    push(2);
    push(3);
    printStack();

    int x = pop();
    printf("Got value: %d from stack\n", x);

    x = peek();
    printf("Current value at top of stack: %d\n", x);

    return 0;
}