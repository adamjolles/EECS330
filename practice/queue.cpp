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
    return 0;
}