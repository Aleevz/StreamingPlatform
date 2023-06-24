// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#ifndef CATALOGO_H
#define CATALOGO_H
#include "Serie.h"
#include "Pelicula.h"

class Catalogo{
  public:
    Catalogo();
    Catalogo(vector <Video*>);
    void mostrarTodo();
    void porRating();
    void porGenero();
    void mostrarPelis();
    void mostrarSeries();
    void calificarVideo();

  private:
    vector<Video*> videos;

};

#endif