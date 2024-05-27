/* oleh Liya Khoirunnisa - 2311102124 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/// Program Graph untuk menghitung jarak dari sebuah kota ke kota lainnya.

// Fungsi input nama setiap simpul
void inputNamaSimpul(string simpul_2124[], int jmlSimpul_2124)
{
    for (int i = 0; i < jmlSimpul_2124; ++i)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul_2124[i];
    }
}

// Fungsi input bobot antar simpul
void inputBobot(int bobot_2124[][10], string simpul_2124[], int jmlSimpul_2124)
{
    for (int i = 0; i < jmlSimpul_2124; ++i)
    {
        for (int j = 0; j < jmlSimpul_2124; ++j)
        {
            cout << simpul_2124[i] << "--> " << simpul_2124[j] << " = ";
            cin >> bobot_2124[i][j];
        }
    }
}

// Fungsi untuk menampilkan matriks bobot
void tampilGraph(int bobot_2124[][10], string simpul_2124[], int jmlSimpul_2124)
{
    cout << setw(3) << " ";
    for (int i = 0; i < jmlSimpul_2124; ++i)
    {
        cout << setw(10) << simpul_2124[i];
    }
    cout << endl;

    for (int i = 0; i < jmlSimpul_2124; ++i)
    {
        cout << setw(6) << simpul_2124[i];
        for (int j = 0; j < jmlSimpul_2124; ++j)
        {
            cout << setw(7) << bobot_2124[i][j];
        }
        cout << endl;
    }
}

int main()
{
    // Deklarasi variabel
    int jmlSimpul_2124;

    // Input jumlah simpul
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> jmlSimpul_2124;

    // Array untuk menyimpan nama simpul
    string simpul_2124[jmlSimpul_2124];
    int bobot_2124[10][10];

    // Menampilkan nama simpul
    cout << "Silakan masukkan nama simpul" << endl;
    inputNamaSimpul(simpul_2124, jmlSimpul_2124); // Memanggil fungsi input nama simpul

    // Input bobot
    cout << "Silakan masukkan bobot antar simpul" << endl;
    inputBobot(bobot_2124, simpul_2124, jmlSimpul_2124); // Memanggil fungsi input bobot
    cout << endl;

    // Menampilkan graph
    tampilGraph(bobot_2124, simpul_2124, jmlSimpul_2124);
    cout << endl;

    return 0;
}
