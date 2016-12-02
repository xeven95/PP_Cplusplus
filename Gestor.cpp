#include "Gestor.h" 


Gestor::Gestor(){

}

Gestor::~Gestor(){
    
}

//Añade contenido principal
void Gestor::addContenido(std::shared_ptr<Contenido> cont){
    //Añadir los tres tipos de contenido principal
    if (!this->exist_contenido(cont->getTitulo())){
        contenido[cont->getTipo()].push_back(cont);
        this->addGenero(cont->getGenero(),cont);
        std::cout << "Se ha añadido el contenido llamado " << cont->getTitulo() << " ." << '\n';
    } else {
        std::cout << "El contenido llamado " << cont->getTitulo() << " ya existe." << '\n';
    }
}
//Añade temporadas a las series
void Gestor::addContenido(std::string nserie, std::string ntemp){
    std::shared_ptr<Contenido> cont = this->encontrar_contenido_serie(nserie);
    if(cont){
        cont->addTemporada(ntemp);
    } else {
        std::cout << "La serie llamada " << nserie << " no ha sido encontrada." << '\n';        
    }
}
//Añade episodios a la temporadas de la serie
void Gestor::addContenido(std::string nserie, std::string ntemp, std::string nepi, unsigned int dur){
    std::shared_ptr<Contenido> cont = this->encontrar_contenido_serie(nserie);
    if(cont){
        cont->addEpisodio(ntemp,nepi,dur);
        //llamar metodo que meta una temporada

    } else {
        std::cout << "La serie llamada " << nserie << " no ha sido encontrada." << '\n';        
    }
}
//Añade un episodio a una un documental
void Gestor::addContenido(std::string ndocu, std::string nepi, unsigned int dur){
    std::shared_ptr<Contenido> cont = this->encontrar_contenido_documental(ndocu);
    if (cont){
        cont->addEpisodio("",nepi,dur);
    } else {
        std::cout << "El documental llamada " << ndocu << " no ha sido encontrada." << '\n';  
    }
}

//Borra contenido principal
void Gestor::removeContenido(std::string nombre){
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> >::iterator it;
    std::vector<std::shared_ptr<Contenido>>::iterator it2;
    bool borrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !borrado; it++){
        it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](std::shared_ptr<Contenido> n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            borrado=true;
            std::shared_ptr<Contenido> cont = *it2;
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
//Eliminar una temporada de una serie o un episodio de Documental
void Gestor::removeContenido(std::string nombre, std::string elemento){
    std::shared_ptr<Contenido> cont = this->encontrar_contenido_serie(nombre);
    if (cont){
        cont->removeTemporada(elemento);
    } else {
        cont = this->encontrar_contenido_documental(nombre);
        if (cont){
            cont->removeTemporada(elemento);
        } else {
            std::cout << "No se ha podido eliminar el contenido llamado " << nombre << " porque no ha sido encontrado." << '\n';
        }    
    }
}
//Eliminar un capitulo de una temporada de una serie
void Gestor::removeContenido(std::string nserie, std::string ntemp, std::string nepi){
    std::shared_ptr<Contenido> cont = this->encontrar_contenido_serie(nserie);
    if (cont){
        cont->removeEpisodio(ntemp,nepi);
    } else {
        std::cout << "No se ha podido eliminar el contenido llamado " << nserie << " porque no ha sido encontrado." << '\n';
    }
}

//Metodos para añadir y eliminar genero relacionad a un contenido
void Gestor::addGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont){
    std::vector<std::string>::iterator it;
    for (it=genero.begin(); it!=genero.end();it++){
        generos[*it].push_back(cont);
    }
}
void Gestor::removeGenero(std::vector<std::string> genero, std::shared_ptr<Contenido> cont){
    std::vector<std::string>::iterator it;
    std::vector<std::shared_ptr<Contenido>>::iterator it2;
    for (it=genero.begin(); it!=genero.end();it++){
        it2 = std::remove_if (generos[*it].begin(), generos[*it].end(), [cont](std::shared_ptr<Contenido> n){
            return cont->getTitulo() == n->getTitulo();
        });
        generos[*it].erase(it2);
    }
}
void Gestor::buscarGeneros(std::vector<std::string> genero){
    std::vector<std::shared_ptr<Contenido>> aux;
    if (genero.size()==0){
        std::cout << "Debe de buscar algun genero" << '\n';
    } else if (genero.size() == 1){
        aux=generos[genero.front()];
    } else if(genero.size()==2){
        aux=this->buscarGenerosMetodo(generos[genero.front()],generos[genero.back()]);
    } else if(genero.size()>=3){
        aux=this->buscarGenerosMetodo(generos[genero[0]],generos[genero[1]]);
        std::vector<std::string>::iterator it=genero.begin();
        for( std::advance(it,2); it!=genero.end(); it++){
            aux=this->buscarGenerosMetodo(aux,generos[*it]);
            std::cout << "aux: "<< aux.size() << '\n';
        }
    } 
    this->mostrar_contenido(aux);
    
}
std::vector<std::shared_ptr<Contenido>> Gestor::buscarGenerosMetodo(std::vector<std::shared_ptr<Contenido> >& cont1, std::vector<std::shared_ptr<Contenido> >& cont2){
    std::vector<std::shared_ptr<Contenido>> alm;
    std::set_intersection(cont1.begin(),cont1.end(),cont2.begin(),cont2.end(),std::back_inserter(alm));
    return alm;
}

//Metodos para buscar un puntero
std::shared_ptr<Contenido> Gestor::encontrar_contenido(std::string nombre){
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> >::iterator it;
    std::vector<std::shared_ptr<Contenido>>::iterator it2;
    bool encontrado=false;
    std::shared_ptr<Contenido> cont;
    for(it=contenido.begin(); it!=contenido.end() && !encontrado; it++){
        it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](std::shared_ptr<Contenido> n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            encontrado=true;
            cont = *it2;
        }
    }
    cont->getInfo();      
    return cont;
}
std::shared_ptr<Contenido> Gestor::encontrar_contenido_pelicula(std::string nombre) {
    std::vector<std::shared_ptr<Contenido>>::iterator it;
    std::shared_ptr<Contenido> cont;
    it = std::find_if (contenido["pelicula"].begin(), contenido["pelicula"].end(), [nombre](std::shared_ptr<Contenido> n){
        return n->getTitulo() == nombre;
    });
    if(it != contenido["pelicula"].end()){
        cont = *it;
    }
    return cont;
}
std::shared_ptr<Contenido> Gestor::encontrar_contenido_serie(std::string nombre){
    std::vector<std::shared_ptr<Contenido>>::iterator it;
    std::shared_ptr<Contenido> cont;
    it = std::find_if (contenido["serie"].begin(), contenido["serie"].end(), [nombre](std::shared_ptr<Contenido> n){
        return n->getTitulo() == nombre;
    });
    
    if(it != contenido["serie"].end()){
        cont = *it;
    }
    return cont;
}
std::shared_ptr<Contenido> Gestor::encontrar_contenido_documental(std::string nombre){
    std::vector<std::shared_ptr<Contenido>>::iterator it;
    std::shared_ptr<Contenido> cont;
    it = std::find_if (contenido["documental"].begin(), contenido["documental"].end(), [nombre](std::shared_ptr<Contenido> n){
        return n->getTitulo() == nombre;
    });
    
    if(it != contenido["documental"].end()){
        cont = *it;
    }
    return cont;
}

void Gestor::buscarContenidoporNumero(std::string nombre, unsigned int n1, unsigned int n2){
    std::shared_ptr<Contenido> cont;
    std::shared_ptr<Episodio> epi;
    if (n2 == 0){
        cont = this->encontrar_contenido_documental(nombre);
    } else {
        cont = this->encontrar_contenido_serie(nombre);
    }
    if (cont){
        epi = cont->buscarEpisodio(n1,n2);
        if (epi){
            std::cout << "Episodio - Nombre: " << epi->getNombre() << " Duracion: " << epi->getDuracion() << '\n';
        }
    } else {
        std::cout << "No existe el contenido llamado "<< nombre << '\n';
    }
    
}

//Si existe un contenido principal ya con dicho nombre
bool Gestor::exist_contenido(std::string nombre){
    std::map<std::string, std::vector<std::shared_ptr<Contenido>> >::iterator it;
    bool encontrado=false;
    for(it=contenido.begin(); it!=contenido.end() && !encontrado; it++){
        std::vector<std::shared_ptr<Contenido>>::iterator it2 = std::find_if (contenido[it->first].begin(), contenido[it->first].end(), [nombre](std::shared_ptr<Contenido> n){
            return n->getTitulo() == nombre;
        });
        if(it2 != contenido[it->first].end()){
            encontrado=true;
        }
    }
    return encontrado;
}

//Metodos para mostrar informacion
void Gestor::mostrar_contenido(){
    std::map<std::string, std::vector<std::shared_ptr<Contenido> > >::iterator it;
    std::vector<std::shared_ptr<Contenido> >::iterator it2;
    std::shared_ptr<Contenido> cont;
    for(it=contenido.begin(); it!=contenido.end();it++){
        for(it2=contenido[it->first].begin(); it2!=contenido[it->first].end();it2++){
            cont = *it2;
            cont->getInfo();
        }
    }
}
void Gestor::mostrar_contenido(std::vector<std::shared_ptr<Contenido> > cont){
    std::vector<std::shared_ptr<Contenido> >::iterator it;
    std::shared_ptr<Contenido> elem;
    for(it=cont.begin(); it!=cont.end();it++){
        elem=*it;
        elem->getInfo();
    }
}
int Gestor::sizeContenido(){
    return contenido.size();
}
void Gestor::mostrarInfoGenero(){
    std::cout << "Nº de generos: " << generos.size() << '\n';
    std::map<std::string, std::vector<std::shared_ptr<Contenido> > >::iterator it;
    for(it=generos.begin(); it!=generos.end();it++){
        std::cout << it->first <<": " << generos[it->first].size() << '\n';    
    }
}
