#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>

int maxAux(int,int);

template<typename T>
class LinkedList{
    private:
        Node<T>* pHead;
        Node<T>* pTail;
        Node<T>* pActual;               // 9.
        int _size;
        int RMaximum(Node<T>*);         // 2.
        void Rprint(Node<T>*);          // 3.
        void reverseRPrint(Node<T>*);   // 4.
        T partition( T* , int , int , bool );       // 7. ,8.
        void quickSort( T* , int , int , bool );    // 7. ,8.
    public:
        LinkedList() :pHead(nullptr), pTail(nullptr), pActual(nullptr), _size(0) {}
        LinkedList(int, T);
        ~LinkedList();
        int size() { return _size; }
        void push_back(T);
        void push_front(T);
        Node<T>* get(int);
        void insert(int, T);
        void print();
        //homework
        int Maximum();                  // 1.
        int recursiveMaximun();         // 2.
        void recursivePrint();          // 3.
        void reverseRecursivePrint();   // 4.
        void reversePrint();            // 5.
        int PairCount();                // 6.
        void sortA();                   // 7.   ascendente
        void sortD();                   // 8.   descendente
        void Begin();                   // 10.
        void Last();                    // 11.
        void Next();                    // 12.
        void Previus();                 // 13.
        T GetDato();                    // 14.
        void print2();                  // 15.
        void print3();                  // 16.
};

template<typename T>
LinkedList<T>::LinkedList(int size, T value)
{
    _size = 0;
    while (size--) push_back(value);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* tmp = pHead;
    while (tmp)
    {
        tmp = pHead->getNext();
        delete pHead;
        pHead = tmp;
    }
}

template<typename T>
void LinkedList<T>::push_back(T value)
{
    Node<T>* nodo = new Node<T>(value);
    if (!pHead)                        //si esta vacio
    {
        pHead = nodo;                   //nuevo head
        pTail = pHead;                  //nuevo tail
    }
    else                               //si hay al menos un elemento
    {
        nodo->setPrev(pTail);           // tail <- nodo -> null
        pTail->setNext(nodo);           // tail <-> nodo -> null
        pTail = nodo;                   // nuevo tail
    }
    _size++;
}

template<typename T>
void LinkedList<T>::push_front(T value)
{
    Node<T>* nodo = new Node<T>(value);
    if (!pHead)                        //si esta vacio
    {
        pHead = nodo;                   //nuevo head
        pTail = pHead;                  //nuevo tail
    }
    else                                //si hay al menos un elemento
    {
        nodo->setNext(pHead);           // null <- nodo -> head
        pHead->setPrev(nodo);           // null <- nodo <-> head
        pHead = nodo;                   // nuevo head
    }
    _size++;
}

template<typename T>
Node<T>* LinkedList<T>::get(int pos)      //devuelve puntero por posicion
{
    Node<T>* tmp = nullptr;
    if (pos < _size)                       //si la pos es menor que el tamaño
    {
        tmp = pHead;
        for (int i = 0; i < pos; i++) tmp = tmp->getNext();   //avanza por la lista hasta que i = pos
    }
    return tmp;                             //devuelve puntero en la posicion pos
}

template<typename T>
void LinkedList<T>::insert(int pos, T value)     //inserta elemento por posicion
{
    if (!pHead) push_front(value);                   //si esta vacio inserta al inicio
    else if (pos >= _size) return;                //si pos es mayor o igual al tamaño, termina
    else                                            //en otro caso
    {
        if (pos == 0) push_front(value);             //inserta al inicio
        else if (pos == _size - 1) push_back(value);   //inserta al final
        else
        {
            Node<T>* nodo = new Node<T>(value);
            Node<T>* prev = get(pos - 1);             //obtiene el elemento anterior
            Node<T>* next = prev->getNext();        //guarda el sig
            nodo->setNext(next);                    // null <- nodo -> next
            nodo->setPrev(prev);                    // prev <- nodo -> next
            next->setPrev(nodo);                    // prev <- nodo <-> next
            prev->setNext(nodo);                    // prev <-> nodo -> next
            _size++;
        }
    }
}

template<typename T>
void LinkedList<T>::print()
{
    Node<T>* tmp = pHead;
    while (tmp)
    {
        std::cout << tmp->getValue() << ' ';
        tmp = tmp->getNext();
    }
    std::cout << '\n';
}

template<typename T>
int LinkedList<T>::Maximum()
{
    Node<T>* tmp = pHead;
    int max=tmp->getValue();
    while(tmp)
    {
        if(tmp->getValue()>max)
        {
            max=tmp->getValue();
        }
        tmp = tmp->getNext();
    }
    return max;
}

int maxAux(int a,int b)
{
    if ( a>b ){ return a; }else{ return b; }
}

template<typename T>
int LinkedList<T>::RMaximum(Node<T>* lista)
{   
    int max=lista->getValue();
    if( lista->getNext() == nullptr )
    {
        return lista->getValue();
    }
    else
    {
        lista = lista->getNext();
        return maxAux(max,RMaximum(lista));
    }
}

template<typename T>
int LinkedList<T>::recursiveMaximun()
{
    return RMaximum( pHead );
}

template<typename T>
void LinkedList<T>::Rprint(Node<T>* lista)
{
    if( lista==nullptr )
    {
        std::cout<<std::endl;
        return;
    }
    else
    {
        std::cout<<lista->getValue()<<' ';
        lista = lista->getNext();
        return Rprint(lista);
    }
}

template<typename T>
void LinkedList<T>::recursivePrint()
{
    Rprint( pHead );
}

template<typename T>
void LinkedList<T>::reverseRPrint(Node<T>* lista)
{
    if( lista==nullptr )
    {
        std::cout<<std::endl;
        return;
    }
    else
    {
        std::cout<<lista->getValue()<<' ';
        lista = lista->getPrev();
        return reverseRPrint(lista);
    }
}

template<typename T>
void LinkedList<T>::reverseRecursivePrint()
{
    reverseRPrint( pTail );
}

template<typename T>
void LinkedList<T>::reversePrint()
{
    Node<T>* rTmp = pTail;
    while (rTmp)
    {
        std::cout << rTmp->getValue() << ' ';
        rTmp = rTmp->getPrev();
    }
    std::cout << '\n';
}

template<typename T>
int LinkedList<T>::PairCount()
{
    Node<T>* tmp = pHead;
    int pairs=0;
    while(tmp)
    {
        if( tmp->getValue()%2 == 0 ) pairs++;
        tmp = tmp->getNext();
    }
    return pairs;
}

template<typename T>
T LinkedList<T>::partition( T* a , int i , int j , bool op )
{
    T p = a[i];                         // p es el pivote
    int m = i;                          // m es la posicion donde terminara el pivote ya ordenado
    for (int k = i + 1; k <= j; k++)
    {                                   // avanza por el arreglo
        if (op)                         // true para usar menor
        {   
            if ( a[k] < p )             //si el elemento es menor a pivote
            {                               
                m++;                    //aumenta m
                std::swap(a[k], a[m]);  //intercambia a[K] con a[m], deja a [k] al lado izq de donde ira pivote  
            } 
        }                              
        else                            // para usar mayor
        {
            if ( a[k] > p )
            {                              
                m++;
                std::swap(a[k], a[m]);      
            }                               
        }
    }
    std::swap(a[i], a[m]);                  // intercambia pivote con a[m] y deja al pivote ordenado
                                            // a la izq. de piv estan los menores, a la der. los mayores
    return m;                               // devuelve la posicion de pivote
}

template<typename T>
void LinkedList<T>::quickSort( T* a , int i , int j , bool op)
{
    if (i < j)
    {
        int m = partition( a , i , j , op );            // O(N)
        // a[i..j] -> a[i..m–1], pivot, a[m+1..j]
        quickSort( a , i , m - 1 , op );                // llamada recursiva con el subarreglo a la izq de m
        // a[m] = pivote ya esta ordenado, izq. los menores, der. los mayores
        quickSort( a , m + 1 , j , op );                // llamada recursiva con el subarreglo a la der de m
    }
}

template<typename T>
void LinkedList<T>::sortA()
{
    T* arr = new T[_size];                  //guarda los valores de la lista en un arreglo dinamico
    Node<T>* tmp = pHead;
    for( int i=0 ; tmp ; ++i , tmp = tmp->getNext() ) arr[i]=tmp->getValue();   //copia los valores
    quickSort( arr , 0 , _size-1 , true );                                      //ordena el arrego
    tmp = pHead;
    for( int i=0 ; tmp ; ++i , tmp = tmp->getNext() ) tmp->setValue(arr[i]);    //copia el arreglo ordenado en la lista
    delete arr;
}

template<typename T>
void LinkedList<T>::sortD()
{
    T* arr = new T[_size];                  
    Node<T>* tmp = pHead;
    for( int i=0 ; tmp ; ++i , tmp = tmp->getNext() ) arr[i]=tmp->getValue();
    quickSort( arr , 0 , _size-1 , false );
    tmp = pHead;
    for( int i=0 ; tmp ; ++i , tmp = tmp->getNext() ) tmp->setValue(arr[i]);
    delete arr;
}

//10. void Begin() que coloca el puntero pActual a la cabeza de la lista.         
template<typename T>
void LinkedList<T>::Begin() 
{
    pActual = pHead;
}

//11. void Last() que coloca el puntero pActual a al final de la lista.           
template<typename T>
void LinkedList<T>::Last() 
{
    pActual = pTail;
}

//12. void Next() que mueve el puntero pActual al siguiente nodo.                 
template<typename T>
void LinkedList<T>::Next() 
{
    if ( pActual->getNext() )
        pActual = pActual->getNext();
}

//13. void Previus() que mueve el puntero pActual al nodo anterior.               
template<typename T>
void LinkedList<T>::Previus() 
{
    if ( pActual->getPrev() )
        pActual = pActual->getPrev();
}

//14. T GetDato() que retorna el dato apuntado por pActual.                       
template<typename T>
T LinkedList<T>::GetDato() 
{
    return pActual->getValue();  
}

template<typename T>
void LinkedList<T>::print2()
{
    Begin();
    while(true)
    {
        std::cout<<GetDato()<<' ';
        if( !pActual->getNext() ) break;
        Next();
    }
    std::cout<<'\n';
}

template<typename T>
void LinkedList<T>::print3()
{
    Last();
    while(true)
    {
        std::cout<<GetDato()<<' ';
        if( !pActual->getPrev() ) break;
        Previus();
    }
    std::cout<<'\n';
}

#endif