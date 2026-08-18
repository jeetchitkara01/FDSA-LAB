#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int item[n];
    

    cout << "Enter item IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> item[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    int k = h % n;

    cout << "\nFinal display order:\n";

    for (int i = k; i < n; i++)
    {
        cout << item[i] << " ";
    }

    for (int i = 0; i < k; i++)
    {
        cout << item[i] << " ";
    }

    return 0;
}