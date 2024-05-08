#include <iostream>
using namespace std;
/// PROGRAM STACK Liya Khoirunnisa

// Inisialisasi array
string arrayBuku[5];
int maksimal = 5, top = 0;

// Fungsi untuk mengecek apakah stack penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Fungsi untuk menambahkan data ke dalam stack
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

// Fungsi untuk menghapus data di stack
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

// Fungsi untuk melihat data pada posisi tertentu
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data
int countStack()
{
    return top;
}

// Fungsi untuk mengubah data pada posisi tertentu
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

// Fungsi untuk menghapus semua data pada stack
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

// Fungsi untuk mencetak data dalam stack
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    // Menambahkan data ke dalam stack
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Mencetak data stack
    cetakArrayBuku();
    cout << "\n";

    // Mengecek apakah stack penuh atau kosong
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    // Melihat data pada posisi tertentu
    peekArrayBuku(2);

    // Menghapus data di stack
    popArrayBuku();

    // Menghitung jumlah data stack
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");

    // Mencetak data dalam stack
    cetakArrayBuku();
    cout << "\n";

    // Menghapus semua data dalam stack
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    // Mencetak data setelah stack kosong
    cetakArrayBuku();

    return 0;
}