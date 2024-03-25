#include <iostream>
using namespace std;
// PROGRAM DOUBLE LINKED LIST Liya Khoirunnisa

// Node class untuk merepresentasikan setiap elemen dalam list
class Node {
public:
    int data;
    Node *prev;
    Node *next;
};

// Doublylinkedlist class untuk mengelola linked list
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    // Inisialisasi linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Menambahkan data ke awal linked list 
    void push(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    // Menghapus data dari awal linked list
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    // Mengupdate data dalam linked list
    bool update(int oldData, int newData) {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Menghapus semua data dari linked list
    void deleteAll() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Menampilkan semua data dalam linked list
    void display() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Looping untuk menampilkan menu dan menerima input pengguna
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case untuk memproses pilihan pengguna
        switch (choice) {
            case 1:{
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}