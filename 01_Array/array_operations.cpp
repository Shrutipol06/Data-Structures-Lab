#include <iostream>
using namespace std;

int main() {
    int a[10] = {10, 20, 30, 40, 50};
    int n = 5; 

    cout << "The list of Array:\n";
    // Traversal
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Insertion
    if (n < 10) {
        a[n] = 60;
        n++;
    } else {
        cout << "No space to insert new element\n";
    }

    cout << "List of Array after insertion:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Deletion
    int delIndex = 2;
    if (delIndex >= 0 && delIndex < n) {
        for (int i = delIndex; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    } else {
        cout << "Invalid deletion index\n";
    }

    cout << "The List of Array After Deletion:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Searching
    int key = 40;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            cout << "\nElement " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nElement not found\n";

    // Updating
    int updateIndex = 1;
    if (updateIndex >= 0 && updateIndex < n)
        a[updateIndex] = 100;
    else
        cout << "Invalid update index\n";

    cout << "\nAfter updating index 1:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Sorting 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Merging
    int b[3] = {70, 80, 90};
    int n2 = 3;
    int c[25];

    for (int i = 0; i < n; i++)
        c[i] = a[i];

    for (int i = 0; i < n2; i++)
        c[n + i] = b[i];

    cout << "\nMerged array:\n";
    for (int i = 0; i < n + n2; i++)
        cout << c[i] << " ";
    cout << endl;

    return 0;
}