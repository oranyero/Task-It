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


#include "tfecha.h"



/*
 Funcion comparar:
 Devuelve 0 si son iguales
 Devuelve 1 si la primera fecha es mayor que la segunda
 Devuelve -1 si la primera fecha es menor que la segunda.
 */


/*!
 * \brief comparar Fechas-> compara dos fechas para introducir ordenado segun la fecha.
 * \param tfecha , tfecha-> las fechas que queremos comparar.E.
 * \return int-> devuelve 0 sin son igusles; 1 si la primera fecha es mayor y -1 se la primera fecha es menor que la segunda. 
 */
int compararFechas(tfecha fecha1, tfecha fecha2) {
    
    if(fecha1.anio == fecha2.anio) { //si el año de las dos fechas es igual, se comparan primero los meses
        
        if(fecha1.mes == fecha2.mes) { //si el primer mes es igual que el segundo, se pasa a comparar los días
            
            if (fecha1.dia == fecha2.dia) { //si el primer día es igual que el segundo, se devuelve 0
                
                return 0;
            }
            
            else if (fecha1.dia < fecha2.dia) { //si el primer día es menor que el segundo, se devuelve -1
                
                return -1;
            }
            
            else { //si el primer día es mayor que el segundo, se devuelve 1
                
                return 1;
            }
        }
        
        else if (fecha1.mes<fecha2.mes) { //si el primer mes es menor que el segundo, se devuelve -1
            
            return -1;
        }
        
        else { //si el primer mes es mayor que el segundo, se devuelve 1
            
            return 1;
        }
    }
    
    else if (fecha1.anio<fecha2.anio) { //si el primer año es menor que el otro, se devuelve -1
        
        return -1;
    }
    
    else { //si el primer año es mayor que el otro, se devuelve 1
        
        return 1;
    }
}

//****************************************************************************


/*!
 * \brief leer Mes-> lee por teclado el mes de la tarea que queremos introducir.
 * \return int -> devuelve el mes introducido. 
 */

int leerMes(){
    
    int datoSalida;

    do{
        cin>>datoSalida;
        
        if (datoSalida<1 || datoSalida>12){
            cout<<"\nError, introduzca un dato entre 1 y 12: "<<endl;
            cout<<"\nVuelva a escribirlo: ";
        }
        
    } while (datoSalida <1 || datoSalida>12);
    
    return datoSalida;
}

//****************************************************************************


/*!
 * \brief es Bisiesto-> comprueba si un año es bisiesto o no.
 * \param int-> el año que queremos comprobar. E.
 * \return bool-> devuelve false si no es bisiesto y devuelve true si es bisiesto. S.
 */

bool esBisiesto(int anio){
    
    bool esBisiesto;
    
    if ( anio%4==0 ){
        
        esBisiesto = true;
        
        if (anio%100==0 && anio%400!=0 ){
            esBisiesto = false;
        }
        
    } else {
        esBisiesto = false;
    }
    
    return(esBisiesto);
    
}

//****************************************************************************


/*!
 * \brief leer Hora-> lee por teclado la hora de la tarea.
 * \return thora-> devuelve la hora introducida. S. 
 */

thora leerHora(){
    thora hora;

    cout<<"Hora: ";
    hora.hora = leerNhoras();
    
    cout<<" Minuto: ";
    hora.minuto = leerNminutos();
    
    return (hora);
}

//****************************************************************************


/*!
 * \brief leer Nhoras -> comprueba el rango de horas entre 0 y 24.
 * \return int -> devuelve la hora. S. 
 */

int leerNhoras(){
    int num;

    do{
        cin>> num;
        
        if (num<0 || num>24){
            cout << "\nERROR. Escribe una hora entre 0 y 24"<<endl;
            cout << "\nVuelva a escribirlo: ";
        }
        
    } while (num < 0 || num > 24);
    
    return (num);
}

//****************************************************************************


/*!
 * \brief leer Nminutos -> comprueba el rango de minutos entre 0 y 59.
 * \return int -> devuelve el minuto. S.
 */

int leerNminutos(){
    
    int num;
    
    do{
        
        cin>> num;
        
        if (num < 0 || num > 59){
            
            cout << "\nERROR. Escribe los minutos de un valor entre 0 y 59." << endl;
            cout << "\nVuelva a escribirlo: ";
        }
    }while (num < 0 || num > 59);
    
    return (num);
}

//****************************************************************************


/*!
 * \brief leer Fecha-> lee por teclado la fecha de la tarea.
 * \return tfecha-> devuelve la fecha introducida. S.
 */

tfecha leerFecha(){

    tfecha fecha;
    bool diaIncorrecto, Bisiesto;
    
    cout << "\nAnio: ";
    cin >> fecha.anio;
    Bisiesto = esBisiesto(fecha.anio);
    cout << "\nMes: ";
    
    fecha.mes = leerMes();
    
    do{
        
        cout<<" Dia: ";
        cin>>fecha.dia;
        
        switch (fecha.mes){
                
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                
                if (fecha.dia>31){
                    diaIncorrecto = true;
                } else {
                    diaIncorrecto = false;
                }
                break;
                
            case 2:
                if (Bisiesto==true){
                    
                    if (fecha.dia>29){
                        diaIncorrecto = true;
                    } else {
                        diaIncorrecto = false;
                    }
                }
                if (Bisiesto == false){
                    
                    if (fecha.dia > 28){
                        diaIncorrecto = true;
                    } else {
                        diaIncorrecto = false;
                    }
                }
                break;
                
            default :
                
                if (fecha.dia>30){
                    diaIncorrecto = true;
                } else {
                    diaIncorrecto = false;
                }
        }
        
        if (diaIncorrecto == true){
            cout << "\nError, dia no valido para ese mes. Dia:";
            cout << "\nVuelva a escribirlo: ";
        }
        
    }while (diaIncorrecto);
    
    return (fecha);
}
