/*Oleh Liya Khoirunnisa - 2311102124*/

// Contoh Program Struct dan Class
#include <iostream>

using namespace std;

// Mendefinisikan struct mahasiswa
struct Mahasiswa_2124 {
    string nama_2124; // Menyimpan nama mahasiswa
    string jurusan_2124; // Menyimpan jurusan mahasiswa
    string kelas_2124; // Menyimpan kelas mahasiswa
};

// Mendefinisikan class dosen
class Dosen_2124 {
public:
    string nama_2124; // Menyimpan nama dosen
    string mataKuliah_2124; // Menyimpan mata kuliah yang diampu

};

int main() {
    // Membuat objek mahasiswa
    Mahasiswa_2124 mhs1;
    mhs1.nama_2124 = "Liya Khoirunnisa"; // Inisialisasi nilai nama mahasiswa
    mhs1.jurusan_2124 = "S1 Teknik Informatika"; // Inisialisasi nilai jurusan mahasiswa
    mhs1.kelas_2124 = "IF-11-D"; // Inisialisasi nilai kelas mahasiswa

    // Membuat objek dosen
    Dosen_2124 dsn1;
    dsn1.nama_2124 = "Muhammad Afrizal Amrustian, S.Kom., M.Kom"; // Inisialisai nilai nama dosen
    dsn1.mataKuliah_2124 = "Struktur Data dan Algoritma"; // Inisialisasi nilai mata kuliah yang diampu

    // Mencetak informasi mahasiswa dan dosen ke layar
    cout << "Informasi Mahasiswa: \n";
    cout << "Nama: " << mhs1.nama_2124 << endl; // Mencetak nama mahasiswa
    cout << "Jurusan: " << mhs1.jurusan_2124 << endl; // Mencetak jurusan mahasiswa
    cout << "Kelas: " << mhs1.kelas_2124 << endl; // Mencetak kelas mahasiswa
    cout << "Dosen: " << dsn1.nama_2124 << " mengampu mata kuliah " << dsn1.mataKuliah_2124 << endl; // Mencetak Informasi dosen

    return 0;
}
