#include <iostream>
using namespace std;

// Заповнення масиву числами Фібоначчі
void fillFibonacci(int arr[], int size) {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < size; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

// Інтерполяційний пошук
int interpolationSearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + (double((high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    const int size = 30;
    int arr[size];

    fillFibonacci(arr, size);

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int result = interpolationSearch(arr, size, key);

    if (result != -1)
        cout << "Number " << key << " found at position " << result << endl;
    else
        cout << "Number " << key << " not found in the array." << endl;

    return 0;
}