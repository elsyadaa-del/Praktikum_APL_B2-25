#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct User {
    string username;
    string nim;
};

struct Reservasi {
    string nama, ktp, noHP;
    int noKamar, lama, totalHarga;
};

struct Kamar {
    int noKamar;
    string tipe;
    int harga;
    int tersedia; 
};

Kamar kamarList[7] = {
    {101, "Standar", 137000, 1},
    {102, "Standar", 137000, 1},
    {103, "Standar Couple", 250000, 1},
    {201, "Deluxe", 200000, 1},
    {202, "Deluxe", 200000, 1},
    {203, "Deluxe Couple", 500000, 1},
    {301, "Family", 750000, 1},
};

User akun[10];
Reservasi dataReservasi[100];
int jumlahKamar = 7; 
int jumlahReservasi = 0;
int jumlahUser = 0;

void tampilHeader() {
    cout << "\n=====================================================\n";
    cout << "                SISTEM RESERVASI HOTEL               \n";
    cout << "=====================================================\n";
}

void tampilKamar(Kamar* k, int* n) {
    cout << left << setw(6) << "No" << setw(15) << "Tipe" << setw(12) << "Harga" << setw(10) << "Status" << endl;
    for (int i = 0; i < *n; i++) {
        cout << left << setw(6) << k[i].noKamar << setw(15) << k[i].tipe << setw(12) << k[i].harga 
             << setw(10) << (k[i].tersedia == 1 ? "Tersedia" : "Terisi") << endl;
    }
}

void create(Kamar* kList, Reservasi* rList, int* nK, int* nR) {
    tampilKamar(kList, nK);
    int pilihNo;
    cout << "\nPilih Nomor Kamar: "; cin >> pilihNo;
    
    for (int i = 0; i < *nK; i++) {
        if (kList[i].noKamar == pilihNo && kList[i].tersedia == 1) {
            cin.ignore();
            cout << "Nama Tamu        : "; getline(cin, rList[*nR].nama);
            cout << "KTP Tamu         : "; getline(cin, rList[*nR].ktp);  
            cout << "No HP Tamu       : "; getline(cin, rList[*nR].noHP); 
            cout << "Lama Inap (hari) : "; cin >> rList[*nR].lama;
            
            rList[*nR].noKamar = pilihNo;
            rList[*nR].totalHarga = kList[i].harga * rList[*nR].lama;
            
            kList[i].tersedia = 0; 
            (*nR)++;
            cout << "\nReservasi Berhasil! Total: Rp " << rList[*nR-1].totalHarga << endl;
            return;
        }
    }
    cout << "Kamar tidak tersedia atau nomor salah!\n";
}

void read(Reservasi* rList, int* nR) {
    if (*nR == 0) { cout << "Belum ada data.\n"; return; }
    cout << left << setw(4) << "No" << setw(15) << "Nama" << setw(15) << "KTP" << setw(13) << "No HP" << setw(8) << "Kamar" << "Total" << endl;
    for (int i = 0; i < *nR; i++) {
        cout << left << setw(4) << i+1 
             << setw(15) << rList[i].nama 
             << setw(15) << rList[i].ktp 
             << setw(13) << rList[i].noHP 
             << setw(8) << rList[i].noKamar 
             << "Rp " << rList[i].totalHarga << endl;
    }
}

void update(Reservasi* rList, int* nR, Kamar* kList, int* nK) {
    int idx;
    read(rList, nR);
    if (*nR == 0) return;
    cout << "\nPilih nomor urut yang diubah: "; cin >> idx;
    if (idx > 0 && idx <= *nR) {
        cout << "Lama Inap Baru: "; cin >> rList[idx-1].lama;
        for(int i=0; i < *nK; i++) {
            if(kList[i].noKamar == rList[idx-1].noKamar) {
                rList[idx-1].totalHarga = kList[i].harga * rList[idx-1].lama;
            }
        }
        cout << "Data berhasil diupdate!\n";
    }
}

void hapus(Reservasi* rList, int* nR, Kamar* kList, int* nK) {
    int idx;
    read(rList, nR);
    if (*nR == 0) return;
    cout << "\nPilih nomor urut yang dihapus: "; cin >> idx;
    if (idx > 0 && idx <= *nR) {
        for(int i=0; i < *nK; i++) {
            if(kamarList[i].noKamar == rList[idx-1].noKamar) kamarList[i].tersedia = 1;
        }
        for (int i = idx - 1; i < *nR - 1; i++) {
            rList[i] = rList[i + 1];
        }
        (*nR)--;
        cout << "Data dihapus!\n";
    }
}

void sortingMenu(Kamar* k, int n) { 
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (k[j].tipe > k[m].tipe) m = j;
        }
        Kamar t = k[i]; k[i] = k[m]; k[m] = t;
    }
}

void registrasi() {
    if (jumlahUser < 10) {
        cout << "\n--- DAFTAR AKUN ---" << endl;
        cout << "Masukkan Username: "; cin >> akun[jumlahUser].username;
        cout << "Masukkan Password (NIM): "; cin >> akun[jumlahUser].nim;
        jumlahUser++;
        cout << "Registrasi Berhasil!\n";
    }
}

int linearSearchNama(Reservasi* rList, int nR, string cari) {
    for (int i = 0; i < nR; i++) {
        if (rList[i].nama == cari) {
            return i;
        }
    }
    return -1;
}

int binarySearchKamar(Kamar* kList, int nK, int cari) {
    int low = 0, high = nK - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (kList[mid].noKamar == cari) return mid;
        else if (kList[mid].noKamar < cari) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void cariNama(Reservasi* rList, int* nR) {
    cin.ignore();
    string nama;
    cout << "Masukkan nama yang dicari: ";
    getline(cin, nama);

    int hasil = linearSearchNama(rList, *nR, nama);

    if (hasil != -1) {
        cout << "Data ditemukan:\n";
        cout << "Nama       : " << rList[hasil].nama << endl;
        cout << "Kamar      : " << rList[hasil].noKamar << endl;
        cout << "Lama Inap  : " << rList[hasil].lama << " hari" << endl;
        cout << "Total      : Rp " << rList[hasil].totalHarga << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

void cariKamar(Kamar* kList, int* nK) {
    int no;
    cout << "Masukkan nomor kamar: ";
    cin >> no;

    for (int i = 0; i < *nK - 1; i++) {
        for (int j = i + 1; j < *nK; j++) {
            if (kList[i].noKamar > kList[j].noKamar) {
                Kamar t = kList[i];
                kList[i] = kList[j];
                kList[j] = t;
            }
        }
    }

    int hasil = binarySearchKamar(kList, *nK, no);

    if (hasil != -1) {
        cout << "Kamar ditemukan:\n";
        cout << kList[hasil].noKamar << " | " << kList[hasil].tipe 
             << " | Rp " << kList[hasil].harga << endl;
    } else {
        cout << "Kamar tidak ditemukan.\n";
    }
}


int login() {
    if (jumlahUser == 0) {
        cout << "Belum ada akun. Register dulu ya!\n";
        return 0;
    }
    string u, p;
    cout << "\n--- LOGIN ---" << endl;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    for (int i = 0; i < jumlahUser; i++) {
        if (akun[i].username == u && akun[i].nim == p) return 1;
    }
    return 0;
}

int main() {
    int pilihAwal;
    int statusLogin = 0;

    while (statusLogin == 0) {
        cout << "\n=====================================================\n";
        cout << "                   MENU REGISTRASI                  \n";
        cout << "=====================================================\n";
        cout << "\n1. Login\n2. Register\n3. Keluar\nPilih: "; cin >> pilihAwal;
        if (pilihAwal == 1) {
            if (login() == 1) statusLogin = 1; 
            else cout << "Login Gagal!\n";
        } 
        else if (pilihAwal == 2) registrasi();
        else return 0;
    }
    
    int pilih;
    do {
        tampilHeader();
        cout << "1. Tambah Reservasi\n2. Lihat Reservasi\n3. Update Reservasi\n4. Hapus Reservasi\n5. Lihat Kamar\n6. Cari Nama Tamu\n7. Cari Nomor Kamar\n8. Keluar\n";
        cout << "Pilih: "; cin >> pilih;

        switch (pilih) {
            case 1: create(kamarList, dataReservasi, &jumlahKamar, &jumlahReservasi); break;
            case 2: read(dataReservasi, &jumlahReservasi); break;
            case 3: update(dataReservasi, &jumlahReservasi, kamarList, &jumlahKamar); break;
            case 4: hapus(dataReservasi, &jumlahReservasi, kamarList, &jumlahKamar); break;
            case 5: 
                sortingMenu(kamarList, jumlahKamar);
                tampilKamar(kamarList, &jumlahKamar); 
                break;
            case 6: cariNama(dataReservasi, &jumlahReservasi); break;
            case 7: cariKamar(kamarList, &jumlahKamar); break;
        }
    } while (pilih != 8);
    return 0;
}