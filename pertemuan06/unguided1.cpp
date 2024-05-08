#include <iostream>
using namespace std;

/// PROGRAM STACK Liya Khoirunnisa

// Inisialisasi array
char isi_2124[10];
int maksimal_2124 = 5, top_2124 = -1;

// Fungsi untuk mengecek apakah stack penuh
bool isFull_2124()
{
    return (top_2124 == maksimal_2124 - 1);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty_2124()
{
    return (top_2124 == -1);
}

// Fungsi untuk menambahkan data ke dalam stack
void pushArrayKalimat_2124(char data_2124)
{
    if (isFull_2124())
    {
        cout << "Data telah penuh\n";
    }
    else
    {
        top_2124++;
        isi_2124[top_2124] = data_2124;
    }
}

// Fungsi untuk menghapus data di stack
void popArrayKalimat_2124()
{
    if (isEmpty_2124())
    {
        cout << "Tidak ada data yang dihapus\n";
    }
    else
    {
        top_2124--;
    }
}

int main()
{
    // Deklarasi variabel
    string kalimat_2124;
    int j;
    bool palindrom = true;

    // Menampilkan judul program
    cout << "===========================================\n";
    cout << "Program Mengecek Kata dan Kalimat Palindrom\n";
    cout << "===========================================\n";

    // Input Kalimat
    cout << "Masukkan Kalimat : ";
    cin >> kalimat_2124;
    j = kalimat_2124.length();

    // Menambahkan kalimat ke dalam stack
    for (int i = 0; i < j; i++)
    {
        pushArrayKalimat_2124(kalimat_2124[i]);
    }

    // Cek Palindrom
    for (int i = 0; i < j; i++)
    {
        if (kalimat_2124[i] != isi_2124[top_2124])
        {
            palindrom = false;
            break;
        }
        popArrayKalimat_2124();
    }

    if (palindrom == true)
    {
        cout << "Kalimat tersebut adalah : Palindrom\n";
    }
    else
    {
        cout << "Kalimat tersebut adalah : Bukan Palindrom\n";
    }
    cout << "===========================================\n\n";
    return 0;
}