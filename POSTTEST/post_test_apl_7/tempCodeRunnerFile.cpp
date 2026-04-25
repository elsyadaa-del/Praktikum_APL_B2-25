#include "hotel_lib.h"


Kamar kamarList[7] = {
    {101, "Standar", 137000, 1}, {102, "Standar", 137000, 1},
    {103, "Standar Couple", 250000, 1}, {201, "Deluxe", 200000, 1},
    {202, "Deluxe", 200000, 1}, {203, "Deluxe Couple", 500000, 1},
    {301, "Family", 750000, 1}
};
User akun[10];
Reservasi dataReservasi[100];
int jumlahKamar = 7; 
int jumlahReservasi = 0;
int jumlahUser = 0;

void cekInputPositif(int nilai) {
    if (nilai < 0) throw invalid_argument("Input tidak boleh negatif!");
}

void tampilHeader() {
    cout << "\n=====================================================\n";
    cout << "                SISTEM RESERVASI HOTEL               \n";
    cout << "=====================================================\n";
}
void tampilKamar(Kamar* k, int* n) {
    cout << "\n==========================================================" << endl;
    cout << "                    DAFTAR KAMAR HOTEL                    " << endl;
    cout << "==========================================================" << endl;
    cout << left << setw(12) << "No Kamar" << setw(20) << "Tipe Kamar" << setw(12) << "Harga" << setw(10) << "Status" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < *n; i++) {
        cout << left << setw(12) << k[i].noKamar << setw(20) << k[i].tipe << "Rp " << setw(9) << k[i].harga << setw(10) << (k[i].tersedia == 1 ? "[Tersedia]" : "[Terisi]") << endl;
    }
    cout << "==========================================================" << endl;
}

void tampilKamar(Kamar* k, int n, string filterTipe) {
    string filterLower = filterTipe;
    transform(filterLower.begin(), filterLower.end(), filterLower.begin(), ::tolower);

    cout << "\n--- FILTER: " << filterTipe << " ---" << endl;
    
    bool ditemukan = false;
    for(int i = 0; i < n; i++) {
        string tipeKamar = k[i].tipe;
        transform(tipeKamar.begin(), tipeKamar.end(), tipeKamar.begin(), ::tolower);

        if(tipeKamar == filterLower) {
            cout << "No: " << k[i].noKamar << " | Harga: Rp " << k[i].harga << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "[!] Tipe kamar '" << filterTipe << "' tidak ditemukan." << endl;
    }
}
void create(Kamar* kList, Reservasi* rList, int* nK, int* nR) {
    tampilKamar(kList, nK); 
    int pilihNo;
    cout << "\nMasukkan Nomor Kamar yang ingin dipesan: "; cin >> pilihNo;
    bool ditemukan = false;
    for (int i = 0; i < *nK; i++) {
        if (kList[i].noKamar == pilihNo && kList[i].tersedia == 1) {
            ditemukan = true;
            try {
                cin.ignore(1000, '\n'); 
                cout << "\n--- ISI DATA TAMU ---" << endl;
                cout << "Nama Tamu        : "; getline(cin, rList[*nR].nama);
                cout << "KTP Tamu         : "; getline(cin, rList[*nR].data.ktp);
                cout << "No HP Tamu       : "; getline(cin, rList[*nR].data.noHP);
                cout << "Lama Inap (hari) : "; cin >> rList[*nR].lama;
                cekInputPositif(rList[*nR].lama);
                
                rList[*nR].noKamar = pilihNo;
                rList[*nR].totalHarga = kList[i].harga * rList[*nR].lama;
                cout << "\n==========================================" << endl;
                cout << "             NOTA RESERVASI               " << endl;
                cout << "==========================================" << endl;
                cout << " Nama Tamu    : " << rList[*nR].nama << endl;
                cout << " No. Kamar    : " << rList[*nR].noKamar << endl;
                cout << " Lama Inap    : " << rList[*nR].lama << " hari" << endl;
                cout << " Total Biaya  : Rp " << rList[*nR].totalHarga << endl;
                cout << "==========================================" << endl;
                cout << " Terima kasih telah memesan!" << endl;

                kList[i].tersedia = 0;
                (*nR)++; 
                
                cout << "\n[BERHASIL] Reservasi Kamar " << pilihNo << " telah diproses." << endl;
            } catch (const invalid_argument& e) { cout << "\n[ERROR] Input tidak valid: " << e.what() << endl; }
            return; 
        }
    }
    if (!ditemukan) cout << "\n[GAGAL] Kamar tidak ditemukan atau sudah terisi!" << endl;
}
void read(Reservasi* rList, int* nR) {
    if (*nR == 0) { cout << "Belum ada data.\n"; return; }
    cout << left << setw(4) << "No" << setw(15) << "Nama" << setw(15) << "KTP" << setw(13) << "No HP" << setw(8) << "Kamar" << "Total" << endl;
    for (int i = 0; i < *nR; i++) {
        cout << left << setw(4) << i+1 << setw(15) << rList[i].nama << setw(15) << rList[i].data.ktp << setw(13) << rList[i].data.noHP << setw(8) << rList[i].noKamar << "Rp " << rList[i].totalHarga << endl;
    }
}

void update(Reservasi* rList, int* nR, Kamar* kList, int* nK) {
    int idx; read(rList, nR);
    if (*nR == 0) return;
    cout << "\nPilih nomor urut yang diubah: "; cin >> idx;
    if (idx > 0 && idx <= *nR) {
        try {
            cout << "Lama Inap Baru: "; cin >> rList[idx-1].lama;
            cekInputPositif(rList[idx-1].lama); 
            for(int i=0; i < *nK; i++) {
                if(kList[i].noKamar == rList[idx-1].noKamar) rList[idx-1].totalHarga = kList[i].harga * rList[idx-1].lama;
            }
            cout << "Data berhasil diupdate!\n";
        } catch(const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
    }
}

void hapus(Reservasi* rList, int* nR, Kamar* kList, int* nK) {
    int idx; read(rList, nR);
    if (*nR == 0) return;
    cout << "\nPilih nomor urut yang dihapus: "; cin >> idx;
    if (idx > 0 && idx <= *nR) {
        for(int i=0; i < *nK; i++) { if(kamarList[i].noKamar == rList[idx-1].noKamar) kamarList[i].tersedia = 1; }
        for (int i = idx - 1; i < *nR - 1; i++) rList[i] = rList[i + 1];
        (*nR)--;
        cout << "Data dihapus!\n";
    }
}

void sortingMenu(Kamar* k, int n) { 
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) { if (k[j].tipe > k[m].tipe) m = j; }
        Kamar t = k[i]; k[i] = k[m]; k[m] = t;
    }
}

void sortKamarByNumber(Kamar* k, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (k[j].noKamar > k[j + 1].noKamar) { Kamar temp = k[j]; k[j] = k[j + 1]; k[j + 1] = temp; }
        }
    }
}
void insertionSortHarga(Kamar* k, int n) {
    for (int i = 1; i < n; i++) {
        Kamar key = k[i];
        int j = i - 1;
        while (j >= 0 && k[j].harga > key.harga) { k[j + 1] = k[j]; j--; }
        k[j + 1] = key;
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

int binarySearchRekursif(Kamar* k, int low, int high, int cari) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (k[mid].noKamar == cari) return mid;
    return (k[mid].noKamar > cari) ? binarySearchRekursif(k, low, mid - 1, cari) : binarySearchRekursif(k, mid + 1, high, cari);
}
void cariNama(Reservasi* rList, int* nR) {
    cin.ignore(); 
    string nama;
    cout << "\n--- PENCARIAN DATA TAMU ---" << endl;
    cout << "Masukkan nama lengkap yang dicari: "; 
    getline(cin, nama);

    cout << "\n[Sistem sedang memproses pencarian...]" << endl;

    bool ditemukan = false;
    int index = -1;

    for(int i = 0; i < *nR; i++) {
        if(rList[i].nama == nama) {
            ditemukan = true;
            index = i;
            break; 
        }
    }

    if (ditemukan) {
        cout << "\n==========================================" << endl;
        cout << "         DATA TAMU DITEMUKAN              " << endl;
        cout << "==========================================" << endl;
        cout << " Nama Tamu    : " << rList[index].nama << endl;
        cout << " KTP          : " << rList[index].data.ktp << endl;
        cout << " No. HP       : " << rList[index].data.noHP << endl;
        cout << " No. Kamar    : " << rList[index].noKamar << endl;
        cout << " Total Biaya  : Rp " << rList[index].totalHarga << endl;
        cout << "==========================================" << endl;
    } else {
        cout << "\n[!] Maaf, nama '" << nama << "' tidak ditemukan dalam database." << endl;
        cout << "[i] Silakan cek kembali penulisan nama." << endl;
    }
}
void cariKamar(Kamar* kList, int* nK) {
    int no; 
    cout << "\n--- PENCARIAN KAMAR ---" << endl;
    cout << "Masukkan nomor kamar yang dicari: "; 
    cin >> no;
    
    cout << "\n[Sistem sedang mencari data di database...]" << endl;

    sortKamarByNumber(kList, *nK); 
    int hasil = binarySearchRekursif(kList, 0, *nK - 1, no);

    if (hasil != -1) {
        cout << "\n==========================================" << endl;
        cout << "         DETAIL INFORMASI KAMAR           " << endl;
        cout << "==========================================" << endl;
        cout << " Nomor Kamar : " << kList[hasil].noKamar << endl;
        cout << " Tipe Kamar  : " << kList[hasil].tipe << endl;
        cout << " Harga/Malam : Rp " << kList[hasil].harga << endl;
        cout << " Status      : " << (kList[hasil].tersedia == 1 ? "Tersedia" : "Terisi") << endl;
        cout << "==========================================" << endl;
    } else {
        cout << "\n[!] Maaf, nomor kamar '" << no << "' tidak terdaftar." << endl;
        cout << "[i] Silakan cek kembali daftar kamar pada menu utama." << endl;
    }
}

int login() {
    if (jumlahUser == 0) { cout << "Belum ada akun. Register dulu!\n"; return 0; }
    string u, p; cout << "\n--- LOGIN ---" << endl;
    cout << "Username: "; cin >> u; cout << "Password: "; cin >> p;
    for (int i = 0; i < jumlahUser; i++) if (akun[i].username == u && akun[i].nim == p) return 1;
    return 0;
}

int main() {
    int pilihAwal, statusLogin = 0, percobaan = 0; 
    bool programJalan = true;
    while (programJalan) {
        statusLogin = 0;
        while (statusLogin == 0) {
            cout << "\n=====================================================" << endl;
            cout << "              SELAMAT DATANG DI HOTEL                " << endl;
            cout << "=====================================================" << endl;
            cout << " Status Percobaan Login : [" << percobaan + 1 << "/3]" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << " [1] Login ke Sistem" << endl;
            cout << " [2] Registrasi Akun Baru" << endl;
            cout << " [3] Keluar dari Aplikasi" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << " Pilih Opsi (1-3) : "; 
            cin >> pilihAwal;

            if (pilihAwal == 1) { 
                if (login() == 1) {
                    statusLogin = 1; 
                } else { 
                    percobaan++; 
                    cout << "\n[!] Gagal! Username/Password salah." << endl;
                    if (percobaan >= 3) { 
                        cout << "[!] Akun terkunci karena salah 3x. Program berhenti." << endl;
                        return 0; 
                    }
                }
            } else if (pilihAwal == 2) {
                registrasi(); 
            } else if (pilihAwal == 3) {
                programJalan = false;
                cout << "\nTerima kasih, sampai jumpa!" << endl;
                break; 
            } else {
                cout << "\n[!] Pilihan tidak valid, silakan coba lagi." << endl;
            }
        }

            while (statusLogin == 1) {
                int pilih;
                tampilHeader();
                cout << "[1] Reservasi Kamar Baru" << endl;
                cout << "[2] Lihat Daftar Reservasi" << endl;
                cout << "[3] Ubah Detail Reservasi" << endl;
                cout << "[4] Batalkan Reservasi (Check-out)"<< endl;
                cout << "[5] Kelola & Urutkan Daftar Kamar" << endl;
                cout << "[6] Cari Data Tamu" << endl;
                cout << "[7] Cek Ketersediaan (Cari ID)" << endl;
                cout << "[8] Filter Kamar (by Tipe)" << endl;
                cout << "[9] Keluar (Logout)" << endl;
                cout << "------------------------------" << endl;
                cout << "Pilih Layanan (1-9): "; cin >> pilih;

                switch (pilih) {
                    case 1: create(kamarList, dataReservasi, &jumlahKamar, &jumlahReservasi); break;
                    case 2: read(dataReservasi, &jumlahReservasi); break;
                    case 3: update(dataReservasi, &jumlahReservasi, kamarList, &jumlahKamar); break;
                    case 4: hapus(dataReservasi, &jumlahReservasi, kamarList, &jumlahKamar); break;
                    case 5: { 
                        int s; 
                        cout << "\n--- PILIH METODE PENGURUTAN DAFTAR KAMAR ---" << endl;
                        cout << "[1] Urutkan berdasarkan Tipe Kamar" << endl;
                        cout << "[2] Urutkan berdasarkan Nomor Kamar" << endl;
                        cout << "[3] Urutkan berdasarkan Harga Kamar" << endl;
                        cout << "Pilihan Anda (1-3): "; cin >> s;

                        if(s == 1) {
                            sortingMenu(kamarList, jumlahKamar);
                        } else if(s == 2) {
                            sortKamarByNumber(kamarList, jumlahKamar);
                        } else if(s == 3) {
                            insertionSortHarga(kamarList, jumlahKamar);
                        } else {
                            cout << "[!] Pilihan tidak valid. Menggunakan urutan default." << endl;
                        }

                        cout << "\n[INFO] Data berhasil diurutkan:" << endl;
                        tampilKamar(kamarList, &jumlahKamar);
                        break;
                    }
                    case 6: cariNama(dataReservasi, &jumlahReservasi); break;
                    case 7: cariKamar(kamarList, &jumlahKamar); break;
                    case 8: { 
                        string t; cin.ignore(); cout << "Masukkan tipe kamar: "; getline(cin, t);
                        tampilKamar(kamarList, jumlahKamar, t);
                        break;
                    }
                    case 9: statusLogin = 0; cout << "\n[INFO] Anda telah Logout." << endl; break;
                    default: cout << "[!] Pilihan tidak tersedia." << endl;
                }
            }
        }
    return 0;
}