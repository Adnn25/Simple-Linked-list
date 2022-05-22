#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int count_of_node(struct node *head)
{
    int count=0;
    if(head==NULL)
        printf("liste khawya");

    struct node *ptr = NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;

}
void print_data(struct node *head)
{
    if(head==NULL)
    {
        printf("liste khawya");
    }
    else
    {
        struct node *ptr =NULL;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
struct node* add_last (struct node *head,int a)
{
    struct node *current = (struct node*)malloc(sizeof(struct node));
    struct node *ptr ;
    ptr=head;
    current->data=a;
    current->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=current;
    return head;
}
struct node* ajouter_simple(struct node *head, int nbr)
{
    struct node *current = malloc(sizeof(struct node));
    current->data=nbr;
    current->link=NULL;
    head->link=current;
    return current ;
}
struct node* add_beg (struct node *head,int a)
{
    struct node *beg = malloc(sizeof(struct node));
    beg->data=a;
    beg->link=head;
    head=beg;
    return head;
}
void insert(struct node *head,int place)
{
    struct node *nv=malloc(sizeof(struct node));
    nv->data=55;
    nv->link=NULL;
    int count=1;
    while(count!=place-1)
    {
        head=head->link;
        count++;
    }
    nv->link=head->link;
    head->link=nv;

}
struct node* delete_first_node(struct node *head)
{
    struct node *ptr ;
    ptr=head;
    head=head->link;
    free(ptr);
    return head;
}
void delete_last_node(struct node *head)
{
    struct node *ptr, *tst ;
    ptr = head;

    while (ptr->link!=NULL)
    {
        tst=ptr;
        ptr=ptr->link;
    }
    tst->link=NULL;
    free(ptr);
}
void delete_pos_node(struct node *head,int place)
{
    struct node *ptr = head;
    struct node *tst;
    int count=1 ;
    while(count!=place)
    {
        tst=ptr;
        ptr=ptr->link;
        count++;
    }
    tst->link=ptr->link;
    free(ptr);

}
struct node* del_list (struct node *head)
{
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        free(head);
        head=ptr;
    }
    return head ;
};
struct node* reverse(struct node *head)
{
    struct node *next=NULL, *prev=NULL;
    struct node*rev=head;
    while(rev!=NULL)
    {
        next=rev->link;
        rev->link=prev;
        prev=rev;
        rev=next;
    }
    rev=prev;
    return rev;
};
struct node* TabListe(int *T, int nb)
{
    struct node* A=NULL;
    A=malloc(sizeof(struct node));
    A->data=T[0];
    A->link=NULL;
    int i;
    for(i=1; i<nb; i++)
    {
        A=add_last(A,T[i]);
    }
    return A;
};
int* ListeTab(struct node*head)
{
    int *T=malloc(count_of_node(head)*sizeof(int));
    struct node*ptr;
    ptr=head;
    int i;
    for(i=0; i<count_of_node(head); i++)
    {
        T[i]=ptr->data;
        ptr=ptr->link;
    }
    return T;
};
int testTrie (struct node*head)
{
    if(!head->link)
        return 0;
    while(head->link!=NULL)
    {
        if(head->data>head->link->data)
        {
            return -1;
        }
        head=head->link;
    }
    return 1;
}
int inserTie (struct node *head,int nb)
{
    struct node*num=NULL;
    num=malloc(sizeof(struct node));
    num->data=nb;
    num->link=NULL;
    if(head==NULL)
        return 0;
    if(head->link==NULL){
        if(head->data<nb){
            add_last(head,nb);
        }else{
            add_beg(head,nb);
        }
    }
    while(head->link!=NULL)
    {
        if(head->data<nb && head->link->data>nb)
        {
            num->link=head->link;
            head->link=num;

        }
        head=head->link;
    }
    if(head->link==NULL&&head->data<nb){
        head->link=num;
    }
    return 1 ;
}
int main()
{
    struct node *head = NULL ;

    int T[]= {5};
    head=TabListe(T,1);
    /*
        int *Tab;
        struct node*rev=NULL ;

        struct node *ptr=NULL;
        head = (struct node*) malloc(sizeof(struct node));
        head->data = 12;
        head->link = NULL;

        struct node *current = malloc(sizeof(struct node));
        current->data=15;
        current->link=NULL;
        head->link=current;

        current=malloc(sizeof(struct node));
        current->data=18;
        current->link=NULL;
        head->link->link = current ;
        */
    /*
    ptr=head;
    ptr=ajouter_simple(ptr,7);
    ptr=ajouter_simple(ptr,23);
    ptr=ajouter_simple(ptr,27);
    ptr=ajouter_simple(ptr,32);
    count_of_node(head);
    print_data(head);
    add_last (head);
    printf("\nle nombre 22 est ajoutee a la fin \n");
    count_of_node(head);
    print_data(head);
    head=add_beg (head);
    printf("\nle nombre 2 est ajoutee au debut \n");
    count_of_node(head);
    print_data(head);
    insert(head,5);
    count_of_node(head);
    print_data(head);
    head=delete_first_node(head);
    count_of_node(head);
    print_data(head);
    delete_last_node(head);
    count_of_node(head);
    print_data(head);
    delete_pos_node(head,3);
    count_of_node(head);
    print_data(head);
    head = del_list(head);
    if(head==NULL){
        printf("\nla liste a ete bien supprime \n");
    }

    head=reverse(head);
    print_data(head);
    Tab=ListeTab(head);
    int i ;
    for(i=0;i<count_of_node(head);i++){
        printf("%d\t",Tab[i]);
    }
    printf("\n");
    rev=reverse(head);
    print_data(rev);
    */
    print_data(head);
    int a=testTrie(head);
    printf("%d\t",a);
    inserTie (head,57);
    printf("\n");
    print_data(head);

    return 0;
}


