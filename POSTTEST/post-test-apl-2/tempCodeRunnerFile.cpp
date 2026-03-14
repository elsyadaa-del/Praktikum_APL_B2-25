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