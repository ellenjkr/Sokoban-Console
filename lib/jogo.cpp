#include "jogo.h"

void imprimeMenuPrincipal(int *menu, Cursor cursor, int linhas, int colunas){
    cout << "====SOKOBAN====" << endl << endl;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (cursor.posicao.x == i and cursor.posicao.y == j){
                cout << " o";
            }
            else if (menu[i * colunas + j] == ORIENTACOES){
                cout << " Orientacoes";
            }
            else if (menu[i * colunas + j] == JOGAR){
                cout << " Jogar";
            }
            else if (menu[i * colunas + j] == SAIR){
                cout << " Sair";
            }
            else{
                cout << " " << " ";
            }

        }
        cout << endl;
    }
    cout << "===============";
}

int escolheOpcao(int *menu, Cursor &cursor, int colunas){
    char tecla;
    int escolha = 0;

    if ( _kbhit() ){
        tecla = getch();
        switch(tecla){
            case 'w':
                if (menu[(cursor.posicao.x-1) * colunas + cursor.posicao.y] == 0){
                    cursor.posicao.x--;
                }
            break;
            case 's':
                if (menu[(cursor.posicao.x+1) * colunas + cursor.posicao.y] == 0){
                    cursor.posicao.x++;
                }
            break;
            case 'd':
                escolha = menu[cursor.posicao.x * colunas + cursor.posicao.y + 1];
            break;
        }
    }
    return escolha;
}

void imprimeOrientacoes(bool &abreMenuPrincipal){
    system("cls");
    char tecla;

    cout << "===============================================================================================" << endl << endl;
    cout << "\tAperte 'a' Para Retornar Ao Menu";
    cout << "\n\n\tSOKOBAN\n\n";
    cout << "\tO jogo:\n\t\tO Sokoban Consiste em um jogo de transporte e deposito de caixas por\n\t\tum armazem. O objetivo se baseia em, no menor numero de movimentos\n\t\tpossivel, posicionar todas as caixas nos devidos locais.";
    cout << "\n\n\tRegras:\n\t\t-Apenas uma caixa pode ser movimentada por vez.\n\t\t-Nao pode haver sobreposicao (pular outra caixa).\n\t\t-O jogador nao podera ocupar o mesmo lugar da caixa ou andar nos muros.\n\t\t-O jogo e finalizado quando todas as caixas sao depositadas.";
    cout << "\n\n\tMovimentacao:\n\t\tw: cima\n\t\ts: baixo\n\t\td: direita\n\t\ta: esquerda";
    cout << endl << endl<< "===============================================================================================";
    while(true){
        tecla = getch();
        if(tecla == 'a'){
            system("cls");
            abreMenuPrincipal = true;
            break;
        }
    }
}

void imprimeMenuJogar(Fase fase1, Fase fase2, int *menu, Cursor cursor, int linhas, int colunas){
    cout << "===== Escolha Um Mapa Para Jogar =====" << endl << endl;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (cursor.posicao.x == i and cursor.posicao.y == j){
                cout << " o";
            }
            else if (menu[i * colunas + j] == MAPA1){
                cout << " Mapa 1";
                if (fase1.finalizada == true){
                    cout << " - Completo";
                }
            }
            else if (menu[i * colunas + j] == MAPA2){
                cout << " Mapa 2";
                if (fase2.finalizada == true){
                    cout << " - Completo";
                }
            }
            else if (menu[i * colunas + j] == VOLTAR){
                cout << " Retornar ao Menu Principal";
            }
            else{
                cout << " " << " ";
            }

        }
        cout << endl;
    }
    cout << endl << "======================================";
}

void imprimeMapa(Fase fase, int *mapa, int *mapaAux, int linhas, int colunas){
    int lin, col;
    lin = 0;
    while (lin < linhas) {
        if (lin != 0) printf("\n");
        col = 0;
        while (col < colunas) {
            if (lin == fase.personagem.posicao.x and col == fase.personagem.posicao.y){
                cout << "X";
            }
            else if (mapa[lin * colunas + col] == PAREDE){
                cout << char (178);
            }
            else if (mapa[lin * colunas + col] == CAIXA and mapaAux[lin * colunas + col] == DEPOSITO){
                cout << "@";
            }
            else if (mapa[lin * colunas + col] == CAIXA){
                cout << char (219);
            }
            else if (mapaAux[lin * colunas + col] == DEPOSITO){
                cout << ".";
            }
            else if (mapa[lin * colunas + col] == VAZIO) {
                cout << " ";
            }
            col++;
        }
        lin++;
    }
    cout << "\nMovimentos: "<< fase.mov << "\nRecord: "; //Imprime os movimentos
     if (fase.auxRecord==0){ //Caso ainda nao haja record
        cout << "-";
     }
     else {
        cout <<  fase.record; //Imprime o record
     }
     cout << "\n\nRestart: r\nMenu: m" << endl;
}

void imprimeMenuFase(int *menu, Cursor cursor, int linhas, int colunas){
    cout << "===== Deseja Retornar Ao Menu Principal? =====" << endl;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (cursor.posicao.x == i and cursor.posicao.y == j){
                cout << " \t\to";
            }
            else if (menu[i * colunas + j] == SIM){
                cout << " Sim";
            }
            else if (menu[i * colunas + j] == NAO){
                cout << " Nao";
            }
            else{
                cout << " \t\t" << " ";
            }

        }
        cout << endl;
    }
    cout << endl << "==============================================";
}

void retornaMenuPrincipal(int *menuFase, Cursor &cursor, bool &abreMenuFase, bool &abreMenuPrincipal){
    system("cls");
    imprimeMenuFase(menuFase, cursor, 4, 2);
    int escolha = escolheOpcao(menuFase, cursor, 2);
    if (escolha == NAO){
        system("cls");
        abreMenuFase = false;
    }
    else if (escolha == SIM){
        system("cls");
        abreMenuFase = false;
        abreMenuPrincipal = true;
    }
}

void retornaMapaInicial(int *mapa, int *copiaMapa, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            mapa[i*colunas + j]=copiaMapa[i*colunas + j]; //mapa adquire os valores de sua cópia inicial
        }
    }
}

void reiniciaFase(Fase &fase, int *mapa, int *copiaMapa, int linhas, int colunas){
    system("cls");
    fase.personagem.posicao.x = fase.xInicial; //Posição inicial do personagem em X
    fase.personagem.posicao.y = fase.yInicial; //Posição inicial do personagem em Y
    fase.mov = 0;
    retornaMapaInicial(mapa, copiaMapa, linhas, colunas);
}

void movimentaPersonagem(Fase &fase, int *mapa, int *copiaMapa, int linhas, int colunas, bool &abreMenuFase){
    char tecla;
    if ( _kbhit() ){
        tecla = getch();
        switch(tecla){
            case 'w': //Movimentação do personagem para baixo
                if(mapa[(fase.personagem.posicao.x-1) * colunas + fase.personagem.posicao.y]==0 or mapa[(fase.personagem.posicao.x-1) * colunas + fase.personagem.posicao.y] == 3) { //Condições para o personagem se mover
                    fase.personagem.posicao.x--;
                    fase.mov++;
                }
                else if ((mapa[(fase.personagem.posicao.x-1) * colunas + fase.personagem.posicao.y] == 2 and mapa[(fase.personagem.posicao.x-2) * colunas + fase.personagem.posicao.y] == 0) or mapa[(fase.personagem.posicao.x-2) * colunas + fase.personagem.posicao.y]==3){ //Movimentação da caixa
                    mapa[(fase.personagem.posicao.x-1) * colunas + fase.personagem.posicao.y]=0;
                    mapa[(fase.personagem.posicao.x-2) * colunas + fase.personagem.posicao.y]=2;
                    fase.personagem.posicao.x--;
                    fase.mov++; //Aumenta os movimentos
                }
            break;
            case 's': //Movimentação do personagem para baixo
                if(mapa[(fase.personagem.posicao.x+1) * colunas + fase.personagem.posicao.y]==0 or mapa[(fase.personagem.posicao.x+1) * colunas + fase.personagem.posicao.y]==3) { //Condições para o personagem se mover
                fase.personagem.posicao.x++;
                fase.mov++;
                }
                else if ((mapa[(fase.personagem.posicao.x+1) * colunas + fase.personagem.posicao.y]==2 and mapa[(fase.personagem.posicao.x+2) * colunas + fase.personagem.posicao.y]==0)or mapa[(fase.personagem.posicao.x+2) * colunas + fase.personagem.posicao.y]==3){ //Movimentação da caixa
                    mapa[(fase.personagem.posicao.x+1) * colunas + fase.personagem.posicao.y]=0;
                    mapa[(fase.personagem.posicao.x+2) * colunas + fase.personagem.posicao.y]=2;
                    fase.personagem.posicao.x++;
                    fase.mov++; //Aumenta os movimentos
                }
            break;
            case 'd': //Movimentação do personagem para a direita
                if(mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+1)]==0 or mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+1)]==3) { //Condições para o personagem se mover
                    fase.personagem.posicao.y++;
                    fase.mov++;
                }
                else if ((mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+1)]==2 and mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+2)]==0)or mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+2)]==3){ //Movimentação da caixa
                    mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+1)]=0;
                    mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y+2)]=2;
                    fase.personagem.posicao.y++;
                    fase.mov++; //Aumenta os movimentos
                }
            break;
            case 'a': //Movimentação do personagem para a esquerda
                if(mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-1)]==0 or mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-1)]==3) { //Condições para o personagem se mover
                    fase.personagem.posicao.y--;
                    fase.mov++;
                }
                else if ((mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-1)]==2 and mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-2)]==0)or mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-2)]==3){ //Movimentação da caixa
                    mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-1)]=0;
                    mapa[fase.personagem.posicao.x * colunas + (fase.personagem.posicao.y-2)]=2;
                    fase.personagem.posicao.y--;
                    fase.mov++; //Aumenta os movimentos
                }
            break;
            case 'r': //Reinicia a fase
                reiniciaFase(fase, mapa, copiaMapa, linhas, colunas);
            break;
            case 'm':
                abreMenuFase = true;
        }
    }
}

void avaliaRecord(Fase &fase1){
    if (fase1.auxRecord == 0){ //define o record pela primeira vez que terminar a fase
        fase1.record = fase1.mov;
    }
    if (fase1.mov < fase1.record){ //caso o record seja batido, ele adquire o novo valor
        fase1.record = fase1.mov;
    }
    fase1.auxRecord = 1; //indica que existe um record
}

bool finalizaFase(bool &abreMenuPrincipal){
    system ("cls");
    cout << "\n\n========================="<< endl << "Fim de Jogo, Voce Venceu"<< endl <<"=========================\n\n";
    cout << "'a' Retornar Ao Menu";
    char tecla;

    while(true){
        tecla = getch();
        if(tecla == 'a'){
            system("cls");
            abreMenuPrincipal = true;
            break;
        }
    }
    bool finaliza = true; //Fase completa
    return finaliza;
}

void jogaFase1(int *menuFase, Cursor cursor, Fase &fase1, int *mapa1, int *copiaMapa1, int *mapa1Aux, int linhas, int colunas, bool &abreMenuFase, bool &abreMenuPrincipal){

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO     cursorInfo;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = false; // set the cursor visibility
            SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
            short int CX=0, CY=0;
            COORD coord;
            coord.X = CX;
            coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA

    reiniciaFase(fase1, mapa1, copiaMapa1, linhas, colunas);

    while ((mapa1[5*colunas+7]!=CAIXA or mapa1[5*colunas+8]!=CAIXA or mapa1[6*colunas+6]!=CAIXA or mapa1[6*colunas+7]!=CAIXA or mapa1[6*colunas+8]!=CAIXA or mapa1[7*colunas+7]!=CAIXA) and abreMenuPrincipal == false){
        movimentaPersonagem(fase1, mapa1, copiaMapa1, linhas, colunas, abreMenuFase);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Para não ficar reimprimindo o mapa embaixo
        imprimeMapa(fase1, mapa1, mapa1Aux, linhas, colunas);
        cursor.posicao.x = 1;
        cursor.posicao.y = 0;
        while (abreMenuFase == true){
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            retornaMenuPrincipal(menuFase, cursor, abreMenuFase, abreMenuPrincipal);
        }
    }
    if (abreMenuPrincipal == false){
        avaliaRecord(fase1);
        fase1.finalizada = finalizaFase(abreMenuPrincipal);
    }
}

void jogaFase2(int *menuFase, Cursor cursor, Fase &fase2, int *mapa2, int *copiaMapa2, int *mapa2Aux, int linhas, int colunas, bool &abreMenuFase, bool &abreMenuPrincipal){

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO     cursorInfo;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = false; // set the cursor visibility
            SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
            short int CX=0, CY=0;
            COORD coord;
            coord.X = CX;
            coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA

    reiniciaFase(fase2, mapa2, copiaMapa2, linhas, colunas);

    while ((mapa2[5*colunas+1]!=CAIXA or mapa2[4*colunas+3]!=CAIXA or mapa2[4*colunas+4]!=CAIXA) and abreMenuPrincipal == false){
        movimentaPersonagem(fase2, mapa2, copiaMapa2, linhas, colunas, abreMenuFase);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Para não ficar reimprimindo o mapa embaixo
        imprimeMapa(fase2, mapa2, mapa2Aux, linhas, colunas);
        cursor.posicao.x = 1;
        cursor.posicao.y = 0;
        while (abreMenuFase == true){
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            retornaMenuPrincipal(menuFase, cursor, abreMenuFase, abreMenuPrincipal);
        }
    }
    if (abreMenuPrincipal == false){
        avaliaRecord(fase2);
        fase2.finalizada = finalizaFase(abreMenuPrincipal);
    }
}
