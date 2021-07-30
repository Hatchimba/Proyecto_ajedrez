#ifndef TABLERO_H
#define TABLERO_H

#include<string>
#include<vector> 
#include "Piezas.h"
using namespace std;
class Tablero{
	private: 
		int x = 9; 
		int y = 9;
		string **tablero_aj;
		vector<Piezas*> piezas_blancas; 
		vector<Piezas*> piezas_negras; 
	public: 
		Tablero();
		Tablero(string **_tablero):tablero_aj(_tablero){};
		virtual ~Tablero(){}; 
		void manipular_piezas_blancas(vector<Piezas*> p){piezas_blancas = p;}; 
		void manipular_piezas_negras(vector<Piezas*> p){piezas_negras = p;}; 
		void generar_tablero_original(vector <Piezas*> piezas_blancas, vector <Piezas*> piezas_negras); 
		void recargar_tablero(vector <Piezas*> piezas_blancas, vector <Piezas*> piezas_negras);
		void generar_tablero_testeo(); 
		void mostrar_tablero(); 
		int ubicar_ficha(vector<Piezas*> piezas, string origen); 
		int espacio_destino(vector<Piezas*> piezas_o, vector<Piezas*> piezas_d, string destino); 
		bool mover_ficha(vector<Piezas*> pieza_o, string destino, int index1);
		bool comer_ficha(vector<Piezas*> pieza_o, vector<Piezas*> pieza_d, string destino, int index1, int index2);
		bool entorno_movimiento();
};
#endif
