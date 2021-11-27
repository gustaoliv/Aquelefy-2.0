#include "musica.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

Musica::Musica(){
}

Musica::Musica(char nome[], char artista[], char estilo[], int temp){
    id = rand() % 1000;
    strcpy(nomeMusica, nome);
    strcpy(nomeArtista, artista);
    strcpy(estiloMusica, estilo);
    tempo = temp;
    time_t mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    dataAno = tm.tm_year + 1900;
    dataMes = tm.tm_mon + 1;
    dataDia = tm.tm_mday;
}

void Musica::printMusica(){
    cout << "Id: " << id << endl;
    cout << "Nome: " << nomeMusica << endl;
    cout << "Artista: " << nomeArtista << endl;
    cout << "Estilo: " << estiloMusica << endl;
    cout << "Duracao: " << tempo << " segundos"<< endl;
    cout << "Data: " << dataDia << "/" << dataMes << "/" << dataAno << endl;
}
void Musica::printFormatado(){
    cout << setw(5) << left << id << " | " << setw(50) << left << nomeMusica << " | "  << setw(50) << left << nomeArtista  << " | " << setw(50) << left << estiloMusica  << " | " << setw(20) << left << tempo << " | " << dataDia << "/" << dataMes << "/" << dataAno << "       | " << endl;

}

int Musica::getId(){
    return id;
}

int Musica::getTempo(){
    return tempo;
}

string Musica::getNomeMusica(){
    return nomeMusica;
}