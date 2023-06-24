// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#include "Video.h"

Video::Video(){
  ID = 0;
  nombre = " ";
  duracion = 0;
  genero = " ";
  rating = 0.0;
}

Video::Video(int id,string n, int d, string g, double r){
  ID = id;
  nombre = n;
  duracion = d;
  genero = g;
  rating = r;
}

int Video::getID() const{
  return ID;
}

string Video::getNombre() const{
  return nombre;
}

int Video::getDuracion() const{
  return duracion;
}

string Video::getGenero() const{
  return genero;
}

double Video::getRating() const{
  return rating;
}

void Video::setID(int id){
  ID = id;
}

void Video::setNombre(string nom){
  nombre = nom;
}


void Video::setDuracion(int dur){
  duracion = dur;
}

void Video::setGenero(string g){
  genero = g;
}

void Video::setRating(double r){
  rating = r;
}

string Video::imprime(){
  string r = to_string(rating);
  r.resize(4);
  string s = "ID: "+ to_string(ID) + " - "+nombre+" - Duracion: " + to_string(duracion) + " min - Genero: " + genero + " - Rating: " + r;
  return s;
}

// Sobrecarga de operador de flujo de salida
ostream &operator << (std::ostream & salida, Video* video){
    salida << video->imprime();
    return salida;
}