#include <iostream>
#include <iomanip>

using namespace std;
/// PROGRAM MENAMPILKAN GRAF KOTA DENGAN MATRIKS Liya Khoirunnisa

// Daftar simpul kota
string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

// Matriks busur
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

// Fungsi menampilkan graf
void tampilGraph()
{
    // Perulangan setiap baris matriks busur
    for (int baris = 0; baris < 7; baris++)
    {
        // Menampilkan nama kota
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // perulangan setiap kolom matriks busur
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                // Menampilkan nama kota tujuan dan bobot busur
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    // Memanggil fungsi untuk menampilkan graf
    tampilGraph();
    return 0;
}