#include <iostream>
using namespace std;
/// PROGRAM SQUENTIAL SEARCH Liya Khoirunnisa

int main()
{
    // Deklarasi variabel
    int n = 10;                                      // Jumlah elemen array
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Inisialisasi array
    int cari = 10;                                   // Nilai yang akan dicari dalam array
    bool ketemu = false;                             // Variabel boleean
    int i;                                           // Variabel iterasi

    // Algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }

    // Menampilkan data
    cout << "\tProgram Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Mengecek data
    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}