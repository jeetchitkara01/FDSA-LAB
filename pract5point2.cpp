#include <iostream> 
using namespace std; 
 
struct SNode { 
    int data; 
    SNode* next; 
}; 
 
SNode* shead = NULL; 
 
void sInsert(int data, int pos) { 
    SNode* temp = new SNode; 
    temp->data = data; 
 
    if (shead == NULL) { 
        temp->next = temp; 
        shead = temp; 
        return; 
    } 
 
    if (pos == 1) { 
        SNode* p = shead; 
 
        while (p->next != shead) 
            p = p->next; 
 
        temp->next = shead; 
        p->next = temp; 
        shead = temp; 
        return; 
    } 
 
    SNode* p = shead; 
 
    for (int i = 1; i < pos - 1 && p->next != shead; i++) 
        p = p->next; 
 
    temp->next = p->next; 
    p->next = temp; 
} 
 
void sDelete(int data) { 
    if (shead == NULL) 
        return; 
 
    if (shead->data == data) { 
        if (shead->next == shead) { 
            delete shead; 
            shead = NULL; 
            return; 
        } 
 
        SNode* last = shead; 
 
        while (last->next != shead) 
            last = last->next; 
 
        SNode* temp = shead; 
        shead = shead->next; 
        last->next = shead; 
        delete temp; 
        return; 
    } 
 
    SNode* p = shead; 
 
    while (p->next != shead && p->next->data != data) 
        p = p->next; 
 
    if (p->next != shead) { 
        SNode* temp = p->next; 
        p->next = temp->next; 
        delete temp; 
    } 
} 
 
void sDisplay() { 
    if (shead == NULL) { 
        cout << "Circle is empty" << endl; 
        return; 
    } 
 
    SNode* p = shead; 
 
    do { 
        cout << p->data << " "; 
        p = p->next; 
    } while (p != shead); 
 
    cout << endl; 
} 
 
 
struct DNode { 
    int data; 
    DNode* next; 
    DNode* prev; 
}; 
 
DNode* dhead = NULL; 
 
void dInsert(int data, int pos) { 
    DNode* temp = new DNode; 
    temp->data = data; 
 
    if (dhead == NULL) { 
        temp->next = temp; 
        temp->prev = temp; 
        dhead = temp; 
        return; 
    } 
 
    if (pos == 1) { 
        DNode* last = dhead->prev; 
 
        temp->next = dhead; 
        temp->prev = last; 
        last->next = temp; 
        dhead->prev = temp; 
        dhead = temp; 
        return; 
    } 
 
    DNode* p = dhead; 
 
    for (int i = 1; i < pos - 1 && p->next != dhead; i++) 
        p = p->next; 
 
    temp->next = p->next; 
    temp->prev = p; 
    p->next->prev = temp; 
    p->next = temp; 
} 
 
void dDelete(int data) { 
    if (dhead == NULL) 
        return; 
 
    DNode* p = dhead; 
 
    do { 
        if (p->data == data) { 
            if (p->next == p) { 
                delete p; 
                dhead = NULL; 
                return; 
            } 
 
            p->prev->next = p->next; 
            p->next->prev = p->prev; 
 
            if (p == dhead) 
                dhead = p->next; 
 
            delete p; 
            return; 
        } 
 
        p = p->next; 
 
    } while (p != dhead); 
} 
 
void dDisplay() { 
    if (dhead == NULL) { 
        cout << "Circle is empty" << endl; 
        return; 
    } 
 
    DNode* p = dhead; 
 
    do { 
        cout << p->data << " "; 
        p = p->next; 
    } while (p != dhead); 
 
    cout << endl; 
} 
 
int main() { 
    int choice, data, pos; 
 
    do { 
        cout << "\n1. Join Singly Circular"; 
        cout << "\n2. Leave Singly Circular"; 
        cout << "\n3. Display Singly Circular"; 
        cout << "\n4. Join Doubly Circular"; 
        cout << "\n5. Leave Doubly Circular"; 
        cout << "\n6. Display Doubly Circular"; 
        cout << "\n0. Exit"; 
        cout << "\nEnter choice: "; 
        cin >> choice; 
 
        if (choice == 1) { 
            cout << "Enter student number: "; 
            cin >> data; 
            cout << "Enter position: "; 
            cin >> pos; 
            sInsert(data, pos); 
            sDisplay(); 
        } 
        else if (choice == 2) { 
            cout << "Enter student number: "; 
            cin >> data; 
            sDelete(data); 
            sDisplay(); 
        } 
        else if (choice == 3) { 
            sDisplay(); 
        } 
        else if (choice == 4) { 
            cout << "Enter student number: "; 
            cin >> data; 
            cout << "Enter position: "; 
            cin >> pos; 
            dInsert(data, pos); 
            dDisplay(); 
        } 
        else if (choice == 5) { 
            cout << "Enter student number: "; 
            cin >> data; 
            dDelete(data); 
            dDisplay(); 
        } 
        else if (choice == 6) { 
            dDisplay(); 
        } 
 
    } while (choice != 0); 
 
    return 0; 
} 