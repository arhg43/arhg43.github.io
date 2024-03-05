#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk konversi kecepatan
double konversiKecepatan(double kecepatan, int pilihan) {
    if (pilihan == 1) { // Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)
        return kecepatan * 100000 / 3600; // Kilometer/jam ke Centimeter/detik
    } else if (pilihan == 2) { // Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)
        return kecepatan * 0.036; // Centimeter/detik ke Kilometer/jam
    } else if (pilihan == 3) { // Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)
        return kecepatan * 3.6; // Meter/detik ke Kilometer/jam
    } else if (pilihan == 4) { // Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)
        return kecepatan * 1.60934; // Mil/jam ke Kilometer/jam
    } else {
        return -1; // Return -1 jika pilihan tidak valid
    }
}

// Fungsi untuk membuat akun
void buatAkun(string& nama, string& nim) {
    cout << "Buat akun baru\n";
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Akun berhasil dibuat!\n";
}

int main() {
    string nama, nim, namaInput, nimInput;
    double kecepatan;
    int menu;
    int salahLogin = 0;

    // Loop utama program
    while (salahLogin < 3) {
        cout << "\nMenu Utama:\n";
        cout << "1. Buat akun\n";
        cout << "2. Login\n";
        cout << "Pilih menu (1/2) atau ketik 0 untuk keluar: ";
        cin >> menu;

        if (menu == 0) {
            cout << "Terima kasih. Program selesai.\n";
            break; // Keluar dari loop utama
        } else if (menu == 1) {
            buatAkun(nama, nim);
        } else if (menu == 2) {
            cout << "Masukkan Nama: ";
            cin >> namaInput;
            cout << "Masukkan NIM: ";
            cin >> nimInput;

            // Cek login
            if (namaInput == nama && nimInput == nim) {
                cout << "Login berhasil!\n";

                // Loop untuk konversi kecepatan
                while (true) {
                    cout << "\nMenu Konversi Kecepatan:\n";
                    cout << "1. Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)\n";
                    cout << "2. Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
                    cout << "3. Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)\n";
                    cout << "4. Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)\n";
                    cout << "Pilih menu (1-4) atau ketik 0 untuk keluar: ";
                    cin >> menu;

                    if (menu == 0) {
                        cout << "Terima kasih. Program selesai.\n";
                        break; // Keluar dari loop konversi
                    }

                    // Input kecepatan
                    cout << "Masukkan kecepatan: ";
                    cin >> kecepatan;

                    // Panggil fungsi konversiKecepatan dan tampilkan hasil
                    double hasil = konversiKecepatan(kecepatan, menu);
                    if (hasil != -1) {
                        cout << "Hasil konversi: " << hasil << endl;
                    } else {
                        cout << "Menu tidak valid.\n";
                    }
                }

                break; // Keluar dari loop utama
            } else {
                cout << "Nama atau NIM salah.\n";
                salahLogin++;
            }
        } else {
            cout << "Menu tidak valid.\n";
        }

        if (salahLogin == 3) {
            cout << "Anda telah salah login sebanyak 3 kali. Program berhenti.\n";
            break; // Keluar dari loop utama
        }
    }

    return 0;
}
