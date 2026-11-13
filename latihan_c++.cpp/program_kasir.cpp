#include <iostream>
using namespace std;

int main() {
    // Variabel laporan toko
    int jumlah_transaksi = 0;
    double total_pendapatan = 0;
    double transaksi_terbesar = 0;
    int menu;
    int nomor_pembeli = 1;

    //loop menu utama toko
    while (true) {
        cout << "========== TOKO MAJU ==========" << endl;
        cout << "1. Kasir" << endl;
        cout << "0. Selesai Belanja" << endl;
        cout << endl;
        cout << "Pilih Menu: ";
        cin >> menu;

        if (menu == 0) {
            break;
        }

        if (menu == 1) {
            char pembeli_berikutnya = 'y';

            while (pembeli_berikutnya == 'y' || pembeli_berikutnya == 'Y') {
                cout << endl;
                cout << "========== PEMBELI " << nomor_pembeli << " ==========" << endl;
                
                cout << "Member? (y/n) : ";
                char member;
                cin >> member;

                int total_sementara = 0;
                int kode_barang;

                // LOOP INPUT BARANG BELANJAAN
                while (true) {
                    cout << endl;
                    cout << "Pilih kode barang : ";
                    cin >> kode_barang;

                    if (kode_barang == 0) {
                        break;
                    }

                    int harga_satuan = 0;

                    if (kode_barang == 1) {
                        harga_satuan = 15000;
                    }
                    else if (kode_barang == 3) {
                        harga_satuan = 20000;
                    }
                    else if (kode_barang == 4) {
                        harga_satuan = 3500;
                    }
                    else {
                        cout << "Kode barang tidak tersedia" << endl;
                        continue;
                    }

                    cout << "Jumlah : ";
                    int jumlah;
                    cin >> jumlah;

                    if (jumlah <= 0) {
                        cout << "Jumlah harus lebih dari 0!" << endl;
                        continue;
                    }

                    int subtotal = harga_satuan * jumlah;
                    total_sementara = total_sementara + subtotal;

                    cout << "Subtotal : Rp" << subtotal << endl;
                    cout << "Total sementara : Rp" << total_sementara << endl;
                }

                // ========== PROSES PEMBAYARAN ==========
                cout << endl;
                cout << "========== PEMBAYARAN ==========" << endl;

                int total_awal = total_sementara;
                cout << "Total awal : Rp" << total_awal << endl;

                int diskon_belanja = 0;
                if (total_awal >= 100000) {
                    diskon_belanja = total_awal * 5 / 100;
                }
                cout << "Diskon Belanja (5%) : Rp" << diskon_belanja << endl;

                int setelah_diskon = total_awal - diskon_belanja;
                cout << "Setelah diskon : Rp" << setelah_diskon << endl;

                int diskon_member = 0;
                cout << "Diskon Member : Rp" << diskon_member << endl;

                int total_bayar = setelah_diskon - diskon_member;
                cout << "Total bayar : Rp" << total_bayar << endl;
                cout << endl;

                int uang_bayar;
                cout << "Uang pembayaran : > ";
                cin >> uang_bayar;

                while (uang_bayar < total_bayar) {
                    cout << "Uang tidak cukup!" << endl;
                    cout << "Uang pembayaran : > ";
                    cin >> uang_bayar;
                }

                int kembalian = uang_bayar - total_bayar;
                cout << "Kembalian : Rp" << kembalian << endl;
                cout << "Transaksi berhasil!" << endl;
                cout << endl;

                jumlah_transaksi = jumlah_transaksi + 1;
                total_pendapatan = total_pendapatan + total_bayar;

                if (total_bayar > transaksi_terbesar) {
                    transaksi_terbesar = total_bayar;
                }

                cout << "Ada pembeli berikutnya? (y/n) : ";
                cin >> pembeli_berikutnya;

                if (pembeli_berikutnya == 'y' || pembeli_berikutnya == 'Y') {
                    nomor_pembeli = nomor_pembeli + 1;
                }
            }
        }
        else {
            cout << "Pilihan salah! Masukkan angka 1 atau 0" << endl;
            cout << endl;
        }
    }

    // ========== LAPORAN TOKO ==========
    cout << endl;
    cout << "========== LAPORAN TOKO ==========" << endl;
    cout << "Jumlah transaksi berhasil : " << jumlah_transaksi << endl;
    cout << "Total pendapatan : Rp" << total_pendapatan << endl;
    cout << "Transaksi terbesar : Rp" << transaksi_terbesar << endl;
    cout << "Toko ditutup." << endl;

    return 0;
}
