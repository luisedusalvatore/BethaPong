#ifndef INTERACOES_HPP
#define INTERACOES_HPP
#include <raylib.h>
#include <iostream>
#include "coisas.hpp"
#include "player.hpp"
#include "orbe.hpp"
using namespace std;
void detectar_colisoes(Player *player, Orbe *orbe){
    if(CheckCollisionRecs(player->getRectangle(), orbe->getRectangle())){
        orbe->bate_raquete(player->getVel(), player->getSentido());
    }
}
void inicio_desenha_texto(){
    int tam = 60;
    const char* texto = "Para inciar o jogo pressione:";
    const char* texto2 = "INICIAR ou aperte a tecla ESPAÇO";
    int altura = tam;
    int largura = MeasureText(texto, tam);
    int x = (WIDTH - largura)/2;
    int y = ((HEIGHT - altura)/2 - (tam/2)) - 200;
    DrawText(texto, x, y, tam, RAYWHITE);
    int largura2 = MeasureText(texto2, tam);
    int x2 = (WIDTH - largura2)/2;
    int y2 = ((HEIGHT - altura)/2 + (tam/2)) - 200;
    DrawText(texto2, x2, y2, tam, RAYWHITE);
}
void inicio_desenha_botao(){
    int tam = 60;
    int grossura = 30;
    const char* texto = "INICIAR";
    int altura = tam;
    int largura = MeasureText(texto, tam);
    int x = (WIDTH - largura)/2;
    int y = (HEIGHT - altura)/2;
    int altura_botao = altura + grossura;
    int largura_botao = largura + grossura;
    int x_botao = (WIDTH - largura_botao)/2;
    int y_botao = (HEIGHT - altura_botao)/2;
    DrawRectangle(x_botao, y_botao, largura_botao, altura_botao, RAYWHITE);
    DrawText(texto, x, y, tam, PRETO_CINZA);
}
void desenha_placar(Player *j1, Player *j2){

}
int inicio_verifica_posi_mouse(int x, int y){
    int tam = 60;
    int grossura = 30;
    const char* texto = "INICIAR";
    int altura = tam + grossura;
    int largura = MeasureText(texto, tam) + grossura;
    int x_botao = (WIDTH - largura)/2;
    int y_botao = (HEIGHT - altura)/2;
    
    if(x >= x_botao && x <= x_botao + largura){
        if(y >= y_botao && y <= y_botao + altura){
            return 1;
        }
    }
    return 0;
}
#endif