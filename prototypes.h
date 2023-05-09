#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *top;
};

struct Queue{ // ii
    Node *front;
    Node *rear;
};

Node *createNode(int n);
Node *insertAtHead(Node *top, int n);
Node *deleteAtHead(Node *top);
Stack *initStack();
bool isEmpty(Stack *s);
int peek(Stack *s);
int pop(Stack *s);
void push(Stack *s, int n);
Queue *initQueue();
bool isEmpty(Queue *q);
int peek(Queue *q);
int dequeue(Queue *q);
void enqueue(Queue* q, int n);

Node *createNode(int n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Node *top, int n){
    Node *newNode = createNode(n);
    return (top == NULL) ? newNode : (newNode->next = top, top = newNode);
}

Node *deleteAtHead(Node *top){
    if(top == NULL) return NULL;
    Node *temp = top->next;
    free(top);
    return temp;
}

void print(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    print(top->next);
}

Stack *initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

int peek(Stack *s){
    if(isEmpty(s)){
        cout << "The stack is empty\n";
        return -999;
    }
    return s->top->data;
}

int pop(Stack *s){
    if(isEmpty(s)){
        cout << "The stack is empty\n";
        return -999;
    }
    int n = s->top->data;
    s->top = deleteAtHead(s->top);
    return n;
}

void push(Stack *s, int n){
    s->top = insertAtHead(s->top, n);
}

Queue *initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue *q){
    return q->front == NULL;
}

int peek(Queue *q){
    if(isEmpty(q)){
        cout << "Queue is empty\n";
        return -999;
    }
    return q->front->data;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        cout << "Queue is empty\n";
        return -999;
    }
    int n = q->front->data;
    q->front = deleteAtHead(q->front);
    return n;
}

void enqueue(Queue* q, int n) {
    Node* newNode = createNode(n);
    isEmpty(q) ? q->front = newNode : q->rear->next = newNode;
    q->rear = newNode;
}


#endif
