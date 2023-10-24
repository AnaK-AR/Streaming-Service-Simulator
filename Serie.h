#include <iostream>
using namespace std;

// Declaracion de clase descendiente "Serie", que hereda de clase base "Video"
class Serie : public Video {
    
    // Variables publicos
    public:

        // Constructor sin parametros (default)
        Serie();

        // Constructor con parametros 
        Serie(int id, string nombre, int duracion, string genero, double calificacion, int episodio, string tituloEpisodio, int temporada);

        // Getters
        int getEpisodio();
        string getTituloEp();
        int getTemporada();

        // Setters
        void setEpisodio(const int e);
        void setTituloEp(const string te);
        void setTemporada(const int t);

        //Método
        void imprime();

    // Variables privados
    private:
        int Episodio;
        string TituloEp;
        int Temporada;
};