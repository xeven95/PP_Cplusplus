/* 
 * File:   Gestor.h
 * Author: All-PC
 *
 * Created on 21 de noviembre de 2016, 0:30
 */

#ifndef GESTOR_H
#define	GESTOR_H

#include "Contenido.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <fstream>


class Gestor{
public:
    Gestor();
    virtual ~Gestor();
    
    void addContenido(std::shared_ptr<Contenido> cont); //Add contenido principal
    void addContenido(std::string nserie, unsigned int ntemp); //Añadir temporada a serie
    void addContenido(std::string nserie, unsigned int ntemp, std::string nepi , unsigned int dur); //Añadir episodio a temporada de una serie
    void addContenido(std::string ndocu, std::string nepi,unsigned int dur);//Añadir un episodio a un documental
    
    void removeContenido(std::string nombre);
    void removeContenido(std::string nombre, std::string elemento);
    void removeContenido(std::string nserie, unsigned int ntemp);
    void removeContenido(std::string nserie, std::string ntemp, std::string nepi);
    
    //Consultar contenido por nombre
    void buscarContenidoNombre(std::string nombre);
    //Consultar contenido por genero
    void buscarGeneros (std::vector<std::string> genero);
    //Consulta de un episodio de serie o documental
    void buscarContenidoporNumero (std::string nombre, unsigned int n1,unsigned int n2 = 0);    
    //Guardar info en fichero
    void guardarfichero();
    
    //Metodos secundarios para opciones extra
    void mostrar_contenido();
    void mostrar_contenido(std::vector<std::shared_ptr<Contenido>> cont);
    int sizeContenido();
    void mostrarInfoGenero();
    
    
private:
    void addGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont);
    void removeGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont);
    std::vector<std::shared_ptr<Contenido>> buscarGenerosMetodo(std::vector<std::shared_ptr<Contenido>>& cont1,std::vector<std::shared_ptr<Contenido>>& cont2);

    
    bool exist_contenido(std::string nombre);
    std::shared_ptr<Contenido> encontrar_contenido(std::string nombre);
    std::shared_ptr<Contenido> encontrar_contenido_pelicula(std::string nombre);
    std::shared_ptr<Contenido> encontrar_contenido_serie(std::string nombre);
    std::shared_ptr<Contenido> encontrar_contenido_documental(std::string nombre);

    //Variables
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> > contenido;
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> > generos;
    
};

#endif	/* GESTOR_H */

