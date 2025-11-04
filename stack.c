#include<stdio.h>
#include<conio.h>
#define size 10
void push(int);
void pop();
void display();
int top = -1, arr[size];
void push(int val)
{
    if(top == size-1)
    printf("Stack Overflow!!");
    else{
    top++;
    arr[top]=val;
    printf("\nInsertion Successful");
    }
}
void pop()
{
    if(top==-1)
        printf("Stack Empty!!, Deletion not possible");
    else{
        printf("\n Deleted:%d",arr[top]);
        top--;
    }
}
void display(){
    if(top == -1)
        printf("Stack Empty!!");
    else{
        int i;
        printf("\n Stack Elements are:");
        for(i=top; i>-1; i--)
            printf("\n%d",arr[i]);
    }
}
void main()
{
    int val,choice;
    while(1)
    {
        printf("\n\n***MENU***\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the value to be inserted: ");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\n Wrong Selection!! Try Again!!");
        }
    }
}
