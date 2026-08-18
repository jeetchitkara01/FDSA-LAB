#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int book[n];

    cout << "Enter book IDs:\n";
    for (int i = 0; i < n; i++)5
    {
        cin >> book[i];
    }

    cout << "\nBooks borrowed more than once:\n";

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (book[i] == book[j])
            {
                count++;
            }
        }

        bool printed = false;

        for (int k = 0; k < i; k++)
        {
            if (book[i] == book[k])
            {
                printed = true;
            }
        }

        if (count > 1 && printed == false)
        {
            cout << book[i] << " ";
        }
    }

    return 0;
}