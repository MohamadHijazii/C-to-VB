#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 256

typedef struct elet{
    char s[200];
}elet;

typedef struct node{
    char e[N];
    struct node *next;
}node;

typedef struct list{
    int c;
    node *first;
    node *last;
}list;



typedef struct stack{
    list l;
}stack;

typedef struct queue{
    list l;
}queue;

stack new_stack(){
    stack p;
    p.l.c = 0;
    p.l.first = NULL;
    p.l.last = NULL;
    return p;
}

int push(stack *s,char e[]){
    node *l = (node *)malloc(sizeof(node));
    strcpy(l->e,e);
    if(s->l.c == 0){
        l->next =NULL;
        s->l.first = l;
        s->l.last = l;
        s->l.c ++;
        return 1;
    }
    l->next = s->l.first;
    s->l.first = l;
    s->l.c ++;
    return 1;
}

int pop(stack *s,char e[]){
    node *topop = s->l.first;    
    strcpy(e,topop->e);
    
    s->l.first = topop -> next;
    if(s->l.c == 1){
        s->l.last = NULL;        
    }
    s->l.c --;
    free(topop);
    return 1;
}

int stack_empty(stack s){
    return s.l.c == 0;
}

queue new_queue(){    
    queue q;
    q.l.c = 0;
    q.l.first = NULL;
    q.l.last = NULL;
    return q;
}

int enqueue(queue *q,char e[]){    
    node *l = (node *)malloc(sizeof(node));    
    strcpy(l->e,e);
    l->next =NULL;
    if(q->l.c == 0){
        q->l.first = l;
        q->l.last = l;
    }
    else{
        q->l.last->next = l;
    }
    q->l.last = l;
    q->l.c ++;
    return 1;
}

int dequeue(queue *q,char e[]){
    node *topop = q->l.first;
    
    strcpy(e,topop->e);
    q->l.first = topop -> next;
    if(q->l.c == 1){
        q->l.last = NULL;        
    }
    q->l.c --;
    free(topop);
    return 1;
}

int queue_empty(queue q){
    return q.l.c == 0;
}