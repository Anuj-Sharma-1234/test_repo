#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1;
}

// Iterative Binary Search
int binarySearchIterative(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter " << size << " sorted elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter the number to search: ";
    cin >> key;
    
    // Performing recursive binary search
    int resultRecursive = binarySearchRecursive(arr, 0, size - 1, key);
    if (resultRecursive != -1)
        cout << "Recursive: Element found at index " << resultRecursive << endl;
    else
        cout << "Recursive: Element not found" << endl;
    
    // Performing iterative binary search
    int resultIterative = binarySearchIterative(arr, size, key);
    if (resultIterative != -1)
        cout << "Iterative: Element found at index " << resultIterative << endl;
    else
        cout << "Iterative: Element not found" << endl;
    
    return 0;
}
