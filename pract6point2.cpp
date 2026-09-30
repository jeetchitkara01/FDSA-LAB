#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* temp = new Node;
    temp->page = page;
    temp->next = top;
    top = temp;

    cout << "Current page: " << top->page << endl;
}

void back() {
    if (top == NULL || top->next == NULL) {
        cout << "No previous page" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    cout << "Current page: " << top->page << endl;
}

int main() {
    int choice;
    string page;

    do {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Current Page";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            visit(page);
        }
        else if (choice == 2) {
            back();
        }
        else if (choice == 3) {
            if (top == NULL)
                cout << "No page visited" << endl;
            else
                cout << "Current page: " << top->page << endl;
        }

    } while (choice != 0);

    return 0;
}