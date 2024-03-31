/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <iomanip>

using namespace std;
// Program single linked list non-circular untuk menampilkan nama mahasiswa dan NIM

// Deklarasi Struct Node
struct Node
{
    string nama_2124;
    string nim_2124;
    Node *next;
};
Node *head;
Node *tail;

// Inisialisasi Node
void init_2124()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty_2124()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void insertDepan_2124(string nama_2124, string nim_2124)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama_2124 = nama_2124;
    baru->nim_2124 = nim_2124;
    baru->next = NULL;
    if (isEmpty_2124() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang_2124(string nama_2124, string nim_2124)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama_2124 = nama_2124;
    baru->nim_2124 = nim_2124;
    baru->next = NULL;
    if (isEmpty_2124() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList_2124()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah_2124(string nama_2124, string nim_2124, int posisiNama_2124)
{
    if (posisiNama_2124 < 1 || posisiNama_2124 > hitungList_2124())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisiNama_2124 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->nama_2124 = nama_2124;
        baru->nim_2124 = nim_2124;

        // traversal
        bantu = head;
        int nomor = 1;
        while (nomor < posisiNama_2124 - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus depan
void hapusDepan_2124()
{
    Node *hapus;
    if (isEmpty_2124() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang_2124()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty_2124() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah_2124(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList_2124()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                sebelum = bantu;
            } 
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

/// Ubah Depan
void ubahDepan_2124(string nama_2124, string nim_2124)
{
    if (isEmpty_2124() == false)
    {
        head->nama_2124 = nama_2124;
        head->nim_2124 = nim_2124;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah_2124(string nama_2124, string nim_2124, int posisiNama_2124)
{
    Node *bantu;
    if (isEmpty_2124() == 0)
    {
        if (posisiNama_2124 < 1 || posisiNama_2124 > hitungList_2124())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisiNama_2124 == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor_2124 = 1;
            while (nomor_2124 < posisiNama_2124)
            {
                bantu = bantu->next;
                nomor_2124++;
            }
            bantu->nama_2124 = nama_2124;
            bantu->nim_2124 = nim_2124;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang_2124(string nama_2124, string nim_2124)
{
    if (isEmpty_2124() == 0)
    {
        tail->nama_2124 = nama_2124;
        tail->nim_2124 = nim_2124;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void clearList_2124() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Menampilkan seluruh data linked list
void tampil_2124()
{
    Node *bantu;
    bantu = head;
    if (isEmpty_2124() == false)
    {
        cout << "============================================\n";
        cout << "|              DATA MAHASISWA              |\n";
        cout << "============================================\n";
        cout << "| NAMA               | NIM                 |\n";
        cout << "============================================\n";
        while (bantu != NULL)
        {
            cout << "| " << setw(19) << left << bantu->nama_2124;
            cout << "| " << setw(19) << left << bantu->nim_2124 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "============================================\n";
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Deklarasi variabel
int pilih_2124, posisiNama_2124;
string nama_2124, nim_2124;

int main()
{
    init_2124();
    do
    {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. TAMPILKAN\n";
        cout << "0. KELUAR\n";
        cout << "Pilih Operasi: ";
        cin >> pilih_2124;
        cout << endl;
        switch (pilih_2124)
        {
        case 1:
            cout << "/////////////////// Tambah Depan //////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan Nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            insertDepan_2124(nama_2124, nim_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah ditambahkan\n";
            cout << "===================================================\n";
            break;
        case 2:
            cout << "///////////////// Tambah Belakang /////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan Nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            insertBelakang_2124(nama_2124, nim_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah ditambahkan\n";
            cout << "===================================================\n";
            break;
        case 3:
            cout << "////////////////// Tambah Tengah ///////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan Nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            int posisiNama_2124;
            cout << "Masukkan Posisi: ";
            cin >> posisiNama_2124;
            insertTengah_2124(nama_2124, nim_2124, posisiNama_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah ditambahkan pada posisi ke-" << posisiNama_2124 << endl;
            cout << "===================================================\n";
            break;
        case 4:
            cout << "//////////////////// Ubah Depan ///////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan Nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            ubahDepan_2124(nama_2124, nim_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah diubah\n";
            cout << "===================================================\n";
            break;
        case 5:
            cout << "////////////////// Ubah Belakang //////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            ubahBelakang_2124(nama_2124, nim_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah diubah\n";
            cout << "===================================================\n";
            break;
        case 6:
            cout << "/////////////////// Ubah Tengah ///////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan Nama: ";
            cin >> nama_2124;
            cout << "Masukkan NIM: ";
            cin >> nim_2124;
            cout << "Masukkan Posisi: ";
            cin >> posisiNama_2124;
            ubahTengah_2124(nama_2124, nim_2124, posisiNama_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data telah diubah\n";
            cout << "===================================================\n";
            break;
        case 7:
            cout << "/////////////////// Hapus Depan ///////////////////\n";
            cout << "===================================================\n";
            hapusDepan_2124();
            cout << "---------------------------------------------------\n";
            cout << "Data berhasil dihapus\n";
            cout << "===================================================\n";
            break;
        case 8:
            cout << "////////////////// Hapus Belakang /////////////////\n";
            cout << "===================================================\n";
            hapusBelakang_2124();
            cout << "---------------------------------------------------\n";
            cout << "Data berhasil dihapus\n";
            cout << "===================================================\n";
            break;
        case 9:
            cout << "/////////////////// Hapus Tengah //////////////////\n";
            cout << "===================================================\n";
            cout << "Masukkan posisi: ";
            cin >> posisiNama_2124;
            hapusTengah_2124(posisiNama_2124);
            cout << "---------------------------------------------------\n";
            cout << "Data berhasil dihapus\n";
            cout << "===================================================\n";
            break;
        case 10:
            clearList_2124();
            break;
        case 11:
            tampil_2124();
            break;
        case 0:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Maaf, pilihan tidak tersedia!\n";
        }
    } while (pilih_2124 != 0);

    return 0;
}
