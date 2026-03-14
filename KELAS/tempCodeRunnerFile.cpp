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