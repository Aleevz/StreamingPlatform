// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#include "Serie.h"

Serie::Serie(){
  vector <Episodio*> episodios;
}

Serie::Serie(int i, string n, int d, string g, double r,vector<Episodio*> e):Video(i,n,d,g,r){
  episodios = e;
}

vector<Episodio*> Serie::getEpisodios() const{
  return episodios;
}

void Serie::setEpisodios(vector<Episodio*> e){
  episodios = e;
}
string Serie::imprime(){
  string s = Video::imprime()+"\n\n\tEPISODIOS: \n\n";
  for(int i=0; i<episodios.size(); i++){
      s = s + episodios[i]->imprime() +"\n";
    }
  return s;
}





















