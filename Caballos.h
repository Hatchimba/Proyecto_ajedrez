#ifndef AJEDREZZZ_CABALLOS_H
#define AJEDREZZZ_CABALLOS_H
#include<string>
#include "Piezas.h"
using namespace std;
class Caballos: public Piezas{
private:
    string caballo_id;
    int x, y, mov_1;
public:
    Caballos(){};
    Caballos(string i, string p, int _x, int _y, int m):Piezas(i){caballo_id = p; x = _x; y = _y; mov_1 = m;};
    virtual ~Caballos(){};
    string get_id_ficha(){return caballo_id;};
    int get_x(){return x;};
    int get_y(){return y;};
    int get_mov(){return mov_1;};
    void set_x(int _x){x = _x;};
    void set_y(int _y){y = _y;};
    void set_mov(){mov_1 += 1;}
};
#endif //AJEDREZZZ_CABALLOS_H
