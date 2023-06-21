/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 09:39 PM
 */
#include <fstream>
#include "Lista.h"
#include "PedidoEspecial.h"
#include "PedidoUsual.h"
#include "PedidoEventual.h"
#include "Nodo.h"

using namespace std;

Lista::Lista() {
    lini = NULL;
    lfin = NULL;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::inserta(ifstream& arch){
    int codigo;
    Nodo *p = lini,*nuevo,*rec=NULL;
        
    nuevo = new Nodo;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    
    arch >> codigo;
    if(arch.eof()) return;        
            
    if(codigo<400000) 
        nuevo->ped = new PedidoEspecial;
    if(codigo>=400000 && codigo<600000) 
        nuevo->ped = new PedidoUsual;
    if(codigo>=600000) 
        nuevo->ped = new PedidoEventual;
    
    nuevo->ped->lee(codigo,arch);
    
    while(p){
        if(p->cmp(*nuevo)) break;
        rec=p;
        p=p->sig;
    }
    nuevo->sig = p;
    if(p!=NULL) p->ant = nuevo;
    if(rec == NULL) {
        if(p==NULL) lfin = nuevo;
        lini = nuevo;
    }
    else{   rec->sig = nuevo;
            nuevo->ant = rec;
            if(rec == lfin) lfin = nuevo;
    }    
}    

void Lista::muestra(ofstream& arch){
    class Nodo *p;

    p=lini;
        
    while(p)
    {   p->ped->imprime(arch,0,0);
        p=p->sig;
    }        

}

void Lista::modifica(int dni, int fecha){
    Nodo *p = lini,*nuevo,*rec=NULL;   
    nuevo = new Nodo;
    nuevo->ped = new PedidoEspecial;
    nuevo->ped->SetDni(dni);
    nuevo->ped->SetFecha(fecha);
    while(p){
        if(p->cmp(*nuevo)) break;
        rec=p;
        p=p->sig;
    }    
    p=rec;
    while(p->ped->GetDni()==dni){
        p->ped->actualiza();
        rec=p;
        p=p->ant;
    }
    
}

