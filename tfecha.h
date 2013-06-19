//////////////////////////////////////////////////////////////////
/**
 *
 * @version$Id: tfecha.h 0007 2013-05-07 12:05:00 Proyecto de Programación con estructuras lineales.
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
using namespace std;

//tipos

struct tfecha{
    int dia;
    int mes;
    int anio;
};

struct thora{
    int hora;
    int minuto;
};

int compararFechas(tfecha, tfecha);
int leerMes();
bool esBisiesto(int);
thora leerHora();
int leerNhoras();
int leerNminutos();
tfecha leerFecha();
int validarPrioridad();
float leerRealPositivo();
