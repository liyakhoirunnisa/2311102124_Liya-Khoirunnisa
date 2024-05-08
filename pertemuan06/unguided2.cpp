/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;
/// PROGRAM STACK Liya Khoirunnisa

// Inisialisasi array
char isi_2124[50];
int maksimal_2124 = 50, top_2124 = 0;

// Fungsi untuk mengecek apakah stack penuh
bool isFull_2124()
{
    return (top_2124 == maksimal_2124);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty_2124()
{
    return (top_2124 == 0);
}

// Fungsi untuk menambahkan data ke dalam stack
void pushArrayKalimat_2124(char data_2124)
{
    if (top_2124 == maksimal_2124)
    {
        cout << "Data telah penuh";
    }
    else
    {
        top_2124 = top_2124 + 1;
        isi_2124[top_2124] = data_2124;
    }
}

// Fungsi untuk menghapus data di stack
char popArrayKalimat_2124()
{
    char hasil_2124;
    if (top_2124 == 0)
    {
        cout << "Tidak ada data yang dihapus";
        hasil_2124 = ' ';
    }
    else
    {
        hasil_2124 = isi_2124[top_2124];
        top_2124 = top_2124 - 1;
    }
    return hasil_2124;
}

// program utama
int main()
{
    // Deklarasi variabel
    string kalimat_2124;
    int j;
    cout << "===========================================\n";
    cout << "       Program untuk Membalik kalimat      \n";
    cout << "===========================================\n";

    // Inputkan kalimat yang akan dibalik
    cout << "Masukkan Kata : ";
    getline(cin, kalimat_2124);
    j = kalimat_2124.length();

    // Menambahkan data ke dalam stack
    for (int i = 0; i < j; i++)
    {
        pushArrayKalimat_2124(kalimat_2124[i]);
    }

    // Mencetak data
    cout << "Datastack Array : ";
    cout << "\nData : ";

    // Menghapus data di stack
    for (int i = 0; i < j; i++)
    {
        cout << popArrayKalimat_2124();
    }
    cout << "\n===========================================\n";
    return 0;
}