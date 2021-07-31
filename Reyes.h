#ifndef AJEDREZZZ_REYES_H
#define AJEDREZZZ_REYES_H
#include<string>
#include "Piezas.h"
using namespace std;
class Reyes: public Piezas{
private:
    string rey_id;
    int x, y, mov_1;
public:
    Reyes(){};
    Reyes(string i, string p, int _x, int _y, int m):Piezas(i){rey_id = p; x = _x; y = _y; mov_1 = m;};
    virtual ~Reyes(){};
    string get_id_ficha(){return rey_id;};
    int get_x(){return x;};
    int get_y(){return y;};
    int get_mov(){return mov_1;};
    void set_x(int _x){x = _x;};
    void set_y(int _y){y = _y;};
    void set_mov(){mov_1 += 1;}
};
#endif //AJEDREZZZ_REYES_H
