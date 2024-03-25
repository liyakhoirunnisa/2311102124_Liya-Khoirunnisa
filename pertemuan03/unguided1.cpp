/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;
// Program single linked list untuk menampilkan nama mahasiswa dan umur

// Deklarasi Struct Node
struct Node {
    string nama_2124;
    int usia_2124;
    Node *next;
};
Node *head;
Node *tail;

// Inisialisasi Node
void init_2124() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty_2124() {
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void insertDepan_2124(string nama_2124, int usia_2124) {
    // Buat Node baru
    Node *baru_2124 = new Node;
    baru_2124->nama_2124 = nama_2124;
    baru_2124->usia_2124 = usia_2124;
    baru_2124->next = NULL;
    if (isEmpty_2124() == true) {
        head = tail = baru_2124;
        tail->next = NULL;
    }
    else {
        baru_2124->next = head;
        head = baru_2124;
    }
}

// Tambah Belakang
void insertBelakang_2124(string nama_2124, int usia_2124) {
    // Buat Node baru
    Node *baru_2124 = new Node;
    baru_2124->nama_2124 = nama_2124;
    baru_2124->usia_2124 = usia_2124;
    baru_2124->next = NULL;
    if (isEmpty_2124() == true) {
        head = tail = baru_2124;
        tail->next = NULL;
    }
    else {
        tail->next = baru_2124;
        tail = baru_2124;
    }
}

// Tambah Tengah
void insertTengah_2124(string nama_2124, int usia_2124, string posisiNama_2124) {
    // Buat Node baru
    Node *baru_2124 = new Node;
    baru_2124->nama_2124 = nama_2124;
    baru_2124->usia_2124 = usia_2124;

    Node *temp_2124 = head;
    while (temp_2124 != NULL && temp_2124->nama_2124 != posisiNama_2124 ) {
        temp_2124 = temp_2124->next;
    }

    if (temp_2124 == NULL) {
        cout << "Node dengan nama " << posisiNama_2124 << " tidak ditemukan." << endl;
        return;
    }
        baru_2124->next = temp_2124->next;
        temp_2124->next = baru_2124;
}

// Menghapus node berdasarkan nama
void hapus_2124(string nama_2124) {
    Node *hapus_2124, *temp_2124;
    if (isEmpty_2124() == false) {
        hapus_2124 = head;
        temp_2124 = head;
        while (hapus_2124 != NULL && hapus_2124->nama_2124 != nama_2124) {
            temp_2124 = hapus_2124;
            hapus_2124 = hapus_2124->next;
        }
        if (hapus_2124 == NULL) {
            cout << "Data dengan nama " << nama_2124 << " tidak ditemukan." << endl;
        }
        else if (hapus_2124 == head) {
            head = head->next;
            delete hapus_2124;
        }
        else {
            temp_2124->next = hapus_2124->next;
            delete hapus_2124;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

// Mengubah nama dan usia baru
void ubah_2124(string nama_2124, string namaBaru_2124, int usiaBaru_2124) {
    Node *temp_2124 = head;
    while (temp_2124 != NULL && temp_2124->nama_2124 != nama_2124) {
        temp_2124 = temp_2124->next;
    }
    if (temp_2124 == NULL) {
        cout << "Data dengan nama " << nama_2124 << " tidak ditemukan." << endl;
    }
    else {
        temp_2124->nama_2124 = namaBaru_2124;
        temp_2124->usia_2124 = usiaBaru_2124;
    }
}

// Menampilkan seluruh data linked list
void tampil_2124() {
    Node *temp_2124;
    temp_2124 = head;
    if (isEmpty_2124() == false) {
        while (temp_2124 != NULL) {
            cout << temp_2124->nama_2124 << " " << temp_2124->usia_2124 << endl;
            temp_2124 = temp_2124->next;
        }
        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

// Deklarasi variabel
int pilih_2124, usia_2124, usiaBaru_2124;
string nama_2124, namaBaru_2124, posisiNama_2124;

int main() {
    init_2124();

    // Perulangan untuk menampilkan menu 
     do {
        // Tampilkan menu
        cout << "Menu \n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Hapus\n";
        cout << "5. Ubah\n";
        cout << "6. Tampil\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih_2124;

        // Switch case untuk memproses pilihan pengguna
        switch (pilih_2124) {
            case 1:
                // Menambah data baru di depan
                cout << "Masukkan nama: ";
                cin >> nama_2124;
                cout << "Masukkan usia: ";
                cin >> usia_2124;
                insertDepan_2124(nama_2124, usia_2124);
                break;
            case 2:
                // Menambah data baru di belakang
                cout << "Masukkan nama: ";
                cin >> nama_2124;
                cout << "Masukkan usia: ";
                cin >> usia_2124;
                insertBelakang_2124(nama_2124, usia_2124);
                break;
            case 3:
                // Menambah data baru di tengah
                cout << "Masukkan nama: ";
                cin >> nama_2124;
                cout << "Masukkan usia: ";
                cin >> usia_2124;
                cout << "Masukkan nama posisi: ";
                cin >> posisiNama_2124;
                insertTengah_2124(nama_2124, usia_2124, posisiNama_2124);
                break;
            case 4:
                // Menghapus node berdasarkan nama
                cout << "Masukkan nama yang akan dihapus: ";
                cin >> nama_2124;
                hapus_2124(nama_2124);
                break;
            case 5:
                // Mengubah nama dan usia baru
                cout << "Masukkan nama yang ingin diubah: ";
                cin >> nama_2124;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru_2124;
                cout << "Masukkan usia baru: ";
                cin >> usiaBaru_2124;
                ubah_2124(nama_2124, namaBaru_2124, usiaBaru_2124);
                break;
            case 6:
                // Menampilkan isi list
                cout << "Data Mahasiswa: " << endl;
                tampil_2124();
                break;
            case 7:
                // Keluar dari program
                cout << "Keluar dari program." << endl;
                break;
            default:
                // Input yang dimasukkan tidak tersedia
                cout << "Maaf, pilihan tidak tersedia!" << endl;
        }
    } while (pilih_2124 != 7);
    
    return 0;
}