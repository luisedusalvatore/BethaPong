#ifndef JOGO_HPP
#define JOGO_HPP
#include <raylib.h>
#include "coisas.hpp"
#include "player.hpp"
#include "orbe.hpp"
#include "interacoes.hpp"
class Jogo{
    private:
        enum estados{
                INICIO,
                GAME,
                GAME_OVER,
        };
        void inicio(){

            BeginDrawing();
            inicio_desenha_texto();
            inicio_desenha_botao();
            ClearBackground(PRETO_CINZA);
            EndDrawing();
        }
        void game(){

        }
        void game_over(){

        }
    public:

        void roda(){
            
            InitWindow(WIDTH, HEIGHT, "Pong");
            InitAudioDevice();
            SetTargetFPS(60);
            estados estado = INICIO;
            while(!WindowShouldClose()){
                switch(estado){
                    case INICIO:
                    inicio();
                    break;
                    case GAME:
                    game();
                    break;
                    case GAME_OVER:
                    game_over();
                    break;
                }
            }
            CloseAudioDevice();
            CloseWindow();
        }
};
#endif