#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <raylib.h>
#include "coisas.hpp"

class Player{
    private:
        int placar = 0;
        int sentido = 0;
        int altura = 160;
        int largura = 12;
        int x = 0;
        int y = (HEIGHT - altura)/2;
        int v = 0;
        int vel = 10;
        int verifica_altura(int sinal){
            if(sinal < 0){
                if((y + altura + vel) > HEIGHT) return 0;
            }
            else{
                if((y - vel) < 0) return 0;
            }
            return 1;
        }

        
    public:
        void setX(int posi){
            x = posi;
        }
        void moveY(){
            if(verifica_altura(sentido)) y -= sentido * vel;
        }
        void desenha_peça(){
            DrawRectangle(x, y, largura, altura, RAYWHITE);
        }
        void atualiza_placar(){
            placar ++;
        }
        Rectangle getRectangle(){
            Rectangle retangulo;
            retangulo.height = altura;
            retangulo.width = largura;
            retangulo.x = x;
            retangulo.y = y;
            return retangulo;
        }
        int getVel(){
            return vel;
        }
        void setSentido(int sinal){
            sentido = sinal;
        }
        int getSentido(){
            return sentido;
        }
        void resetaSentido(){
            sentido = 0;
        }
};
#endif