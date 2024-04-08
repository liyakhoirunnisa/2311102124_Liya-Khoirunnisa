/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
/// Program hash table data mahasiswa berdasarkan NIM dan nilai

// Ukuran hash table
const int tableSize_2124 = 11;

// Class untuk merepresentasikan node pada hash tabel
class hashpair_2124 {
public:
    string nim_2124;
    float nilai_2124;
    hashpair_2124(string nim_2124, float nilai_2124) {
        this->nim_2124 = nim_2124;
        this->nilai_2124 = nilai_2124;
    }
};

// Class untuk merepresentasikan hash map
class hashMap_2124 {
private:
    vector<hashpair_2124 *> table[tableSize_2124];

public:
    int hashFunc_2124(string key) {
        int hashVal_2124 = 0;
        for (char c : key) {
            hashVal_2124 += c;
        }
        return hashVal_2124 % tableSize_2124;
    }

    // Tambah data ke dalam hash map
    void tambah_2124(string nim_2124, float nilai_2124) {
        int hashVal_2124 = hashFunc_2124(nim_2124);
        for (auto pair : table[hashVal_2124]) {
            if (pair->nim_2124 == nim_2124) {
                pair->nilai_2124 = nilai_2124;
                return;
            }
        }
        table[hashVal_2124].push_back(new hashpair_2124(nim_2124, nilai_2124));
    }
    
    // Penghapusan data dari hash map
    void hapus_2124(string nim_2124){
        int hashVal_2124 = hashFunc_2124(nim_2124);
        for (auto it = table[hashVal_2124].begin(); it != table[hashVal_2124].end(); it++) {
            if ((*it)->nim_2124 == nim_2124) {
                table[hashVal_2124].erase(it);
                return;
            }
        }
    }

    // Pencarian nilai berdasarkan nama
    float cariNim_2124(string nim_2124) {
        int hashVal_2124 = hashFunc_2124(nim_2124);
        for (auto pair : table[hashVal_2124]) {
            if (pair->nim_2124 == nim_2124) {
                return pair->nilai_2124;
            }
        }
        return -1;
    }

    // Pencarian nilai berdasarkan rentang nilai
    void cariRentangNilai_2124(int min, int max) {
        cout << "============================================\n";
        cout << "|              DATA MAHASISWA              |\n";
        cout << "============================================\n";
        cout << "| NIM                | NILAI               |\n";
        cout << "============================================\n";
        bool ditemukan_2124 = false;
        for (int i = 0; i < tableSize_2124; i++) {
            for (auto pair : table[i]) {
                if (pair->nilai_2124 >= min && pair->nilai_2124 <= max) {
                    ditemukan_2124 = true;
                    cout << "| " << setw(19) << left << pair->nim_2124;
                    cout << "| " << setw(19) << left << pair->nilai_2124 << " |\n";
                }
            }
        }
        if (!ditemukan_2124) {
            cout << "|              Tidak ada data              |\n";
        }
        cout << "============================================\n";
        cout << endl;
    }

    // Pencetakan isi hash map
    void print_2124() {
        
        for (int i = 0; i < tableSize_2124; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->nim_2124 << ", " << pair->nilai_2124 << "]";
                }
            }
            cout << endl;
        }
    }
};

// Deklarasi variabel
int pilihan_2124, minNilai_2124, maksNilai_2124;
string nim_2124;
float nilai_2124;
int main() {
    hashMap_2124 mahasiswaMap;

    // Perulangan menu
    do{
        cout << "////////////////////// MENU //////////////////////\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa berdasarkan NIM\n";
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai\n";
        cout << "5. Tampilkan data mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "------------------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> pilihan_2124;

        // Percabangan menu
        switch (pilihan_2124) {
            case 1:
                // Input NIM
                cout << "Masukkan NIM: ";
                cin >> nim_2124;

                // Input nilai
                cout << "Masukkan nilai: ";
                cin >> nilai_2124;

                // Tambah data mahasiswa
                mahasiswaMap.tambah_2124(nim_2124, nilai_2124);
                cout << "Data berhasil ditambahkan\n";
                break;
            case 2:
                // Input NIM 
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> nim_2124;

                // Hapus data mahasiswa
                mahasiswaMap.hapus_2124(nim_2124);
                cout << "Data berhasil dihapus\n";
                break;
            case 3:
                // Input NIM
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> nim_2124;

                // Cari nilai berdasarkan NIM
                nilai_2124 = mahasiswaMap.cariNim_2124(nim_2124);
                if (nilai_2124 != -1) {
                    cout << "Nilai mahasiswa dengan NIM " << nim_2124 << ": " << nilai_2124 << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << nim_2124 << " tidak ditemukan.\n";
                }
                break;
            case 4:
                // Input rentang nilai yang dicari
                cout << "Masukkan rentang nilai (min, max): ";
                cin >> minNilai_2124 >> maksNilai_2124;

                // Cari nilai berdasarkan rentang nilai
                cout << "Mahasiswa dengan nilai antara " << minNilai_2124 << " dan " << maksNilai_2124 << ":\n";
                mahasiswaMap.cariRentangNilai_2124(minNilai_2124, maksNilai_2124);
                break;
            case 5:
                // Mencetak data mahasiswa
                mahasiswaMap.print_2124();
                break;
            case 6:
                // Keluar program
                cout << "Keluar dari program.\n";
                break;
            default:
                // Kesalahan input
                cout << "Maaf, pilihan tidak tersedia!\n";
        }
        cout << endl;
    } while (pilihan_2124 != 6);

    return 0;
}