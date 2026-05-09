#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[100], temp[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int size = 1; size < n; size = size * 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {

            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            int i = left, j = mid + 1, k = left;

            while (i <= mid && j <= right) {
                if (a[i] < a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i <= mid)
                temp[k++] = a[i++];

            while (j <= right)
                temp[k++] = a[j++];

            for (int x = left; x <= right; x++)
                a[x] = temp[x];
        }
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
