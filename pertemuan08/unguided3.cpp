/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;
/// Program Sequential Search untuk menghitung banyak angka 4 pada

int main()
{
    // Deklarasi variabel
    int n = 10;                                     // Jumlah elemen array
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Insialisasi array
    int cari = 4;                                   // Nilai yang akan dicari dalam array
    bool ketemu = false;                            // Variabel boleean
    int hitung = 0;                                 // Variabel untuk menghitung kemunculan nilai

    // Algoritma Sequential Search
    for (int i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            hitung++;
        }
    }

    // Menampilkan data
    cout << "===========================================================\n";
    cout << "\t\tProgram Sequential Search\n";
    cout << "===========================================================\n";
    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Mengecek data
    if (ketemu)
    {
        cout << "Angka " << cari << " ditemukan sebanyak " << hitung << endl;
    }
    else
    {
        cout << "Angka " << cari << " tidak ditemukan pada data." << endl;
    }
    cout << "===========================================================\n";
    return 0;
}