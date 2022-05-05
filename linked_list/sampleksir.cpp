 struct list *t,*h;
    h=head;
    t=h;
 printf("\n");
    while(t!=NULL){

    while(h!=NULL){
    t=h->left;
    printf("%d",t->ldata);
    h=h->right;
    }
    
    }