//program to create a node in double linked list

#include<stdio.h>
#include<stdlib.h>
struct node {
    int num;
    struct node *next;
    struct node *prev;

};
int main(){
    struct node *node1, *head , * temp;
    int data;
    node1=malloc(sizeof(struct node));
    printf("enter the value of node1 ");
    scanf("%d",&data);
    node1->num=data;
    node1->next=NULL;
    node1->prev=NULL;
    head=node1;

    if(head==NULL){
        printf("memory can not be allocated");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->num);
            temp=temp->next;
        }
    }
    return 0;
}