#include <iostream>
#include <fstream>
using namespace std;

class Artista{
    private:
        int id;
        char nome[100];
        char tipo[100]; //banda, cantor solo, dupla, trio
        char estilo[100]; //sertanejo, funk, forro
    public:
        Artista();
        Artista(char nome[], char tipo[], char estilo[]);
        void printFormatado();

        int getId();


        //nome
        string getNome();
        void setNome(char nome[]);

        //tipo
        string getTipo();
        void setTipo(char tipo[]);

        //estilo
        string getEstilo();
        void setEstilo(char estilo[]);


        friend ostream& operator<<(ostream& os, const Artista& a){
            os << a.nome << "\n";
            os << a.tipo << "\n";
            os << a.estilo << "\n";
        }

        friend istream& operator>>(istream& is, Artista& a){
            is >> a.nome
               >> a.tipo
               >> a.estilo;

            return is;
        }
};

