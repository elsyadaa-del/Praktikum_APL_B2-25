#ifndef HOTEL_LIB_H
#define HOTEL_LIB_H

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <cctype>

using namespace std;

// --- Struct ---
struct DataTamu {
    string ktp, noHP;
};

struct User {
    string username, nim;
};

struct Reservasi {
    string nama;
    DataTamu data;
    int noKamar, lama, totalHarga;
};

struct Kamar {
    int noKamar;
    string tipe;
    int harga;
    int tersedia; 
};

// Variabel Global
extern Kamar kamarList[7];
extern User akun[10];
extern Reservasi dataReservasi[100];
extern int jumlahKamar;
extern int jumlahReservasi;
extern int jumlahUser;

// Prototipe Fungsi
void cekInputPositif(int nilai);
void tampilKamar(Kamar* k, int* n);
void tampilKamar(Kamar* k, int n, string filterTipe);
void create(Kamar* kList, Reservasi* rList, int* nK, int* nR);
void read(Reservasi* rList, int* nR);
void update(Reservasi* rList, int* nR, Kamar* kList, int* nK);
void hapus(Reservasi* rList, int* nR, Kamar* kList, int* nK);
void sortingMenu(Kamar* k, int n);
void sortKamarByNumber(Kamar* k, int n);
void insertionSortHarga(Kamar* k, int n);
void registrasi();
int login();
int binarySearchRekursif(Kamar* k, int low, int high, int cari);
void cariNama(Reservasi* rList, int* nR);
void cariKamar(Kamar* kList, int* nK);
void tampilHeader();

#endif