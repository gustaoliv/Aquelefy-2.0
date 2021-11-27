#include "artista.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

Artista::Artista(){
}

Artista::Artista(char nome[], char tipo[], char estilo[]){
    id = rand() % 1000;
    strcpy(this->nome, nome);
    strcpy(this->tipo, tipo);
    strcpy(this->estilo, estilo);
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