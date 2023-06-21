/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promociones.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 09:42 PM
 */
#include "Lista.h"

#ifndef PROMOCIONES_H
#define PROMOCIONES_H

class Promociones {
public:
    Promociones();
    Promociones(const Promociones& orig);
    virtual ~Promociones();
    void leepedidos();
    void imprimepedidos();
    void actualizapedidos();
private:
    Lista Lpedidos;
};

#endif /* PROMOCIONES_H */

