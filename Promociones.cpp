/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promociones.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 09:42 PM
 */
#include <fstream>
#include <iostream>
#include "Promociones.h"
#include "Lista.h"

using namespace std;

Promociones::Promociones() {
}

Promociones::Promociones(const Promociones& orig) {
}

Promociones::~Promociones() {
}

void Promociones::leepedidos(){
    ifstream arch("Pedidos5.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Pedidos";
        exit(1);
    }
    while(1){
        Lpedidos.inserta(arch);
        if(arch.eof()) break;
    }    
}

void Promociones::imprimepedidos(){
       
    ofstream arch("reporte.txt",ios::out);
    if(!arch)
    {   cout << "Archivo no encontrado" << endl;
        exit(1);
    }
    Lpedidos.muestra(arch);
        
}
/*
33713901,06/06/2019
57263719,01/10/2020
 */
void Promociones::actualizapedidos(){
    int fecha,dni,aa,mm,dd;
    char c;
    ifstream arch("promocion.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Promocion";
        exit(1);
    }
    while(1){
        arch>>dni;
        arch.get();
        arch >> dd  >>c >>mm>>c>>aa;
        arch.get();
        fecha=aa*10000+mm*100+dd;
        Lpedidos.modifica(dni,fecha);
        if(arch.eof()) break;
    }     
    
    
    
}