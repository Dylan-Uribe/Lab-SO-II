#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

int get_lenght(const struct Node *h) {

    if(h != head) return 0;

    int lenght = 0;

    do{
        lenght++;
        h = h->next;

    } while(h!=head);

    return lenght;
}

void display(const struct Node *h)
{
   do
   {
       printf("%d ", h->data);
       h = h->next;
   }
    while(h!=head);
}

void r_display(const struct Node *h)
{
    static int flag = 0;

    if(h!=head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        r_display(h->next);
    }
    flag=0;
}

void insert(struct Node *h,const int index, const int number)
{
    if(index < 0 || index > get_lenght(h)) return;

    struct Node *p_t = malloc(sizeof(struct Node));

    if(index==0)
    {
        p_t->data=number;
        //Si la lista está vacía, mete valores al inicio
        if(head==NULL)
        {
            head=p_t;
            head->next=head;
        }
        //Si la lista no está vacía
        else
        {
            while(h->next!=head)h=h->next;
            h->next=p_t;
            p_t->next=head;
            head=p_t;
        }
    }
    else
    {
        for(int i=0; i < index - 1; i++) h=h->next;

        p_t->data=number;
        p_t->next=h->next;
        h->next=p_t;
    }
}

int delete(struct Node *h,const int index)
{
    if(index < 1 || index > get_lenght(head)) return -1;

    int number;

    if(index==1)
    {
        while(h->next!=head) h=h->next;
        number=head->data;
        if(head==h)
        {
            free(head);
            head=NULL;
        }
        else
        {
            h->next=head->next;
            free(head);
            head=h->next;
        }
    }
    else
    {
        for(int i=0; i < index-2; i++) h=h->next;

        struct Node *q = h->next;
        h->next=q->next;
        number=q->data;
        free(q);
    }
    return number;
}


void create(const int array_A[], const int n) {

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = array_A[0];
    head->next = head;

    struct Node *p_last = head;

    for(int i = 1; i < n; i++) {
        struct Node *p_t = malloc(sizeof(struct Node));
        p_t->data = array_A[i];
        p_t->next = p_last->next;
        p_last->next = p_t;
        p_last = p_t;
    }
}

int main() {

    const int array_A[] = {2,3,4,5,6};
    create(array_A, sizeof(array_A)/sizeof(array_A[0]));

    printf("%s \n", "Circular Linked List:");
    display(head); printf("\n");

    printf("%s \n", "Recursrive Circular Linked List:");
    r_display(head); printf("\n");

    printf("%s \n", "inserting an element:"); insert(head, 0,10);
    display(head); printf("\n");

    printf("%s %d \n", "removing an element: ", delete(head, 3));
    display(head);

    return 0;
}