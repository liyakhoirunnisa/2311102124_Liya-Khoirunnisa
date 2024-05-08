/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;
/// PROGRAM STACK Liya Khoirunnisa

// Inisialisasi array
char isi[100];
int maksimal = 100, top = 0;

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
void PUSH(char x)
{
    if (top == maksimal)
    {
        cout << "Tumpukan Sudah Penuh";
    }
    else
    {
        top = top + 1;
        isi[top] = x;
    }
}

// Fungsi untuk menghapus data di stack
char POP()
{
    char hasil;
    if (top == 0)
    {
        cout << "Tumpukan sudah kosong";
        hasil = ' ';
    }
    else
    {
        hasil = isi[top];
        top = top - 1;
    }
    return hasil;
}

// program utama
int main()
{
    // Deklarasi variabel
    int i;
    string kalimat;
    cout << "===========================================\n";
    cout << "Program untuk Membalik kalimat\n";
    cout << "===========================================\n";

    // Inputkan kalimat yang akan dibalik
    cout << "Masukkan kata : ";
    getline(cin, kalimat);

    // Menambahkan data ke dalam stack
    for (i = 0; i < kalimat.length(); i++)
    {
        PUSH(kalimat[i]);
    }

    // Mencetak data
    cout << "Datastack Array : ";
    cout << "\nData : ";

    // Menghapus data di stack
    for (i = 0; i < kalimat[i]; i++)
    {
        cout << POP();
    }
    cout << "\n===========================================\n";
    return 0;
}