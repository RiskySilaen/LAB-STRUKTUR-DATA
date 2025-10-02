#include <iostream>
using namespace std;

// deklarasi sebuah struktur mode
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// insert di depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

// insert di belakang
void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if ( head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// insert dengan nilai tertentu
void insertAfter(int n, int check) {
    if(head == NULL) {
        cout << "List kosong, insert di depan dulu\n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;
    while(p !=NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai" << check << "tidak di temukan\n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail) {
            tail == newNode;
        }
    }
}

// cetak lingked list
void printList() {
    Node *temp = head;
    cout << "isi dari linked list: ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}
int main() {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}