//////////////////////////////////////////////////////////////////
/**
 *
 * @version$Id: mainwindow.cpp 0007 2013-05-07 12:05:00 Proyecto de Programación con estructuras lineales.
 * @package Xcode C++
 * @copyright Copyright (C) 2013 Open Source. All rights reserved.
 * @licenseGNU/GPL, see LICENSE.txt
 *
 * Task It! is free software. This version may have been modified pursuant
 * to the GNU General Public License, and as distributed it includes or
 * is derivative of works licensed under the GNU General Public License or
 * other free or open source software licenses.
 *
 */

//////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
using namespace std;

#include "ttarea.h"

typedef ttarea telemento;

struct tnodo{

    telemento elemento;
    tnodo * sig;

};


typedef tnodo * tlista; //esto quiere decir que tlista es un puntero a tnodo
typedef tnodo * tposicion;   

bool esVacia (tlista);
void insertarPrincipio (tlista &,telemento);
void insertarFinal(tlista &, telemento);
void insertarOrdenado(tlista &, telemento);
void borrar (tlista &,tposicion);
void mostrar(tlista);
int longitud(tlista);
tposicion buscarPosicion (tlista,telemento);
bool modificarLista(tlista &,telemento);
bool leerNhoras(int &);
