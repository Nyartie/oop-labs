#include "./include/triangle.h"


Triangle::Triangle(): Figure(3){

}

Triangle::Triangle(const vector<coord>&v):Figure(v, 3){

}
Triangle::Triangle(const initializer_list<coord> &l):Figure(l,3){
    
}

Triangle::Triangle(const Triangle &other):Figure(other){

}

Triangle::Triangle(Triangle &&other)noexcept:Figure(other) {

}
