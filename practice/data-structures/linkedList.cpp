#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
    int data;
    node *next;
};

// int main() {
//     node *head = NULL;
//     node *temp = NULL;

//     temp = new node;
//     temp->data = 2;
//     temp->next = NULL;
//     head = temp;

//     cout << temp << endl;
//     delete temp;
// }


int main() {
    int a = 5;
    int& b = a;
    cout << b << endl;
    cout << &b << endl;
    cout << &a << endl;
}