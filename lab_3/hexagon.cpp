#include "./include/hexagon.h"

Hexagon::Hexagon(): Figure(6){

}

Hexagon::Hexagon(const vector<coord>&v):Figure(v, 6){

}
Hexagon::Hexagon(const initializer_list<coord> &l):Figure(l,6){
    
}

Hexagon::Hexagon(const Hexagon &other):Figure(other){

}

Hexagon::Hexagon(Hexagon &&other)noexcept:Figure(other){

}

