#include "Serie.h"

//--------------------Constructores--------------------//

// Sin parametros
Serie::Serie() {}

// Con parametros
Serie::Serie(int id, string nombre, int duracion, string genero, double calificacion, int episodio, string tituloEpisodio, int temporada):Video(id, nombre, duracion, genero, calificacion) {
    Episodio = episodio;
    TituloEp = tituloEpisodio;
    Temporada = temporada;

}

//---------------Getters y Setters propios de la clase serie---------------//

int Serie::getEpisodio(){
    return Episodio;
}

void Serie::setEpisodio(const int e) { Episodio = e; }


string Serie::getTituloEp(){
    return TituloEp;
}

void Serie::setTituloEp(const string te) { TituloEp = te; }

int Serie::getTemporada(){
    return Temporada;
}

void Serie::setTemporada(const int t) { Temporada = t; }

//Método sobreescrito para está clase en especifico
void Serie::imprime() {
    cout << "Serie | ";
    cout << ID << " | ";
    cout << Nombre << " | ";
    cout << Duracion << " | ";
    cout << Genero << " | ";
    cout << Calificacion << " | ";
    cout << Episodio << " | ";
    cout << TituloEp << " | ";
    cout << Temporada << '\n';
}