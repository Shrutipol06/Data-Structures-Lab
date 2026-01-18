#include <iostream>
using namespace std;

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};

    int sum[2][2], sub[2][2], mul[2][2], trans[2][2];
    int i, j, k, choice;

    // Always display matrices first
    cout << "Matrix A:\n";
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix B:\n";
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    do {
        cout << "\n MATRIX OPERATIONS MENU\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Transpose of Matrix A\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    sum[i][j] = a[i][j] + b[i][j];

            cout << "\nMatrix Addition:\n";
            for(i=0;i<2;i++){
                for(j=0;j<2;j++)
                    cout << sum[i][j] << " ";
                cout << endl;
            }
            break;

        case 2:
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    sub[i][j] = a[i][j] - b[i][j];

            cout << "\nMatrix Subtraction:\n";
            for(i=0;i<2;i++){
                for(j=0;j<2;j++)
                    cout << sub[i][j] << " ";
                cout << endl;
            }
            break;

        case 3:
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    mul[i][j] = 0;
                    for(k=0;k<2;k++)
                        mul[i][j] += a[i][k] * b[k][j];
                }
            }

            cout << "\nMatrix Multiplication:\n";
            for(i=0;i<2;i++){
                for(j=0;j<2;j++)
                    cout << mul[i][j] << " ";
                cout << endl;
            }
            break;

        case 4:
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    trans[j][i] = a[i][j];

            cout << "\nTranspose of Matrix A:\n";
            for(i=0;i<2;i++){
                for(j=0;j<2;j++)
                    cout << trans[i][j] << " ";
                cout << endl;
            }
            break;

        case 5:
            cout << "Program end";
            break;

        default:
            cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}
