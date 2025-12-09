#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* createnode(int data){
struct node* current = malloc(sizeof(struct node*));
if(!current){
    printf("Memory Error!!\n");
    return NULL;
}
current->data=data;
current->next=NULL;
return current;
}

struct node* insert_beg(struct node* head, int data){
struct node* current = createnode(data);
if(head==NULL){
    head = current;
}
else{
    current->next=head;
    head=current;
}
return head;
}

struct node* insert_end(struct node* head, int data){
struct node* current = createnode(data);
if(head==NULL){
        head = current;
}
else{
        struct node* temp = head;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=current;
}
return head;
}

struct node* insert_pos(struct node* head, int data, int pos){
if(pos==1){
    return insert_beg(head, data);
}
    struct node* current = createnode(data);
    struct node* temp = head;

    for(int i=1; i<pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Position Out of Bounds!!\n");
        free(current);
    }
    else{
        current->next = temp->next;
        temp->next=current;
    }
    return head;
}

void display(struct node* head){
if( head==NULL ){
        printf("List is Empty!!\n");
return;
}
struct node* temp = head;
printf("List: ");
while(temp!= NULL){
    printf("%d -> ",temp->data);
    temp = temp->next;
}
printf("NULL\n");
}

int main()
{
    struct node* head = NULL;
    int n, data, pos;
    while(1){
        printf("\n---------MENU----------\n");
        printf("1. Insert at the Beginning.\n");
        printf("2. Insert at the End.\n");
        printf("3. Insert at the Position.\n");
        printf("4. Display the Contents.\n");
        printf("5. Exit.\n");
        printf("Enter your Choice.\n");
        scanf("%d",&n);

        switch(n){
        case 1:printf("Enter the data to Insert\n");
        scanf("%d",&data);
        head = insert_beg(head, data);
        break;
        case 2:printf("Enter the data to Insert\n");
        scanf("%d",&data);
        head = insert_end(head, data);
        break;
        case 3:printf("Enter the data to Insert\n");
        scanf("%d",&data);
        printf("Enter the Position at which to Insert\n");
        scanf("%d",&pos);
        head = insert_pos(head, data, pos);
        break;
        case 4: display(head);
        break;
        case 5:printf("Exiting Program...\n");
        exit(0);
        break;
        default:
            printf("Wrong Input!! Enter Again\n");
            }
    }
    return 0;
}
