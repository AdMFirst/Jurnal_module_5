#include "SLL.h"


int main()
{   // buat list kosong
    List daftarPeg;
    create_list(daftarPeg);

    // Buat Loop dan action-action agar dapat membuat menu tampil ke layar,
    //setiap kali user selesai mengakses menu tertentu.
    //Loop menampilkan menu akan berhenti ketika user memasukkan angka 0
    int pilihan = -1;
    string nipCari;
    while(pilihan != 0){
        // panduan membuat loop menu sederhana sudah dijelaskan pada video tutorial TP modul 5
        // tampilan menu
        // Menu
        // 1. Tambah data pegawai
        // 2. Tampilkan data pegawai
        // 3. Cari data pegawai berdasarkan NIP
        // 4. Hapus data berdasarkan NIP
        // 5. Jumlah pegawai saat ini
        // 6. Rata-Rata penghasilan pegawai
        // 7. Nama Pegawai dengan gaji tertinggi
        // 0. Selesai
        cout << "Menu" <<endl;
        cout << "1. Tambah data pegawai" <<endl;
        cout << "2. Tampilkan data pegawai" <<endl;
        cout << "3. Cari data pegawai berdasarkan NIP" <<endl;
        cout << "4. Hapus data berdasarkan NIP" <<endl;
        cout << "5. Jumlah pegawai saat ini" <<endl;
        cout << "6. Rata-Rata penghasilan pegawai" <<endl;
        cout << "7. Nama Pegawai dengan gaji tertinggi" <<endl;
        cout << "0. Selesai" <<endl;
        cout << "Pilihan anda :";
        cin >> pilihan;
        switch (pilihan){
        case 1:
            add_N_data(daftarPeg);
            break;
        case 2:
            show_all_data(daftarPeg);
            break;
        case 3:

            cout << "Masukan NIP yang dicari :";
            cin >> nipCari;
            cout << search_by_NIP(daftarPeg, nipCari) <<endl;
            break;
        case 4:

            cout << "Masukan NIP yang dihapus :";
            cin >> nipCari;
            delete_Data(daftarPeg, nipCari);
            break;
        case 5:
            cout << "Jumlah pegawai :" << jumlah_pegawai(daftarPeg) << endl;
            break;
        case 6:
            cout << "Rata-rata penghasilan pegawai :" << total_salary(daftarPeg)/jumlah_pegawai(daftarPeg) <<endl;
            break;
        case 7:
            cout << "Tidak tersedia" <<endl;
            break;
        }
    }
    //main2();
    return 0;
}
