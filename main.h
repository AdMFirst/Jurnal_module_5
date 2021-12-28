#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "SLL.h"
int main2(){

    List daftar;
    create_list(daftar);

    add_N_data(daftar);
    show_all_data(daftar);
    string nip;
    cout << "nip :";
    cin >> nip
    delete_Data(daftar, nip);
    show_all_data(daftar);

    int banyakPeg = jumlah_pegawai(daftar);
    int banyakGaji = total_salary(daftar);
    cout << "jumlah karyawan :" << banyakPeg <<endl;
    cout << "jumlah gaji karyawan :" << banyakGaji <<endl;
    return 0;
}

#endif // MAIN_H_INCLUDED
