// Autora: Ana Clara Loureiro Cruz
// Data: 15-05-2021

/*  TRABALHO 2 - LING PROG  */
    // Criar um catalogo de gerenciamento de filmes

/* "Catalogo.cpp" ------------------------------------------------- */
/* Contem os metodos da classe Catalogo */

#include <iostream>
#include <fstream>

#include "Catalogo.h"

using namespace std ;

// Operador <<
ostream &operator<<(ostream & output, const Catalogo & catalogo){
    output << "\tNOME\t\t\tPRODUTORA\t\tNOTA" << endl ;
    for (long unsigned int i = 0 ; i < catalogo.filmes.size() ; i++)
        output << catalogo.filmes[i] ;
    return output;
}

// Construtor
Catalogo::Catalogo(string nomeDoArquivo){
    vector <string> linhas = readLines (nomeDoArquivo);
    if (linhas.size() != 0)
        for (long unsigned int i = 0 ; i < linhas.size() ; i++)
            criaFilmes (linhas[i]);
}

// Adicionar filme
void Catalogo::operator+=(Filme& novoFilme){
    for (long unsigned int i = 0 ; i < filmes.size() ; i++)
        if (filmes[i] == novoFilme){
            cout << "O filme \"" << novoFilme.getNome() << "\" ja esta no catalogo!" << endl ;
            return ;
        }
    filmes.push_back(novoFilme);
    ordenaLista();
}

// Adicionar lista de filmes
void Catalogo::operator+=(vector <Filme>& novosFilmes){
    for (long unsigned int i = 0 ; i < novosFilmes.size() ; i++)
        (*this) += novosFilmes[i];
}

// Remover filme
void Catalogo::operator-=(Filme& filme){
    for (long unsigned int i = 0 ; i < filmes.size() ; i++)
        if (filmes[i] == filme){
            filmes.erase(filmes.begin()+i);
            return ;
        }
    cout << "Este filme nao esta no catalogo!" << endl ;
}

// Buscar um filme pelo nome
Filme* Catalogo::operator()(string nome){
    for (long unsigned int i = 0 ; i < filmes.size() ; i++)
        if (filmes[i].getNome() == nome)
            return &filmes[i];
    return NULL ;
}

// Trocar a produtora de um filme
Filme* Catalogo::operator()(string nome, string novaProdutora){
    Filme* filmeAlterado = (*this)(nome);
    if (! filmeAlterado)
        return NULL ;
    filmeAlterado->setProdutora(novaProdutora);
    return filmeAlterado;
}

// Trocar a nota de um filme
Filme* Catalogo::operator()(string nome, double novaNota){
    Filme* filmeAlterado = (*this)(nome);
    if (! filmeAlterado)
        return NULL ;
    filmeAlterado->setNota(novaNota);
    return filmeAlterado;
}

// Ordena lista
void Catalogo::ordenaLista(){
    Filme auxiliar("","", 0);
    for (long unsigned int i = 0 ; i < filmes.size() ; i++)
        for (long unsigned int j = 0 ; j < filmes.size() ; j++)
            if (filmes[j] > filmes[i]){
                auxiliar = filmes [i];
                filmes[i] = filmes[j];
                filmes[j] = auxiliar ;

            }
}

//Le um arquivo e devolve as linhas separadas em um vetor 
vector <string> Catalogo::readLines (string arquivo){

  vector <string> vetor;
  string linha;

  ifstream file(arquivo);
  
  while (getline(file, linha)) {
    vetor.push_back(linha);
  }
  return vetor;
}

// Cria os objetos a partir de uma linha do arquivo de entrada
/* Recebe uma string que representa um filme e cria o Struct associado 
ex.: se a entrada for "xmen;Universal;3.0" sera criado um Filme com nome "Xmen" produtora "Universal" nota 3.0 */
void Catalogo::criaFilmes (string linha) {
    string dado;
    long unsigned int i ;
    vector <string> vetor;

    for(i=0 ; i<=linha.length() ; i++){
        if(linha[i] != ';' && linha[i] != '\0'){
            dado.push_back(linha[i]);
        }
        else{
            vetor.push_back(dado);
            dado = "";
        }
    }

    if (vetor.size() != 3)
        cout << "ERRO !!! Parece que seu arquivo de entrada esta corrompido. "
             << "Certifique-se de que todos os filmes contem nome, produtora e nota."
             << endl ;
    else {
        Filme filme (vetor[0], vetor[1], stod(vetor[2]));
        filmes.push_back(filme);
    }
}