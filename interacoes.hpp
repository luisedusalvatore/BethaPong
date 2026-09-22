#ifndef INTERACOES_HPP
#define INTERACOES_HPP
#include <raylib.h>
#include "coisas.hpp"
#include "player.hpp"
#include "orbe.hpp"
void detectar_colisoes(Player *player, Orbe *orbe, int sinal){
    if(CheckCollisionRecs(player->getRectangle(), orbe->getRectangle())){
        orbe->bate_raquete(player->getVel(), sinal);
    }
}
#endif