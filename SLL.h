#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
using namespace std;

//Gunakan deklarasi tipe data Single Linked List berikut ini :
struct pegawai {
    string nama, NIP;
    int gaji;
};

typedef pegawai infotype;

typedef struct ElmtPeg *address;

struct ElmtPeg {
    infotype info;
    address next;
};

struct List {
    address first;
};

//procedure berstabilo kuning sudah tersedia di template jawaban praktikum, Anda tinggal menggunakan
void create_list(List &L);
void insert_last(List &L, address P);
address delete_last(List &L);
address delete_first(List &L);
address delete_after(List &L, address prec);

// procedure dan fungsi berikut ini harus Anda buat implementasinyapada file implementasi
address new_element(infotype peg);
void add_N_data(List &ListPeg);
void show_all_data(List ListPeg);
address search_by_NIP(List ListPeg, string NIP);
void delete_Data(List &ListPeg, string NIP);
int jumlah_pegawai(List ListPeg);
int total_salary(List ListPeg);

//test
int main2();
#endif // SLL_H_INCLUDED
