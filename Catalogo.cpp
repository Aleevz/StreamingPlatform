// Alejandra Velasco Zárate A01635453
// Miguel Ángel Pérez Granados A01252536

#include "Catalogo.h"
#include<bits/stdc++.h>

Catalogo::Catalogo(){
  vector <Video*> catalogo;
  vector <Episodio*> episodios;
  string nombre, 
         genero,
         nombreEpisodio;
  double rating;
  int ID,
      year,
      duracion,
      duracionEpisodio,
      num,
      numEpisodio;
  char tipo;
  
  ifstream archivo;
  archivo.open("Datos.txt");
  if (archivo.is_open()){
    while (archivo >> tipo)
        {
            if (tipo == 'p')
            {
                archivo >> ID >> nombre >> duracion >> genero >> rating >> year;
                videos.push_back(new Pelicula(ID,nombre,duracion,genero,rating,year));
            }
            else if (tipo == 's')
            {
                archivo >> ID >> nombre >> duracion >> genero >> rating;
                archivo.ignore();
                archivo >> num;
                for (int i = 0; i < num; i++)
                {
                    archivo >> numEpisodio >> nombreEpisodio >> duracionEpisodio;
                    archivo.ignore();
                    episodios.push_back(new Episodio(numEpisodio, nombreEpisodio, duracionEpisodio));
                }
                videos.push_back(new Serie(ID, nombre, duracion, genero, rating, episodios));
                episodios.clear();
            }
        }
    }
    archivo.close();
}

Catalogo::Catalogo(vector <Video*> c){
  videos = c;
}

void Catalogo::mostrarTodo(){
  cout<<endl<<endl<<endl<<"------------------------------------------------- CATALAGO COMPLETO ---------------------------------------------------"<<endl<<endl;
  for(int i=0; i < videos.size(); i++){
    cout<<videos[i];
  }
}

void Catalogo::porRating(){
  double rango1, rango2,dif;
  int type;
  cout<<endl<<"Seleccione un rango de rating escribiendo 2 numeros entre 0 y 5 (ej. 2.5, 4): "<<endl;
  cout<<"Rango inferior: ";
  cin>>rango1;
  cout<<"Rango superior: ";
  cin>>rango2;
  if(rango2<rango1){
    dif=rango1;
    rango1=rango2;
    rango2=dif;
  }
  cout<<"\n\n\t1. Todos los titulos\n\t2. Peliculas\n\t3. Series"<<endl<<endl;
  cin>>type;
  cout<<endl<<endl;
  cout<<"------------------------------------------- RATING ENTRE "<<rango1<<" Y "<<rango2<<" --------------------------------------------"<<endl<<endl;
  
  
  if(type==1){
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getRating()>=rango1 && videos[i]->getRating()<=rango2){
        cout<<videos[i]; 
      }
    }
  }  
  else if(type==2){
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getRating()>=rango1 && videos[i]->getRating()<=rango2 && dynamic_cast<Pelicula*>(videos[i])!=nullptr){
        cout<<videos[i]; 
      }
    }
  }  
  else{
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getRating()>=rango1 && videos[i]->getRating()<=rango2 && dynamic_cast<Serie*>(videos[i])!=nullptr){
        cout<<videos[i]; 
      }
    }
  }  
  
}

void Catalogo::porGenero(){
  int eleccion, type;
  string genero;
  cout<<"\nSelecciona el genero que buscas: \n\t1. Drama\n\t2. Accion\n\t3. Animacion\n\t4. Misterio\n\t5. Comedia"<<endl<<endl;
  cin>>eleccion;
  cout<<"\n\n\t1. Todos los titulos\n\t2. Peliculas\n\t3. Series"<<endl<<endl;
  cin>>type;
  cout<<endl<<endl;
  if(eleccion==1){
    genero="Drama";
  }
  if(eleccion==2){
    genero="Accion";
  }
  if(eleccion==3){
    genero="Animacion";
  }
  if(eleccion==4){
    genero="Misterio";
  }
  if(eleccion==5){
    genero="Comedia";
  }
  string generoMay = genero;
  transform(generoMay.begin(), generoMay.end(), generoMay.begin(), ::toupper);
  cout<<"----------------------------------------------------------- "<<generoMay<<" -----------------------------------------------------------"<<endl<<endl;
  if(type==1){
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getGenero()==genero){
        cout<<videos[i]; 
      }
    }
  }  
  if(type==2){
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getGenero()==genero && dynamic_cast<Pelicula*>(videos[i])!=nullptr){
        cout<<videos[i]; 
      }
    }
  } 
  if(type==3){
    for(int i=0; i < videos.size(); i++){
      if(videos[i]->getGenero()==genero && dynamic_cast<Serie*>(videos[i]) != nullptr){
        cout<<videos[i]; 
      }
    }
  }  
  
}

void Catalogo::mostrarPelis(){
  cout<<endl<<endl<<endl<<"----------------------------------------------------------- PELICULAS -----------------------------------------------------------"<<endl<<endl;
  for(int i=0; i < videos.size(); i++){
    if (dynamic_cast<Pelicula*>(videos[i]) != nullptr){
      cout<<videos[i];
    }
  }
}

void Catalogo::mostrarSeries(){
  cout<<endl<<endl<<endl<<"------------------------------------------------------------- SERIES -------------------------------------------------------------"<<endl<<endl;
  for(int i=0; i < videos.size(); i++){
    if (dynamic_cast<Serie*>(videos[i]) != nullptr){
      cout<<videos[i];
    }
  }
}

void Catalogo::calificarVideo(){
  double calif;
  int id;
  for(int i=0; i < videos.size(); i++){
    cout<<"\nID: "<<videos[i]->getID()<<" - "<<videos[i]->getNombre();
    if (dynamic_cast<Pelicula*>(videos[i]) != nullptr){
      cout<<" (pelicula)"<<endl;
    }
    else{
      cout<<" (serie)"<<endl;
    }
  }
  cout<<endl<<"Ingrese el ID del video a calificar: ";
  cin>>id;
  cout<<endl<<"Ingrese la calificacion (0-5): ";
  cin>>calif;
  cout<<endl;
  videos[id-1]->setRating(calif);
}
