#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL; 

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " dimasukkan ke stack" << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << top->data << " dihapus dari stack" << endl;
    Node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    Node* temp = top;
    cout << "Isi stack: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    
    pop();
    display();

    return 0;
}