#include <iostream>
using namespace std;

int main() {
    int n, key;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int found = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position: " << i + 1;
            found = 1;
            break;
        }
    }

    if(found == 0) {
        cout << "Element not found.";
    }

    return 0;
}
