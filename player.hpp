#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <raylib.h>
#include "coisas.hpp"

class Player{
    private:
        int placar;
        int altura = 80;
        int largura = 12;
        int x = 0;
        int y = (HEIGHT - altura)/2;
        int vel = 5;
        int verifica_altura(int sinal){
            if(sinal > 0){
                if((y + altura + vel) > HEIGHT) return 0;
            }
            else{
                if((y - vel) < 0) return 0;
            }
            return 1;
        }
        
    public:
        void setX(int posi){
            x = (posi - largura)/2;
        }
        void moveY(int sinal){
            if(verifica_altura(sinal)) y += sinal * vel;
        }
        void desenha_peça(){
            DrawRectangle(x, y, largura, altura, RAYWHITE);
        }
};
#endif