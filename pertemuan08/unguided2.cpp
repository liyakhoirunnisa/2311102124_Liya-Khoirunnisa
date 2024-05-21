/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/// Program Sequential Search untuk menghitung banyak huruf vokal pada sebuah kalimat

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool cekVokal_2124(char huruf_2124)
{
    return (huruf_2124 == 'a' || huruf_2124 == 'A' || huruf_2124 == 'e' || huruf_2124 == 'E' || huruf_2124 == 'i' || huruf_2124 == 'I' || huruf_2124 == 'o' || huruf_2124 == 'O' || huruf_2124 == 'u' || huruf_2124 == 'U');
}

// Fungsi sequential search untuk mencari keberadaan huruf dalam kalimat
bool sequentialSearch_2124(string kalimat_2124, char huruf_2124)
{
    for (char vokal_2124 : kalimat_2124)
    {
        if (vokal_2124 == huruf_2124)
        {
            return true; // Huruf ditemukan
        }
    }
    return false; // Huruf tidak ditemukan
}

// Fungsi untuk menghitung jumlah huruf vokal di dalam kalimat
int hitungVokal_2124(string &kalimat_2124, string &hurufVokal_2124)
{
    int jmlVokal_2124 = 0;
    for (char huruf_2124 : kalimat_2124)
    {
        if (cekVokal_2124(huruf_2124))
        {
            jmlVokal_2124 += sequentialSearch_2124(kalimat_2124, huruf_2124);
            hurufVokal_2124 += huruf_2124;
        }
    }
    return jmlVokal_2124;
}

int main()
{
    // Deklarasi kalimat
    string kalimat_2124, hurufVokal_2124;

    // Tampilan judul program
    cout << "===========================================================\n";
    cout << "\t\tProgram Mencari Huruf Vokal\n";
    cout << "===========================================================\n";

    // Input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_2124);

    // Hitung jumlah vokal dalam kalimat
    int jmlVokal_2124 = hitungVokal_2124(kalimat_2124, hurufVokal_2124);

    // Tampilkan huruf vokal yang terdapat dari kalimat
    cout << "Huruf vokal dalam kalimat:";
    for (char huruf : hurufVokal_2124)
    {
        cout << setw(2) << huruf;
    }
    cout << endl;

    // Tampilkan jumlah huruf vokal yang terdapat di kalimat
    cout << "Jumlah huruf vokal dalam kalimat: " << jmlVokal_2124 << endl;
    cout << "===========================================================\n";
    return 0;
}
