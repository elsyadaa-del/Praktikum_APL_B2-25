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