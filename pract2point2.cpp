#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        return recursiveBinarySearch(arr, left, mid - 1, target);

    return recursiveBinarySearch(arr, mid + 1, right, target);
}

int main()
{
    int n, target;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target code: ";
    cin >> target;

    int left = 0;
    int right = n - 1;
    int found = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            found = mid;
            break;
        }

        if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    if (found == -1)
        cout << "\nIterative Binary Search: Not Found";
    else
        cout << "\nIterative Binary Search: Found at position " << found + 1;

    found = recursiveBinarySearch(arr, 0, n - 1, target);

    if (found == -1)
        cout << "\nRecursive Binary Search: Not Found";
    else
        cout << "\nRecursive Binary Search: Found at position " << found + 1;

    return 0;
}