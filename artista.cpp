#include "artista.h"
#include <iostream>
#include <string.h>
using namespace std;

Artista::Artista(){
}

Artista::Artista(char nome[], char tipo[], char estilo[]){
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