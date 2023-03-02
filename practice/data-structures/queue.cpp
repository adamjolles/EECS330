#include <iostream>
#include <string>

using namespace std;

class queue {
    private:
        int front;
        int rear;
        int arr[5];

    public:

        //constructer
        queue() {
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        //checks if empty
        bool isEmpty() {
            if (front == -1 && rear == -1) {
                return true;
            }
            else {
                return false;
            }
        }

        //checks if full
        bool isFull() {
            if (rear == 4) {
                return true;
            }
            else {
                return false;
            }
        }

        void enqueue(int val) {
            if (isFull()) {
                cout << "queue overflow" << endl;
            }
            else if (isEmpty()) {
                front = 0;
                rear = 0;
                arr[rear] = val;
            }
            else {
                rear++;
                arr[rear] = val;
            }
        }

        int dequeue() {
            int x = 0;
            if (isEmpty()){
                cout << "queue underflow" << endl;
                return 0;
            }
            else if (front == rear) {
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                return x;
            }
            else {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }
};

int main() {
    queue q1;
    int option, value;

    do {
        cout << "what operation do you want to perform? select option number. enter 0 to exit." << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. clear screen" << endl << endl;

        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "enter an item to enqueue in the queue" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "dequeue value: " << q1.dequeue() << endl;
                break;
            case 3:
                if (q1.isEmpty()) {
                    cout << "queue is empty" << endl;
                }
                else {
                    cout << "queue is not empty" << endl;
                }
                break;
            case 4:
                if (q1.isFull()) {
                    cout << "queue is full" << endl;
                }
                else {
                    cout << "queue is not full" << endl;
                }
                break;
            case 5:
                system("clear");
                break;
            default:
                cout << "enter proper option number" << endl;
        }
    } while (option != 0);
    
    return 0;
}