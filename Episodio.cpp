// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#include "Episodio.h"

Episodio::Episodio(){
  num = 0;
  nombre = " ";
  duracion = 0;
}

Episodio::Episodio(int nu, string n, int d){
  num = nu;
  nombre = n;
  duracion = d;
}

int Episodio::getNum() const{
  return num;
}

string Episodio::getNom() const{
  return nombre;
}

int Episodio::getDur() const{
  return duracion;
}

void Episodio::setNum(int nu){
  num=nu;
}

void Episodio::setNom(string n){
  nombre=n;
}

void Episodio::setDur(int d){
  duracion=d;
}

string Episodio::imprime(){
  string s= "\t\tEpisodio #"+ to_string(num)+"  -  Titulo: " + nombre + "  -  Duracion: " + to_string(duracion) + " min \n";
  return s;
}















/*

#include "Episodio.h"

Episodio::Episodio(){
  num = 0;
}

Episodio::Episodio(int nu, string n, int d):Video(n,d){
  num = nu;
}

int Episodio::getNum() const{
  return num;
}

void Episodio::setNum(int nu){
  num=nu;
}

void Episodio::imprime(){
  cout<<"Episodio #"<<num<<"  -  Titulo: "<<Video::getNombre()<<"  -  Duracion: "<<Video::getDuracion()<<endl;
}

*/