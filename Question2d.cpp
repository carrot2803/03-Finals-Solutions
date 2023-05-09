#include "prototypes.h"

Node *deleteHead(Node *top){
    if(top == NULL) return NULL;
    Node *temp = top->next;
    free(top);
    return temp;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    head->next = deleteTail(head->next);
    return head;
}


Node *deleteFL(Node *top){
    if (top == NULL)  return NULL;
    top = deleteHead(top);
    top = deleteTail(top);
    return top;
}

int main(){ //  to output
    Node *top = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{6, NULL}}}}}};
    print(deleteFL(top));
    return 0;
}
