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


#include "tlista.h"


/*
 
 
                        tnodo              tnodo                tnodo
                    ************       ************         ************
                    * elemento *       * elemento *         * elemento *
        tlista      *          *       *          *         *          *
        [-]-------> ************       ************         ************
                    *          *       *          *         *          *
                    *  sig [-]-*-----> *  sig [-]-*-------> *  sig [X] *
                    ************       ************         ************
 
*/


//****************************************************************************

/*!
 * \brief es Vacia-> mira si la lista es vacia o no. 
 * \param tlista-> la lista que queremos comprobar si es vacia o no.E.
 * \return bool -> devuelve True si la lista está vacia. S.
 */

bool esVacia (tlista l){

    return (l == NULL);
}

//****************************************************************************

/*!
 * \brief insertar Principio-> añade un elemento en la primera posición de la lista.
 * \param tlista-> la lista en la que queremos introducir el elemento. E/S.
 * \param telemento-> elemento que queremos introducir. E.
 */

void insertarPrincipio (tlista &l, telemento e){
    
    tnodo * nuevonodo;
    nuevonodo = new tnodo;
    nuevonodo->elemento = e; //(*nuevonodo).elemento = e;
    nuevonodo->sig = l;
    l=nuevonodo;

}

//****************************************************************************

/*!
 * \brief insertar Final-> añade un elemento al final de la lista.
 * \param tlista-> la lista en la que queremos introducir el elemento. E/S.
 * \param telemento-> elemento que queremos introducir. E.
 */

void insertarFinal(tlista&l,telemento e){

    tnodo * nn;
    nn = new tnodo;
    nn->elemento = e;
    
    tposicion p;
    
    if (esVacia(l)){
    
        nn->sig = NULL;
        l = nn;
        
    }else{
    
        for (p = l; p->sig != NULL; p = p->sig) {
            
        }
        
        p->sig = nn;
        nn->sig = NULL;
    }
    

}


//****************************************************************************

/*!
 * \brief buscar posicion-> busca la posicion en la que se encuentra un elemento en la lista.
 * \param tlista-> la lista en la que queremos buscar el elemento. E.
 * \param telemento-> elemento que queremos buscar. E.
 * \return tposicion-> devuelve la posicion en la que se encuentra el elemento. S. 
 */

tposicion buscarPosicion (tlista l, telemento e){
    
    bool encontrado = false;
    tposicion p;
    p = l;
    
    if (!esVacia(l)){
        
    for (p = l; ((encontrado == false) && (p->sig != NULL)); p = p->sig) {
        
        if (comparar(e, p->elemento) == true){
        
            encontrado = true;
        }
        
    }


}
 
    return p;

}

//*************************************************************************

/*!
 * \brief borrar-> elimina el elemento que ocupa la posicion que recibe de entrada.
 * \param tlista-> la lista en la que queremos borrar el elemento. E/S.
 * \param tposicion-> posicion que ocupa el elemento que queremos borrar.E.
 */

void borrar (tlista &l, tposicion p){

    
    tposicion pant;
    
    if (p!=l){
    
        for (pant = l; pant->sig != p; pant = pant->sig) {
            
            
        }
        
        pant->sig = p->sig;
    
        
        
    }else{
    
        l = l->sig;
    
    }
    
    delete p;

}

//****************************************************************************

/*!
 * \brief mostrar-> muestra la lista.
 * \param tlista-> la lista que queremos mostrar. E/S.
 */

void mostrar (tlista l){

    tposicion p;
    
    for (p = l; p != NULL; p = p->sig) {
        
       escribir(p->elemento);
        
    }


}


//****************************************************************************

/*!
 * \brief longitud-> calcula la longitud de la lista.
 * \param tlista-> la lista de la cual queremos saber su longitud. E.
 * \return int -> devuelve un entero que es la longitud de la lista. S.
 */

int longitud(tlista l){

    int contador=0;
    tposicion p;
    
    for (p=l; p!=NULL; p=p->sig) {
        contador++;
    }
    return contador;
}


/**********************************************************************************
 
 Función de comparar para el insertar ordenado
 
 int comparar (ttarea,ttarea)
 si es igual devuelve 0
 si es mayor la primera tarea que se compara que la segunda se devuelve 1
 si es menor la primera tarea que se compara que la segunda se devuelve 2
 
 
 **********************************************************************************/

/*!
 * \brief insertar Ordenado-> añade un elemento ordenado en la lista.
 * \param tlista-> la lista en la que queremos introducir el elemento. E/S.
 * \param telemento-> elemento que queremos introducir. E.
 */
 
 void insertarOrdenado (tlista &l, telemento e){

    tposicion p;
    tposicion pant;
    tnodo *nn;
    nn=new tnodo;
    nn->elemento=e;
    
    if (esVacia(l)){
    
        nn->sig=NULL;
        l=nn;
    
        
    }else{
        
        for (p=l->sig,pant=l; ((p!=NULL)&&(!((comparar(e, pant->elemento)==1)&&(comparar(e, p->elemento)==2)))) ; p=p->sig,pant=pant->sig) {
        
        }
        
        nn->sig=p;
        pant->sig=nn;
        
    
    }
    
    
}

//****************************************************************************

/*!
 * \brief modificar Lista-> modifica la lista, buscando la posicion que queremos modificar y a su vez la tarea amodificar.
 * \param tlista-> la lista queremos modificar. E/S.
 * \param telemento-> elemento que queremos modificar. E.
 * \return bool-> devuelve true si modifica la lista. Devuelve false si no modifica la lista por no haber encontrado el elemento a modificar.  
 */

bool modificarLista(tlista &l,telemento e){
    
    tposicion posicion;
    
    if (!esVacia(l)){
        
    posicion = buscarPosicion(l, e);
    
    modificarTarea(posicion->elemento);
        
    return true;
    } else
     return false;
}


