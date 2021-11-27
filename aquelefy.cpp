#include <iostream>
#include <fstream>
#include "musica.h"
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;

int menu(){
    system("clear||cls");
    int resp;
    cout << "--------------------------------------------------" << endl;
    cout << "                  AQUELEFY MUSIC                  " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "0 - Fechar o programa" << endl;
    cout << "1 - Cadastrar musica" << endl;
    cout << "2 - Listar musicas cadastradas" << endl;
    cout << "3 - Pesquisar musica" << endl;
    cout << "4 - Listar artistas disponiveis" << endl;
    cout << "5 - Cadastrar novo artista" << endl;
    cout << "\nEscolha sua opcao: "; cin >> resp;
    return resp;
}

int main(){
    int resp;
    do{
        resp = menu();
        if (resp == 0){
            cout << "ENCERRANDO O PROGRAMA..." << endl;
            break;
        }
        else if (resp == 1){
            system("clear||cls");
            cout << "\n------------------------------------------- CADASTRAR MUSICA -------------------------------------------\n";
            
            char nome[100];
            Artista artista;
            char estilo[100];
            int tempo; 

            char quer[3];
            cout << "Voce ja sabe o ID do cantor? (sim/nao) "; cin >> quer;
            if(strcmp(quer, "nao") == 0 || strcmp(quer, "NAO") == 0 || strcmp(quer, "Nao") == 0){
                ifstream ifs("artistas.dat", ios_base::in);
                Artista artistaTemp;
                cout << "\n\n\n";
                cout << setw(5) << left << "ID" << " | " << setw(50) << left << "NOME DO ARTISTA" << " | "  << setw(50) << left << "TIPO"  << " | " << setw(50) << left << "ESTILO"  << " | " << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                if(ifs.good()){
                    while(ifs.read((char*)&artistaTemp, sizeof(Artista))){
                        artistaTemp.printFormatado();
                    }
                }
                ifs.close();
                
                char tem[3];
                cout << "\n\n\n";
                cout << "O artista ja esta listado? (sim/nao) "; cin >> tem;

                if(strcmp(tem, "sim") == 0){
                    int id;
                    cout << "Qual o ID do artista que ira cadastrar a musica: "; cin >> id;
                    ifstream ifs("artistas.dat", ios_base::in);
                    while(ifs.read((char*)&artistaTemp, sizeof(Artista))){
                        if(artistaTemp.getId() == id){
                            artista = artistaTemp;
                        }
                    }
                    ifs.close();
                }
                else{
                    cout << "\n\n\n";
                    cout << "\n------------------------------------------- CADASTRAR ARTISTA -------------------------------------------\n";
                    ofstream ofs("artistas.dat", ios_base::app);
                    char nome[100];
                    char tipo[100];
                    char estilo[100];
                    cin.ignore();
                    cout << "Nome do artista/banda: "; gets(nome);
                    cout << "Tipo de artista(dupla, banda, solo, trio): "; gets(tipo);
                    cout << "Estilo ";
                    if(strcmp(tipo, "banda") == 0)
                        cout << "da banda: ";
                    else if(strcmp(tipo, "solo") == 0)
                        cout << "do cantor: ";
                    else if(strcmp(tipo, "dupla") == 0)
                        cout << "da dupla: ";
                    else
                        cout << "do artista: "; 
                    gets(estilo);

                    Artista artistaTemp(nome, tipo, estilo);

                    ofs.write((char *)&artistaTemp, sizeof(Artista));
                    artista = artistaTemp;
                    ofs.close();
                    cout << "\nCADASTRADO COM SUCESSO...\n";
                }
            }
            else{
                int id;
                Artista artistaTemp;
                cout << "Qual o ID do artista que ira cadastrar a musica: "; cin >> id;
                ifstream ifs("artistas.dat", ios_base::in);
                while(ifs.read((char*)&artistaTemp, sizeof(Artista))){
                    if(artistaTemp.getId() == id){
                        artista = artistaTemp;
                    }
                }
                ifs.close();
            }


            ofstream ofs("musicas.dat", ios_base::app);
            cin.ignore();

            cout << "Nome da musica: "; gets(nome);
            cout << "Estilo da musica: "; gets(estilo);
            cout << "Duracao da musica (s): "; cin >> tempo;

            
            Musica musica(nome, artista, estilo, tempo);

            ofs.write((char *)&musica, sizeof(Musica));

            cout << "\nCADASTRADA COM SUCESSO...\n";
            getch();

            ofs.close();
        }
        else if(resp == 2){
            system("clear||cls");
            //cout << "\n------------------------------------------- MUSICAS  CADASTRADAS -------------------------------------------\n\n";
            cout << setw(5) << left << "ID" << " | " << setw(50) << left << "NOME DA MUSICA" << " | "  << setw(50) << left << "NOME DO ARTISTA/BANDA"  << " | " << setw(50) << left << "ESTILO"  << " | " << setw(20) << left << "DURACAO (S)"  << " | " << setw(10) << left << "DATA DE CADASTRO" << " | " << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            Musica musica;
            ifstream ifs("musicas.dat", ios_base::in);
            if(ifs.good()){
                while(ifs.read((char*)&musica, sizeof(Musica))){
                    musica.printFormatado();
                    //cout << "--------------------------------------------------------------------------------------------------------" << endl;
                }
                ifs.close();
            }
            getch();
        }
        else if(resp == 3){
            int id;
            system("clear||cls");
            cout << "Digite o ID da musica: "; cin >> id;
            Musica musica;
            int achou = 0;
            ifstream ifs("musicas.dat", ios_base::in);
            if(ifs.good()){
                while(ifs.read((char*)&musica, sizeof(Musica))){
                    if(musica.getId() == id){
                        cout << "Musica encontrada: \n" << id << endl;
                        musica.printMusica();
                        achou = 1;
                    }
                }

                if(achou == 0){
                    cout << "Musica nao encontrada!" << endl;
                
                }
            }
            ifs.close();
            getch();
        }
        else if(resp == 4){
            system("clear||cls");
            ifstream ifs("artistas.dat", ios_base::in);
            Artista artista;
            cout << setw(5) << left << "ID" << " | " << setw(50) << left << "NOME DO ARTISTA" << " | "  << setw(50) << left << "TIPO"  << " | " << setw(50) << left << "ESTILO"  << " | " << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            if(ifs.good()){
                while(ifs.read((char*)&artista, sizeof(Artista))){
                    artista.printFormatado();
                }
            }
            ifs.close();
            getch();
        }
        else if(resp = 5){
            system("clear||cls");
            cout << "\n------------------------------------------- CADASTRAR ARTISTA -------------------------------------------\n";
            ofstream ofs("artistas.dat", ios_base::app);
            char nome[100];
            char tipo[100];
            char estilo[100];
            cin.ignore();
            cout << "Nome do artista/banda: "; gets(nome);
            cout << "Tipo de artista(dupla, banda, solo, trio): "; gets(tipo);
            cout << "Estilo ";
            if(strcmp(tipo, "banda") == 0)
                cout << "da banda: ";
            else if(strcmp(tipo, "solo") == 0)
                cout << "do cantor: ";
            else if(strcmp(tipo, "dupla") == 0)
                cout << "da dupla: ";
            else
                cout << "do artista: "; 
            gets(estilo);

            Artista artista(nome, tipo, estilo);

            ofs.write((char *)&artista, sizeof(Artista));

            ofs.close();
            cout << "\nCADASTRADO COM SUCESSO...\n";
            getch();
        }

        else{
            cout << "OPCAO INVALIDA!!" << endl;
        }        
    }while(resp != 0);

    return 0;
}

