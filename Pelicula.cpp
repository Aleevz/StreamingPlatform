// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#include "Pelicula.h"

Pelicula::Pelicula(){
  year = 0;
}

Pelicula::Pelicula(int i, string n,int d, string g, double r, int a):Video(i,n,d,g,r){
  year=a;
}

int Pelicula::getYear() const{
  return year;
}

void Pelicula::setYear(int a){
  year=a;
}

string Pelicula::imprime(){
  string s = Video::imprime() + " - Year: " + to_string(year) + "\n\n";
  return s;
}