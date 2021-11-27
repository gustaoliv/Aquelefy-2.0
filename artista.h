#include <iostream>
using namespace std;

class Artista{
    private:
        char nome[100];
        char tipo[100]; //banda, cantor solo, dupla, trio
        char estilo[100]; //sertanejo, funk, forro
    public:
        Artista();
        Artista(char nome[], char tipo[], char estilo[]);

        //nome
        string getNome();
        void setNome(char nome[]);

        //tipo
        string getTipo();
        void setTipo(char tipo[]);

        //tipo
        string getTipo();
        void setTipo(char tipo[]);

        //estilo
        string getEstilo();
        void setEstilo(char estilo[]);
};

