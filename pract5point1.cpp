#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insertBeginning(string song) {
    Node* temp = new Node;
    temp->song = song;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
}

void insertEnd(string song) {
    Node* temp = new Node;
    temp->song = song;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->prev = p;
}

void insertAfter(string currentSong, string newSong) {
    Node* p = head;

    while (p != NULL && p->song != currentSong)
        p = p->next;

    if (p == NULL) {
        cout << "Song not found" << endl;
        return;
    }

    Node* temp = new Node;
    temp->song = newSong;
    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL)
        p->next->prev = temp;

    p->next = temp;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void countSongs() {
    int count = 0;
    Node* p = head;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    cout << "Total songs: " << count << endl;
}

void display() {
    if (head == NULL) {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* p = head;

    while (p != NULL) {
        cout << p->song << " ";
        p = p->next;
    }

    cout << endl;
}

int main() {
    int choice;
    string song, currentSong;

    do {
        cout << "\n1. Add Beginning";
        cout << "\n2. Add End";
        cout << "\n3. Insert After Song";
        cout << "\n4. Delete First";
        cout << "\n5. Count Songs";
        cout << "\n6. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter song: ";
            cin >> song;
            insertBeginning(song);
            display();
        }
        else if (choice == 2) {
            cout << "Enter song: ";
            cin >> song;
            insertEnd(song);
            display();
        }
        else if (choice == 3) {
            cout << "Enter current song: ";
            cin >> currentSong;
            cout << "Enter new song: ";
            cin >> song;
            insertAfter(currentSong, song);
            display();
        }
        else if (choice == 4) {
            deleteFirst();
            display();
        }
        else if (choice == 5) {
            countSongs();
        }
        else if (choice == 6) {
            display();
        }

    } while (choice != 0);

    return 0;
}