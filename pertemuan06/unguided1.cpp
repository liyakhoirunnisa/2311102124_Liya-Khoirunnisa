/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
using namespace std;

/// PROGRAM STACK Liya Khoirunnisa

// Inisialisasi array
string kalimat[5];
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
void pushArrayKalimat(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        kalimat[top] = data;
        top++;
    }
}

// Fungsi untuk menghapus data di stack
void popArrayKalimat()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        kalimat[top - 1] = "";
        top--;
    }
}

int main()
{
    // Deklarasi variabel
    string kalimat;
    int i, j;
    bool palindrom = true;

    // Menampilkan judul program
    cout << "===========================================\n";
    cout << "Program Mengecek Kata dan Kalimat Palindrom\n";
    cout << "===========================================\n";

    // Input Kalimat
    cout << "Masukkan Kalimat : ";
    cin >> kalimat;
    j = kalimat.length();

    // Cek Palindrom
    for (i = 0; i < j; i++)
    {
        if (kalimat[i] != kalimat[j - i - 1])
        {
            palindrom = false;
            break;
        }
    }
    if (palindrom == true)
    {
        cout << "Kalimat tersebut adalah : Palindrom\n";
    }
    else
    {
        cout << "Kalimat tersebut adalah : Bukan Palindrom\n";
    }
    cout << "===========================================\n";
    return 0;
}