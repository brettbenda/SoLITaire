#ifndef DECK_H
#define DECK_H
#include <QPushButton>

class Node{
private:
    int number;
    string suit;
    bool faceup;
    Node *next;
    QPushButton card;

public:
    //GETTER & SETTER METHODS
    void SetNum(int n) { number = n; }
    void SetNext(Node *a) { next = a; }
    void SetSuit(char n) { suit = n; }
    void SetFaceup(bool boolean) { faceup = boolean; }
    int Num() { return number; }
    Node *Next() { return next; }
    string Suit() { return suit; }
    bool Faceup() { return faceup; }

};




#endif // DECK_H
