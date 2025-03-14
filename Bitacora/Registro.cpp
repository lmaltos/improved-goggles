#include "Registro.h"

using namespace std;
Registro::Registro() {

}

Registro::Registro(Fecha _f, string ip, string mensaje)
 : f(f), ip(ip), mensaje(mensaje) {
    
}

fstream& operator>>(fstream& file,Registro& r) {
    file >> r.f >> r.ip;
    getline(file,r.mensaje);
    return file;
}

std::ostream& operator<<(std::ostream& os,Registro& r) {
    os << r.f << " " << r.ip << " " << r.mensaje;
    return os;
}