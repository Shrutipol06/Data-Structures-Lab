#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* FRONT = NULL;
Node* REAR = NULL;
Node* AVAIL = NULL;

// Initialize AVAIL list
void initAvail(int n) {
    for(int i = 0; i < n; i++) {
        Node* temp = new Node;
        temp->link = AVAIL;
        AVAIL = temp;
    }
}

// ENQUEUE operation
void enqueue(int item) {
    if (AVAIL == NULL) {
        cout << "Queue Overflow\n";
        return;
    }

    Node* newNode = AVAIL;
    AVAIL = AVAIL->link;

    newNode->info = item;
    newNode->link = NULL;

    if (FRONT == NULL) {
        FRONT = REAR = newNode;
    } else {
        REAR->link = newNode;
        REAR = newNode;
    }

    cout << "Inserted: " << item << endl;
}

// DEQUEUE operation
void dequeue() {
    if (FRONT == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = FRONT;
    cout << "Deleted: " << temp->info << endl;

    FRONT = FRONT->link;

    if (FRONT == NULL)
        REAR = NULL;

    // Return node to AVAIL
    temp->link = AVAIL;
    AVAIL = temp;
}

// DISPLAY operation
void display() {
    if (FRONT == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = FRONT;
    cout << "Queue: ";
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
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> item;
                enqueue(item);
                break;

            case 2:
                dequeue();
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