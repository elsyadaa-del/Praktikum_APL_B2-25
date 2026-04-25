#include <iostream>
#include <string>
using namespace std;

struct Pelanggan {
    string nama;
    string ktp;
    string noHp;
};

struct Kamar {
    int nomor;
    string tipe;
    bool tersedia;
    int hargaPerMalam; 
};

struct Reservasi {
    Pelanggan pelanggan;
    int idKamar;
    int lamaMenginap;
};

struct User {
    string username;
    string password;
};

#define MAX_KAMAR 10
#define MAX_RESERVASI 100
#define MAX_USER 10

// Data global
Kamar daftarKamar[MAX_KAMAR] = {
    {101, "Standard",  true, 500000},
    {102, "Standard",  true, 500000},
    {103, "Standard",  true, 500000},
    {104, "Deluxe",    true, 800000},
    {105, "Deluxe",    true, 800000},
    {106, "Deluxe",    true, 800000},
    {107, "Suite",     true, 1200000},
    {108, "Suite",     true, 1200000},
    {109, "Suite",     true, 1200000},
    {110, "President", true, 2500000}
};

Reservasi daftarReservasi[MAX_RESERVASI];
int panjangReservasi = 0;

User daftarUser[MAX_USER];
int panjangUser = 0;

// hitung harga
int hitungTotalHarga(int idxKamar, int lama) {
    return daftarKamar[idxKamar].hargaPerMalam * lama;
}

// login 
void registerUser() {
    if (panjangUser >= MAX_USER) {
        cout << "Maaf, kapasitas user penuh!\n";
        return;
    }
    User baru;
    cout << "\n--- REGISTER ---\n";
    cout << "Username: ";
    cin >> baru.username;

    for (int i = 0; i < panjangUser; i++) {
        if (daftarUser[i].username == baru.username) {
            cout << "Username sudah terdaftar!\n";
            return;
        }
    }

    cout << "Password: ";
    cin >> baru.password;
    daftarUser[panjangUser] = baru;
    panjangUser++;
    cout << "Registrasi berhasil! Silakan login.\n";
}

bool login() {
    string username, password;
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "\n--- LOGIN ---\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int i = 0; i < panjangUser; i++) {
            if (daftarUser[i].username == username && daftarUser[i].password == password) {
                cout << "Login berhasil! Selamat datang, " << username << ".\n";
                return true;
            }
        }
        percobaan++;
        cout << "Login gagal! Kesempatan tersisa: " << 3 - percobaan << "\n";
    }
    cout << "Anda telah gagal login 3 kali.\n";
    return false;
}

void tampilkanKamarTersedia() {
    cout << "\n--- KAMAR TERSEDIA ---\n";
    cout << "No. Kamar\tTipe\n";
    cout << "-------------------------\n";
    for (int i = 0; i < MAX_KAMAR; i++) {
        if (daftarKamar[i].tersedia) {
            cout << daftarKamar[i].nomor << "\t\t" << daftarKamar[i].tipe << endl;
        }
    }
}

void buatReservasi() {
    if (panjangReservasi >= MAX_RESERVASI) {
        cout << "Kapasitas reservasi penuh!\n";
        return;
    }

    tampilkanKamarTersedia();
    int pilihKamar;
    cout << "Masukkan nomor kamar yang ingin dipesan: ";
    cin >> pilihKamar;

    int idxKamar = -1;
    for (int i = 0; i < MAX_KAMAR; i++) {
        if (daftarKamar[i].nomor == pilihKamar && daftarKamar[i].tersedia) {
            idxKamar = i;
            break;
        }
    }
    if (idxKamar == -1) {
        cout << "Kamar tidak tersedia atau nomor salah!\n";
        return;
    }

    cout << "\nHarga per malam untuk kamar " << daftarKamar[idxKamar].tipe 
         << " (No. " << daftarKamar[idxKamar].nomor << ") : Rp " 
         << daftarKamar[idxKamar].hargaPerMalam << endl;

    Reservasi baru;
    cin.ignore();
    cout << "Masukkan nama pelanggan: ";
    getline(cin, baru.pelanggan.nama);
    cout << "Masukkan KTP: ";
    getline(cin, baru.pelanggan.ktp);
    cout << "Masukkan No HP: ";
    getline(cin, baru.pelanggan.noHp);
    cout << "Lama menginap (hari): ";
    cin >> baru.lamaMenginap;

    int totalHarga = hitungTotalHarga(idxKamar, baru.lamaMenginap);

    baru.idKamar = idxKamar;
    daftarKamar[idxKamar].tersedia = false;
    daftarReservasi[panjangReservasi] = baru;
    panjangReservasi++;

    cout << "\nReservasi berhasil ditambahkan!\n";
    cout << "====================================\n";
    cout << "TOTAL HARGA (" << baru.lamaMenginap << " hari) : Rp " << totalHarga << endl;
    cout << "====================================\n";
}

void readReservasi() {
    if (panjangReservasi == 0) {
        cout << "Belum ada reservasi.\n";
        return;
    }
    cout << "\n--- DAFTAR RESERVASI ---\n";
    cout << "No\tNama Pelanggan\t\tKTP\t\tNo HP\t\tKamar\tTipe\tLama (hari)\n";
    cout << "------------------------------------------------------------------------------------\n";
    
    for (int i = 0; i < panjangReservasi; i++) {
        Reservasi r = daftarReservasi[i];
        Kamar k = daftarKamar[r.idKamar];
        cout << i+1 << "\t" 
            << r.pelanggan.nama << "\t\t" 
            << r.pelanggan.ktp << "\t" 
            << r.pelanggan.noHp << "\t" 
            << k.nomor << "\t" 
            << k.tipe << "\t" 
            << r.lamaMenginap << endl;
    }
}

void cariReservasi() {
    if (panjangReservasi == 0) { cout << "Belum ada reservasi.\n"; return; }
    cin.ignore();
    string cari;
    cout << "Masukkan nama pelanggan yang dicari: ";
    getline(cin, cari);
    cout << "\nHasil pencarian:\n";
    bool ditemukan = false;
    for (int i = 0; i < panjangReservasi; i++) {
        if (daftarReservasi[i].pelanggan.nama == cari) {
            ditemukan = true;
            Reservasi r = daftarReservasi[i];
            Kamar k = daftarKamar[r.idKamar];
            cout << "No. " << i+1 
                 << " | Nama: " << r.pelanggan.nama
                 << " | KTP: " << r.pelanggan.ktp
                 << " | Kamar: " << k.nomor << " (" << k.tipe << ")"
                 << " | Lama: " << r.lamaMenginap << " hari\n";
        }
    }
    if (!ditemukan) cout << "Tidak ada reservasi dengan nama tersebut.\n";
}

void updateReservasi() {
    if (panjangReservasi == 0) { cout << "Belum ada reservasi.\n"; return; }
    readReservasi();
    int idx;
    cout << "Masukkan nomor reservasi yang akan diubah: ";
    cin >> idx;
    if (idx < 1 || idx > panjangReservasi) { cout << "Nomor tidak valid.\n"; return; }
    idx--;
    cin.ignore();
    cout << "Masukkan nama baru: ";
    getline(cin, daftarReservasi[idx].pelanggan.nama);
    cout << "Masukkan lama menginap baru: ";
    cin >> daftarReservasi[idx].lamaMenginap;
    cout << "Data berhasil diupdate.\n";
}

void deleteReservasi() {
    if (panjangReservasi == 0) { cout << "Belum ada reservasi.\n"; return; }
    readReservasi();
    int idx;
    cout << "Masukkan nomor reservasi yang akan dihapus: ";
    cin >> idx;
    if (idx < 1 || idx > panjangReservasi) { cout << "Nomor tidak valid.\n"; return; }
    idx--;

    int idKamar = daftarReservasi[idx].idKamar;
    daftarKamar[idKamar].tersedia = true;

    for (int i = idx; i < panjangReservasi - 1; i++) {
        daftarReservasi[i] = daftarReservasi[i + 1];
    }
    panjangReservasi--;
    cout << "Reservasi berhasil dihapus.\n";
}

void menuUtama() {
    int pilihan;
    do {
        cout << "\n==========   FAIRMONT HOTEL  ==========\n";
        cout << "1. Tambah Reservasi\n";
        cout << "2. Lihat Semua Reservasi\n";
        cout << "3. Lihat Kamar Tersedia\n";
        cout << "4. Cari Reservasi\n";
        cout << "5. Ubah Reservasi\n";
        cout << "6. Hapus Reservasi\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: buatReservasi(); break;
            case 2: readReservasi(); break;
            case 3: tampilkanKamarTersedia(); break;
            case 4: cariReservasi(); break;
            case 5: updateReservasi(); break;
            case 6: deleteReservasi(); break;
            case 7: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);
}

int main() {
    daftarUser[0].username = "admin";
    daftarUser[0].password = "070";
    panjangUser = 1;

    int opsi;
    do {
        cout << "\n=====    FAIRMONT HOTEL  =====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> opsi;

        switch (opsi) {
            case 1: if (login()) menuUtama(); break;
            case 2: registerUser(); break;
            case 3: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (opsi != 3);

    return 0;
}