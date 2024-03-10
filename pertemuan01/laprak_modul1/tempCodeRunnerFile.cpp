#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    long nim;
    string kelas;
};

class Dosen {
private:
    string nama;
    string mataKuliah;
public:
    Dosen(string n, string matkul) : nama(n), mataKuliah(matkul) {}
    void mengajar() {
        cout << "Dosen " << nama << " mengampu mata kuliah " << mataKuliah << endl;
    }
};

int main() {
    Mahasiswa mhs1;
    mhs1.nama = "Liya Khoirunnisa";
    mhs1.nim = 2311102124;
    mhs1.kelas = "IF-11-D";

    Dosen dsn1("Muhammad Afrizal Amrustian, S.Kom., M.Kom", "Struktur Data dan Algoritma");

    cout << "Informasi Mahasiswa: \n";
    cout << "Nama: " << mhs1.nama << endl;
    cout << "NIM: " << mhs1.nim << endl;
    cout << "Kelas: " << mhs1.kelas << endl;

    dsn1.mengajar();

    return 0;
}
