#ifndef FECHA_H
#define FECHA_H
#include <fstream>

class Fecha {
    private:
      int mes,dia,hh,mm,ss;
    public:
      //Fecha();
      friend std::fstream& operator>>(std::fstream&,Fecha&);
      friend std::ostream& operator<<(std::ostream&,Fecha&);
      int mtoi(const std::string&);
  };
  
  #endif