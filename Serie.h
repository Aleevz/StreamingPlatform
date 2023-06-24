// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"
#include <vector>

using namespace std;

class Serie:public Video{
  public:
    Serie();
    Serie(int, string, int, string, double,vector<Episodio*>);
    vector<Episodio*> getEpisodios() const;
    void setEpisodios(vector<Episodio*>);
    string imprime() override;

  private:
    vector<Episodio*> episodios;
};

#endif














