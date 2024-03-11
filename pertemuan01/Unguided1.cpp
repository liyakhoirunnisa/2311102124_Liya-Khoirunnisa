/*oleh Liya Khoirunnisa - 2311102124*/
#include <iostream>
#include <cmath> // Library untuk mengakses fungsi M_PI dan pow()

using namespace std;

int pilihan_2124; // Tipe data primitif int untuk menyimpan pilihan menu pilihan_2124

// Fungsi untuk menampilkan menu pilihan bangun datar yang akan dihitung
void tampilanMenu_2124() {
    cout << "Bentuk Bangun Datar\n";
    cout << "1. Segitiga\n";
    cout << "2. Persegi\n";
    cout << "3. Persegi Panjang\n";
    cout << "4. Lingkaran\n";
    cout << "5. Trapesium\n";
    cout << "Masukkan pilihan (1-5): ";
    cin >> pilihan_2124;
}

// Fungsi untuk menghitung luas segitiga
float hitungLuasSegitiga_2124(float alas_2124, float tinggi_2124){
    return 0.5 * alas_2124 * tinggi_2124; // Mengembalikan nilai luas segitiga
}

// Fungsi untuk menghitung persegi
float hitungLuasPersegi_2124(float sisi_2124){
    return sisi_2124 * sisi_2124; // mengembalikan nilai luas persegi
}

// Fungsi untuk menghitung luas persegi panjang
float hitungLuasPersegiPanjang_2124(float panjang_2124, float lebar_2124){
    return panjang_2124 * lebar_2124; // Mengembalikan nilai luas persegi panjang 
}

// Fungsi untuk menghitung lingkaran
float hitungLuasLingkaran_2124(float jariJari_2124){
    return M_PI * pow(jariJari_2124, 2); // Mengembalikan nilai luas lingkaran
}

// Fungsi untuk menghitung luas luas trapesium
float hitungLuasTrapesium_2124(float tinggi_2124, float alas1_2124, float alas2_2124){
    return 0.5 * tinggi_2124 * (alas1_2124 + alas2_2124); // Mengembalikan nilai luas trapesium
}

int main() {
    float alas_2124, alas1_2124, alas2_2124, tinggi_2124, jariJari_2124, panjang_2124, lebar_2124, sisi_2124; // Tipe data primitif float untuk variabel yang diperlukan
        tampilanMenu_2124(); // Memanggil fungsi untuk menampilkan menu bangun datar
        
        // Switch case untuk menentukan tindakan yang dipilih pengguna pada menu bangun datar
    switch (pilihan_2124){
        case 1 : 
            cout << "Masukkan alas: ";
            cin >> alas_2124;
            cout << "Masukkan tinggi: ";
            cin >> tinggi_2124;            
            cout << "Luas Segitiga adalah: " << hitungLuasSegitiga_2124(alas_2124, tinggi_2124); // Menampilkan hasil luas segitiga
            cout << endl;
            break;
        case 2 :
            cout << "Masukkan sisi: ";
            cin >> sisi_2124;
            cout << "Luas Persegi adalah: " << hitungLuasPersegi_2124(sisi_2124) << endl; // Menampilkan hasil luas persegi
            break;
        case 3 :
            cout << "Masukkan panjang: ";
            cin >> panjang_2124;
            cout << "Masukkan lebar: ";
            cin >> lebar_2124;
            cout << "Luas Persegi Panjang adalah: " << hitungLuasPersegiPanjang_2124(panjang_2124, lebar_2124) << endl; // Menampilkan hasil luas persegi panjang
            break;
        case 4 :
            cout << "Masukkan jari-jari: ";
            cin >> jariJari_2124;
            cout << "Luas Lingkaran adalah: " << hitungLuasLingkaran_2124(jariJari_2124) << endl; // Menampilkan hasil luas lingkaran
            break;
        case 5 :
            cout << "Masukkan tinggi: ";
            cin >> tinggi_2124;
            cout << "Masukkan alas 1: ";
            cin >> alas1_2124;
            cout << "Masukkan alas 2: ";
            cin >> alas2_2124;
            cout << "Luas Trapesium adalah: " << hitungLuasTrapesium_2124(tinggi_2124, alas1_2124, alas2_2124) << endl; // Menampilkan hasil luas trapesium
            break;
        default :
            cout << "Maaf, pilihan tidak tersedia!\n"; // Menampilkan pesan jika pilihan tidak tersedia
    }
        
    return 0;    
}