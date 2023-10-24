#include "Video.h"
#include <iostream>

using namespace std;

//--------------------Constructores--------------------//

// Sin parametros (default)
Video::Video(){
    ID = 0;
    Nombre = "";
    Duracion = 0;
    Genero = "";
    num_cal = 0;
}

// Con parametros
Video::Video(int id, string nombre, int duracion, string genero, double calificacion) {
    ID = id;
    Nombre = nombre;
    Duracion = duracion;
    Genero = genero;
    Calificacion = calificacion;
    num_cal = 0;
}

//--------------------Getters--------------------//
int Video::getID(){
    return ID;
}

string Video::getNombre() {
    return Nombre;
}

int Video::getDuracion(){
    return Duracion;
}

string Video::getGenero(){
    return Genero;
}

//--------------------Setters--------------------//
void Video::setID(const int i) { ID = i; }
void Video::setNombre(const string n) { Nombre = n; }
void Video::setDuracion(const int d) { Duracion = d; }
void Video::setGenero(const string g) { Genero = g; }
void Video::setCalificacion(const double c) { Calificacion = c; }

//Método para que las calificaciones ingresadas sean promediadas
void Video::calificar(int c) {
    Calificacion = (Calificacion*num_cal+c)/(num_cal+1);
    num_cal++;
}

//Método que será sobreescribido en las demas clases
void Video::imprime() {
    cout << ID << " | ";
    cout << Nombre << " | ";
    cout << Duracion << " | ";
    cout << Genero << " | ";
    cout << Calificacion << '\n';
}
