/* 
 * File:   main.cpp
 * Author: All-PC
 *
 * Created on 19 de noviembre de 2016, 20:26
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Gestor.h"
#include "Pelicula.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char opc;
    std::vector<std::string> auxgen;
    
    Gestor gestor;
    Pelicula peli("asd","asd",auxgen,6);
    
    gestor.addContenido("pelicula",peli);
    gestor.addContenido("pelicula",peli);
    std::cout << "----" << '\n';
    gestor.removeContenido("asd");
    gestor.addContenido("pelicula",peli);


    /*
    
    std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);
  int aux= 5;
  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), [aux](int n){
      return aux == n;
  });
  if (it == myvector.end()){
      it--;
  }
  std::cout << "The first odd value is " << *it << '\n';
  std::cout << "El tamaño es " << gestor.size() << '\n';
  
  */
  return 0;
    
    do{
        std::cout << "Elija una opcion" <<'\n';
        std::cout << "1) Mostrar Peliculas, Series y Documentales." <<'\n';
        std::cout << "2) Consultar una pelicula, serie o documental." <<'\n';
        std::cout << "3) Consultar un episodio de una serie." <<'\n';
        std::cout << "4) Consultar un episodio de un documental." <<'\n';
        std::cout << "5) Consultar un elemento por genero o generos." <<'\n';
        std::cout << "6) Salir." <<'\n';
        std::cin >> opc;
        std::cout << opc <<'\n';
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                return 0;
                break;
            default:
                std::cout << "Elija una opcion valida." << '\n';
        }
    }while (opc!='f');    
    
}
