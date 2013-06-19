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

#include "iostream"
#include "tfecha.h"
using namespace std;

//tipos

struct ttarea{
    tfecha fecha;
    thora hora;
    char descripcion[50];
    int prioritario;
};

/*
 LA FUNCIÓN COMPARAR NOS VA A DEVOLVER UN TRUE SI SON IGUALES
 */

int comparar(ttarea,ttarea);

/**********************************************************************************
 
 Función de comparar para el insertar ordenado
 
 int comparar (ttarea,ttarea)
 si es igual devuelve 0
 si es mayor la primera tarea que se compara que la segunda se devuelve 1
 si es menor la primera tarea que se compara que la segunda se devuelve 2
 
 
 **********************************************************************************/


void escribir(ttarea);

void modificarTarea(ttarea &);

void leerTarea(ttarea &);

