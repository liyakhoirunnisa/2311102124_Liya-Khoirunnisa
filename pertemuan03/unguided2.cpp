/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <iomanip>

using namespace std;
// Program modifikasi Double Linked List Guided 2 untuk menampilkan nama produk dan harga

// Class node untuk menyimpan data produk
class Node {
public:
    string nama_2124;
    int harga_2124;
    Node *prev;
    Node *next;
};

// Class Doubly linked list untuk menyimpan daftar produk
class DoublyLinkedList_2124 {
public:
    Node *head;
    Node *tail;
    DoublyLinkedList_2124() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan produk ke akhir daftar
    void push_2124(string nama_2124, int harga_2124) {
        Node *newNode = new Node;
        newNode->nama_2124 = nama_2124;
        newNode->harga_2124 = harga_2124;
        newNode->prev = tail;
        newNode->next = nullptr;
        if (head != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    // Fungsi untuk menghapus produk dari awal daftar
    void pop_2124() {
        if (head == nullptr) {
            return;
        }
        Node *temp_2124 = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp_2124;
    }

    // Mengupdate data produk
    bool update(string namaLama_2124, string namaBaru_2124, int hargaBaru_2124) {
        Node *current_2124 = head;
        while (current_2124 != nullptr) {
            if (current_2124->nama_2124 == namaLama_2124) {
                current_2124->nama_2124 = namaBaru_2124;
                current_2124->harga_2124 = hargaBaru_2124;
                return true;
            }
            current_2124 = current_2124->next;
        }
        return false;
    }

    // Fungsi untuk menyisipkan data produk pada posisi tertentu
    void insertPosition(string nama_2124, int harga_2124, int posisi_2124) {
        Node *newNode = new Node;
        newNode->nama_2124 = nama_2124;
        newNode->harga_2124 = harga_2124;

        if (posisi_2124 == 1) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            } else {
                tail = newNode;
            }
            head = newNode;
            return;
        }

        Node *current_2124 = head;
        int count_2124 = 1;
        while (current_2124 != nullptr && count_2124 < posisi_2124 - 1){
            current_2124 = current_2124->next;
            count_2124++;
        }
        if (current_2124 == nullptr) {
            cout << "Posisi tidak ditemukan." << endl;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current_2124->next;
            newNode->prev = current_2124;
            if (current_2124->next != nullptr) {
            current_2124->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current_2124->next = newNode;
        }
    }

    // Fungsi untuk menghapus data produk pada posisi tertentu
    void deletePosition(int posisi_2124) {
        if (head == nullptr || posisi_2124 <= 0) {
            return;
        }

        Node *current_2124 = head;
        for (int i = 1; current_2124 != nullptr && i < posisi_2124; i++) {
            current_2124 = current_2124->next;
        }

        if (current_2124 == nullptr) {
            return;
        }

        if (current_2124->prev != nullptr) {
            current_2124->prev->next = current_2124->next;
        }
        else {
            head = current_2124->next;
        }

        if (current_2124->next != nullptr) {
            current_2124->next->prev = current_2124->prev;
        }
        else {
            tail = current_2124->prev;
        }

        delete current_2124;
    }

    // Fugsi untuk menghapus semua data dari daftar
    void deleteAll() {
            Node *current_2124 = head;
            while (current_2124 != nullptr) {
                Node *temp_2124 = current_2124;
                current_2124 = current_2124->next;
                delete temp_2124;
            }
            head = nullptr;
            tail = nullptr;
        }

    // Fungsi untuk menampilkan semua produk dalam daftar
    void display() {
    cout << "============================================" << endl;
    cout << "| Nama Produk        | Harga               |" << endl;
    cout << "============================================" << endl;
    Node *current_2124 = head;
    while (current_2124 != nullptr) {
        cout << "| " << setw(19) << left << current_2124->nama_2124;
        cout << "| " << setw(19) << left << current_2124->harga_2124 << " |" << endl;
        current_2124 = current_2124->next;
    }
    cout << "============================================" << endl;
    cout << endl;
    }
};

// Deklarasi variabel
int pilih_2124, harga_2124, hargaBaru_2124, posisi_2124;
string nama_2124, namaBaru_2124;

int main() {
    DoublyLinkedList_2124 list;
    while (true) {
        // Menampilkan menu
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        // Meminta inputan pilihan dari pengguna
        cout << "Masukkan pilihan anda: ";
        cin >> pilih_2124;
        switch (pilih_2124) {
        case 1:{
                // Menambah data baru
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, nama_2124);
                cout << "Masukkan harga produk: ";
                cin >> harga_2124;
                list.push_2124(nama_2124, harga_2124);
                break;
            }
            case 2: {
                // Menghapus data produk
                list.pop_2124();
                break;
            }
            case 3: {
                // Mengupdate data produk
                cout << "Masukkan nama produk yang akan diubah: ";
                cin.ignore();
                getline(cin, nama_2124);
                cout << "Masukkan nama produk baru: ";
                getline(cin, namaBaru_2124);
                cout << "Masukkan harga: ";
                cin >> hargaBaru_2124;
                bool updated = list.update(nama_2124, namaBaru_2124,hargaBaru_2124);
                if (!updated) {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                // Menambahkan data produk pada posisi tertentu
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, nama_2124);
                cout << "Masukkkan harga produk: ";
                cin >> harga_2124;
                cout << "Masukkan posisi produk: ";
                cin >> posisi_2124;
                list.insertPosition(nama_2124, harga_2124, posisi_2124);
                break;
            }
            case 5: {
                // Menghapus data produk pada posisi tertentu
                cout << "Masukkan posisi produk: ";
                cin >> posisi_2124;
                list.deletePosition(posisi_2124);
                break;
            }
            case 6: {
                // Menghapus semua data dari daftar
                list.deleteAll();
                break;
            }
            case 7: {
                // Menampilkan semua produk dalam daftar
                list.display();
                break;
            }
            case 8: {
                // Keluar dari program
                return 0;
            }
            default: {
                // Piihan yang diinputkan pengguna tidak tersedia
                cout << "Maaf, pilihan tidak tersedia!" << endl;
                break;
            }
        }
    }
    return 0;
}
