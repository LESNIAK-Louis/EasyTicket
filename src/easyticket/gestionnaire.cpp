#include "gestionnaire.h"

template <class T>
Gestionnaire<T>::Gestionnaire()
{

}

template <class T>
QMap<int,T*> Gestionnaire<T>::getCollection(){
    return collection;
}

template <class T>
T& Gestionnaire<T>::getItem(int id){
    return *(collection.value(id));
}

template <class T>
void Gestionnaire<T>::ajouterItem(T& item){

}
