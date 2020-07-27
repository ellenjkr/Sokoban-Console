#include <iostream>
#include "jogo.h"

using namespace std;


int main(){

    ///INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO     cursorInfo;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = false; // set the cursor visibility
            SetConsoleCursorInfo(out, &cursorInfo);
    ///FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    ///INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
            short int CX=0, CY=0;
            COORD coord;
            coord.X = CX;
            coord.Y = CY;
    ///FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA

    Fase fase1, fase2;
    Cursor cursor;

    fase1.xInicial = fase1.personagem.posicao.x = 1;
    fase1.yInicial = fase1.personagem.posicao.y = 7;

    fase2.xInicial = fase2.personagem.posicao.x = 2;
    fase2.yInicial = fase2.personagem.posicao.y = 3;

    int menuPrincipal[4][2] = {{ 0, 1},
                               { 0, 2},
                               { 0, 3},
                               {-1,-1}};

    int menuJogar[3][2]={{0,1},
                         {0,2},
                         {0,3}};

    int menuFase[4][2]={{-1,-1},
                        { 0, 1},
                        { 0, 2},
                        {-1,-1}};

    int mapa1[9][10] = {{0,0,0,0,0,0,1,1,1,1},
                        {1,1,1,1,1,1,1,0,0,1},
                        {1,0,0,0,1,0,0,0,0,1},
                        {1,0,0,0,2,0,0,2,0,1},
                        {1,1,0,1,1,2,1,0,1,1},
                        {0,1,0,0,2,0,1,2,0,1},
                        {0,1,1,0,0,2,0,0,0,1},
                        {0,0,1,0,0,0,1,0,0,1},
                        {0,0,1,1,1,1,1,1,1,1}};

    int mapa1Aux[9][10] = {{0,0,0,0,0,0,1,1,1,1},
                           {1,1,1,1,1,1,1,0,0,1},
                           {1,0,0,0,1,0,0,0,0,1},
                           {1,0,0,0,2,0,0,2,0,1},
                           {1,1,0,1,1,2,1,0,1,1},
                           {0,1,0,0,2,0,1,3,3,1},
                           {0,1,1,0,0,2,3,3,3,1},
                           {0,0,1,0,0,0,1,3,0,1},
                           {0,0,1,1,1,1,1,1,1,1}};

    int copiaMapa1[9][10] = {{0,0,0,0,0,0,1,1,1,1},
                             {1,1,1,1,1,1,1,0,0,1},
                             {1,0,0,0,1,0,0,0,0,1},
                             {1,0,0,0,2,0,0,2,0,1},
                             {1,1,0,1,1,2,1,0,1,1},
                             {0,1,0,0,2,0,1,2,0,1},
                             {0,1,1,0,0,2,0,0,0,1},
                             {0,0,1,0,0,0,1,0,0,1},
                             {0,0,1,1,1,1,1,1,1,1}};

    int mapa2[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,1,0,0,0,0,0,0,1},
                         {1,0,1,2,1,1,0,0,1,1},
                         {1,0,0,0,0,0,2,1,0,1},
                         {1,0,0,0,1,1,0,0,0,1},
                         {1,1,0,1,0,0,2,0,0,1},
                         {1,1,0,0,0,1,1,0,1,1},
                         {1,1,1,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,1,1,1,1}};

    int mapa2Aux[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,0,1},
                            {1,0,1,0,0,0,0,0,0,1},
                            {1,0,1,2,1,1,0,0,1,1},
                            {1,0,0,3,3,0,2,1,0,1},
                            {1,3,0,0,1,1,0,0,0,1},
                            {1,1,0,1,0,0,2,0,0,1},
                            {1,1,0,0,0,1,1,0,1,1},
                            {1,1,1,0,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1,1,1,1}};

    int copiaMapa2[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                              {1,0,0,0,0,0,0,0,0,1},
                              {1,0,1,0,0,0,0,0,0,1},
                              {1,0,1,2,1,1,0,0,1,1},
                              {1,0,0,0,0,0,2,1,0,1},
                              {1,0,0,0,1,1,0,0,0,1},
                              {1,1,0,1,0,0,2,0,0,1},
                              {1,1,0,0,0,1,1,0,1,1},
                              {1,1,1,0,0,0,0,0,0,1},
                              {1,1,1,1,1,1,1,1,1,1}};

    int escolha;
    bool abreMenuPrincipal = true, abreMenuJogar = false, abreMenuFase = false, sair = false;
    while (sair == false){

        while (abreMenuPrincipal == true){
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            imprimeMenuPrincipal(menuPrincipal[0], cursor, 4, 2);
            escolha = escolheOpcao(menuPrincipal[0], cursor, 2);
            if (escolha == ORIENTACOES){
                abreMenuPrincipal = false;
                imprimeOrientacoes(abreMenuPrincipal);
                break;
            }
            else if (escolha == JOGAR){
                system("cls");
                abreMenuPrincipal = false;
                abreMenuJogar = true;
                cursor.posicao.x = 0;
                cursor.posicao.y = 0;
                while(abreMenuJogar == true){
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    imprimeMenuJogar(fase1, fase2, menuJogar[0], cursor, 3, 2);
                    escolha = escolheOpcao(menuJogar[0], cursor, 2);
                    if (escolha == MAPA1){
                        system("cls");
                        abreMenuJogar = false;
                        jogaFase1(menuFase[0], cursor, fase1, mapa1[0], copiaMapa1[0], mapa1Aux[0], 9, 10, abreMenuFase, abreMenuPrincipal);

                    }
                    else if (escolha == MAPA2){
                        system("cls");
                        abreMenuJogar = false;
                        jogaFase2(menuFase[0], cursor, fase2, mapa2[0], copiaMapa2[0], mapa2Aux[0], 10, 10, abreMenuFase, abreMenuPrincipal);
                    }
                    else if (escolha == VOLTAR){
                        system("cls");
                        cursor.posicao.x = 0;
                        cursor.posicao.y = 0;
                        abreMenuJogar = false;
                        abreMenuPrincipal = true;
                    }
                }
                break;
            }
            else if (escolha == SAIR){
                sair = true;
                break;
            }
        }
    }
}





