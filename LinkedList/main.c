#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *p_first = NULL,
  *p_second = NULL,
  *p_third = NULL;

void merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if(p->data < q->data)
    {
        p_third=last=p;
        p=p->next;
        p_third->next=NULL;
    }
    else
    {
        p_third=last=q;
        q=q->next;
        p_third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}

int count (const struct Node *p) {
    int counter = 0;
    while (p) {
        counter++;
        p = p->next;
    }
    return counter;
}

void remove_duplcate(struct Node *p) {
    struct Node *q=p->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int delete(struct Node *p, const int index){

    struct Node *p_q = NULL;
    int number = -1;

    if(index < 0 || index > count(p) - 1) {
        return number;
    }

    if(index == 0) {
        p_q = p_first;
        number = p_first->data;
        p_first = p_first->next;
        free(p_q);
        return number;
    }

    for(int i = 0; i < index; i++) {
        p_q = p;
        p = p->next;
    }

    p_q->next=p->next;
    number=p->data;
    free(p);

    return number;
}

void insert(struct Node *p, const int index, const int number) {

    if(index < 0 || index > count(p)) {
        return;
    }

    struct Node *p_t = malloc(sizeof(struct Node));
    p_t->data = number;
    p_t->next = NULL;

    if(index == 0) {
        p_t->next = p_first;
        p_first = p_t;
        return;
    }

    for(int i = 0; i < index - 1; i++) {
        p = p->next;
    }

    p_t->next = p->next;
    p->next = p_t;
}

void r_display(const struct Node *p) {

    if(p) {
        r_display(p->next);
        printf("%d ", p->data);
    }

}

void display(const struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void create_linked_list(int array[], const int n) {

    p_first = (struct Node *)malloc(sizeof(struct Node));
    p_first->data = array[0];
    p_first->next = NULL;

    struct Node *p_last = p_first;

    for(int i = 1; i < n; ++i) {
        struct Node *p_t  = malloc(sizeof(struct Node));
        p_t->data = array[i];
        p_t->next = NULL;
        p_last->next=p_t;
        p_last=p_t;
    }
}

void create_linked_list2(int array[], const int n) {

    p_second = (struct Node *)malloc(sizeof(struct Node));
    p_second->data = array[0];
    p_second->next = NULL;

    struct Node *p_last = p_second;

    for(int i = 1; i < n; ++i) {
        struct Node *p_t  = malloc(sizeof(struct Node));
        p_t->data = array[i];
        p_t->next = NULL;
        p_last->next=p_t;
        p_last=p_t;
    }
}

int main(void) {

    int array_A[] = {1,11,3,4,5};
    int array_B[] = {10,11,2,13,14};
    create_linked_list(array_A, sizeof(array_A)/sizeof(array_A[0]));

   /* printf("%s \n", "Linked List: ");
    display(p_first); printf("\n");

    printf("%s \n", "Recursive Linked List: ");
    r_display(p_first); printf("\n");

    printf("%s %d \n", "Deleting element: ", delete(p_first, 4));
    display(p_first); printf("\n");

    printf("%s \n","Inserting an element"); insert(p_first, 2, 50);
    display(p_first); printf("\n");

    printf("%s \n","Removing duplicate:"); remove_duplcate(p_first);
    display(p_first); printf("\n");*/

    printf("%s \n","Merging two linked list: ");
    create_linked_list2(array_B, sizeof(array_B)/sizeof(array_B[0]));
    merge(p_first, p_second); display(p_third);


    return 0;
}
