#include <iostream>
using namespace std;

// Declaracion de clase descendiente "Pelicula", que hereda de clase base "Video"
class Pelicula : public Video {
    
    // Variables publicos
    public:

    // Constructor sin parametros (default)
        Pelicula();

    // Constructor con parametros
        Pelicula(int, string, int, string, double);

    // Método
        void imprime();
};



