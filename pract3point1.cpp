#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int marks1[] = {45, 12, 89, 34, 67, 23};
    int marks2[] = {45, 12, 89, 34, 67, 23};
    int marks3[] = {45, 12, 89, 34, 67, 23};
    int n = 6;

    bubbleSort(marks1, n);
    cout << "Bubble Sort: ";
    printArray(marks1, n);

    selectionSort(marks2, n);
    cout << "Selection Sort: ";
    printArray(marks2, n);

    insertionSort(marks3, n);
    cout << "Insertion Sort: ";
    printArray(marks3, n);

    return 0;
}