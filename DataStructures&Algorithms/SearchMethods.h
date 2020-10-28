//
// Created by Alexander P on 20/09/11.
//

#include "vector"

using namespace std;

#ifndef FIRST_STEPS_WITH_C___SEARCHMETHODS_H
#define FIRST_STEPS_WITH_C___SEARCHMETHODS_H


template<typename E>
int IterativeBinarySearch(vector<E> &elements, E &request)        // es mas eficiente que el anterior
{
    //~ int resultado;
    int derecha = int(elements.size()) - 1;
    int izquierda = 0;
    int centro = (izquierda + derecha) / 2;
    int pos = 0;
    //~ char *aux=(char*)malloc(strlen(vector[centro])+1);
    //~ strcpy(aux,vector[centro]);

    while (request != elements[centro] && (izquierda <= derecha)) {
        if (request < elements[centro]) {
            derecha = centro - 1;
        } else {
            izquierda = centro + 1;
            centro = (izquierda + derecha) / 2;
        }
    }
    if (izquierda > derecha)
        pos = -1;
    else
        pos = centro;

    return pos;
}

template<typename E>
int RecursiveBinarySearch(vector<E> &elements, int izquierda, int derecha,
                             E &request) {
    if (izquierda > derecha) return -1;
    int indiceDeLaMitad = int(floor((izquierda + derecha) / 2));
    E elementoDeLaMitad = elements.at(indiceDeLaMitad);

    //printf("\n %s",elementoDeLaMitad);

    if(request==elementoDeLaMitad) return indiceDeLaMitad;
//    int resultadoDeLaComparacion = strncmp(request, elementoDeLaMitad, strlen(request));
//    //~ int resultadoDeLaComparacion = strstr(numBuscar, elementoDeLaMitad);
//    // Si son iguales hemos encontrado el elemento
//    if (resultadoDeLaComparacion == 0) return indiceDeLaMitad;

    // Si no, vemos en cuál mitad podría estar

    // ¿A la izquierda?
    if (request<elementoDeLaMitad) {
        derecha = indiceDeLaMitad - 1;
    } else {
        // A la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    // Recursión justo aquí
    return RecursiveBinarySearch(elements, izquierda, derecha, request);
}

template<typename E>
int BinarySearch(vector<E> &elements, E &request) {
    int central, bajo, alto;
    E valorCentral;
    bajo = 0;
    alto = int(elements.size()) - 1;
    int pos = 0;
    while (bajo <= alto) {
        central = (bajo + alto) / 2; /* índice de elemento central */
        valorCentral = elements.at(central); /* valor del índice central */
        if (request==valorCentral) {
            pos = central;
            break;
        }
            //~ return central; /* encontrado, devuelve posición */
        else if (request<valorCentral)
            alto = central - 1; /* ir a sublista inferior */
        else
            bajo = central + 1; /* ir a sublista superior */
    }
    //~ if(!(bajo <= alto))pos=-1;
//    printf("\npos: %i", pos);
    //~ return -1; /* elemento no encontrado */
    return pos;
}

#endif //FIRST_STEPS_WITH_C___SEARCHMETHODS_H
