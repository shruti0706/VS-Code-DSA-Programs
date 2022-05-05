
    struct list *t, *h;
    h = head;
   
    printf("\n");

    while (h != NULL)
    {
        t=h->left;
        while (t != NULL)
        {
            
            printf("%d", t->ldata);
           t = t->left;
          
        }
       h = h->right;
    }
      printf("\n");