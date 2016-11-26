#include "Gestor.h"
#include <iostream>
#include <algorithm>
#include "Pelicula.h"

Gestor::Gestor(){

}

Gestor::~Gestor(){
    
}

void Gestor::addContenido(Contenido* cont){
    //Añadir los tres tipos de contenido principal
    if (!this->exist_contenido(cont->getTitulo())){
        contenido[cont->getTipo()].push_back(cont);
        this->addGenero(cont->getGenero(),cont);
        std::cout << "Se ha añadido el contenido llamado " << cont->getTitulo() << " ." << '\n';
    } else {
        std::cout << "El contenido llamado " << cont->getTitulo() << " ya existe." << '\n';
    }
    
    // FALTA AÑADIR EPISODIOS Y TEMPORADAS.
    
}

//FALTA ELIMINAR TEMPORADAS Y EPISODIOS
void Gestor::removeContenido(std::string nombre){
    std::map<std::string, std::vector<Contenido*> >::iterator it;
    std::vector<Contenido*>::iterator it2;
    bool borrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !borrado; it++){
        it2 = std::remove_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](Contenido* n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            borrado=true;
            Contenido*& cont = *it2;
            this->removeGenero(cont->getGenero(),cont);

            contenido[it->first].erase(it2);
            std::cout << "El contenido llamado " << cont->getTitulo() << " ha sido borrado." << '\n';
        }
        //std::cout << "Campo valor map: " << it->first << '\n';
    }
    if(!borrado){
        std::cout << "El contenido llamado " << nombre << " no ha sido encontrado." << '\n';
    }
}



//METODOS SECUNDARIOS
void Gestor::addGenero(std::vector<std::string> genero, Contenido* cont){
    std::vector<std::string>::iterator it;
    for (it=genero.begin(); it!=genero.end();it++){
        generos[*it].push_back(cont);
    }
}

void Gestor::removeGenero(std::vector<std::string> genero, Contenido* cont){
    std::vector<std::string>::iterator it;
    std::vector<Contenido*>::iterator it2;
    for (it=genero.begin(); it!=genero.end();it++){
        it2 = std::remove_if (generos[*it].begin(), generos[*it].end(), [cont](Contenido* n){
            return cont->getTitulo() == n->getTitulo();
        });
        generos[*it].erase(it2);
    }
}

std::vector<Contenido*>::iterator Gestor::encontrar_contenido(std::vector<Contenido*> vector, Contenido* cont){
    std::vector<Contenido*>::iterator it2;
    it2 = std::remove_if (vector.begin(), vector.end(), [cont](Contenido* n){
            return cont->getTitulo() == n->getTitulo();
    });
    return it2;
}

Contenido* Gestor::encontrar_contenido(std::string nombre){
    std::map<std::string, std::vector<Contenido*> >::iterator it;
    bool encontrado=false;
    Contenido* cont;
    for(it=contenido.begin(); it!=contenido.end() && !encontrado; it++){
        std::vector<Contenido*>::iterator it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](Contenido* n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            encontrado=true;
        }
        cont = *it2;
        //std::cout << "Campo valor map: " << it->first << '\n';
    }
    return cont; 
}

bool Gestor::exist_contenido(std::string nombre){
    std::map<std::string, std::vector<Contenido*> >::iterator it;
    bool encontrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !encontrado; it++){
        std::vector<Contenido*>::iterator it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](Contenido* n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            encontrado=true;
        }
        //std::cout << "Campo valor map: " << it->first << '\n';
    }
    return encontrado;
}

void Gestor::mostrar_contenido(){
    std::map<std::string, std::vector<Contenido* > >::iterator it;
    std::vector<Contenido* >::iterator it2;
    Contenido* cont;
    for(it=contenido.begin(); it!=contenido.end();it++){
        for(it2=contenido[it->first].begin(); it2!=contenido[it->first].end();it2++){
            cont = *it2;
            cont->getInfo();
        }
    }
}

int Gestor::sizeContenido(){
    return contenido.size();
}

void Gestor::mostrarInfoGenero(){
    std::cout << "Nº de generos: " << generos.size() << '\n';
    std::map<std::string, std::vector<Contenido* > >::iterator it;
    for(it=generos.begin(); it!=generos.end();it++){
        std::cout << it->first <<": " << generos[it->first].size() << '\n';    
    }
}
