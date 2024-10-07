#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
    private:
        int id;
        string password;
    public:
        string username;
    
    User(int id){
        cout << "Parameterized constructor called.";
        this->id = id;
    }
    
    string getPassword(){
        return password;
    }
    
    void setPassword(string Password){
        this->password = Password;
    }
};

int main(){
    // User U1;
    // User U2 = new User(04);
    User U3(07);
    // U1.username = "anil";
    U3.username = "anil";
    // U2.setPassword("abcd");
    
    cout << U3.username << endl;
    // cout << U2.getPassword() << endl;
}