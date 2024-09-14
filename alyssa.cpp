#include <iostream>  // Library untuk input-output
#include <iomanip>   // Library untuk manipulasi output
#include <fstream>   // Library untuk menulis ke file
using namespace std;

int main() {
    // Deklarasi variabel
    float berat_buah, harga_per_kg, pemasukan_kotor, biaya_operasional, pemasukan_bersih, bonus;
    
    // Input
    cout << "Masukkkan berat buah yang berhasil dijual (kg): ";
    cin >> berat_buah;
    cout << "Masukkan harga per kg buah: ";
    cin >> harga_per_kg;
    cout << "Masukkan biaya operasional: ";
    cin >> biaya_operasional;

    // Proses
    pemasukan_kotor = berat_buah * harga_per_kg;
    pemasukan_bersih = pemasukan_kotor - biaya_operasional;

    // Kondisional untuk menghitung bonus
    if (pemasukan_bersih < 100000) {
        bonus = 0;
    } else if (pemasukan_bersih >= 100000 && pemasukan_bersih < 200000) {
        bonus = 0.05 * pemasukan_bersih;
    } else if (pemasukan_bersih >= 200000 && pemasukan_bersih < 300000) {
        bonus = 0.10 * pemasukan_bersih;
    } else {
        bonus = 0.20 * pemasukan_bersih;
    }

    // Output
    cout << fixed << setprecision(2);
    cout << "Pemasukan Kotor: Rp " << pemasukan_kotor << endl;
    cout << "Pemasukan Bersih: Rp " << pemasukan_bersih << endl;
    cout << "Bonus: Rp " << bonus << endl;

    // Menyimpan hasil ke file
    ofstream outfile("hasil_bonus.txt");
    if (outfile.is_open()) {
        outfile << "Berat buah yang dijual: " << berat_buah << " kg\n";
        outfile << "Harga per kg: Rp " << harga_per_kg << "\n";
        outfile << "Pemasukan Kotor: Rp " << pemasukan_kotor << "\n";
        outfile << "Biaya Operasional: Rp " << biaya_operasional << "\n";
        outfile << "Pemasukan Bersih: Rp " << pemasukan_bersih << "\n";
        outfile << "Bonus: Rp " << bonus << "\n";
        outfile.close();
        cout << "Hasil telah disimpan di file 'hasil_bonus.txt'.\n";
    } else {
        cout << "Gagal membuka file untuk menyimpan hasil.\n";
    }

    return 0;
}
