// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#ifndef EPISODIO_H
#define EPISODIO
#include <iostream>
#include <string>
using namespace std;

class Episodio{
  public:
    Episodio();
    Episodio(int,string,int);
    int getNum() const;
    string getNom() const;
    int getDur() const;
    void setNum(int);
    void setNom(string);
    void setDur(int);
    string imprime();

  private:
    int duracion,
        num;
    string nombre;
};

#endif












/*

#ifndef EPISODIO_H
#define EPISODIO
#include "Video.h"

class Episodio: public Video{
  public:
    Episodio();
    Episodio(int,string,int);
    int getNum() const;
    void setNum(int);
    void imprime() override;

  private:
    int duracion,num;
    string nombre;
};

#endif

*/