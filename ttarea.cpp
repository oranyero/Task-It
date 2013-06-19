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


#include "ttarea.h"



/*!
 * \brief leer tarea-> lee por teclado una tarea que queremos introducir en la agenda.
 * \param ttarea-> la tarea que queremos introducir y se guarda en un tipo tarea.E. 
 */

void leerTarea(ttarea &nuevaTarea){
    
    cout<<"Introduzca la fecha: "<<endl;
    nuevaTarea.fecha = leerFecha();
    
    cout<<"Introduzca la hora de la tarea: "<<endl;
    nuevaTarea.hora = leerHora();
    
    cin.ignore ( 80, '\n' );
    
    cout<<"Introduzca la descripcion de la tarea: ";
    cin.getline(nuevaTarea.descripcion, 150, '\n');
    
    cout<<"Prioridad de la tarea, (1. Baja, 2. Media, 3. Alta): ";
    nuevaTarea.prioritario = validarPrioridad();
    
}

//****************************************************************************

/*!
 * \brief comparar-> compara dos tareas segun la fecha para que la agenda esté ordenada.
 * \param ttarea-> la tarea que queremos comparar.E.
 * \param ttarea -> la segunda tarea que queremos comparar. E.
 * \return int -> si las tareas son iguales devuelve 0 sin son iguales. Devuelve 1 si son distintas. S.
 */

int comparar(ttarea a, ttarea b){
    
    if (compararFechas(a.fecha, b.fecha) == 0)
    return 0;
        
    else if (compararFechas(a.fecha, b.fecha) == 1)
    return 1;
            
    else
    return 2;
    
}

//****************************************************************************


/*!
 * \brief modificar Tarea-> modifica una tarea dentro de la agenda.
 * \param ttarea-> la tarea que queremos modificar y añadir en la agenda.E.
 */

void modificarTarea(ttarea &m){
        
    leerTarea(m);
    
}

//****************************************************************************


/*!
 * \brief escribir-> escribe los datos de la nueva tarea en la agenda y que han sido introducidos por teclado. 
 * \param ttarea-> la tarea que queremos escribir.E.
 */

void escribir(ttarea e){

cout << "Nevo dia: " << e.fecha.dia << endl;

cout << "Nuevo mes: " << e.fecha.mes << endl;

cout << "Nuevo año: " << e.fecha.anio << endl;

cout << "Nueva hora: " << e.hora.hora << endl;

cout << "Nuevo minuto: " << e.hora.minuto << endl;

cout << "Nueva descripción: " << e.descripcion << endl;

cout << "Nueva prioridad: " << e.prioritario << endl;
    
}

//****************************************************************************


/*!
 * \brief validar Prioridad-> valida que la prioridad introducida sea un valor entre 1 y 3. 
 * \return int -> devuelve la prioridad entre 1 y 3. S.
 */

int validarPrioridad(){
    //esta funcion valida que la prioridad sea un valor comprendido entre 1 y 3
    int datoSalida;
    do{
        cin>>datoSalida;
        if (datoSalida<=0||datoSalida>3){
            cout<<"Error, introduzca una prioridad valida ";
        }
    } while (datoSalida <=0|| datoSalida>3);
    return datoSalida;
}



