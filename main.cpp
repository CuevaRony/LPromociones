/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 07:27 PM
 */

#include "Promociones.h"


int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();

    return 0;
}

