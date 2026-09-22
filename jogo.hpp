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
        void game(Player *j1, Player *j2, Orbe *orbe, estados * estado, int random){
            j1->resetaSentido();
            j2->resetaSentido();
            if(IsKeyDown(KEY_W)){
                j1->setSentido(1);
                j1->moveY();
            }
            else if(IsKeyDown(KEY_S)){
                j1->setSentido(-1);
                j1->moveY();
            }
            if(IsKeyDown(KEY_UP)){
                j2->setSentido(1);
                j2->moveY();
            }
            else if(IsKeyDown(KEY_DOWN)){
                j2->setSentido(-1);
                j2->moveY();
            }
            orbe->atualiza_posi();     
            detectar_colisoes(j1, orbe);
            detectar_colisoes(j2, orbe);
            if(orbe->verifica_posi() == 1) j1->atualiza_placar();
            if(orbe->verifica_posi() == 2) j2->atualiza_placar();
            orbe->reseta_posi(random);
            BeginDrawing();
            ClearBackground(PRETO_CINZA);
            desenha_placar(j1, j2);
            j1->desenha_peça();
            j2->desenha_peça();
            orbe->desenha_orbe();
            EndDrawing();
        }
        void game_over(){

        }
    public:

        void roda(){
            srand(time(0));
            InitWindow(WIDTH, HEIGHT, "Pong");
            InitAudioDevice();
            SetTargetFPS(60);
            Player j1;
            Player j2;
            Orbe orbe;
            j1.setX(120);
            j2.setX(WIDTH - 120);
            estados estado = INICIO;
            while(!WindowShouldClose()){
                switch(estado){
                    case INICIO:
                    inicio(&estado);
                    break;
                    case GAME:
                    game(&j1, &j2, &orbe, &estado, rand()%2);
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