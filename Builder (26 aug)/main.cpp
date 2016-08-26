//
//  main.cpp
//  Builder (26 aug)
//
//  Created by Alonso Iturbe on 8/26/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include "Avion.h"

int main() {
    Director * dir = new Director();
    dir->setBuilder(new BoeingBuilder());
    dir->construct();
    
    Avion * miAvion = dir->getAvion();
    cout << miAvion->getMarca();
    return 1;
}
