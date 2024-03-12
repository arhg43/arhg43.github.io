#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Akun {
    string nama;
    string nim;
    string peran; 
};

struct Produk {
    string nama;
    double harga;
};

vector<Akun> daftar_akun;
vector<Produk> daftar_produk;

// Fungsi untuk menampilkan menu utama
void tampilkanMenuUtama() {
    cout << "\nMenu Utama:" << endl;
    cout << "1. Tambah akun" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
}

// Fungsi untuk menampilkan menu pelanggan
void tampilkanMenuPelanggan() {
    cout << "\nMenu Pelanggan:" << endl;
    cout << "1. Lihat produk" << endl;
    cout << "2. Pesan produk" << endl;
    cout << "3. Keluar" << endl;
}

// Fungsi untuk menampilkan menu admin
void tampilkanMenuAdmin() {
    cout << "\nMenu Admin:" << endl;
    cout << "1. Tambah produk" << endl;
    cout << "2. Lihat produk" << endl;
    cout << "3. Ubah produk" << endl;
    cout << "4. Hapus produk" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk menambahkan akun
void tambahAkun() {
    Akun akun;
    cout << "Masukkan Nama: ";
    cin >> akun.nama;
    cout << "Masukkan NIM: ";
    cin >> akun.nim;
    akun.peran = "pelanggan"; 
    daftar_akun.push_back(akun);
    cout << "Akun berhasil ditambahkan." << endl;
}

// Fungsi untuk login
string login() {
    string input_nama, input_nim;
    cout << "Masukkan Nama: ";
    cin >> input_nama;
    cout << "Masukkan NIM: ";
    cin >> input_nim;
    for (int i = 0; i < daftar_akun.size(); ++i) {
        if (daftar_akun[i].nama == input_nama && daftar_akun[i].nim == input_nim) {
            cout << "Login berhasil!" << endl;
            return daftar_akun[i].peran; 
        }
    }
    cout << "Nama atau Nim salah. Coba lagi." << endl;
    return ""; // Jika login gagal, mengembalikan string kosong
}

// Fungsi untuk menambahkan produk (hanya untuk admin)
void tambahProduk() {
    Produk produk;
    cout << "Masukkan nama produk: ";
    cin >> produk.nama;
    cout << "Masukkan harga produk: ";
    cin >> produk.harga;
    daftar_produk.push_back(produk);
    cout << "Produk berhasil ditambahkan." << endl;
}

// Fungsi untuk melihat produk
void lihatProduk() {
    cout << "\nDaftar Produk:" << endl;
    if (daftar_produk.empty()) {
        cout << "Belum ada produk." << endl;
    } else {
        for (int i = 0; i < daftar_produk.size(); ++i) {
            cout << i + 1 << ". " << daftar_produk[i].nama << " - Rp " << daftar_produk[i].harga << endl;
        }
    }
}


void pesanProduk() {
    lihatProduk();
    if (daftar_produk.empty()) {
        return;
    }
    int idx_produk;
    cout << "Masukkan nomor produk yang ingin dipesan: ";
    cin >> idx_produk;
    --idx_produk; 
    if (idx_produk >= 0 && idx_produk < daftar_produk.size()) {
        int jumlah;
        cout << "Masukkan jumlah barang yang ingin dipesan: ";
        cin >> jumlah;
        double total_harga = daftar_produk[idx_produk].harga * jumlah;
        cout << "Total harga pesanan: Rp " << total_harga << endl;
        cout << "Pesanan berhasil!" << endl;
    } else {
        cout << "Nomor produk tidak valid." << endl;
    }
}

int main() {

    Akun admin;
    admin.nama = "ari";
    admin.nim = "2309106085";
    admin.peran = "admin";
    daftar_akun.push_back(admin);

    while (true) {
        tampilkanMenuUtama();
        int pilihan;
        cout << "Pilih menu (1/2/3): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahAkun();
                break;
            case 2: {
                string peran = login(); 
                if (peran == "admin") {
                    while (true) {
                        tampilkanMenuAdmin();
                        int pilihanAdmin;
                        cout << "Pilih menu (1/2/3/4/5): ";
                        cin >> pilihanAdmin;
                        switch (pilihanAdmin) {
                            case 1:
                                tambahProduk();
                                break;
                            case 2:
                                lihatProduk();
                                break;
                            case 3:
                                cout << "Menu Ubah produk" << endl;
                                break;
                            case 4:
                                cout << "Menu Hapus produk" << endl;
                                break;
                            case 5:
                                cout << "Keluar dari menu admin." << endl;
                                break;
                            default:
                                cout << "Menu tidak valid. Silakan pilih kembali." << endl;
                        }
                        if (pilihanAdmin == 5) {
                            break;
                        }
                    }
                } else if (peran == "pelanggan") {
                    while (true) {
                        tampilkanMenuPelanggan();
                        int pilihanPelanggan;
                        cout << "Pilih menu (1/2/3): ";
                        cin >> pilihanPelanggan;
                        switch (pilihanPelanggan) {
                            case 1:
                                lihatProduk();
                                break;
                            case 2:
                                pesanProduk();
                                break;
                            case 3:
                                cout << "Keluar dari menu pelanggan." << endl;
                                break;
                            default:
                                cout << "Menu tidak valid. Silakan pilih kembali." << endl;
                        }
                        if (pilihanPelanggan == 3) {
                            break;
                        }
                    }
                } else {
                    cout << "Nama atau Nim salah. Coba lagi." << endl;
                }
                break;
            }
            case 3:
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Menu tidak valid. Silakan pilih kembali." << endl;
        }
    }
    return 0;
}
