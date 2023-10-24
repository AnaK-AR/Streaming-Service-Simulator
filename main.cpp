//Programa elaborado por Carolina de los Santos, Ana Karina Aramoni y Daniel Ríos

#include "Video.cpp"
#include "Serie.cpp"
#include "Pelicula.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Función para leer enteros del teclado
int get_int()
{
    int value;
    if (cin>>value) return value;
    cout << "please enter en integer: ";
    cin.clear();
    cin.ignore( 1000000, '\n' );
    return get_int();
}

//Función para leer cadenas del teclado
string read_string(string prompt)
{
    string txt;
    cout << prompt;
    cin >> ws;
    getline(cin,txt);
    return txt;
}

//Función para cargar las bases de datos
void cargarDatos(vector<Pelicula> &pelicula, vector<Serie> &serie) {
	string name_m = "movies.csv";
	vector<vector<string> > content_m;
	vector<string> row;
	string line, word;
	fstream file (name_m, ios::in);
	if(file.is_open()) {
		while(getline(file, line))
		{
			row.clear();
			stringstream str(line);
			while(getline(str, word, ',')) row.push_back(word);
			content_m.push_back(row);
		}
	}
	else cout << "Imposible abrir el archivo de peliculas\n";       
//-----------------------------------------------------------------
    int num_movies = content_m.size();
    cout << "Se leyeron " << num_movies << " peliculas" << endl;
	for(int i=0; i<content_m.size(); i++) {
        Pelicula p(0," ",0," ",0.0);
        p.setID(stoi(content_m[i][0]));
        p.setNombre(content_m[i][1]);
        p.setDuracion(stoi(content_m[i][2]));
        p.setGenero(content_m[i][3]);
        p.setCalificacion(stof(content_m[i][4]));
        p.imprime();
        pelicula.push_back(p);

	}
//-----------------------------------------------------------    

	string name_s = "series.csv";
	vector<vector<string> > content_s;
	fstream file_s (name_s, ios::in);
	if(file_s.is_open()) {
		while(getline(file_s, line))
		{
			row.clear();
			stringstream str(line);
			while(getline(str, word, ',')) row.push_back(word);
			content_s.push_back(row);
		}
	}
	else cout << "Imposible abrir el archivo de series\n";       
//------------------------------------------------------------
    int num_series = content_s.size();
    cout << "Se leyeron " << num_series << " episodios" << endl;
	for(int i=0; i<content_s.size();/*i<num_series;*/ i++) {
        Serie s(0,"",0,"",0.0,0,"",0);
        s.setID(stoi(content_s[i][0]));
        s.setNombre(content_s[i][1]);
        s.setDuracion(stoi(content_s[i][6]));
        s.setGenero(content_s[i][2]);
        s.setCalificacion(stof(content_s[i][7]));
        s.setEpisodio(stoi(content_s[i][4]));
        s.setTituloEp(content_s[i][5]);
        s.setTemporada(stoi(content_s[i][3]));
        s.imprime();
        serie.push_back(s);
	}
//-----------------------------------------------------------
}

//Función para filtrar videos por genero
void filtrarGen(const vector<Pelicula> pelicula, const vector<Serie> serie) {
    vector<Video> video;
    for(int i=0; i<pelicula.size(); i++) video.push_back(pelicula[i]);
    for(int i=0; i<serie.size(); i++) video.push_back(serie[i]);
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Videos filtrados por género" << endl;
    string gen = read_string("Ingresa género: ");
    cout << endl << "Coincidencias..." << endl;
    for(int i=0; i<video.size(); i++) {
        if(video[i].getGenero() == gen) {
            video[i].imprime();
        }
    }
}

//Función para filtrar videos por calificación
void filtrarCali(const vector<Pelicula> pelicula, const vector<Serie> serie) {
    vector<Video> video;
    for(int i=0; i<pelicula.size(); i++) video.push_back(pelicula[i]);
    for(int i=0; i<serie.size(); i++) video.push_back(serie[i]);
    cout << endl <<"-------------------------" << endl;
    cout << endl << "Videos filtrados por calificación" << endl;
    cout << "Ingresa calificación: ";
    int cal = get_int();
    cout << endl << "Coincidencias..." << endl;
    for(int i=0; i<video.size(); i++) {
        if(int(video[i].getCalificacion()) == cal) {
            video[i].imprime();
        }
    }
}

//Función para filtrar peliculas por calificación
void filtrarPCali(const vector<Pelicula> pelicula) {
    vector<Video> video;
    for(int i=0; i<pelicula.size(); i++) video.push_back(pelicula[i]);
    cout << endl <<"-------------------------" << endl;
    cout << endl << "Peliculas filtradas por calificación" << endl;
    cout << "Ingresa calificación: ";
    int Pcal = get_int(); 
    cout << endl << "Coincidencias..." << endl;
    for(int i=0; i<video.size(); i++) {
        if(int(video[i].getCalificacion()) == Pcal) {
            video[i].imprime();
        }
    }
}

//Función para filtrar peliculas por calificación
void filtroEpisodios(vector<Serie> &serie) {
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Filtrado de episodios" << endl;
    string nombre = read_string("Ingresa nombre de la serie: ");
    string scalificacion = read_string("Ingresa calificacion: ");
    int calificacion = stoi(scalificacion);
    cout << "Buscando coincidencias..." << endl;
    for(int i=0; i<serie.size(); i++) {
        if(serie[i].getNombre() == nombre && int(serie[i].getCalificacion()) == calificacion)
            serie[i].imprime();
    }
}

//Funcion para asignar calificaciones a los videos (episodios o peliculas)
void calificarVideo(vector<Pelicula> &pelicula, vector<Serie> &serie) {
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Calificar video" << endl;
    string nombre = read_string("Nombre del video a calificar: ");
    cout << "Buscando coincidencias..." << endl;
    for(int i=0; i<pelicula.size(); i++) {
        if(pelicula[i].getNombre() == nombre) {
            cout << "Coincidencia encontrada." << endl;
            pelicula[i].imprime();
            cout << "Puntuacion actual: " << pelicula[i].getCalificacion() << endl;
            cout << "Puntuacion a asignar (1-5): ";
            int p = get_int();
            pelicula[i].calificar(p);
            cout << "Nueva puntuacion: " << pelicula[i].getCalificacion() << endl;
        }
    }
    for(int i=0; i<serie.size(); i++) {
        if(serie[i].getNombre() == nombre) {
            cout << "Coincidencia encontrada." << endl;
            serie[i].imprime();
            cout << "Puntuacion actual: " << serie[i].getCalificacion() << endl;
            cout << "Puntuacion a asignar (1-5): ";
            int p = get_int();
            serie[i].calificar(p);
            cout << "Nueva puntuacion: " << serie[i].getCalificacion() << endl;
        }
    }
}

//Función para comparar peliculas
void CompararP(vector<Pelicula> &pelicula) {
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Comparar Calificaciones - Peliculas" << endl;
    string nombreP1 = read_string("Ingresa nombre de la primera pelicula: ");
    string nombreP2 = read_string("Ingresa nombre de la segunda pelicula: "); 
    Pelicula p1, p2;
    bool existe1 = false, existe2 = false;  
    for(int i=0; i<pelicula.size(); i++) {
        if(pelicula[i].getNombre() == nombreP1){
            p1 = pelicula[i];
            existe1 = true;
        }
        if(pelicula[i].getNombre() == nombreP2){
            p2 = pelicula[i];
            existe2 = true;
        }
    }
    if (existe1 && existe2) {
        if(p1 > p2)
            cout << " La pelicula 1 está mejor valorada  " << endl;
        else if (p1 == p2) 
            cout << " las peliculas tienen la misma valoración " << endl;
        else 
            cout << " La pelicula 2 está mejor valorada " << endl;
    }
}

//Función para comparar capitulos de serie
void CompararS(vector<Serie> &serie) {
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Comparar Calificaciones - Episodios" << endl;
    string nombreS1 = read_string("Ingresa nombre del primer capitulo: ");
    string nombreS2 = read_string("Ingresa nombre del segundo capitulo: "); 
    Serie s1, s2;
    bool existe1 = false, existe2 = false;  
    for(int i=0; i<serie.size(); i++) {
        if(serie[i].getTituloEp() == nombreS1){
            s1 = serie[i];
            existe1 = true;
        }
        if(serie[i].getTituloEp() == nombreS2){
            s2 = serie[i];
            existe2 = true;
        }
    }
    if (existe1 && existe2) {
        if(s1 > s2)
            cout << " El capitulo 1 está mejor valorado  " << endl;
        else if (s1 == s2) 
            cout << " Los capitulos tienen la misma valoración " << endl;
        else 
            cout << " El capitulo 2 está mejor valorado " << endl;
    }
}

//Función para comparar peliculas y capitulos de serie
void CompararPS(vector<Pelicula> &pelicula, vector<Serie> &serie) {
    cout << endl <<"-------------------------" << endl;
    cout << endl <<"Comparar Calificaciones " << endl;
    string nombreP1 = read_string("Ingresa nombre de la pelicula: ");
    string nombreS1 = read_string("Ingresa nombre del capitulo: "); 
    Serie s1;
    Pelicula p1;
    bool existe1 = false, existe2 = false;  
    for(int i=0; i<pelicula.size(); i++) {
        if(pelicula[i].getNombre() == nombreP1){
            p1 = pelicula[i];
            existe1 = true;
        }
    }
    for(int i=0; i<serie.size(); i++) {
        if(serie[i].getTituloEp() == nombreS1){
            s1 = serie[i];
            existe2 = true;
        }
    }
    if (existe1 && existe2) {
        if(p1 > s1)
            cout << " La pelicula está mejor valorada  " << endl;
        else if (p1 == s1) 
            cout << " La pelicula y el capitulo tienen la misma valoración " << endl;
        else 
            cout << " El capitulo está mejor valorado " << endl;
    }
}


int main()
{
    //Vectores donde se almacenan los colección de peliculas
	vector<Pelicula> pelicula;

    //Vectores donde se almacenan los colección de series y capitulos
    vector<Serie> serie;

    //Menú
    int op = 1;
    int op2 = 1;
    int op6 = 1;
    while(op != 0) {
        cout << endl <<"-------------------------" << endl;
        cout << endl <<" Menu plataforma " << endl;
        cout << endl <<"1. Cargar datos" << endl;
        cout << "2. Filtrar videos por género o calificación" << endl;
        cout << "3. Filtrar episodios de una serie por calificación" << endl;
        cout << "4. Filtrar peliculas por calificación" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "6. Comparar video" << endl;
        cout << "0. Salir" << endl;
        cout << "Escoge una opción: ";
        cin >> op;
        switch(op) {
            case 1:
                cargarDatos(pelicula, serie);
                break;
            case 2:
                op2 = 1;
                while(op2 != 0) {
                    cout << endl <<"-------------------------" << endl;
                    cout << endl <<" Menú videos" << endl;
                    cout << endl <<"1. Videos por género" << endl;
                    cout << "2. Videos por calificación" << endl;
                    cout << "0. Salir" << endl;
                    cout << "Escoge una opción: ";
                    op2 = get_int();
                    switch(op2) {
                        case 1:
                            filtrarGen(pelicula, serie);
                            break; 
                        case 2:
                            filtrarCali(pelicula, serie);
                            break;
                        case 0:
                            break; 
                    }
                }                           
                break;
            case 3:
                filtroEpisodios(serie);
                break;
            case 4:
                filtrarPCali(pelicula);
                break;
            case 5:
                calificarVideo(pelicula,serie);
                break;
            case 6:
                op6 = 1;
                while(op6 != 0) {
                    cout << endl <<"-------------------------" << endl;
                    cout << endl <<" Menú videos" << endl;
                    cout << endl <<"1. Comparar peliculas" << endl;
                    cout << "2. Comparar series" << endl;
                    cout << "3. Comparar pelicula con capitulo" << endl;
                    cout << "0. Salir" << endl;
                    cout << "Escoge una opción: ";
                    op6 = get_int();
                    switch(op6) {
                        case 1:
                            CompararP(pelicula);
                            break; 
                        case 2:
                            CompararS(serie);
                            break; 
                        case 3:
                            CompararPS(pelicula, serie);
                            break; 
                        case 0:
                            break; 
                    }
                }
                break;   
            case 0:
                break;
        }
        cout << endl;
    }
	
    return 0;
}