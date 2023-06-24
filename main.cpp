#include "Catalogo.h"
#include <limits>
using namespace std;

int main() {
  Catalogo catalogo;
  int i = 1, opt; 
  float test, test2;

  cout << "Bienvenidos a la plataforma de streaming Migale." << endl;

  while (i == 1) {
    cout << "\n---- MENU PRINCIPAL ---- \n\n1. Mostrar todos los titulos \n2. "
            "Mostrar peliculas \n3. Mostrar series \n4. Mostrar por "
            "calificacion \n5. Mostrar por genero \n6. Calificar un titulo"
         << endl;
    while(true){
      try{        
        while (!(cin >> test)) { 
          cin.clear(); //clear bad input flag 
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input 
          throw "\nNo es un numero entero"; 
        } 
        opt=test;
        if(opt<1 || opt>6 || opt!=test){
          throw "\nIngrese un numero entero valido (1-6)";
        }
        
        if (opt == 1) {
          catalogo.mostrarTodo();
        } else if (opt == 2) {
          catalogo.mostrarPelis();
        } else if (opt == 3) {
          catalogo.mostrarSeries();
        } else if (opt == 4) {
          catalogo.porRating();
        } else if (opt == 5) {
          catalogo.porGenero();
        } else if (opt == 6) {
          catalogo.calificarVideo();
        }
        break;
      }
      catch (const char *msg)
      {
        cerr << msg << endl;
      }
    }

    
    cout << endl << endl << "Continuar en el menu principal? \n\t1.Si \n\t2.No" << endl;
    while(true){
      try{        
        while (!(cin >> test2)) { 
          cin.clear(); //clear bad input flag 
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input 
          cout << "\nNo es un numero entero"<<endl; 
        } 
        i=test2;
        if(i<1 || i>2 || i!=test2){
          i=1;
          throw "\nIngrese un numero entero valido (1 o 2)";
        }
        break;
      }
      catch (const char *msg){
        cerr << msg << endl;
      }
    }
  }
  cout << "\nGracias por utilizar la plataforma de streaming Migale :)" << endl;
}