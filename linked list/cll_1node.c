//Circular linked list for one node

#include<stdio.h>
#include<stdlib.h>
struct node{
    int num;
 struct node *link;
    
};

int main(){
    struct node *node1,*head;
    node1=malloc(sizeof(struct node));
    printf("enter data for a node");
    scanf("%d",&node1->num);
    node1->link=node1;
    head=node1;

    printf("%d",node1->num);

    return 0;
}