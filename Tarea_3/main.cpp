//
//  main.cpp
//  Tarea_3
//
//  Created by Alonso Iturbe on 8/19/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include "Fabrica.hpp"
#include "Computadora.hpp"

//Edit: Se movió esta línea a justo afuera de la clase FabricaFisica para claridad
//FabricaFisica * FabricaFisica::instancia = 0;

int main() {
    
    // NOTA: Para su compilación en la terminal, se debe de compilar con el comando:
    // g++ *.cpp
    // esto debido a un error en el cual no encuentra todos los archivos .cpp, por alguna razón
    
    //Objeto auxiliar que nos crea los demás apuntadores a objetos tipo Computadora
    
    FabricaFisica * apple = FabricaFisica::getInstance();
    
    Computadora * macbook = apple->crearComputadora("laptop");
    
    Computadora * macbookair = apple->crearComputadora("netbook");
    
    Computadora * imac = apple->crearComputadora("desktop");
    
    Computadora * ipad = apple->crearComputadora("tablet");
    
    Clonado <Computadora, Laptop> * nueva;
    
    delete macbook;
    delete macbookair;
    delete imac;
    delete ipad;
    
    return 0;
}
