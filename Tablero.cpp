#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <cstdlib>
#include "Tablero.h"
#include "Piezas.h"
#include "Peones.h"
#include "Alfiles.h"
#include "Torres.h"
#include "Caballos.h"
#include "Reyes.h"
#include "Reinas.h"
using namespace std;


void Tablero::generar_tablero_original(vector <Piezas*> piezas_blancas, vector <Piezas*> piezas_negras){
	tablero_aj = new string*[x];
	int _x, _y; 
  	for (int i = 0; i < y; i++){
		tablero_aj[i] = new string[y]; 
    	}
	
	for (int i = 0; i < x; i++){
        	for(int j = 0; j < y; j++){
			if(j == 0 && i == 0){
        			*(*(tablero_aj + i) + j) = " ";
			} else if(i == 0){
				if(j == 1){
					*(*(tablero_aj + i) + j) = "a "; 
				} else if( j == 2){
					*(*(tablero_aj + i) + j) = "b "; 
				} else if( j == 3){
					*(*(tablero_aj + i) + j) = "c "; 
				} else if( j == 4){
					*(*(tablero_aj + i) + j) = "d "; 
				} else if( j == 5){
					*(*(tablero_aj + i) + j) = "e "; 
				} else if( j == 6){
					*(*(tablero_aj + i) + j) = "f "; 
				} else if( j == 7){
					*(*(tablero_aj + i) + j) = "g "; 
				} else if( j == 8){
					*(*(tablero_aj + i) + j) = "h "; 
				}
			} else if(j == 0){
				string num(to_string(x-i));
				*(*(tablero_aj + i) + j) = num; 
			} else {
        			*(*(tablero_aj + i) + j) = " ";
			}

        	}
    	}

	for (int i = 0; i < piezas_blancas.size(); i++){
		_x = piezas_blancas.at(i)->get_x();
		_y = piezas_blancas.at(i)->get_y(); 
		*(*(tablero_aj + _x) + _y) = piezas_blancas.at(i)->get_id_ficha();
	}
	for (int i = 0; i < piezas_negras.size(); i++){
		_x = piezas_negras.at(i)->get_x();
		_y = piezas_negras.at(i)->get_y(); 
		*(*(tablero_aj + _x) + _y) = piezas_negras.at(i)->get_id_ficha();
	}	
}

void Tablero::recargar_tablero(vector <Piezas*> piezas_blancas, vector <Piezas*> piezas_negras){
	int _x, _y; 
	for (int i = 0; i < x; i++){
        	for(int j = 0; j < y; j++){
			if(j == 0 && i == 0){
        			*(*(tablero_aj + i) + j) = " ";
			} else if(i == 0){
				if(j == 1){
					*(*(tablero_aj + i) + j) = "a "; 
				} else if( j == 2){
					*(*(tablero_aj + i) + j) = "b "; 
				} else if( j == 3){
					*(*(tablero_aj + i) + j) = "c "; 
				} else if( j == 4){
					*(*(tablero_aj + i) + j) = "d "; 
				} else if( j == 5){
					*(*(tablero_aj + i) + j) = "e "; 
				} else if( j == 6){
					*(*(tablero_aj + i) + j) = "f "; 
				} else if( j == 7){
					*(*(tablero_aj + i) + j) = "g "; 
				} else if( j == 8){
					*(*(tablero_aj + i) + j) = "h "; 
				}
			} else if(j == 0){
				string num(to_string(x-i));
				*(*(tablero_aj + i) + j) = num; 
			} else {
        			*(*(tablero_aj + i) + j) = " ";
			}

        	}
    	}

	for (int i = 0; i < piezas_blancas.size(); i++){
		_x = piezas_blancas.at(i)->get_x();
		_y = piezas_blancas.at(i)->get_y(); 
		*(*(tablero_aj + _x) + _y) = piezas_blancas.at(i)->get_id_ficha();
	}
	for (int i = 0; i < piezas_negras.size(); i++){
		_x = piezas_negras.at(i)->get_x();
		_y = piezas_negras.at(i)->get_y(); 
		*(*(tablero_aj + _x) + _y) = piezas_negras.at(i)->get_id_ficha();
	}
}

void Tablero::mostrar_tablero(){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << setw(5) << tablero_aj[i][j] << " ";
		}
		cout << endl << endl; 
	}	
}

int Tablero::ubicar_ficha(vector<Piezas*> piezas, string origen){
	int index, _y, x, y; 
	char chr_y = origen[0];
	int _x =  origen[1] - '0';
	_x = (_x - 9)*-1; 
	if (chr_y == 'a'){
		_y = 1; 
	} else if(chr_y == 'b'){
		_y = 2; 
	} else if(chr_y == 'c'){
		_y = 3;
	} else if(chr_y == 'd'){
		_y = 4; 
	} else if(chr_y == 'e'){
		_y = 5; 
	} else if(chr_y == 'f'){
		_y = 6; 
	} else if(chr_y == 'g'){
		_y = 7; 
	} else if(chr_y == 'h'){
		_y = 8; 
	} else {
		return -1; 
	}
	for (int i = 0; i < piezas.size(); i++){
		x = piezas.at(i)->get_x();
		y = piezas.at(i)->get_y(); 
		if (_x == x && _y == y){
			return i; 
		}
	}	
	return -1; 
}

int Tablero::espacio_destino(vector<Piezas*> piezas_o, vector<Piezas*> piezas_d, string destino){
	int index, _y, x, y; 
	char chr_y = destino[0];
	int _x =  destino[1] - '0';
	string id; 
	_x = (_x - 9)*-1; 
	if (chr_y == 'a'){
		_y = 1; 
	} else if(chr_y == 'b'){
		_y = 2; 
	} else if(chr_y == 'c'){
		_y = 3;
	} else if(chr_y == 'd'){
		_y = 4; 
	} else if(chr_y == 'e'){
		_y = 5; 
	} else if(chr_y == 'f'){
		_y = 6; 
	} else if(chr_y == 'g'){
		_y = 7; 
	} else if(chr_y == 'h'){
		_y = 8; 
	} else {
		return -2; 
	}	
	for (int i = 0; i < piezas_o.size(); i++){
		if(*(*(tablero_aj + _x) + _y) == piezas_o.at(i)->get_id_ficha()){
			return -2; 
		} else if(*(*(tablero_aj + _x) + _y) == " " ){
			return -1; 
		} else if(*(*(tablero_aj + _x) + _y) != " " ){
			for (int j = 0; j < piezas_d.size(); j++){
				x = piezas_d.at(j)->get_x(); 
				y = piezas_d.at(j)->get_y(); 
				if (x == _x && y == _y){
					return j; 
				}
			}		
		}
	}
	return -2; 
}

bool Tablero::mover_ficha(vector<Piezas*> pieza_o, string destino, int index1){
	int index, _y, x, y; 
	char chr_y = destino[0];
	int _x =  destino[1] - '0';
	string id; 
	_x = (_x - 9)*-1; 
	if (chr_y == 'a'){
		_y = 1; 
	} else if(chr_y == 'b'){
		_y = 2; 
	} else if(chr_y == 'c'){
		_y = 3;
	} else if(chr_y == 'd'){
		_y = 4; 
	} else if(chr_y == 'e'){
		_y = 5; 
	} else if(chr_y == 'f'){
		_y = 6; 
	} else if(chr_y == 'g'){
		_y = 7; 
	} else if(chr_y == 'h'){
		_y = 8; 
	}
	id = pieza_o.at(index1)->get_id_ficha();
	x = pieza_o.at(index1)->get_x();
	y = pieza_o.at(index1)->get_y();
	if(id == "PB" || id == "PN" ){
		if(id == "PB"){
			if(pieza_o.at(index1)->get_mov() == 0){
				if((x-2 == _x && y == _y) || (x-1 == _x && y == _y)){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					pieza_o.at(index1)->set_mov();
					return true; 
				}
			} else {
				if(x-1 == _x && y == _y){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					return true;
				}
			}
		} else if(id == "PN"){
			if(pieza_o.at(index1)->get_mov() == 0){
				if((x+2 == _x && y == _y) || (x+1 == _x && y == _y)){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					pieza_o.at(index1)->set_mov();
					return true; 
				}
			} else {
				if(x+1 == _x && y == _y){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					return true; 
				}
			}
		}

	}
	
	if(id == "AB" || id == "AN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x  && y - i == _y) || (x - i == _x && y + i == _y) 
			|| (x + i == _x && y - i == _y) || (x + i == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				pieza_o.at(index1)->set_mov();
				return true; 
			}

		}
	}

	if(id == "CB" || id == "CN"){
		if((x - 2 == _x && y -1 == _y) || (x - 2 == _x && y + 1 == _y) || (x - 1 == _x && y - 2 == _y) || (x - 1 == _x && y + 2 == _y)
		|| (x + 2 == _x && y -1 == _y) || (x + 2 == _x && y + 1 == _y) || (x + 1 == _x && y - 2 == _y) || (x + 1 == _x && y + 2 == _y) ){
			tablero_aj[x][y] = " "; 
			tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
			pieza_o.at(index1)->set_x(_x);
			pieza_o.at(index1)->set_y(_y);
			return true; 
		}
	}

	if(id == "TB" || id == "TN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x && y == _y) || (x + i == _x && y == _y) 
			|| (x == _x && y - i == _y) || (x == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				return true; 
			}
		}
	}

	if(id == "QB" || id == "QN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x && y == _y) || (x + i == _x && y == _y) 
			|| (x == _x && y - i == _y) || (x == _x && y + i == _y)
			|| (x - i == _x  && y - i == _y) || (x - i == _x && y + i == _y) 
			|| (x + i == _x && y - i == _y) || (x + i == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				return true; 
			}
		}
	}

	if(id == "KB" || id == "KN"){
		if((x - 1 == _x && y == _y) || (x + 1 == _x && y == _y) 
		|| (x == _x && y - 1 == _y) || (x == _x && y + 1 == _y)
		|| (x - 1 == _x  && y - 1 == _y) || (x - 1 == _x && y + 1 == _y) 
		|| (x + 1 == _x && y - 1 == _y) || (x + 1 == _x && y + 1 == _y)){
			tablero_aj[x][y] = " "; 
			tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
			pieza_o.at(index1)->set_x(_x);
			pieza_o.at(index1)->set_y(_y);
			return true; 
		}
	}
	
	return false; 
}

bool Tablero::comer_ficha(vector<Piezas*> pieza_o, vector<Piezas*> pieza_d, string destino, int index1, int index2){
	int index, _y, x, y; 
	char chr_y = destino[0];
	int _x =  destino[1] - '0';
	string id; 
	_x = (_x - 9)*-1; 
	if (chr_y == 'a'){
		_y = 1; 
	} else if(chr_y == 'b'){
		_y = 2; 
	} else if(chr_y == 'c'){
		_y = 3;
	} else if(chr_y == 'd'){
		_y = 4; 
	} else if(chr_y == 'e'){
		_y = 5; 
	} else if(chr_y == 'f'){
		_y = 6; 
	} else if(chr_y == 'g'){
		_y = 7; 
	} else if(chr_y == 'h'){
		_y = 8; 
	}
	id = pieza_o.at(index1)->get_id_ficha();
	x = pieza_o.at(index1)->get_x();
	y = pieza_o.at(index1)->get_y();

	if(id == "PB" || id == "PN" ){
		if(id == "PB"){
			if((x-1 == _x && y+1 == _y) || (x-1 == _x && y-1 == _y) ){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					return true; 
			}
		} else if(id == "PN"){
			if((x+1 == _x && y-1 == _y) || (x+1 == _x && y+1 == _y)){
					tablero_aj[x][y] = " "; 
					tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
					pieza_o.at(index1)->set_x(_x);
					pieza_o.at(index1)->set_y(_y);
					return true; 
			}
		}
	}

	if(id == "AB" || id == "AN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x  && y - i == _y) || (x - i == _x && y + i == _y) || (x + i == _x && y - i == _y) || (x + i == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				pieza_o.at(index1)->set_mov();
				return true; 
			}

		}
	}

	if(id == "CB" || id == "CN"){
		if((x - 2 == _x && y -1 == _y) || (x - 2 == _x && y + 1 == _y) || (x - 1 == _x && y - 2 == _y) || (x - 1 == _x && y + 2 == _y)
		|| (x + 2 == _x && y -1 == _y) || (x + 2 == _x && y + 1 == _y) || (x + 1 == _x && y - 2 == _y) || (x + 1 == _x && y + 2 == _y) ){
			tablero_aj[x][y] = " "; 
			tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
			pieza_o.at(index1)->set_x(_x);
			pieza_o.at(index1)->set_y(_y);
			return true; 
		}
	}

	if(id == "TB" || id == "TN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x && y == _y) || (x + i == _x && y == _y) 
			|| (x == _x && y - i == _y) || (x == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				return true; 
			}
		}
	}

	if(id == "QB" || id == "QN"){
		for (int i = 0; i < 9; i++){
			if((x - i == _x && y == _y) || (x + i == _x && y == _y) 
			|| (x == _x && y - i == _y) || (x == _x && y + i == _y)
			|| (x - i == _x  && y - i == _y) || (x - i == _x && y + i == _y) 
			|| (x + i == _x && y - i == _y) || (x + i == _x && y + i == _y)){
				tablero_aj[x][y] = " "; 
				tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
				pieza_o.at(index1)->set_x(_x);
				pieza_o.at(index1)->set_y(_y);
				return true; 
			}
		}
	}

	if(id == "KB" || id == "KN"){
		if((x - 1 == _x && y == _y) || (x + 1 == _x && y == _y) 
		|| (x == _x && y - 1 == _y) || (x == _x && y + 1 == _y)
		|| (x - 1 == _x  && y - 1 == _y) || (x - 1 == _x && y + 1 == _y) 
		|| (x + 1 == _x && y - 1 == _y) || (x + 1 == _x && y + 1 == _y)){
			tablero_aj[x][y] = " "; 
			tablero_aj[_x][_y] = pieza_o.at(index1)->get_id_ficha(); 
			pieza_o.at(index1)->set_x(_x);
			pieza_o.at(index1)->set_y(_y);
			return true; 
		}
	}

	return false; 
}

