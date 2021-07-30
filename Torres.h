#ifndef TORRES_H
#define TORRES_H
#include<string>
#include "Piezas.h"
using namespace std;
class Torres: public Piezas{
	private: 
		string torre_id; 
		int x, y, mov_1; 
	public: 
		Torres(){}; 
		Torres(string i, string p, int _x, int _y, int m):Piezas(i){torre_id = p; x = _x; y = _y; mov_1 = m;};
		virtual ~Torres(){};
		string get_id_ficha(){return torre_id;};
		int get_x(){return x;}; 
		int get_y(){return y;};
		int get_mov(){return mov_1;};
		void set_x(int _x){x = _x;}; 
		void set_y(int _y){y = _y;}; 
		void set_mov(){mov_1 += 1;}
};
#endif

