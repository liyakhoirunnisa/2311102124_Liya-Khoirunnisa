# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Liya Khoirunnisa - 2311102124</p>

## Dasar Teori

Hash Table adalah sebuah array dengan  sel - sel  yang  ukuranya  telah  di tentukan  dan dapat  berisi  data  atau key yang  memiliki  kesamaan dengan  data. Hashing Function (fx), digunakan untuk mengubah suatu identifier X menjadi suatu alamat yang ada dalam hash table. Hash table dibayangkan sebagai matriks yang setiap barisnya mewakili identifier dari f(x). Huruf pertama dari identifier X diambil, lalu baris dibagi menjadi beberapa slot atau kolom dimana masing-masing kolom berisi 1 record. <br/>
Hashing adalah  teknik  yang digunakan untuk  melakukan  penambahan data,  penghapusan data,  dan  pencaraian  data dengan teknik melacak alamat key yang diperoleh dari aturan fungsi tertentu. Hashing digunakan untuk menyimpan kumpulan data yang cukup besar pada ADT (Abstract Data Type) yang di sebut tabel Hash. Ukuran tabel Hash biasanya lebih besar dari data yang akan di simpan. Key dalam tabel hashing dapat ditentukan lalu memanggil key tersebut untuk melakukan pencarian dan penghapusan data.<br/>
Fungsi Hashing memetakan elemen pada indeks dari tabel Hash. Untuk menambahkan data  atau melakukan pencarian ditentukan key dari data  tersebut dan digunakan sebuah fungsi hashing untuk menetapkan lokasi key tersebut. Untuk memetakan setiap key,  fungsi hashing dapat diterapkan pada angka dalam rentang 0 hingga Hash-Size-1. Salah satu fungsi hasing yang bisa digunakan adalah Modular Aritmatic dengan cara melakukan konversi data menjadi bilangan bulat, membagi dengan ukuran Hash Table dan mengambil hasil sisa bagi sebagai indeks/alamat key. Sebuah fungsi hashing yang  baik  memiliki  dua  kriteria,  yakni  efisisen dan meminimalisir terjadinya collision. Collisoin adalah jika dua buah key atau lebih di petakan pada sel data yang sama. Ada dua strategi umum untuk meminimalisir terjadinya collision yakni Close Hashing (Opening Addres) dan Open Hashing (Chaining). 

## Guided 

### 1. Program Hash Table

```C++
#include <iostream>
using namespace std;
/// PROGRAM HASH TABLE Liya Khoirunnisa

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node **table;

public:
    HashTable() {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node *current = table[i];
            while (current != nullptr) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node *current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    return 0;
}
```
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array.

### 2. Program Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/// PROGRAM HASH TABLE Liya Khoirunnisa

// Ukuran hash table
const int TABLE_SIZE = 11;

// Deklarasi variabel global
string name;
string phone_number;

// Class untuk merepresentasikan node pada hash tabel
class HashNode {
public:
    string name;
    string phone_number;

    // Inisialisasi Name dan Phone Number
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class untuk merepresentasikan hash map
class HashMap {
private:
    // Array vektor untuk menyimpan node hash
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Menghitung nilai hash dari key Name
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Tambah data ke dalam hashmap
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    
    // Penghapusan data dari hash map
    void remove(string name){
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Pencarian Phone Number berdasarkan Name
    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    // Pencetakan isi hash map
    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    
    // Memasukkan data ke dalam hashmap
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencetak Phone Number berdasarkan Name
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    
    // Menghapus data Name "Mistah"
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl<< endl;
    
    // Mencetak isi hashmap
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Pada program di atas, class HashNode merepresentasikan setiap node dalam hash table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan.

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.

```C++
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
```
#### Output:
![unguided1(1)](unguided1(1).png)
![unguided1(2)](unguided1(2).png)
![unguided1(3)](unguided1(3).png)
![unguided1(4)](unguided1(4).png)

Kode di atas untuk menampilkan data mahasiswa berdasarkan NIM dan nilai dengan menggunakan hash table. NIM dan nilai direpresentasikan oleh sebuah node hash table. Program di atas menggunakan struktur hash map dengan menggunakan vektor yang menampung pointer ke node hash. Fungsi hashFunc_2124 digunakan untuk menghitung nilai hash dari NIM. Fungsi tambah_2124 digunakan untuk menambahkan data baru ke hash table. Fungsi hapus_2124 digunakan untuk menghapus data. Fungsi cariNim_2124 untuk mencari nilai berdasarkan NIM. Fungsi cariRentangNilai_2124 digunakan untuk mencari nilai berdasarkan rentang nilai yang dimasukkan.


## Kesimpulan
Dari hasil praktikum dan pembelajaran yang didapat, dapat disimpulkan bahwa Hash Table adalah sebuah array dengan  sel - sel  yang  ukurannya  telah  di tentukan  dan dapat  berisi  data  atau key yang  memiliki  kesamaan dengan  data. Praktikum ini memberikan pemahaman yang mendalam tentang konsep hash table dan penerapannya. Penggunaan fungsi hash memungkinkan kita menemukan lokasi data yang disimpan dalam hash table dengan cepat. Hal ini dapat mempermudah dalam melakukan penambahan, penghapusan, dan pencarian data dalam waktu yang cepat. 

## Referensi
[1] Soetanto, H. (2022). Struktur Data Dasar-Dasar Pemrograman. Jakarta: Universitas Budi Luhur<br/>
[2] Syahrir, M., & Fatimatuzzahra, F. (2020). Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer, 20(1), 149-158.