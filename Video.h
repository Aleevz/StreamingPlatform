// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Video{
  public:
    Video();
    Video(int, string,int, string, double);
    int getID() const;
    string getNombre() const;
    int getDuracion() const;
    string getGenero() const;
    double getRating()const;
    void setID(int); 
    void setNombre(string);
    void setDuracion(int);
    void setGenero(string);
    void setRating(double);
    virtual string imprime();
    friend ostream& operator<< (ostream &, Video*);

  private:
    int ID,
        duracion;
    string nombre,
           genero;
    double rating;
};

#endif