#include <iostream>
#include <prototypes.h>
using namespace std;

struct myQueue{ // Part i
    Node *front;
    Node *rear;
};

void myEnqueue(Queue* q, int n) {  // spelt weird to avoid overflow
    Node* newNode = createNode(n);
    isEmpty(q) ? q->front = newNode : q->rear->next = newNode;
    q->rear = newNode;
}

int main() { // main for testing
    Queue* q = initQueue(); // create a new queue

    enqueue(q, 10); // add some elements to the queue
    enqueue(q, 20);
    enqueue(q, 30);

    while (!isEmpty(q)) 
        cout << dequeue(q) << " ";

    return 0;
}