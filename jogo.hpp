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
        void inicio(estados *estado){
            if(IsKeyPressed(KEY_SPACE)) *estado = GAME;
            else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                int x = GetMouseX();
                int y = GetMouseY();
                if(inicio_verifica_posi_mouse(x, y)) *estado = GAME;
            }
            BeginDrawing();
            ClearBackground(PRETO_CINZA);
            inicio_desenha_texto();
            inicio_desenha_botao();
            
            EndDrawing();
        }
        void game(){
            BeginDrawing();
            ClearBackground(RAYWHITE);
            EndDrawing();
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
                    inicio(&estado);
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