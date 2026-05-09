#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
Node* AVAIL = NULL;

// Create AVAIL list
void initAvail(int n) {

    for(int i = 0; i < n; i++) {

        Node* temp = new Node;

        temp->next = AVAIL;
        AVAIL = temp;
    }
}

// Get node from AVAIL
Node* getNode() {

    if(AVAIL == NULL) {
        cout << "Overflow: No free nodes available\n";
        return NULL;
    }

    Node* temp = AVAIL;
    AVAIL = AVAIL->next;

    return temp;
}

// Return node to AVAIL
void freeNode(Node* temp) {

    temp->next = AVAIL;
    AVAIL = temp;
}

// Insert at beginning
void insertBegin(int val) {

    Node* newNode = getNode();

    if(newNode == NULL)
        return;

    newNode->data = val;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertEnd(int val) {

    Node* newNode = getNode();

    if(newNode == NULL)
        return;

    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insertPos(int val, int pos) {

    if(pos == 1) {
        insertBegin(val);
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* newNode = getNode();

    if(newNode == NULL)
        return;

    newNode->data = val;
    newNode->next = temp->next;

    temp->next = newNode;
}

// Delete from beginning
void deleteBegin() {

    if(head == NULL) {
        cout << "List Empty\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    cout << "Deleted: " << temp->data << endl;

    freeNode(temp);
}

// Delete from end
void deleteEnd() {

    if(head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if(head->next == NULL) {

        cout << "Deleted: " << head->data << endl;

        freeNode(head);
        head = NULL;

        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
        temp = temp->next;

    Node* del = temp->next;

    temp->next = NULL;

    cout << "Deleted: " << del->data << endl;

    freeNode(del);
}

// Delete from position
void deletePos(int pos) {

    if(head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if(pos == 1) {
        deleteBegin();
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if(temp->next == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* del = temp->next;

    temp->next = del->next;

    cout << "Deleted: " << del->data << endl;

    freeNode(del);
}

// Display SLL
void display() {

    if(head == NULL) {
        cout << "List Empty\n";
        return;
    }

    Node* temp = head;

    cout << "SLL: ";

    while(temp != NULL) {

        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Display AVAIL
void displayAvail() {

    Node* temp = AVAIL;

    cout << "AVAIL: ";

    while(temp != NULL) {

        cout << "[Free Node] -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Main Function
int main() {

    int n, choice, val, pos;

    cout << "Enter number of nodes for AVAIL list: ";
    cin >> n;

    initAvail(n);

    do {

        cout << "\n--- SLL MENU ---\n";

        cout << "1. Insert Begin\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Begin\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Display SLL\n";
        cout << "8. Display AVAIL\n";
        cout << "9. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertPos(val, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                displayAvail();
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 9);

    return 0;
}