#include <iostream>
using namespace std;
#include <fstream>

class Musica{
    private:
        int id;
        char nomeMusica[100];
        char nomeArtista[100];
        char estiloMusica[100];
        int tempo; //segundos
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
            os << m.nomeMusica << "\n";
            os << m.nomeArtista << "\n";
            os << m.estiloMusica << "\n";
            os << m.tempo << "\n";
            os << m.dataDia << "\n";
            os << m.dataMes << "\n";
            os << m.dataAno << "\n";
        }

        //sobrecarga do operador de extração de dados
        friend istream& operator>>(istream& is, Musica& m){
            is >> m.id 
               >> m.nomeMusica 
               >> m.nomeArtista 
               >> m.estiloMusica 
               >> m.tempo 
               >> m.dataDia 
               >> m.dataMes 
               >> m.dataAno;
            return is;
        }
};