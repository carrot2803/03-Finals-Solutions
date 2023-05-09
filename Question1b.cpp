#include "prototypes.h"
using namespace std;

void loadStack(Stack *s, int arr[], int n){
    for(int i = 0; i < n; i++)
        push(s, arr[i]);
}

int getSum(Stack *s){
    int sum = 0;
    while(!isEmpty(s))
        sum += pop(s);
    return sum;
}

int getAvg(int sum, int n){
    return sum/n;
}

void printDiff(Stack *s, int avg){
    while(!isEmpty(s))
        cout << pop(s) - avg << endl;    
}

int main(){
    Stack *s = initStack();
    int num[] = {49, 3, 2, 10, 11, 9, 5, 24, 81, 62}; // use 10 instead of 100 for display purposes
    int sum = getSum(s), avg = getAvg(sum, 10);

    loadStack(s, num, 10);
    cout << sum << endl;

    loadStack(s, num, 10);
    printDiff(s, avg);

    return 0;
}