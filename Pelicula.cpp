#include "Pelicula.h"
#include <iostream>

using namespace std;

//--------------------Constructores--------------------//

// Sin parametros (default)
Pelicula::Pelicula() { }

// Con parametros
Pelicula::Pelicula(int id, string nombre, int duracion, string genero, double calificacion):Video(id, nombre, duracion, genero, calificacion) {
    num_cal=0;
}

//Método sobreescrito 
void Pelicula::imprime() {
    cout << "Pelicula | ";
    cout << ID << " | ";
    cout << Nombre << " | ";
    cout << Duracion << " | ";
    cout << Genero << " | ";
    cout << Calificacion << '\n';
}
