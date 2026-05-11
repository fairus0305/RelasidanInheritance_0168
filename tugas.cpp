#include <iostream>
#include <vector>
#include <string>

using namespace std;


class User {
protected:
    static int globalId; 
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        generateId();
    }

    void generateId() {
        globalId++;
        this->id = globalId;
    }
};


int User::globalId = 0;


class Member : public User {
private:
    string status;

public:
   
    Member(string nama, string email) : User(nama, email) {
        this->status = "Aktif"; 
    }

    void setStatus(string statusBaru) {
        this->status = statusBaru;
    }

    string getStatus() {
        return status;
    }

    int getId() { return id; }
    string getNama() { return nama; }

    void showProfile() {
        cout << "=== Profil Member ===" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << status << endl;
        cout << "---------------------" << endl;
    }
};


class Admin : public User {
public:
    Admin(string nama, string email) : User(nama, email) {}

   
    void showAllMember(const vector<Member>& daftarMember) {
        cout << "\n[Admin] Daftar Seluruh Member:" << endl;
        for (auto m : daftarMember) {
            cout << "- ID: " << m.getId() << " | Nama: " << m.getNama() << " | Status: " << m.getStatus() << endl;
        }
    }

    
    void toggleActivationMember(Member& m) {
        if (m.getStatus() == "Aktif") {
            m.setStatus("Non-Aktif");
        } else {
            m.setStatus("Aktif");
        }
        cout << "\n[Admin] Status Member " << m.getNama() << " berhasil diubah." << endl;
    }
};


int main() {
    
    Admin adminUtama("Super Admin", "admin@web.com");

    
    vector<Member> listMember;
    listMember.push_back(Member("Iqbal", "iqbalgantengs@mail.com"));
    listMember.push_back(Member("Fairus", "fairusror@mail.com"));

   
    listMember[0].showProfile();

   
    adminUtama.showAllMember(listMember);

    
    adminUtama.toggleActivationMember(listMember[0]);

    
    listMember[0].showProfile();

    return 0;
}