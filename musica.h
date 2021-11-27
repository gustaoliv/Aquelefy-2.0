#include <iostream>
#include "artista.h"
using namespace std;
#include <fstream>

class Musica{
    private:
        int id;
        char nome[100];
        Artista artista;
        char estilo[100];
        int duracao; //segundos
        //data cadastro
        short dataDia;
        short dataMes;
        int dataAno;
    public:
        Musica();
        Musica(char nome[], char artista[], char estilo[], int temp);
        void printMusica();
        void printFormatado();

        //id
        int getId();
        void setId(int id);

        //nomeMusica
        string getNomeMusica();
        void setNomeMusica(string nome);

        //nomeArtista
        //string getNomeArtista();
        //void setNomeArtista(string artista);

        //estiloMusica
        //string getEstiloMusica();
        //void setEstiloMusica(string estilom);

        //tempo
        int getTempo();
        //void setTempo(int temp);

        /*Data
        Date getData();
        void setData();*/

        //sobrecarga do operador de inserção de dados
        friend ostream& operator<<(ostream& os, const Musica& m){
            os << m.id << "\n";
            os << m.nome << "\n";
            os << m.artista << "\n";
            os << m.estilo << "\n";
            os << m.duracao << "\n";
            os << m.dataDia << "\n";
            os << m.dataMes << "\n";
            os << m.dataAno << "\n";
        }

        //sobrecarga do operador de extração de dados
        friend istream& operator>>(istream& is, Musica& m){
            is >> m.id 
               >> m.nome
               >> m.artista
               >> m.estilo
               >> m.duracao 
               >> m.dataDia 
               >> m.dataMes 
               >> m.dataAno;
            return is;
        }
};