// // #include <iostream>
// // using namespace std;
// // int main() {
// // int nilai[2][2][2] = {
// //     { {80, 85}, {75, 90} },
// //     { {88, 92}, {70, 78} }
// // };
// // cout << " = DATA NILAI MAHASISWA =\n\n";
// //     for (int k = 0; k < 2; k +) {
// //         cout << "Kelas " << char('A' + k) < endl;
// //         for (int m = 0; m < 2; m +) {
// //             cout << " Mahasiswa " << m + 1 < endl;
// //             cout << " UTS : " < nilai[k][m][0] < endl;
// //             cout << " UAS : " < nilai[k][m][1] < endl;
// //         }
// //     cout << endl;
// //     }
// // return 0;
// // }

// #include <iostream>
// using namespace std;

// struct Alamat {
//     string jalan;
//     int    nomor;
//     string kota;
// };

// struct Mahasiswa {
//     string nama;
//     int    umur;
//     string jurusan;
//     Alamat alamat;
// };

// #define MAX_MAHASISWA 100
// int panjang = 0;
// Mahasiswa mhs[MAX_MAHASISWA];

// int main() {
//     int pilihan, index;
    
//     do {
//         cout << "==============================" << endl;
//         cout << "   Menu Manajemen Mahasiswa  " << endl;
//         cout << "==============================" << endl;
//         cout << "1. Tampilkan Data Mahasiswa"  << endl;
//         cout << "2. Tambah Data Mahasiswa"     << endl;
//         cout << "3. Ubah Data Mahasiswa"       << endl;
//         cout << "4. Hapus Data Mahasiswa"      << endl;
//         cout << "5. Keluar"                    << endl;
//         cout << "Pilihan: ";
//         cin >> pilihan;
        
//         switch (pilihan) {
            
//         case 1: // READ
//             if (panjang == 0) {
//                 cout << "Belum ada data mahasiswa." << endl;
//             } else {
//                 cout << "Daftar Mahasiswa:" << endl;
//                 cout << "================================" << endl;
//                 for (int i = 0; i < panjang; i++) {
//                     cout << "Mahasiswa ke-" << i + 1 << endl;
//                     cout << "Nama    : " << mhs[i].nama    << endl;
//                     cout << "Umur    : " << mhs[i].umur    << endl;
//                     cout << "Jurusan : " << mhs[i].jurusan << endl;
//                     cout << "Alamat  : " << mhs[i].alamat.jalan
//                         << " No. " << mhs[i].alamat.nomor
//                         << ", "    << mhs[i].alamat.kota << endl;
//                     cout << "--------------------------------" << endl;
//                 }
//             }
//             break;
            
//         case 2: // CREATE
//             if (panjang < MAX_MAHASISWA) {
//                 cin.ignore();
//                 cout << "Masukkan nama     : ";
//                 getline(cin, mhs[panjang].nama);
                
//                 cout << "Masukkan umur     : ";
//                 cin >> mhs[panjang].umur;
                
//                 cin.ignore();
//                 cout << "Masukkan jurusan  : ";
//                 getline(cin, mhs[panjang].jurusan);
                
//                 cout << "--- Alamat ---" << endl;
//                 cout << "Jalan : ";
//                 getline(cin, mhs[panjang].alamat.jalan);
                
//                 cout << "Nomor : ";
//                 cin >> mhs[panjang].alamat.nomor;
                
//                 cin.ignore();
//                 cout << "Kota  : ";
//                 getline(cin, mhs[panjang].alamat.kota);
                
//                 panjang++;
//                 cout << "Data berhasil ditambahkan!" << endl;
//             } else {
//                 cout << "Kapasitas penuh!" << endl;
//             }
//             break;
            
//         case 3: // UPDATE
//             if (panjang == 0) {
//                 cout << "Belum ada mahasiswa untuk diubah." << endl;
//             } else {
//                 cout << "Daftar Mahasiswa" << endl;
//                 cout << "==================" << endl;
//                 for (int i = 0; i < panjang; i++) {
//                     cout << i + 1 << ". " << mhs[i].nama << endl;
//                 }
                
//                 cout << "Masukkan nomor mahasiswa yang akan diubah: ";
//                 cin >> index;
                
//                 if (index > 0 && index <= panjang) {
//                     cin.ignore();
//                     cout << "Masukkan nama mahasiswa baru: ";
//                     getline(cin, mhs[index - 1].nama);
                    
//                     cout << "Masukkan umur mahasiswa baru: ";
//                     cin >> mhs[index - 1].umur;
                    
//                     cin.ignore();
//                     cout << "Masukkan jurusan mahasiswa baru: ";
//                     getline(cin, mhs[index - 1].jurusan);
                    
//                     cout << "Masukkan alamat mahasiswa baru:" << endl;
//                     cout << "Jalan: ";
//                     getline(cin, mhs[index - 1].alamat.jalan);
                    
//                     cout << "Nomor: ";
//                     cin >> mhs[index - 1].alamat.nomor;
                    
//                     cin.ignore();
//                     cout << "Kota: ";
//                     getline(cin, mhs[index - 1].alamat.kota);
                    
//                     cout << "Mahasiswa berhasil diubah" << endl;
//                 } else {
//                     cout << "Nomor mahasiswa tidak valid" << endl;
//                 }
//             }
//             break;
            
//         case 4: // DELETE
//             if (panjang == 0) {
//                 cout << "Belum ada mahasiswa untuk dihapus." << endl;
//             } else {
//                 cout << "Daftar Mahasiswa" << endl;
//                 cout << "==================" << endl;
//                 for (int i = 0; i < panjang; i++) {
//                     cout << i + 1 << ". " << mhs[i].nama << endl;
//                 }
                
//                 cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
//                 cin >> index;
                
//                 if (index > 0 && index <= panjang) {
//                     for (int i = index - 1; i < panjang - 1; i++) {
//                         mhs[i] = mhs[i + 1];
//                     }
//                     panjang--;
//                     cout << "Mahasiswa berhasil dihapus" << endl;
//                 } else {
//                     cout << "Nomor mahasiswa tidak valid" << endl;
//                 }
//             }
//             break;
            
//         case 5:
//             cout << "Sampai jumpa!" << endl;
//             break;
            
//         default:
//             cout << "Pilihan tidak valid!" << endl;
//             break;
//         }
        
//     } while (pilihan != 5);
    
//     return 0;
// // }

// void buatReservasi() {
//     tampilkanKamarTersedia();

//     int pilihKamar;
//     cout << "Masukkan nomor kamar: ";
//     cin >> pilihKamar;

//     Reservasi baru;
//     cin.ignore();
//     cout << "Nama pelanggan: ";
//     getline(cin, baru.pelanggan.nama);

//     cout << "Lama menginap: ";
//     cin >> baru.lamaMenginap;

//     daftarReservasi[panjangReservasi] = baru;
//     panjangReservasi++;
// }

// Fungsi menampilkan reservasi
// void readReservasi() {
//     for (int i = 0; i < panjangReservasi; i++) {
//         cout << daftarReservasi[i].pelanggan.nama
//              << " - " << daftarReservasi[i].lamaMenginap
//              << " hari\n";
//     }
// }

void menuUtama() {
    int pilihan;
    do {
        cout << "1. Tambah Reservasi\n";
        cout << "2. Lihat Reservasi\n";
        cout << "3. Keluar\n";
        cin >> pilihan;

        switch(pilihan) {
            case 1: buatReservasi(); break;
            case 2: readReservasi(); break;
        }

    } while (pilihan != 3);
}