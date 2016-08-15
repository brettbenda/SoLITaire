#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

namespace Ui {
class MainWindow;
}

//Each Node can be thought of as a card
class Node{
private:
    int number;
    string suit;
    bool faceup;
    Node *next;
    QPushButton* button = NULL;

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
    void SetButton(QPushButton* b)  {  button = b;  }
    QPushButton* getButton()    {
        return button;
    }
};

//Class for the MainWindow, GUI Window with all methods
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    void moveButton(Node* n, int x, int y);
    void raiseButton(Node* n);
    void moveCard(QPushButton *first, QPushButton *second);
    bool fixVector(QPushButton *first, QPushButton *second);
    int findIndex(vector<Node*> input, QPushButton *button);
    bool checkMove(Node* first, Node* second);
    bool CheckMovetoCol(vector<Node*> moving, vector<Node*> adding);
    bool checkFoundationMove(Node* first, Node* second);
    bool fixTablaeuOrFoundation(QPushButton *first, QPushButton *second);
    bool checkFirstFoundation(Node* first, string suit2);
    bool checkFirstTableau(Node* first);
    void flipLast();
    void flipCard(Node* first, bool up);
    void checkWin();
    void moveCardDeckTableau(QPushButton *first, QPushButton *second);

private slots:

    void on_mainMenu_optionsButton_clicked();

    void on_optionsMenu_backToMainMenuButton_clicked();

    void on_mainMenu_startNewGameButton_clicked();

    void on_gameplay_quitGameButton_clicked();

    void on_optionsMenu_changeCardBackDesignButton_clicked();

    void on_cardBackMenu_returnToOptionsMenuButton_clicked();

    void on_optionsMenu_changeBackgroundButton_clicked();

    void on_backgroundMenu_returnToOptionsMenuButton_clicked();

    void on_backgroundMenu_setWoodBackgroundButton_clicked();

    void on_backgroundMenu_setVelvetBackgroundButton_clicked();

    void on_backgroundMenu_setCircuitBackgroundButton_clicked();

    void on_backgroundMenu_setChalkboardBackgroundButton_clicked();

    void on_backgroundMenu_setStarWarsBackgroundButton_clicked();

    void on_backgroundMenu_setMemeBackgroundButton_clicked();

    void on_mainMenu_easterEggButton_clicked();

    void showTime();

    void on_optionsMenu_removeTimerButton_clicked();

    void on_card_1H_clicked();

    void on_card_2H_clicked();

    void on_card_3H_clicked();

    void on_card_4H_clicked();

    void on_card_5H_clicked();

    void on_card_6H_clicked();

    void on_card_7H_clicked();

    void on_card_8H_clicked();

    void on_card_9H_clicked();

    void on_card_10H_clicked();

    void on_card_11H_clicked();

    void on_card_12H_clicked();

    void on_card_13H_clicked();

    void on_card_1D_clicked();

    void on_card_2D_clicked();

    void on_card_3D_clicked();

    void on_card_4D_clicked();

    void on_card_5D_clicked();

    void on_card_6D_clicked();

    void on_card_7D_clicked();

    void on_card_8D_clicked();

    void on_card_9D_clicked();

    void on_card_10D_clicked();

    void on_card_11D_clicked();

    void on_card_12D_clicked();

    void on_card_13D_clicked();

    void on_card_1C_clicked();

    void on_card_2C_clicked();

    void on_card_3C_clicked();

    void on_card_4C_clicked();

    void on_card_5C_clicked();

    void on_card_6C_clicked();

    void on_card_7C_clicked();

    void on_card_8C_clicked();

    void on_card_9C_clicked();

    void on_card_10C_clicked();

    void on_card_11C_clicked();

    void on_card_12C_clicked();

    void on_card_13C_clicked();

    void on_card_1S_clicked();

    void on_card_2S_clicked();

    void on_card_3S_clicked();

    void on_card_4S_clicked();

    void on_card_5S_clicked();

    void on_card_6S_clicked();

    void on_card_7S_clicked();

    void on_card_8S_clicked();

    void on_card_9S_clicked();

    void on_card_10S_clicked();

    void on_card_11S_clicked();

    void on_card_12S_clicked();

    void on_card_13S_clicked();

    void on_foundation_club_clicked();

    void on_foundation_spade_clicked();

    void on_foundation_diamond_clicked();

    void on_foundation_heart_clicked();

    void on_tableau_1_clicked();

    void on_tableau_2_clicked();

    void on_tableau_3_clicked();

    void on_tableau_4_clicked();

    void on_tableau_5_clicked();

    void on_tableau_6_clicked();

    void on_tableau_7_clicked();

    void on_deck_clicked();

    void moveCardtoTableauOrDeck(QPushButton *first, QPushButton *second);

    void moveCardtoFoundation(QPushButton *first, QPushButton *second);

    void moveColumn(QPushButton *first, QPushButton *second);

    void on_setBackOne_clicked();

    void on_setBackTwo_clicked();

    void on_setBackThree_clicked();

    void on_setBackFour_clicked();

    void on_setBackFive_clicked();

    void on_setBackSix_clicked();

private:
};

//List Class for the creation of the deck
class List{
private:
    Node *head;
    int Loc;
    Node *DrawnCard;

public:
    List(vector<string> cards, MainWindow* w);
    vector<Node*> createColumn(int size);

};

#endif // MAINWINDOW_H
