/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;
// Program Queue dengan linked list untuk antrian mahasiswa

// Struktur node untuk linked list
struct Node
{
    string nama_2124;
    string nim_2124;
    Node *next;
};

// Batas maksimal queue
int maksimalNode_2124 = 5;

// Variabel global untuk front dan rear
Node *front = NULL;
Node *rear = NULL;

// Fungsi menghitung jumlah elemen dalam queue
int countQueue_2124()
{
    int count_2124 = 0;
    Node *temp = front;
    while (temp != NULL)
    {
        count_2124++;
        temp = temp->next;
    }
    return count_2124;
}

// Fungsi mengecek apakah queue penuh
bool isFull_2124()
{
    if (countQueue_2124() == maksimalNode_2124)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Fungsi mengecek apakah queue kosong
bool isEmpty_2124()
{
    return front == NULL;
}

// Fungsi menambahkan elemen ke belakang queue
void enqueueAntrian_2124(string nama_2124, string nim_2124)
{
    if (isFull_2124())
    {
        cout << "Antrian penuh" << endl;
    }
    Node *newNode = new Node;
    newNode->nama_2124 = nama_2124;
    newNode->nim_2124 = nim_2124;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi menghapus elemen dari depan queue
void dequeueAntrian_2124()
{
    if (front == NULL)
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

// Fungsi menampilkan seluruh queue
void viewQueue_2124()
{
    cout << "Data antrian mahasiswa:" << endl;
    Node *temp = front;
    for (int i = 0; i < 5; i++)
    {
        if (temp != NULL)
        {
            cout << i + 1 << ".  Nama: " << temp->nama_2124 << endl;
            cout << "    NIM: " << temp->nim_2124 << endl;
            temp = temp->next;
        }
        else
        {
            cout << i + 1 << ".  (kosong)" << endl;
        }
    }
}

// Fungsi menghapus semua elemen dalam queue
void clearQueue_2124()
{
    while (front != NULL)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

int main()
{
    enqueueAntrian_2124("Syifa Hadju", "2211102124");
    enqueueAntrian_2124("Liya Khoirunnisa", "2311102124");
    viewQueue_2124();
    cout << "Jumlah antrian = " << countQueue_2124() << endl;
    dequeueAntrian_2124();
    viewQueue_2124();
    cout << "Jumlah antrian = " << countQueue_2124() << endl;
    clearQueue_2124();
    viewQueue_2124();
    cout << "Jumlah antrian = " << countQueue_2124() << endl;
    return 0;
}
