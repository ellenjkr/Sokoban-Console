#ifndef JOGO_SOKOBAN_
#define JOGO_SOKOBAN_

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

enum Componentes{
        VAZIO,
        PAREDE,
        CAIXA,
        DEPOSITO
};

struct Coordenada{
    int x = 0;
    int y = 0;
};

struct Personagem{
    Coordenada posicao;
};

struct Fase{
    Personagem personagem;
    int xInicial = 0;
    int yInicial = 0;
    int record = 0;
    int auxRecord = 0;
    int mov = 0;
    bool finalizada = false;
};

enum MenuPrincipal{
    NADA,
    ORIENTACOES,
    JOGAR,
    SAIR
};

enum MenuJogar{
    MAPA1 = 1,
    MAPA2,
    VOLTAR
};

enum MenuFase{
    SIM = 1,
    NAO
};

struct Coordenadas{
    int x = 0;
    int y = 0;
};

struct Cursor{
    Coordenadas posicao;
};

void imprimeMenuPrincipal(int *menu, Cursor cursor, int linhas, int colunas);

int escolheOpcao(int *menu, Cursor &cursor, int colunas);

void imprimeOrientacoes(bool &abreMenuPrincipal);

void imprimeMenuJogar(Fase fase1, Fase fase2, int *menu, Cursor cursor, int linhas, int colunas);

void imprimeMapa(Fase fase, int *mapa, int *mapaAux, int linhas, int colunas);

void imprimeMenuFase(int *menu, Cursor cursor, int linhas, int colunas);

void retornaMenuPrincipal(int *menuFase, Cursor &cursor, bool &abreMenuFase, bool &abreMenuPrincipal);

void retornaMapaInicial(int *mapa, int *copiaMapa, int linhas, int colunas);

void reiniciaFase(Fase &fase, int *mapa, int *copiaMapa, int linhas, int colunas);

void movimentaPersonagem(Fase &fase, int *mapa, int *copiaMapa, int linhas, int colunas, bool &abreMenuFase);

void avaliaRecord(Fase &fase1);

bool finalizaFase(bool &abreMenuPrincipal);

void jogaFase1(int *menuFase, Cursor cursor, Fase &fase1, int *mapa1, int *copiaMapa1, int *mapa1Aux, int linhas, int colunas, bool &abreMenuFase, bool &abreMenuPrincipal);

void jogaFase2(int *menuFase, Cursor cursor, Fase &fase2, int *mapa2, int *copiaMapa2, int *mapa2Aux, int linhas, int colunas, bool &abreMenuFase, bool &abreMenuPrincipal);

#endif
