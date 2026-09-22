#ifndef ORBE_HPP
#define ORBE_HPP
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <raylib.h>
#include "coisas.hpp"

class Orbe {
    private:
        
        int altura = 12;
        int largura = 12;

        double x = (WIDTH - largura)/2;
        double y = (HEIGHT - altura)/2;

        double v_max = 5;
        double vx = 3;
        double vy = 4;

        

    public:
        int verifica_posi(){
            
            if(x + vx <= 0) return 1;
            if(x + largura + vx >= WIDTH) return 2;
            if(y + vy <= 0) return 3;
            if(y + altura + vy >= HEIGHT) return 3;
            return 0;
            
        }

        void ajusta_v(){
            double v = sqrt(pow(vx, 2)+pow(vy, 2));
            vx = (vx/v)*v_max;
            vy = (vy/v)*v_max;
            
        }

        void atualiza_posi(){
            x += vx;
            y += vy;
            bate_parede();
        }

        void bate_parede(){
            if(verifica_posi() == 3)
            vy *= -1;
        }

        void bate_raquete(int vel, int sinal){
            vx *= -1;
            vy += (vel*sinal);
            ajusta_v();
        }
        void desenha_orbe(){
            DrawRectangle(x, y, largura, altura, RAYWHITE);
        }
        void reseta_posi(int gerador){
            
            if(verifica_posi() == 1){
                if(gerador == 0){
                   x = ((WIDTH - largura)/2);
                   y = ((HEIGHT - altura)/2) + 40;
                   vx = -4;
                   vy = -5;
                }
                else{
                   x = ((WIDTH - largura)/2);
                   y = ((HEIGHT - altura)/2) - 40;
                   vx = -4;
                   vy = 5;
                }
            }
            else if(verifica_posi() == 2){
                if(gerador == 0){
                   x = ((WIDTH - largura)/2);
                   y = ((HEIGHT - altura)/2) + 40;
                   vx = 4;
                   vy = -5;
                }
                else{
                   x = ((WIDTH - largura)/2);
                   y = ((HEIGHT - altura)/2) - 40;
                   vx = 4;
                   vy = 5;
                }
            }
            ajusta_v();
        }
        Rectangle getRectangle(){
            Rectangle retangulo;
            retangulo.height = altura;
            retangulo.width = largura;
            retangulo.x = x;
            retangulo.y = y;
            return retangulo;
        }
        

};
#endif