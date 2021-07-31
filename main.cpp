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


void juego(Tablero ajedrez);

void seleccion_1(Tablero ajedrez, vector<Piezas*> piezas_blancas, vector <Piezas*> piezas_negras,
                 string id1, string id2);

int main(){
    string **marco;
    Tablero ajedrez(marco);
    juego(ajedrez);
    return 0;
}

void juego(Tablero ajedrez){
    int seleccion;
    string id1, id2;
    while (true){
        cout << endl << "         Ajedrez";
        cout << endl << "1. Iniciar un juego normal" << endl
             << "0. Salir de la aplicacion" << endl;
        cout << "Ingresar seleccion: ";
        cin >> seleccion;
        if (seleccion == 1){
            cout << "Ingrese el nombre de los 2 jugadores";
            cout << endl << "Jugador 1: ";
            cin >> id1;
            cout << "Jugador 2: ";
            cin >> id2;
            Peones *PN1 = new Peones(id2, "PN", 2, 1, 0);
            Peones *PN2 = new Peones(id2, "PN", 2, 2, 0);
            Peones *PN3 = new Peones(id2, "PN", 2, 3, 0);
            Peones *PN4 = new Peones(id2, "PN", 2, 4, 0);
            Peones *PN5 = new Peones(id2, "PN", 2, 5, 0);
            Peones *PN6 = new Peones(id2, "PN", 2, 6, 0);
            Peones *PN7 = new Peones(id2, "PN", 2, 7, 0);
            Peones *PN8 = new Peones(id2, "PN", 2, 8, 0);
            Peones *PB1 = new Peones(id1, "PB", 7, 1, 0);
            Peones *PB2 = new Peones(id1, "PB", 7, 2, 0);
            Peones *PB3 = new Peones(id1, "PB", 7, 3, 0);
            Peones *PB4 = new Peones(id1, "PB", 7, 4, 0);
            Peones *PB5 = new Peones(id1, "PB", 7, 5, 0);
            Peones *PB6 = new Peones(id1, "PB", 7, 6, 0);
            Peones *PB7 = new Peones(id1, "PB", 7, 7, 0);
            Peones *PB8 = new Peones(id1, "PB", 7, 8, 0);

            Alfiles *AB1 = new Alfiles(id1, "AB", 8, 3, 0);
            Alfiles *AB2 = new Alfiles(id1, "AB", 8, 6, 0);
            Alfiles *AN1 = new Alfiles(id2, "AN", 1, 3, 0);
            Alfiles *AN2 = new Alfiles(id2, "AN", 1, 6, 0);

            Torres *TB1 = new Torres(id1, "TB", 8, 1, 0);
            Torres *TB2 = new Torres(id1, "TB", 8, 8, 0);
            Torres *TN1 = new Torres(id2, "TN", 1, 1, 0);
            Torres *TN2 = new Torres(id2, "TN", 1, 8, 0);

            Caballos *CB1 = new Caballos(id1, "CB", 8, 2, 0);
            Caballos *CB2 = new Caballos(id1, "CB", 8, 7, 0);
            Caballos *CN1 = new Caballos(id2, "CN", 1, 2, 0);
            Caballos *CN2 = new Caballos(id2, "CN", 1, 7, 0);

            Reyes *KB = new Reyes(id1, "KB", 8, 5, 0);
            Reyes *KN = new Reyes(id2, "KN", 1, 5, 0);

            Reinas *QB = new Reinas(id1, "QB", 8, 4, 0);
            Reinas *QN = new Reinas(id2, "QN", 1, 4, 0);

            vector<Piezas*> piezas_blancas = {PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8,
                                              AB1, AB2, TB1, TB2, CB1, CB2, KB, QB};
            vector<Piezas*> piezas_negras ={PN1, PN2, PN3, PN4, PN5, PN6, PN7, PN8,
                                            AN1, AN2, TN1, TN2, CN1, CN2, KN, QN};
            ajedrez.generar_tablero_original(piezas_blancas, piezas_negras);
            system("pause");
            seleccion_1(ajedrez, piezas_blancas, piezas_negras, id1, id2);
        } else if(seleccion == 0){
            break;
        }
    }
}

void seleccion_1(Tablero ajedrez, vector<Piezas*> piezas_blancas, vector<Piezas*> piezas_negras, string id1, string id2){
    ajedrez.mostrar_tablero();
    string origen, destino;
    int jugador = 0;
    int ganador;
    int ficha_movida, lugar_objetivo;
    bool movimiento;
    while (true){
        if (jugador == 0){
            cout << endl << "Turno jugador blanco" << endl;
        } else if (jugador == 1){
            cout << endl << "Turno jugador negro" << endl;
        }
        cout << endl << "Movimiento" << endl << "Origen: ";
        cin >> origen;
        cout << "Destinto: ";
        cin >> destino;
        if (jugador == 0){
            ficha_movida = ajedrez.ubicar_ficha(piezas_blancas, origen);
            if(ficha_movida != -1 ){
                lugar_objetivo = ajedrez.espacio_destino(piezas_blancas, piezas_negras, destino);
                if(lugar_objetivo == -2){
                    jugador = jugador;
                } else if(lugar_objetivo == -1){
                    movimiento = ajedrez.mover_ficha(piezas_blancas, destino, ficha_movida);
                    if (movimiento == true){
                        jugador +=1;
                    }
                } else {
                    movimiento = ajedrez.comer_ficha(piezas_blancas, piezas_negras, destino, ficha_movida, lugar_objetivo);
                    if (movimiento == true){
                        piezas_negras.erase(piezas_negras.begin() + lugar_objetivo);
                        ajedrez.recargar_tablero(piezas_blancas, piezas_negras);
                        jugador +=1;
                    }
                }
            }
            if (jugador == 0){
                cout << "Jugada invalida blanco" << endl;
            }
        } else if(jugador == 1){
            ficha_movida = ajedrez.ubicar_ficha(piezas_negras, origen);
            if(ficha_movida != -1 ){
                lugar_objetivo = ajedrez.espacio_destino(piezas_negras, piezas_blancas, destino);
                if(lugar_objetivo == -2){
                    jugador = jugador;
                } else if(lugar_objetivo == -1){
                    movimiento = ajedrez.mover_ficha(piezas_negras, destino, ficha_movida);
                    if (movimiento == true){
                        jugador -=1;
                    }
                } else {
                    movimiento = ajedrez.comer_ficha(piezas_negras, piezas_blancas, destino, ficha_movida, lugar_objetivo);
                    if (movimiento == true){
                        piezas_blancas.erase(piezas_blancas.begin() + lugar_objetivo);
                        ajedrez.recargar_tablero(piezas_blancas, piezas_negras);
                        jugador -=1;
                    }
                }
            }
            if (jugador == 1){
                cout << "Jugada invalida negro" << endl;
            }
        }
        for (int i = 0; i < piezas_blancas.size(); i++){
            if (piezas_blancas.at(i)->get_id_ficha() == "KB") {
                ganador = 0;
                break;
            } else {
                ganador = 2;
            }
        }
        for (int i = 0; i < piezas_negras.size(); i++){
            if (piezas_negras.at(i)->get_id_ficha() == "KN") {
                ganador = 0;
                break;
            } else {
                ganador = 1;
            }
        }
        if (ganador == 1){
            cout << endl<< "El jugador de las fichas blancas gano" << endl;
            break;
        } else if(ganador == 2){
            cout << endl<< "El jugador de las fichas negras gano" << endl;
            break;
        }
        ajedrez.mostrar_tablero();
        system("pause");
    }

}