#include<iostream>
#include "Pasteles.hpp"
using namespace std;

//se declara aquí porque si no hay problema ya que iterator y aggregate son codependientes
template<class T>
class Iterator;

template<class T>
class Aggregate
{
public:
    friend class Iterator<T>;
    Aggregate(){
        pos = 0;
        size = 10; //tamaño predefinido, pero deberíamos hacer que el arreglo fuera dinámico
        lista = new T[size];
    }
    void add(T element){
        if(pos < size)            
            lista[pos++] = element; 
    }
    Iterator<T>* getIterator(){return new Iterator<T>(this);}
    
    //comentado debido a que da un error de retorno (pointer being freed was not allocated)
    //~Aggregate(){delete [] lista;}

    T getElementAt(int pos){return lista[pos];}

    int getPos(){return pos;}

private:
    T* lista;
    int size;
    int pos;
};

template<class T>
class Iterator
{
public:
    Iterator(Aggregate<T>* aggregate) : idx(0), aggregate(aggregate){}
    
    T next()
    {
        if(hasNext())
            //return aggregate->getElementAt(idx++);
            return aggregate->lista[idx++];
        else
            return 0;
    }
    
    bool hasNext()
    {
        return (idx < aggregate->getPos());
    }
    void buscarPastel(string query, Aggregate <Pastel*> listaPasteles){
        Iterator<Pastel *> * iterador;
        for(iterador = listaPasteles.getIterator(); iterador->hasNext(); )
        {
            if (query == iterador->next()->nombre)
            {
                cout << "Se encontró tu pastel " + query + "!" << endl;
                break;
            }
            else
                cout << "No se encontró tu pastel " + query + "!" << endl;

            //iterador->next()->amasado();
        }
    }
    
    void imprimirPasteles(Aggregate <Pastel*> listaPasteles){
        Iterator<Pastel *> * iterador;
        for(iterador = listaPasteles.getIterator(); iterador->hasNext(); )
        {
            cout << iterador->next()->nombre << endl;
        }
    }
    ~Iterator(){}

private:
    Iterator(){}
    Aggregate<T>* aggregate;
    int idx;
};

