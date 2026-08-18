#include <iostream>
using namespace std;

int recursiveSearch(int plate[], int n, int target, int index)
{
    if (index == n)
        return -1;

    if (plate[index] == target)
        return index;

    return recursiveSearch(plate, n, target, index + 1);
}

int main()
{
    int n, target;

    cout << "Enter number of vehicles: ";
    cin >> n;

    int plate[n];

    cout << "Enter license plate IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> plate[i];
    }

    cout << "Enter target plate: ";
    cin >> target;

    int found = -1;

    for (int i = 0; i < n; i++)
    {
        if (plate[i] == target)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
        cout << "\nLinear Search: Not Found";
    else
        cout << "\nLinear Search: Found at position " << found + 1;

    found = recursiveSearch(plate, n, target, 0);

    if (found == -1)
        cout << "\nRecursive Search: Not Found";
    else
        cout << "\nRecursive Search: Found at position " << found + 1;

    return 0;
}