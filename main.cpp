
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
#include "tlista.h"

using namespace std;


void escribirArchivo (tlista);
void leer_fich(tlista &);

//****************************************************************************

int main(){

    tlista lista;
    telemento elemento;
    int select, menu2;
    tposicion p;
    
    cout << "Acciones:\n";
    cout << "0. Programa sin información.\n";
    cout << "1. Carga la base de datos.\n";
    cout << "Seleccionar:";
    cin  >> menu2;
    
    switch (menu2) {
        case 0:
            break;
            
        case 1:
            leer_fich(lista);
            break;
    }
    
    do{

    cout << "\nMenu: \n";
    cout << "1. Para insertar un elemento al princio.\n";
    cout << "2. Para insertar al final.\n";
    cout << "3. Para insertar ordenado.\n";
    cout << "4. Para modificar un elemento.\n";
    cout << "5. Mostrar la lista.\n";
    cout << "6. Eliminar una tarea.\n";
    cout << "9. Guardar en fichero.\n";
    cout << "Introduza uno: ";
    cin  >> select;
    cout << endl;
        
        switch (select) {
                
            case 1:
                leerTarea(elemento);
                insertarPrincipio(lista, elemento);
                break;
                
            case 2:
                cout << "\nInsertar al final: \n";
                leerTarea(elemento);
                insertarFinal(lista, elemento);
                break;
            
            case 3:
                cout << "\nInsertar ordenado:\n";
                leerTarea(elemento);
                insertarOrdenado(lista, elemento);
                break;
                
            case 4:
                
                cout << "\nModificar tarea:\n";
                
                if(!esVacia(lista)){
                
                cout << "Instroduzca la tarea a eliminar:\n";
                leerTarea(elemento);
                modificarLista(lista, elemento);
                    
                cout << "\nSe ha modificado\n.";
                } else
                    cout << "No se ha modificado.\n";
                
                break;
            
            case 5:
                cout << "\nMostrar la lista:\n";
                mostrar(lista);
                break;
                
            case 6:
                
                if (!esVacia(lista)){
                    
                    cout << "\nEliminar tarea, Introduzca la tarea a eliminar";
                    leerTarea(elemento);
                    p = buscarPosicion(lista, elemento);
                    borrar(lista, p);
                    
                }else
                    cout << "\nNo hay elementos que borrar\n";
                break;
                
            case 9:
                escribirArchivo(lista);
                cout << "\nSe ha guardado.\n";
                break;
                
            default:
                break;
        }

        
    } while (select != 0);


}

//****************************************************************************

/*!
 * \brief leer_ fich-> abre un fichero de datos txt e insertar al final la nueva tarea.
 * \param tlista-> la lista que quermeos abrir con el archivo.E.
 */

void leer_fich(tlista &l){
    
    
    fstream AuxArchivo;
    
    AuxArchivo.open("bd.txt", ios::in);
    
    if(!AuxArchivo){
        
        cout << "El archivo no se ha encontrado";
        
    } else {
        
        telemento e;
        int lng;
        
        AuxArchivo >> lng;
        
        for(int i = 0; i < lng; i++){
            
            AuxArchivo >> e.hora.hora;
            AuxArchivo >> e.hora.minuto;
            
            AuxArchivo >> e.fecha.dia;
            AuxArchivo >> e.fecha.mes;
            AuxArchivo >> e.fecha.anio;
            
            AuxArchivo >> e.descripcion;
            AuxArchivo >> e.prioritario;
            
            insertarFinal(l, e);
            
        }
        
    }
    
    AuxArchivo.close();
    
}


//****************************************************************************


/*!
 * \brief escribir Archivo-> guarda los datos introducidos por el usuario en un fichero de datos txt.
 * \param tlista-> la lista que quermeos guardar en el archivo.E.
 */

void escribirArchivo (tlista l){
    
    tposicion p;
    fstream archivo;
    
    archivo.open("bd.txt", ios::out);
    
    if (!archivo)
        
        cout << "\nError al escribir en el archivo.\n";
    
    else{
                
        archivo << longitud(l) << endl;
        
        p = l;
        
        while (p != NULL) {
            
            
            
            archivo << p->elemento.hora.hora << " ";
            archivo << p->elemento.hora.minuto << " ";
            
            archivo << p->elemento.fecha.dia << " ";
            archivo << p->elemento.fecha.mes << " ";
            archivo << p->elemento.fecha.anio << " ";
            
            archivo << p->elemento.prioritario << " ";
            archivo << p->elemento.descripcion << endl;
            
            p = p->sig;
            
        }
        
        cout << "Las tareas se guardaron en la BD correctamente "<<endl;

    }
}
