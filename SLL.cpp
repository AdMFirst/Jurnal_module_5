#include "SLL.h"

void create_list(List &L){
    /*membuat sebuah list baru*/
    L.first = NULL;
};
void insert_last(List &L, address P){
    /*memasukan element ke belakang list*/
    address Q = L.first;

    if(Q != NULL){
        while(Q->next != NULL) {
            Q = Q->next;
        }

        Q->next = P;
        P->next = NULL;
    } else {
        L.first = P;
        P->next = NULL;
    }
};
address delete_last(List &L){
    /*
    { IS. Terdefinisi sebuah list L (L tidak kosong dan berisi lebih dari satu elemen).
    FS. P berisi alamat elmList yang terakhir, elmList yang ditunjuk oleh P dihapus dari list }
    */

    address p, q;
    if(L.first == NULL) {
        p = NULL;
        cout << "List Kosong" << endl;
    } else if(L.first->next == NULL){
        p = L.first;
        L.first = NULL;

    } else {
        q = L.first;
        p = L.first;
        while(p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
    }
    return p;
};
address delete_first(List &L){
    /*
    IS. Terdefinisi sebuah list L (L tidak kosong dan mungkin berisi satu elemen).
    FS. P berisi alamat elmList yang pertama, elmList yang ditunjuk oleh P dihapus dari
    list
    */
    address P;

    P = L.first;
    if((L.first)->next == NULL){
        L.first = NULL;
    } else {
        L.first = (L.first)->next;
    };
    P->next = NULL;

    return P;
};
address delete_after(List &L, address prec){

    address p;
    p = prec->next;
    prec->next = p->next;
    return p;
};

// procedure dan fungsi berikut ini harus Anda buat implementasinyapada file implementasi
address new_element(infotype peg){
    /*
    {I.S. Terdefinisi data record pegawai yang akan dimasukkan menjadi element
     F.S. data record pegawai sudah tersimpan menjadi elemen dengan alamat di simpanoleh pointer p}
    */

    address p = new ElmtPeg;
    p->info = peg;
    p->next = NULL;
    return p;
};
void add_N_data(List &ListPeg){
    /*
    {I.S. Terdefinisi list yang mungkin kosong
     F.S. List akan terisi data pegawai sebanyak N. Data pegawai dan jumlah N didapatkan dari user}
    */
    //Kamus Data
    int N;
    infotype peg;
    address adr;
    //Algoritma
    //meminta N
    cout << "jumlah data yang ingin di input :";
    cin >> N;
    // loop sebanyak N untuk meminta angka dari user
    for(int i = 0; i < N; i++){
        cout << "Masukan Nama :";
        cin >> peg.nama;
        cout << "Masukan NIP :";
        cin >> peg.NIP;
        cout << "Masukan Gaji :";
        cin >> peg.gaji;

        //memanggil function alokasi data dari user menjadi elemen
        adr = new_element(peg);
        //memanggil insert last
        insert_last(ListPeg, adr);
    }
}
void show_all_data(List ListPeg){
    /*
    IS. Terdefinisi sebuah list L
    FS. Menampilkan semua info elmList di list.
    */
    address P;
    int i;

    if(ListPeg.first == NULL){
        cout << "List kosong!" << endl;
    } else {
        i = 1;
        P = ListPeg.first;

        while(P != NULL){
            cout<< i <<endl;
            cout<< "Nama :" << P->info.nama <<endl;
            cout<< "NIP :" << P->info.NIP <<endl;
            cout<< "Gaji :" << P->info.gaji <<endl;
            P = P->next;
            i++;
        };

        cout<< "List selesai ditampilkan!" <<endl;}
};
address search_by_NIP(List ListPeg, string NIP){
    //Fungsi ini akan mengembalikan alamat dari elemen yang memiliki NIP yang dicari
    address p;
    p = ListPeg.first;
    if( p != NULL){
        while(p != NULL && p->info.NIP != NIP){
            p = p->next;
        }
        return(p);
    } else {
        return NULL;
    }
};
void delete_Data(List &ListPeg, string NIP){
    //I.S. Terdefinisi list L yang mungkin kosong, dan NIP yang akan dihapus datanya
    //F.S. Data pegawai dengan NIP tsb terhapus dari list
    address p = search_by_NIP(ListPeg, NIP);

    if(p != NULL){
        if(p == ListPeg.first){
            delete_first(ListPeg);
        } else if(p->next == NULL){
            delete_last(ListPeg);
        } else {
            delete_after(ListPeg, p);
        }
    }
};

int jumlah_pegawai(List ListPeg){
    //Fungsi ini akan mengembalikan jumlah data pegawai di ListPeg
    address p = ListPeg.first;
    int jum = 0;
    while(p != NULL) {
        jum++;
        p = p->next;
    }
    return jum;
};
int total_salary(List ListPeg){
    //Fungsi ini akan mengembalikan total penghasilan dari semu pegawai pada ListPeg
    address p = ListPeg.first;
    int jum = 0;
    while(p != NULL) {
        jum= jum + p->info.gaji;
        p = p->next;
    }
    return jum;
};

