#ifndef Piezas_H
#define Piezas_H
#include <string> 
using namespace std;
class Piezas{
	private: 
		string id_jugador; 
	public: 
		Piezas();
		Piezas(string i):id_jugador(i){};
		virtual ~Piezas(){};
		string get_id_jugador(){return id_jugador;}; 
		virtual int get_x(){};
		virtual int get_y(){};
		virtual int get_mov(){};
		virtual void set_x(int _x){};
		virtual void set_y(int _y){};
		virtual void set_mov(){};
		virtual string get_id_ficha(){}; 
};
#endif

