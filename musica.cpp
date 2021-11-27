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
    strcpy(this->nome, nome);
    strcpy(this->estilo, estilo);
    duracao = temp;
    time_t mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    dataAno = tm.tm_year + 1900;
    dataMes = tm.tm_mon + 1;
    dataDia = tm.tm_mday;
}

void Musica::printMusica(){
    cout << "Id: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Artista: " << artista.getNome() << endl;
    cout << "Estilo: " << estilo << endl;
    cout << "Duracao: " << duracao << " segundos"<< endl;
    cout << "Data: " << dataDia << "/" << dataMes << "/" << dataAno << endl;
}
void Musica::printFormatado(){
    cout << setw(5) << left << id << " | " << setw(50) << left << nome << " | "  << setw(50) << left << artista.getNome()  << " | " << setw(50) << left << estilo  << " | " << setw(20) << left << duracao << " | " << dataDia << "/" << dataMes << "/" << dataAno << "       | " << endl;

}

int Musica::getId(){
    return id;
}

int Musica::getTempo(){
    return duracao;
}

string Musica::getNomeMusica(){
    return nome;
}