#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* TOP = NULL;
Node* AVAIL = NULL;

// Initialize AVAIL list
void initAvail(int n) {
    for(int i = 0; i < n; i++) {
        Node* temp = new Node;
        temp->link = AVAIL;
        AVAIL = temp;
    }
}

// PUSH operation
void push(int item) {
    if (AVAIL == NULL) {
        cout << "Stack Overflow\n";
        return;
    }

    Node* newNode = AVAIL;
    AVAIL = AVAIL->link;

    newNode->info = item;
    newNode->link = TOP;
    TOP = newNode;

    cout << "Inserted: " << item << endl;
}

// POP operation
void pop() {
    if (TOP == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = TOP;
    cout << "Deleted: " << temp->info << endl;

    TOP = TOP->link;

    temp->link = AVAIL;
    AVAIL = temp;
}

// DISPLAY operation
void display() {
    if (TOP == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = TOP;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->info << " -> ";
        temp = temp->link;
    }
    cout << "NULL\n";
}

// MAIN FUNCTION
int main() {
    int n, choice, item;

    cout << "Enter number of nodes for AVAIL list: ";
    cin >> n;

    initAvail(n);

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> item;
                push(item);
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
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}