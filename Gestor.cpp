#include "Gestor.h"
#include <iostream>
#include <algorithm>
Gestor::Gestor(){

}

Gestor::~Gestor(){
    
}


void Gestor::addContenido(std::string tipo, Contenido& cont){
    //Añadir los tres tipos de contenido principal
    if (!this->exist_contenido(cont.getTitulo())){
        contenido[tipo].push_back(cont);
    } else {
         std::cout << "El contenido llamado " << cont.getTitulo() << " ya existe." << '\n';
    }
    
    // FALTA AÑADIR EPISODIOS Y TEMPORADAS.
    
}

//FALTA ELIMINAR TEMPORADAS Y EPISODIOS
void Gestor::removeContenido(std::string nombre){
    std::map<std::string, std::vector<Contenido> >::iterator it;
    std::vector<Contenido>::iterator it2;
    bool borrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !borrado; it++){
        std::cout << it->first << '\n';
        it2 = std::remove_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](Contenido n){
            return n.getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            borrado=true;
            std::cout << "El contenido llamado " << it2->getTitulo() << " ha sido borrado." << '\n';
            contenido[it->first].erase(it2);
        }
        //std::cout << "Campo valor map: " << it->first << '\n';
    }
    if(!borrado){
        std::cout << "El contenido llamado " << nombre << " no ha sido encontrado." << '\n';
    }
}



//METODOS SECUNDARIOS

void Gestor::mostrar_contenido(std::string nombre){
    std::map<std::string, std::vector<Contenido> >::iterator it;
    //FALTA POR TERMINAR
}

bool Gestor::exist_contenido(std::string nombre){
    std::map<std::string, std::vector<Contenido> >::iterator it;
    bool encontrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !encontrado; it++){
        std::vector<Contenido>::iterator it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](Contenido n){
            return n.getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            encontrado=true;
        }
        //std::cout << "Campo valor map: " << it->first << '\n';
    }
    return encontrado;
}


int Gestor::size(){
    return contenido.size();
}