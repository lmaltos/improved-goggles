#include "Fecha.h"
#include <sstream>
using namespace std;

fstream& operator>>(fstream& file,Fecha& f) {
    string str;
    file >> str;
    f.mes = f.mtoi(str);
    file >> f.dia >> str;
    stringstream ss(str);
    getline(ss,str,':');
    f.hh = stoi(str); // string to int
    getline(ss,str,':');
    f.mm = stoi(str);
    getline(ss,str);
    f.ss = stoi(str);
    return file;
}

/**
 * Convierte el mes de formato MMM -> MM (Oct -> 10)
 */
int Fecha::mtoi(const std::string& mes) {
    string M[] = {"Oct","Aug","Jun","Sep","Jul"};
    int nM[] = {10,8,6,9,7};
    for (int i = 0; i < 5; i++) {
        if (mes == M[i]) {
            return nM[i];
        }
    }
    return 12;
}

std::ostream& operator<<(std::ostream& os,Fecha& f) {
    os << f.mes << " " << f.dia
        << (f.hh < 10 ? " 0" : " ") << f.hh
        << (f.mm < 10 ? ":0" : ":") << f.mm
        << (f.ss < 10 ? ":0" : ":") << f.ss;
    return os;
}