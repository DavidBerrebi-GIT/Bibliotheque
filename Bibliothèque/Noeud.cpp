#include "Noeud.h"


template <typename T>
Noeud<T>::Noeud() {
	head = nullptr;
	next = nullptr;
}
template <typename T>
Noeud<T>::Noeud(T* value) {
	head = value;
	next = nullptr;
}
template <typename T>
Noeud<T>::Noeud(T* value, Noeud<T>* nextNode) {
	head = value;
	next = nextNode;
}

template <typename T>
void Noeud<T>::ajouterTete(T* value) {
  Noeud<T>* newNode = new Noeud<T>(this->head,this->next);
  this->head = value;
  this->setNext(newNode);
}
