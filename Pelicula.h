// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

class Pelicula:public Video{
  public:
    Pelicula();
    Pelicula(int, string, int, string,double, int);
    int getYear() const;
    void setYear(int);
    string imprime() override;

  private:
    int year;
};


#endif