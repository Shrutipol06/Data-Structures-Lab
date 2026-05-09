#include <iostream>
using namespace std;

#define SIZE 10   // Size of hash table

int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert element into hash table
void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        cout << "Collision occurred at index " << index << endl;
    }
}

// Display hash table
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> ";
        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];
        cout << endl;
    }
}

int main() {
    // Initialize hash table with -1
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> key;
        insert(key);
    }

    display();

    return 0;
}