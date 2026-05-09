#include <iostream>
using namespace std;

#define MAX 5   // Maximum stack size

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push element.\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack.\n";
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
    } else {
        cout << stack[top] << " popped from stack.\n";
        top--;
    }
}

// Display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- STACK OPERATIONS ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}