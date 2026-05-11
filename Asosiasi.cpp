#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien{ // asosiasi
public:
    string nama;
    vector<dokter *> daftar_dokter;
    pasien(string pNama) : nama(pNama){
        cout << "Pasien \"" << nama << "\" ada\n";
    }
    
}