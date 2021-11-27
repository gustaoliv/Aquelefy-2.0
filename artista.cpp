#include "artista.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

Artista::Artista(){
}

int verificaId(int id){
    Artista artistaTemp;
    ifstream ifs("artistas.dat", ios_base::in);
    int ok = 0;
    while(ifs.read((char*)&artistaTemp, sizeof(Artista))){
        if (artistaTemp.getId() == id){
            ok = 1;
        } 
    }
    ifs.close();
    return ok;
}

Artista::Artista(char nome[], char tipo[], char estilo[]){
    
    do{
        id = rand() % 1000;
    }while(verificaId(id) != 0);

    strcpy(this->nome, nome);
    strcpy(this->tipo, tipo);
    strcpy(this->estilo, estilo);
}

int Artista::getId(){
    return id;
}

string Artista::getNome(){
    return nome;
}

void Artista::setNome(char nome[]){
    strcpy(this->nome, nome);
}

string Artista::getTipo(){
    return tipo;
}

void Artista::setTipo(char tipo[]){
    strcpy(this->tipo, tipo);
}


string Artista::getEstilo(){
    return estilo;
}

void Artista::setEstilo(char estilo[]){
    strcpy(this->estilo, estilo);
}

 void Artista::printFormatado(){
    cout << setw(5) << left << id << " | " << setw(50) << left << nome << " | "  << setw(50) << left << tipo  << " | " << setw(50) << left << estilo  << " | " << endl;

 }