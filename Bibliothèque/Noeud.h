#ifndef NOEUD_H
#define NOEUD_H

template <typename T>
class Noeud {
private:
 T* head;
 Noeud<T>* next;

public:
 Noeud();
 Noeud(T*);
 Noeud(T*, Noeud<T>*);
 virtual ~Noeud();
 T* getHead() { return head; }
 Noeud<T>* getNext() { return next; }
 void setNext(Noeud<T>* nextNode) { next = nextNode; }

 void ajouterTete(T*);
};
#endif  // NOEUD_H
