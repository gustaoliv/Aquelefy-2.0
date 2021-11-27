#include <iostream>
#include <fstream>
#include "musica.h"
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
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
    cout << "4 - Tempo total das musicas cadastras" << endl;
    cout << "5 - Musica com maior e menor duracao" << endl;
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
            ofstream ofs("dados.dat", ios_base::app);
            char nome[100];
            char artista[100];
            char estilo[100];
            int tempo; 
            cin.ignore();
            cout << "Nome da musica: "; gets(nome);
            cout << "Nome do artista/banda: "; gets(artista);
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
            ifstream ifs("dados.dat", ios_base::in);
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
            ifstream ifs("dados.dat", ios_base::in);
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
            Musica musica;
            int total = 0;
            ifstream ifs("dados.dat", ios_base::in);
            if(ifs.good()){
                while(ifs.read((char*)&musica, sizeof(Musica))){
                    total += musica.getTempo();
                }
            }
            cout << "O total de tempo das musicas cadastradas e: " << total << " segundos" << endl;
            ifs.close();
            getch();
        }
        else if(resp = 5){
            system("clear||cls");
            Musica musica;
            Musica maior, menor;
            ifstream ifs("dados.dat", ios_base::in);
            if(ifs.good()){
                ifs.read((char*)&musica, sizeof(Musica));
                maior = musica;
                menor = musica;
                while(ifs.read((char*)&musica, sizeof(Musica))){
                    if(musica.getTempo() > maior.getTempo()){
                        maior = musica;
                    }
                    else if(musica.getTempo() < menor.getTempo()){
                        menor = musica;
                    }
                }
                cout << "Maior musica: " << endl;
                cout << maior.getNomeMusica() << " -> " << maior.getTempo() << " segundos\n" << endl;
                
                cout << "Menor musica: " << endl;
                cout << menor.getNomeMusica() << " -> " << menor.getTempo() << " segundos\n" << endl;
            }
            ifs.close();
            getch();
        }

        else{
            cout << "OPCAO INVALIDA!!" << endl;
        }        
    }while(resp != 0);

    return 0;
}

