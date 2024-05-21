/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;
/// Program Binary Search mencari huruf pada sebuah kalimat

// Fungsi untuk melakukan pengurutan pada data
void selectionSort_2124(char dataArray_2124[], int length_2124)
{
    int min_2124;
    char temp;

    // Perulangan untuk setiap elemen array kecuali yang terakhir
    for (int i = 0; i < length_2124 - 1; i++)
    {
        min_2124 = i;

        // Perulangan untuk menemukan elemen terkecil yang belum diurutkan
        for (int j = i + 1; j < length_2124; j++)
        {

            // Jika elemen saat ini lebih kecil dari elemen minimum, maka elemen tersebut sebagai minimum
            if (dataArray_2124[j] < dataArray_2124[min_2124])
            {
                min_2124 = j;
            }
        }

        // Menukar elemen terkecil dengan lemen pertama
        temp = dataArray_2124[i];
        dataArray_2124[i] = dataArray_2124[min_2124];
        dataArray_2124[min_2124] = temp;
    }
}

// Fungsi binary search untuk melakukan pencarian pada data array
void binarySearch_2124(char dataArray_2124[], int length_2124, char cari_2124)
{
    int awal_2124, akhir_2124, tengah_2124;
    awal_2124 = 0;
    akhir_2124 = length_2124 - 1;
    bool ketemu_2124 = false;

    // Perulangan untuk melakukan binary search
    while (!ketemu_2124 && awal_2124 <= akhir_2124)
    {
        tengah_2124 = (awal_2124 + akhir_2124) / 2;
        if (dataArray_2124[tengah_2124] == cari_2124)
        {
            ketemu_2124 = true;
        }
        else if (dataArray_2124[tengah_2124] < cari_2124)
        {
            awal_2124 = tengah_2124 + 1;
        }
        else
        {
            akhir_2124 = tengah_2124 - 1;
        }
    }

    // Menampilkan hasil pencarian
    if (ketemu_2124)
    {
        cout << "Data ditemukan pada index ke- " << tengah_2124 << endl;
    }
    else
    {
        cout << "Data tidak ditemukan\n";
    }
}

int main()
{
    // Deklarasi variabel
    char kalimat_2124[100], cari_2124;

    // Menampilkan judul progra,
    cout << "===================================================================\n";
    cout << "\t\tProgram Mencari Huruf Pada Kalimat\n";
    cout << "===================================================================\n";

    // Meminta input kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    cin.getline(kalimat_2124, 100);

    // Menentukan panjang kalimat
    int length_2124 = strlen(kalimat_2124);

    // Input huruf yang ingin dicari
    cout << "Cari huruf: ";
    cin >> cari_2124;

    // Menampilkan kalimat asli sebelum diurutkan
    cout << "Kalimat asli: " << kalimat_2124 << endl;

    // Mengurutkan kalimat
    selectionSort_2124(kalimat_2124, length_2124);

    // Menampilkand kalimat yang sudah diurutkan
    cout << "Setelah diurutkan: ";
    for (int x = 0; x < length_2124; x++)
    {
        cout << setw(2) << kalimat_2124[x];
    }
    cout << endl;

    // Melakukan pencarian pada kalimat yang sudah diurutkan
    binarySearch_2124(kalimat_2124, length_2124, cari_2124);

    cout << "===================================================================\n";

    _getche();

    return 0;
}
