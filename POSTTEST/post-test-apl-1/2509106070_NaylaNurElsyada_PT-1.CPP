#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nama, password;
    string passBenar = "070";
    int kesempatan = 0;

    cout << "=====================================\n";
    cout << "        PROGRAM KONVERSI PANJANG\n";
    cout << "=====================================\n\n";

    while (kesempatan < 3) {
        cout << "Silakan login terlebih dahulu\n";
        cout << "Nama     : ";
        getline(cin, nama);
        cout << "Password : ";
        cin >> password;

        if (password == passBenar) {
            cout << "\nLogin berhasil! Halo " << nama << endl;
            break;
        } else {
            kesempatan++;
            cout << "Password salah! Sisa kesempatan: "
                << 3 - kesempatan << "\n\n";
            cin.ignore();
        }
    }

    if (kesempatan == 3) {
        cout << "Anda salah 3 kali. Program selesai.\n";
        return 0;
    }

    int pilih;
    double nilai;

    do {
        cout << "\n=========== MENU UTAMA ===========\n";
        cout << "1. Meter ke Kilometer dan Centimeter\n";
        cout << "2. Kilometer ke Meter dan Centimeter\n";
        cout << "3. Centimeter ke Meter dan Kilometer\n";
        cout << "4. Keluar\n";
        cout << "===================================\n";
        cout << "Pilih (1-4): ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "\nMasukkan nilai dalam meter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:\n";
                cout << "Kilometer  = " << nilai / 1000 << " km\n";
                cout << "Centimeter = " << nilai * 100 << " cm\n";
                break;

            case 2:
                cout << "\nMasukkan nilai dalam kilometer: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:\n";
                cout << "Meter      = " << nilai * 1000 << " m\n";
                cout << "Centimeter = " << nilai * 100000 << " cm\n";
                break;

            case 3:
                cout << "\nMasukkan nilai dalam centimeter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:\n";
                cout << "Meter      = " << nilai / 100 << " m\n";
                cout << "Kilometer  = " << nilai / 100000 << " km\n";
                break;

            case 4:
                cout << "\nTerima kasih sudah menggunakan program ini.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia. Coba lagi.\n";
        }

    } while (pilih != 4);

    return 0;
}