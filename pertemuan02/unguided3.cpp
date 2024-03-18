/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>

using namespace std;

// Deklarasi variabel global
int pilihan_2124, lokasi_2124;

// Fungsi untuk menampilkan menu
void tampilanMenu_2124() {
    cout << "\nMenu:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Hitung nilai rata-rata\n";
    cout << "4. Keluar\n";
    cout << "Masukkan pilihan (1-4): ";
    cin >> pilihan_2124;
}

// Fungsi untuk mencari nilai maksimum dalam array
void cariMaksimum_2124 (int array_2124[], int size_2124) {
    int maksimum_2124 = array_2124[0]; // Inisialisasi maksimum dengan nilai pertama dalam array
    for (int i = 0; i < size_2124; i++) {
        if (array_2124[i] > maksimum_2124) { // Memeriksa apakah nilai saat ini lebih besar dari maksimum
            maksimum_2124 = array_2124[i]; // Jika iya, perbarui nilai maksimum
            lokasi_2124 = i; // Simpan lokasi indeks nilai maksimum
        }
    }
    cout << "Nilai maksimum adalah " << maksimum_2124 << " berada di array ke " << lokasi_2124 << endl; // Menampilkan nilai maksimum dan indeks
}

// Fungsi untuk mencari nilai minimum dalam array
void cariMinimum_2124 (int array_2124[], int size_2124) {
    int minimum_2124 = array_2124[0]; // Inisialisasi minimum dengan nilai pertama dalam array
    for (int i = 0; i < size_2124; i++) { 
        if (array_2124[i] < minimum_2124) { // Memeriksa apakah nilai saat ini lebih kecil dari minimum
            minimum_2124 = array_2124[i]; // Jika iya, perbarui nilai minimum
            lokasi_2124 = i; // Simpan lokasi indeks nilai maksimum
        }
    }
    cout << "Nilai minimum adalah " << minimum_2124 << " berada di array ke " << lokasi_2124 << endl; // Menampilkan nilai minimum dan indeks
}

// Fungsi untuk menghitung rata rata nilai dalam array
void hitungRataRata_2124 (int array_2124[], int size_2124) {
    double total_2124 = 0; // Inisialisasi total dengan 0
    for (int i = 0; i < size_2124; i++) {
        total_2124 += array_2124[i]; // Tambahkan nilai saat ini menjadi total
    }
    double rata_2124 = total_2124/size_2124; // Menghitung rata-rata
    cout << "Nilai rata-rata adalah " << rata_2124 << endl; // Menampilkan nilai rata-rata
}

int main() {
    // Deklarasi variabel size
    int size_2124;
    
    // Meminta pengguna untuk memasukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> size_2124;

    // Deklarasi array dengan ukuran yang dimasukkan oleh pengguna
    int array_2124 [size_2124];

    // Meminta pengguna untuk memasukkan nilai array
    cout << "Masukkan " << size_2124 << " angka\n";
    for(int i = 0; i < size_2124; i++){
        cout << "Array ke-" << (i) << ": ";
        cin >> array_2124[i];
    }

    // Perulangan program utama
    do {
        tampilanMenu_2124(); // Memanggil fungsi untuk menampilkan menu
        
        // Switch case untuk menentukan tindakan yang dipilih pengguna pada menu 
        switch (pilihan_2124) {
            case 1:
                cariMaksimum_2124(array_2124, size_2124); // Memanggil fungsi untuk mencari nilai maksimum
                break;
            case 2: 
                cariMinimum_2124(array_2124, size_2124); // Memanggil fungsi untuk mencari nilai minimum
                break;
            case 3:
                hitungRataRata_2124(array_2124, size_2124); // Memanggil fungsi untuk menghitung rata-rata nilai
                break;
            case 4:
                cout << "Keluar dari program.\n"; // Keluar dari program
                break;
            default:
                cout << "Maaf, Pilihan Tidak Tersedia!\n"; // Pesan kesalahan jika pilihan yang dipilih tidak tersedia
        }
    } while (pilihan_2124 != 4); // Berhenti melakukan perulangan jika pengguna memilih 4

    return 0;
}