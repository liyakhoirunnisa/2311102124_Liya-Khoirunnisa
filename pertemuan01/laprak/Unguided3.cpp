/*Oleh Liya Khoirunnisa - 2311102124*/

#include <iostream>
#include <map> // Library untuk memggunakan fungsi map

using namespace std;

int main() {

    // Deklarasi map dengan key int dan string untuk menyimpan nama mahasiswa
    map<int, string> mahasiswa_2124;

    // Menambahkan nama mahasiswa ke dalam map
    mahasiswa_2124[1] = "Liya Khoirunnisa";
    mahasiswa_2124[2] = "Naya Putwi Setiasih";
    mahasiswa_2124[3] = "Shafa Adila Santoso";

    // Mencetak judul 
    cout << "Anggota Kelompok Struktur Data dan ALgoritma:\n";

    // Looping untuk mencetak elemen map
    for (int i = 1; i <= mahasiswa_2124.size(); i++) {
        cout << i << ". " << mahasiswa_2124[i] << endl; // Mencetak nama anggota kelompok
    }
    return 0;
}