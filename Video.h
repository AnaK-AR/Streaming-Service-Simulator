#include <iostream>
#include <string>

using namespace std;

class Video {

    // Valores publicos
    public:
        // Constructor sin parametros (default)
        Video();

        // Constructor con parametros
        Video(int id, string nombre, int duracion, string genero, double calificacion);

        // Gets
        int getID();
        string getNombre();
        int getDuracion();
        string getGenero();
        double getCalificacion() { return Calificacion; }

        // Sets
        void setID(const int);
        void setNombre(const string);
        void setDuracion(const int);
        void setGenero(const string);
        void setCalificacion(const double);
       
        //Metodos
        void calificar(int c);
        virtual void imprime();

        //Sobrecarga de operadores
        bool operator> (const Video p){
            if (Calificacion > p.Calificacion) return true;
        else return false;
        }

        bool operator== (const Video p){
            if (Calificacion ==  p.Calificacion) return true;
        else return false;
        }

    // Variables protegidos
    protected:
        int ID;
        string Nombre;
        int Duracion;
        string Genero;
        double Calificacion;
        int num_cal;
};