
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push() {
    struct node *newnode;
    int x;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if(top == NULL)
        printf("Stack Underflow\n");
    else {
        struct node *temp = top;
        printf("Popped = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if(top == NULL)
        printf("Stack Empty\n");
    else
        printf("Top = %d\n", top->data);
}

void display() {
    struct node *temp = top;
    if(temp == NULL)
        printf("Stack Empty\n");
    else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice");
        }
    }
}