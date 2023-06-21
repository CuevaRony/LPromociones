/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 08:10 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
    ped=nullptr;
    sig=nullptr;
    ant=nullptr;
    
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    delete ped;
}

int Nodo::cmp(Nodo &nuevo){
    
    if(this->ped->GetDni() > nuevo.ped->GetDni())
        return 1;
    if(this->ped->GetDni()== nuevo.ped->GetDni()){
        if(this->ped->GetFecha() > nuevo.ped->GetFecha())
            return 1;
    }    
    return 0;    
}
