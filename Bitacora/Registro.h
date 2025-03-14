#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
#include <fstream>
#include "Fecha.h"

/*
class IP {
    char ip1,ip2,ip3,ip4,puerto;
    friend std::fstream& operator>>(std::fstream&,IP&);
};*/

class Registro {
  private:
    Fecha f;
    std::string ip;
    std::string mensaje;
  public:
    Registro();
    Registro(Fecha,std::string,std::string);
    friend std::fstream& operator>>(std::fstream&,Registro&);
    friend std::ostream& operator<<(std::ostream&,Registro&);
};

#endif