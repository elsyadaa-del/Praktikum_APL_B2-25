#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Reservasi {
    string nama;
    string ktp;
    int kamar;
    int lama;
};

int hitungTotal(int harga, int lama) {
    return harga * lama;
}

int hitungTotal(int harga, int lama, int pajak) {
    return (harga * lama) + pajak;
}

int hitungTotalRekursif(int harga, int lama) {
    if (lama == 0)
        return 0;
    return harga + hitungTotalRekursif(harga, lama - 1);
}

void tambah(Reservasi data[], int &jumlah) {

    if (jumlah >= MAX) {
        cout << "Data penuh\n";
        return;
    }

    cout << "Nama: ";
    getline(cin >> ws, data[jumlah].nama);

    cout << "KTP: ";
    getline(cin >> ws, data[jumlah].ktp);

    cout << "Nomor kamar: ";
    cin >> data[jumlah].kamar;

    cout << "Lama menginap: ";
    cin >> data[jumlah].lama;

    int harga = 500000;

    int total = hitungTotalRekursif(harga, data[jumlah].lama);

    cout << "Total harga: " << total << endl;

    jumlah++;
}

void tampil(Reservasi data[], int jumlah) {

    if (jumlah == 0) {
        cout << "Belum ada data\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {

        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama  : " << data[i].nama << endl;
        cout << "KTP   : " << data[i].ktp << endl;
        cout << "Kamar : " << data[i].kamar << endl;
        cout << "Lama  : " << data[i].lama << " hari\n";
    }
}

void update(Reservasi data[], int jumlah) {

    tampil(data, jumlah);

    int pilih;
    cout << "\nPilih data yang diubah: ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlah) {
        cout << "Data tidak ada\n";
        return;
    }

    cout << "Nama baru: ";
    getline(cin >> ws, data[pilih - 1].nama);

    cout << "Lama menginap baru: ";
    cin >> data[pilih - 1].lama;

    cout << "Data berhasil diupdate\n";
}

void hapus(Reservasi data[], int &jumlah) {

    tampil(data, jumlah);

    int pilih;
    cout << "\nPilih data yang dihapus: ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlah) {
        cout << "Data tidak ada\n";
        return;
    }

    for (int i = pilih - 1; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;

    cout << "Data berhasil dihapus\n";
}

void menu(Reservasi data[], int &jumlah) {

    int pilih;

    do {

        cout << "\n===== MENU RESERVASI HOTEL =====\n";
        cout << "1. Tambah Reservasi\n";
        cout << "2. Lihat Reservasi\n";
        cout << "3. Update Reservasi\n";
        cout << "4. Hapus Reservasi\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!\n";
            continue;
        }

        switch (pilih) {

            case 1:
                tambah(data, jumlah);
                break;

            case 2:
                tampil(data, jumlah);
                break;

            case 3:
                update(data, jumlah);
                break;

            case 4:
                hapus(data, jumlah);
                break;

            case 5:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak valid\n";
        }

    } while (pilih != 5);
}

int main() {

    Reservasi data[MAX];
    int jumlah = 0;

    menu(data, jumlah);

    return 0;
}