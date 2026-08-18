#include <iostream>
using namespace std;

void sortColors(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int colors[] = {2, 0, 2, 1, 1, 0};
    int n = 6;

    sortColors(colors, n);

    cout << "Sorted Colors: ";
    for (int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}