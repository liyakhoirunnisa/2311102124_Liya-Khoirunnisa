# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Liya Khoirunnisa-2311102124</p>

## Dasar Teori

Tipe data merupakan sebuah jenis nilai yang ditampung dalam variabel yang nilainya sudah ditentukan sebelumnya. Tipe data ini wajib ada ketika ingin membuat sebuah program agar memiliki nilai yang jelas dan spesifik.

1. Tipe data primitif<br/>
Tipe data primitif adalah tipe data yang sudah dibuat oleh sistem dan tidak diturunkan dari tipe data lain. Tipe data ini mencangkup :
    •	Int  adalah tipe data untuk menyimpan bilangan bulat dengan bit
    •	Float adalah tipe data untuk menyimpan bilangan desimal dengan bit
    •	Char adalah tipe data untuk menyimpan huruf atau karakter dengan bit 
    •	Boolean adalah tipe data untuk menyimpan nilai True/False
2. Tipe data Abstrak<br/>
Tipe data abstrak adalah kelas/tipe untuk objek yang perilakunya ditentukan oleh satu set nilai dan satu set operasi. Tipe data ini dibentuk oleh programmer sendiri untuk memudahkan pemrograman dan memberikan fleksbilitas. Contohnya untuk menyederhanakan proses pemecahan masalah kita menggabungkan struktur data dengan operasinya.
3. Tipe data koleksi<br/>
Tipe data koleksi adalah jenis tipe data yang digunakan untuk menghimpun kumpulan data atau data yang berjumlah lebih dari satu.


## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
#include <iomanip>

using namespace std;

//Tipe data primitif Liya

int main() {
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op) {
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    case '-':
        cout << "Result: " << num1 - num2;
        break;
    case '*':
        cout << "Result: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
        } else {
        cout << "Error! Division by zero is not allowed.";
        }
        break;
    default:
        cout << "Error! Operator is not correct";
    }
    return 0;
}
```
Kode di atas adalah sebuah program kalkulator sederhana yang memungkinkan pengguna untuk memilih operasi aritmatika dan pengguna diminta untuk memasukkan operator yang diinginkan dan diminta untuk memasukkan 2 bilangan untuk dihitung. Pada program di atas, terdapat dua tipe data primitif, yaitu char dan float. Tipe data char digunakan untuk menyimpan operator yang dimasukkan pengguna. Tipe data float digunakan untuk menyimpan 2 bilangan yang dimasukkan pengguna.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
#include <string.h>

//Struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};

//Tipe data abstrak Liya

int main() {
    //Menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    //Mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;

    //Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);

    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari dari struct mahasiswa. Terdapat sebuah struct mahasiswa yang terdiri dari array name bertipe data char dengan ukuran 50, array address bertipe data char dengan ukuran 100, dan variabel age bertipe data int. Di dalam fungsi main, inisialisasi dan deklarasi objek mhs1 dan mhs2 pada struct mahasiswa dengan nilai tertentu. Kemudian nilai dicetak ke layar. Pada program di atas, terdapat tipe data abstrak yaitu struct.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;

// Tipe data koleksi Liya

int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    
    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari array. Terdapat library <array> yang memudahkan pengelolaan array. Terdapat array yang menampung 5 nilai yang sudah diinisialisai, yaitu nilai 23, 50, 34, 78, 90 . Kemudian cetak isi array ke layar dengan memanggil setiap indeks array. Pada program di atas, terdapat tipe data koleksi yaitu array.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Istiqomah, N. (2023). TRANSFORMASI DIGITAL. Penerbit Tahta Media.
[2] Santoso, J. T. (2021). STRUKTUR DATA dan ALGORITMA (Bagian 1). Penerbit Yayasan Prima Agus Teknik, 1-333.
[3] Zein, A., & Eriana, E. S. (2022). ALGORITMA DAN STRUKTUR DATA.

