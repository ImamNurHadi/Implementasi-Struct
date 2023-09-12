#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa 
{
    string nama;
    int nrp;
    float umur;
    char goldar;
    string ttl;
    char jender;
};

void pendaftaran(Mahasiswa m[], int &jumlah_mahasiswa)
{
    if (jumlah_mahasiswa < 10)
    {
        cout << "Mahasiswa ke " << (jumlah_mahasiswa + 1) << endl;
        cout << "Nama        : "; cin >> m[jumlah_mahasiswa].nama;
        cout << "nrp         : "; cin >> m[jumlah_mahasiswa].nrp;
        cout << "umur        : "; cin >> m[jumlah_mahasiswa].umur;
        cout << "goldar      : "; cin >> m[jumlah_mahasiswa].goldar;
        cout << "ttl         : "; cin >> m[jumlah_mahasiswa].ttl;
        cout << "Jender L/P  : "; cin >> m[jumlah_mahasiswa].jender;
        jumlah_mahasiswa++;
    }
    else
    {
        cout << "Kapasitas mahasiswa sudah penuh." << endl;
    }
}

void Pembaruan(Mahasiswa m[], int jumlah_mahasiswa)
{
    int nomor;
    cout << "Masukkan nomor mahasiswa yang ingin diubah: ";
    cin >> nomor;

    if (nomor >= 1 && nomor <= jumlah_mahasiswa)
    {
        cout << "Nama        : "; cin >> m[nomor - 1].nama;
        cout << "nrp         : "; cin >> m[nomor - 1].nrp;
        cout << "umur        : "; cin >> m[nomor - 1].umur;
        cout << "goldar      : "; cin >> m[nomor - 1].goldar;
        cout << "ttl         : "; cin >> m[nomor - 1].ttl;
        cout << "Jender L/P  : "; cin >> m[nomor - 1].jender;
        cout << "Data mahasiswa nomor " << nomor << " berhasil diubah." << endl;
    }
    else
    {
        cout << "Nomor mahasiswa tidak valid." << endl;
    }
}

void Penghapusan(Mahasiswa m[], int &jumlah_mahasiswa)
{
    int nomor;
    cout << "Masukkan nomor mahasiswa yang ingin dihapus: ";
    cin >> nomor;

    if (nomor >= 1 && nomor <= jumlah_mahasiswa)
    {
        for (int i = nomor - 1; i < jumlah_mahasiswa - 1; i++)
        {
            m[i] = m[i + 1];
        }
        jumlah_mahasiswa--;
        cout << "Data mahasiswa nomor " << nomor << " berhasil dihapus." << endl;
    }
    else
    {
        cout << "Nomor mahasiswa tidak valid." << endl;
    }
}

void Show(Mahasiswa m[], int jumlah_mahasiswa)
{   
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        cout << "Mahasiswa ke " << (i + 1) << endl;
        cout << "Nama        : " << m[i].nama << endl;
        cout << "nrp         : " << m[i].nrp << endl;
        cout << "umur        : " << m[i].umur << endl;
        cout << "goldar      : " << m[i].goldar << endl;
        cout << "ttl         : " << m[i].ttl << endl;
        cout << "Jender L/P  : " << m[i].jender << endl;
        cout << "" <<endl;
    }
}

int main()
{
    Mahasiswa m[10];
    int jumlah_mahasiswa = 0;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Pendaftaran Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Hapus Data Mahasiswa" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        
        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                pendaftaran(m, jumlah_mahasiswa);
                break;
            case 2:
                Show(m, jumlah_mahasiswa);
                break;
            case 3:
                Penghapusan(m, jumlah_mahasiswa);
                break;
            case 4:
                Pembaruan(m, jumlah_mahasiswa);
                break;
            case 5:
                 cout << "***************" << endl;
                cout << "Program selesai, Makacih UwU" << endl;
                return 0;
            default:
                cout << "Error" << endl;
                break;
        }
    }

    return 0;
}
