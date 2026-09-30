#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter maximum number of trays: ";
    cin >> n;

    int stack[n];
    int top = -1;
    int choice, tray;

    do {
        cout << "\n1. Place Tray";
        cout << "\n2. Take Tray";
        cout << "\n3. Display Top Tray";
        cout << "\n4. Display Stack";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (top == n - 1) {
                cout << "Stack Overflow" << endl;
            }
            else {
                cout << "Enter tray number: ";
                cin >> tray;

                top++;
                stack[top] = tray;

                cout << "Tray placed successfully" << endl;
                cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 2) {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
            }
            else {
                cout << "Tray " << stack[top] << " removed" << endl;
                top--;

                if (top == -1)
                    cout << "Stack is now empty" << endl;
                else
                    cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 3) {
            if (top == -1)
                cout << "Stack is empty" << endl;
            else
                cout << "Top tray: " << stack[top] << endl;
        }

        else if (choice == 4) {
            if (top == -1) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Trays: ";

                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";

                cout << endl;
            }
        }

    } while (choice != 0);

    return 0;
}