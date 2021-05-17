// Autora: Ana Clara Loureiro Cruz
// Data: 15-05-2021

/*  TRABALHO 2 - LING PROG  */
    // Criar um catalogo de gerenciamento de filmes

/* "main.cpp" ------------------------------------------------- */
/* Funcao principal que contem o menu do programa */

#define OK                      0

#define NOME_ARQUIVO_CATALOGO   "Catalogo.txt"

#include <iostream>
#include "Catalogo.h"

using namespace std ;

int main (){
    int opcaoMenu;

    Catalogo catalogo(NOME_ARQUIVO_CATALOGO);

    // Menu de entrada:
    cout << " ______________________________________________________" << endl;
    cout << "| 1 | Exibir Catalogo em ordem alfabetica             |" << endl;
    cout << "| 2 | Inserir filme no catalogo                       |" << endl;
    cout << "| 3 | Inserir varios filmes no catalogo               |" << endl;
    cout << "| 4 | Remover um filme do catalogo                    |" << endl;
    cout << "| 5 | Buscar um filme                                 |" << endl;
    cout << "| 6 | Editar um filme                                 |" << endl;
    cout << "| 7 | Exibir filme mais bem avaliado                  |" << endl;
    cout << "| 8 | Sair e salvar dados                             |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "O que deseja? (digite o numero) -> ";
    cin >> opcaoMenu ;
    cin.ignore();
    cout << endl;

    if (opcaoMenu == 1)
        cout << catalogo ;
    
    else if (opcaoMenu == 2){
        Filme filme ;
        cout << "Escreva [Nome do filme] ENTER [Produtora] ENTER [nota] ENTER :\t" ;
        cin >> filme ;
        catalogo += filme ;
        cout << "Filme adicionado com sucesso!!" << endl ;
    }

    else {
        cout << "ENTRADA INVALIDA escolha um numero de 1 a 8 !!" << endl;
        main ();
    }

    catalogo.escreverArquivo();

    cout << endl;
    return OK ;
}