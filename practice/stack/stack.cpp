#include <iostream>
#include <string>

using namespace std;

class stack{
    private:
        int top;
        int arr[5];

    public:
        //constructer
        stack() {
            top = -1;
            for (int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        //checks if empty
        bool isEmpty() {
            if (top == 1) {
                return true;
            }
            else {
                return false;
            }
        }

        //checks if full
        bool isFull() {
            if (top == 4) {
                return true;
            }
            else {
                return false;
            }
        }

        void push(int val) {
            if (isFull()) {
                cout << "stack overflow" << endl;
            }
            else {
                top++;
                arr[top] = val;
            }
        }

        int pop() {
            if (isEmpty()){
                cout << "stack underflow" << endl;
                return 0;
            }
            else {
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }

        int count() {
            return(top+1);
        }

        int peek(int pos) {
            if (isEmpty()){
                cout << "stack underflow" << endl;
                return 0;
            }
            else {
                return arr[pos]; 
            }
        }

        void change(int pos, int val) {
            arr[pos] = val;
            cout << "item changed at location " << pos << endl;
        }

        void display()
        {
            cout << "all values in the stack are " << endl;
            for (int i = 4; i >= 1; i--) {
                cout << arr[i] << endl;
            }
        }
};

int main()
{
    return 0;
}