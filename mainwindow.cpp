//
//IMPLEMENTATION
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
using namespace std;

//VARIABLES
int clockTime = 0;
bool visibleTimer = true;
bool selected = false;
QPushButton *first;
QPushButton *second;
vector<QPushButton> column;
vector<Node*> col1;
vector<Node*> col2;
vector<Node*> col3;
vector<Node*> col4;
vector<Node*> col5;
vector<Node*> col6;
vector<Node*> col7;
vector<Node*> foundDeck;
vector<Node*> foundDrawn;
vector<Node*> foundClubs;
vector<Node*> foundDiamonds;
vector<Node*> foundSpades;
vector<Node*> foundHearts;
QString cardBack = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackBlue.jpg");
QString backOne = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackBlue.jpg");
QString backTwo = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackRed.jpg");
QString backThree = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackGreen.jpg");
QString backFour = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackGator.jpg");
QString backFive = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/Liu.jpg");
QString backSix = QString("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Backs/cardBackBasketball.jpg");

//CONSTRUCTOR - creates a 52 card deck
List::List(vector<string> cards, MainWindow* w) {
    head = new Node();
    DrawnCard = NULL;
    Loc = 0;
    Node* temp = head;
    for (int i = 0; i < 52; i++) {
        string suit = cards[i];
        //if the number is 10,11,12,13
        if (suit[1] == 48 || suit[1] == 49 || suit[1] == 50 || suit[1] == 51)
        {
            temp->SetSuit(suit[2]);
            int num1 = suit[0];
            int num2 = suit[1];
            int num = num1 + num2;
            num -= 97;
            temp->SetNum(num + 10);
        }
        else {
            temp->SetSuit(suit[1]);
            int num = suit[0];
            num = num - 48;
            temp->SetNum(num);
            temp->SetFaceup(false);
        }
        Node *card = new Node();

        //Assign Each Node to a QPushButton
        if(temp->Suit() == "S" && temp->Num() == 1)    {
           card->SetButton(w->ui->card_1S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 2)   {
            card->SetButton(w->ui->card_2S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 3)   {
            card->SetButton(w->ui->card_3S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 4)   {
            card->SetButton(w->ui->card_4S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 5)   {
            card->SetButton(w->ui->card_5S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 6)   {
            card->SetButton(w->ui->card_6S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 7)   {
            card->SetButton(w->ui->card_7S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 8)   {
            card->SetButton(w->ui->card_8S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 9)   {
            card->SetButton(w->ui->card_9S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 10)   {
            card->SetButton(w->ui->card_10S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 11)   {
            card->SetButton(w->ui->card_11S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 12)   {
            card->SetButton(w->ui->card_12S);
        }
        else if(temp->Suit() == "S" && temp->Num() == 13)   {
            card->SetButton(w->ui->card_13S);
        }
        else if(temp->Suit() == "D" && temp->Num() == 1)   {
            card->SetButton(w->ui->card_1D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 2)   {
            card->SetButton(w->ui->card_2D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 3)   {
            card->SetButton(w->ui->card_3D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 4)   {
            card->SetButton(w->ui->card_4D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 5)   {
            card->SetButton(w->ui->card_5D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 6)   {
            card->SetButton(w->ui->card_6D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 7)   {
            card->SetButton(w->ui->card_7D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 8)   {
            card->SetButton(w->ui->card_8D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 9)   {
            card->SetButton(w->ui->card_9D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 10)   {
            card->SetButton(w->ui->card_10D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 11)   {
            card->SetButton(w->ui->card_11D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 12)   {
            card->SetButton(w->ui->card_12D);
        }
        else if(temp->Suit() == "D" && temp->Num() == 13)   {
            card->SetButton(w->ui->card_13D);
        }
        else if(temp->Suit() == "H" && temp->Num() == 1)   {
            card->SetButton(w->ui->card_1H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 2)   {
            card->SetButton(w->ui->card_2H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 3)   {
            card->SetButton(w->ui->card_3H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 4)   {
            card->SetButton(w->ui->card_4H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 5)   {
            card->SetButton(w->ui->card_5H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 6)   {
            card->SetButton(w->ui->card_6H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 7)   {
            card->SetButton(w->ui->card_7H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 8)   {
            card->SetButton(w->ui->card_8H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 9)   {
            card->SetButton(w->ui->card_9H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 10)   {
            card->SetButton(w->ui->card_10H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 11)   {
            card->SetButton(w->ui->card_11H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 12)   {
            card->SetButton(w->ui->card_12H);
        }
        else if(temp->Suit() == "H" && temp->Num() == 13)   {
            card->SetButton(w->ui->card_13H);
        }
        else if(temp->Suit() == "C" && temp->Num() == 1)   {
            card->SetButton(w->ui->card_1C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 2)   {
            card->SetButton(w->ui->card_2C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 3)   {
            card->SetButton(w->ui->card_3C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 4)   {
            card->SetButton(w->ui->card_4C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 5)   {
            card->SetButton(w->ui->card_5C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 6)   {
            card->SetButton(w->ui->card_6C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 7)   {
            card->SetButton(w->ui->card_7C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 8)   {
            card->SetButton(w->ui->card_8C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 9)   {
            card->SetButton(w->ui->card_9C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 10)   {
            card->SetButton(w->ui->card_10C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 11)   {
            card->SetButton(w->ui->card_11C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 12)   {
            card->SetButton(w->ui->card_12C);
        }
        else if(temp->Suit() == "C" && temp->Num() == 13)   {
            card->SetButton(w->ui->card_13C);
        }
        temp->SetNext(card);
        temp = temp->Next();
    }
}

//CREATE COLUMN - creates the columns
vector<Node*> List::createColumn(int n) {
    //Creates a vector that contains the Node pointers of specified size
    Node* current = head;
    vector<Node*> arr;
    if (n == 0) {
        return arr;
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            current->SetFaceup(true); //places the last card of each column faceup
        }
        arr.push_back(current);
        current = current->Next();

    }
    head = current;//Removes the first n nodes,they're in the vector list now, moves linked list head
    return arr;
}

//FUNCTIONS
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(600);
    this->setFixedWidth(900);

    //Button images
    ui->cardBack_1->setPixmap(QPixmap(backOne));
    ui->cardBack_2->setPixmap(QPixmap(backTwo));
    ui->cardBack_3->setPixmap(QPixmap(backThree));
    ui->cardBack_4->setPixmap(QPixmap(backFour));
    ui->cardBack_5->setPixmap(QPixmap(backFive));
    ui->cardBack_6->setPixmap(QPixmap(backSix));



    //Visibility
    ui->mainMenu->setVisible(true);
    ui->optionsMenu->setVisible(false);
    ui->gameplay->setVisible(false);
    ui->cardBackMenu->setVisible(false);
    ui->backgroundMenu->setVisible(false);

    //Main Menu
    //  --- Background
    QPixmap background("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->mainMenu_background->setPixmap(background);
    QPixmap logo("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Extra Graphics/SoLITaire Logo.png");
    ui->mainMenu_logo->setPixmap(logo);
    //  --- Easter Egg
    QPixmap easterEgg("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Extra Graphics/DoctaLiu.jpg");
    ui->DoctaLiu->setPixmap(easterEgg);
    ui->DoctaLiu->setVisible(false);
    ui->mainMenu_easterEggButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //Options Menu
    QPixmap background2("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->optionsMenu_background->setPixmap(background2);
    QPixmap logo2("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Extra Graphics/SoLITaire Logo.png");
    ui->optionsMenu_design->setPixmap(logo2);

    //Gameplay Menu
    //  --- Background
    QPixmap background3("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->gameplay_background->setPixmap(background3);
    //  --- Timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    //  --- Templates
    ui->foundation_heart->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/foundation_heart.png"));
    ui->foundation_heart->setIconSize(QSize(74, 97));
    ui->foundation_heart->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->foundation_spade->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/foundation_spade.png"));
    ui->foundation_spade->setIconSize(QSize(74, 97));
    ui->foundation_spade->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->foundation_diamond->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/foundation_diamond.png"));
    ui->foundation_diamond->setIconSize(QSize(74, 97));
    ui->foundation_diamond->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->foundation_club->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/foundation_club.png"));
    ui->foundation_club->setIconSize(QSize(74, 97));
    ui->foundation_club->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_1->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_1->setIconSize(QSize(74, 97));
    ui->tableau_1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_2->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_2->setIconSize(QSize(74, 97));
    ui->tableau_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_3->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_3->setIconSize(QSize(74, 97));
    ui->tableau_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_4->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_4->setIconSize(QSize(74, 97));
    ui->tableau_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_5->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_5->setIconSize(QSize(74, 97));
    ui->tableau_5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_6->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_6->setIconSize(QSize(74, 97));
    ui->tableau_6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->tableau_7->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/tableau.png"));
    ui->tableau_7->setIconSize(QSize(74, 97));
    ui->tableau_7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->deck->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Foundations/deck.png"));
    ui->deck->setIconSize(QSize(74, 97));
    ui->deck->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //  --- Cards
    ui->card_1H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1H.GIF"));
    ui->card_1H->setIconSize(QSize(74, 97));
    ui->card_2H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2H.GIF"));
    ui->card_2H->setIconSize(QSize(74, 97));
    ui->card_3H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3H.GIF"));
    ui->card_3H->setIconSize(QSize(74, 97));
    ui->card_4H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4H.GIF"));
    ui->card_4H->setIconSize(QSize(74, 97));
    ui->card_5H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5H.GIF"));
    ui->card_5H->setIconSize(QSize(74, 97));
    ui->card_6H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6H.GIF"));
    ui->card_6H->setIconSize(QSize(74, 97));
    ui->card_7H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7H.GIF"));
    ui->card_7H->setIconSize(QSize(74, 97));
    ui->card_8H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8H.GIF"));
    ui->card_8H->setIconSize(QSize(74, 97));
    ui->card_9H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9H.GIF"));
    ui->card_9H->setIconSize(QSize(74, 97));
    ui->card_10H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10H.GIF"));
    ui->card_10H->setIconSize(QSize(74, 97));
    ui->card_11H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11H.GIF"));
    ui->card_11H->setIconSize(QSize(74, 97));
    ui->card_12H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12H.GIF"));
    ui->card_12H->setIconSize(QSize(74, 97));
    ui->card_13H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13H.GIF"));
    ui->card_13H->setIconSize(QSize(74, 97));
    ui->card_1C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1C.GIF"));
    ui->card_1C->setIconSize(QSize(74, 97));
    ui->card_2C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2C.GIF"));
    ui->card_2C->setIconSize(QSize(74, 97));
    ui->card_3C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3C.GIF"));
    ui->card_3C->setIconSize(QSize(74, 97));
    ui->card_4C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4C.GIF"));
    ui->card_4C->setIconSize(QSize(74, 97));
    ui->card_5C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5C.GIF"));
    ui->card_5C->setIconSize(QSize(74, 97));
    ui->card_6C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6C.GIF"));
    ui->card_6C->setIconSize(QSize(74, 97));
    ui->card_7C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7C.GIF"));
    ui->card_7C->setIconSize(QSize(74, 97));
    ui->card_8C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8C.GIF"));
    ui->card_8C->setIconSize(QSize(74, 97));
    ui->card_9C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9C.GIF"));
    ui->card_9C->setIconSize(QSize(74, 97));
    ui->card_10C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10C.GIF"));
    ui->card_10C->setIconSize(QSize(74, 97));
    ui->card_11C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11C.GIF"));
    ui->card_11C->setIconSize(QSize(74, 97));
    ui->card_12C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12C.GIF"));
    ui->card_12C->setIconSize(QSize(74, 97));
    ui->card_13C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13C.GIF"));
    ui->card_13C->setIconSize(QSize(74, 97));
    ui->card_1D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1D.GIF"));
    ui->card_1D->setIconSize(QSize(74, 97));
    ui->card_2D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2D.GIF"));
    ui->card_2D->setIconSize(QSize(74, 97));
    ui->card_3D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3D.GIF"));
    ui->card_3D->setIconSize(QSize(74, 97));
    ui->card_4D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4D.GIF"));
    ui->card_4D->setIconSize(QSize(74, 97));
    ui->card_5D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5D.GIF"));
    ui->card_5D->setIconSize(QSize(74, 97));
    ui->card_6D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6D.GIF"));
    ui->card_6D->setIconSize(QSize(74, 97));
    ui->card_7D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7D.GIF"));
    ui->card_7D->setIconSize(QSize(74, 97));
    ui->card_8D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8D.GIF"));
    ui->card_8D->setIconSize(QSize(74, 97));
    ui->card_9D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9D.GIF"));
    ui->card_9D->setIconSize(QSize(74, 97));
    ui->card_10D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10D.GIF"));
    ui->card_10D->setIconSize(QSize(74, 97));
    ui->card_11D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11D.GIF"));
    ui->card_11D->setIconSize(QSize(74, 97));
    ui->card_12D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12D.GIF"));
    ui->card_12D->setIconSize(QSize(74, 97));
    ui->card_13D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13D.GIF"));
    ui->card_13D->setIconSize(QSize(74, 97));
    ui->card_1S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1S.GIF"));
    ui->card_1S->setIconSize(QSize(74, 97));
    ui->card_2S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2S.GIF"));
    ui->card_2S->setIconSize(QSize(74, 97));
    ui->card_3S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3S.GIF"));
    ui->card_3S->setIconSize(QSize(74, 97));
    ui->card_4S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4S.GIF"));
    ui->card_4S->setIconSize(QSize(74, 97));
    ui->card_5S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5S.GIF"));
    ui->card_5S->setIconSize(QSize(74, 97));
    ui->card_6S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6S.GIF"));
    ui->card_6S->setIconSize(QSize(74, 97));
    ui->card_7S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7S.GIF"));
    ui->card_7S->setIconSize(QSize(74, 97));
    ui->card_8S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8S.GIF"));
    ui->card_8S->setIconSize(QSize(74, 97));
    ui->card_9S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9S.GIF"));
    ui->card_9S->setIconSize(QSize(74, 97));
    ui->card_10S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10S.GIF"));
    ui->card_10S->setIconSize(QSize(74, 97));
    ui->card_11S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11S.GIF"));
    ui->card_11S->setIconSize(QSize(74, 97));
    ui->card_12S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12S.GIF"));
    ui->card_12S->setIconSize(QSize(74, 97));
    ui->card_13S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13S.GIF"));
    ui->card_13S->setIconSize(QSize(74, 97));

    //Card Back Menu
    QPixmap background4("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->cardBackMenu_background->setPixmap(background4);

    //Background Menu
    //  --- Background
    QPixmap background5("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->backgroundMenu_background->setPixmap(background5);
    //  --- Background Icon
    QPixmap backgroundWoodIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundWoodIcon.jpg");
    ui->backgroundMenu_backgroundWoodIcon->setPixmap(backgroundWoodIcon);
    QPixmap backgroundVelvetIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundVelvetIcon.jpg");
    ui->backgroundMenu_backgroundVelvetIcon->setPixmap(backgroundVelvetIcon);
    QPixmap backgroundCircuitIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundCircuitIcon.jpg");
    ui->backgroundMenu_backgroundCircuitIcon->setPixmap(backgroundCircuitIcon);
    QPixmap backgroundChalkboardIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundChalkboardIcon.jpg");
    ui->backgroundMenu_backgroundChalkboardIcon->setPixmap(backgroundChalkboardIcon);
    QPixmap backgroundStarWarsIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundStarWarsIcon.jpg");
    ui->backgroundMenu_backgroundStarWarsIcon->setPixmap(backgroundStarWarsIcon);
    QPixmap backgroundMemeIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundMemeIcon.jpg");
    ui->backgroundMenu_backgroundMemeIcon->setPixmap(backgroundMemeIcon);

    //Deck Code
    vector<string> shuffler;
    shuffler.push_back("1C");
    shuffler.push_back("2C");
    shuffler.push_back("3C");
    shuffler.push_back("4C");
    shuffler.push_back("5C");
    shuffler.push_back("6C");
    shuffler.push_back("7C");
    shuffler.push_back("8C");
    shuffler.push_back("9C");
    shuffler.push_back("10C");
    shuffler.push_back("11C");
    shuffler.push_back("12C");
    shuffler.push_back("13C");
    shuffler.push_back("1D");
    shuffler.push_back("2D");
    shuffler.push_back("3D");
    shuffler.push_back("4D");
    shuffler.push_back("5D");
    shuffler.push_back("6D");
    shuffler.push_back("7D");
    shuffler.push_back("8D");
    shuffler.push_back("9D");
    shuffler.push_back("10D");
    shuffler.push_back("11D");
    shuffler.push_back("12D");
    shuffler.push_back("13D");
    shuffler.push_back("1S");
    shuffler.push_back("2S");
    shuffler.push_back("3S");
    shuffler.push_back("4S");
    shuffler.push_back("5S");
    shuffler.push_back("6S");
    shuffler.push_back("7S");
    shuffler.push_back("8S");
    shuffler.push_back("9S");
    shuffler.push_back("10S");
    shuffler.push_back("11S");
    shuffler.push_back("12S");
    shuffler.push_back("13S");
    shuffler.push_back("1H");
    shuffler.push_back("2H");
    shuffler.push_back("3H");
    shuffler.push_back("4H");
    shuffler.push_back("5H");
    shuffler.push_back("6H");
    shuffler.push_back("7H");
    shuffler.push_back("8H");
    shuffler.push_back("9H");
    shuffler.push_back("10H");
    shuffler.push_back("11H");
    shuffler.push_back("12H");
    shuffler.push_back("13H");

    //  --- Shuffle the 52-long vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(shuffler.begin(), shuffler.end(), default_random_engine(seed));

    //  --- Creating the 52-card deck object
    List* deck = new List(shuffler, this);

    //Create columns of the tableau
    col1 = deck->createColumn(1);
    col2 = deck->createColumn(2);
    col3 = deck->createColumn(3);
    col4 = deck->createColumn(4);
    col5 = deck->createColumn(5);
    col6 = deck->createColumn(6);
    col7 = deck->createColumn(7);

    //create foundations
    foundClubs = deck->createColumn(0);
    foundDiamonds = deck->createColumn(0);
    foundSpades = deck->createColumn(0);
    foundHearts = deck->createColumn(0);
    foundDeck = deck->createColumn(24);
    foundDrawn = deck->createColumn(0);


    //Create columns
    int x = 20;
    int y = 190;

    //Move column vectors to appropriate columns
    for (unsigned int i = 0; i < col1.size(); i++) {
        moveButton(col1.at(i), x, y);
        raiseButton(col1.at(i));
        y += 30;

        if(i < col1.size()-1){
            flipCard(col1.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col2.size(); i++) {
        moveButton(col2.at(i), x, y);
        raiseButton(col2.at(i));
        y += 30;

        if(i < col2.size()-1){
            flipCard(col2.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col3.size(); i++) {
        moveButton(col3.at(i), x, y);
        raiseButton(col3.at(i));
        y += 30;

        if(i < col3.size()-1){
            flipCard(col3.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col4.size(); i++) {
        moveButton(col4.at(i), x, y);
        raiseButton(col4.at(i));
        y += 30;

        if(i < col4.size()-1){
            flipCard(col4.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col5.size(); i++) {
        moveButton(col5.at(i), x, y);
        raiseButton(col5.at(i));
        y += 30;

        if(i < col5.size()-1){
            flipCard(col5.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col6.size(); i++) {
        moveButton(col6.at(i), x, y);
        raiseButton(col6.at(i));
        y += 30;

        if(i < col6.size()-1){
            flipCard(col6.at(i), false);
        }
    }

    x += 130;
    y = 190;
    for (unsigned int i = 0; i < col7.size(); i++) {
        moveButton(col7.at(i), x, y);
        raiseButton(col7.at(i));
        y += 30;

        if(i < col7.size()-1){
            flipCard(col7.at(i), false);
        }
    }

    //create deck
    x = 760;
    y = 42;

    for (unsigned int i = 0; i < foundDeck.size(); i++) {
        moveButton(foundDeck.at(i), x, y);
        raiseButton(foundDeck.at(i));
    }
    ui->deck->raise();
}

//Flips Card from back to front
void MainWindow::flipCard(Node* first, bool up){
    if(up){
        if(first->Num()==1 && first->Suit().compare("H")==0){
            ui->card_1H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1H.GIF"));
            ui->card_1H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==2 && first->Suit().compare("H")==0){
            ui->card_2H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2H.GIF"));
            ui->card_2H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==3 && first->Suit().compare("H")==0){
            ui->card_3H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3H.GIF"));
            ui->card_3H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==4 && first->Suit().compare("H")==0){
            ui->card_4H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4H.GIF"));
            ui->card_4H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==5 && first->Suit().compare("H")==0){
            ui->card_5H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5H.GIF"));
            ui->card_5H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==6 && first->Suit().compare("H")==0){
            ui->card_6H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6H.GIF"));
            ui->card_6H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==7 && first->Suit().compare("H")==0){
            ui->card_7H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7H.GIF"));
            ui->card_7H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==8 && first->Suit().compare("H")==0){
            ui->card_8H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8H.GIF"));
            ui->card_8H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==9 && first->Suit().compare("H")==0){
            ui->card_9H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9H.GIF"));
            ui->card_9H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==10 && first->Suit().compare("H")==0){
            ui->card_10H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10H.GIF"));
            ui->card_10H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==11 && first->Suit().compare("H")==0){
            ui->card_11H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11H.GIF"));
            ui->card_11H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==12 && first->Suit().compare("H")==0){
            ui->card_12H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12H.GIF"));
            ui->card_12H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==13 && first->Suit().compare("H")==0){
            ui->card_13H->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13H.GIF"));
            ui->card_13H->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==1 && first->Suit().compare("C")==0){
            ui->card_1C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1C.GIF"));
            ui->card_1C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==2 && first->Suit().compare("C")==0){
            ui->card_2C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2C.GIF"));
            ui->card_2C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==3 && first->Suit().compare("C")==0){
            ui->card_3C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3C.GIF"));
            ui->card_3C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==4 && first->Suit().compare("C")==0){
            ui->card_4C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4C.GIF"));
            ui->card_4C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==5 && first->Suit().compare("C")==0){
            ui->card_5C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5C.GIF"));
            ui->card_5C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==6 && first->Suit().compare("C")==0){
            ui->card_6C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6C.GIF"));
            ui->card_6C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==7 && first->Suit().compare("C")==0){
            ui->card_7C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7C.GIF"));
            ui->card_7C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==8 && first->Suit().compare("C")==0){
            ui->card_8C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8C.GIF"));
            ui->card_8C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==9 && first->Suit().compare("C")==0){
            ui->card_9C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9C.GIF"));
            ui->card_9C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==10 && first->Suit().compare("C")==0){
            ui->card_10C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10C.GIF"));
            ui->card_10C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==11 && first->Suit().compare("C")==0){
            ui->card_11C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11C.GIF"));
            ui->card_11C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==12 && first->Suit().compare("C")==0){
            ui->card_12C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12C.GIF"));
            ui->card_12C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==13 && first->Suit().compare("C")==0){
            ui->card_13C->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13C.GIF"));
            ui->card_13C->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==1 && first->Suit().compare("S")==0){
            ui->card_1S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1S.GIF"));
            ui->card_1S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==2 && first->Suit().compare("S")==0){
            ui->card_2S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2S.GIF"));
            ui->card_2S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==3 && first->Suit().compare("S")==0){
            ui->card_3S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3S.GIF"));
            ui->card_3S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==4 && first->Suit().compare("S")==0){
            ui->card_4S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4S.GIF"));
            ui->card_4S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==5 && first->Suit().compare("S")==0){
            ui->card_5S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5S.GIF"));
            ui->card_5S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==6 && first->Suit().compare("S")==0){
            ui->card_6S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6S.GIF"));
            ui->card_6S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==7 && first->Suit().compare("S")==0){
            ui->card_7S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7S.GIF"));
            ui->card_7S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==8 && first->Suit().compare("S")==0){
            ui->card_8S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8S.GIF"));
            ui->card_8S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==9 && first->Suit().compare("S")==0){
            ui->card_9S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9S.GIF"));
            ui->card_9S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==10 && first->Suit().compare("S")==0){
            ui->card_10S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10S.GIF"));
            ui->card_10S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==11 && first->Suit().compare("S")==0){
            ui->card_11S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11S.GIF"));
            ui->card_11S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==12 && first->Suit().compare("S")==0){
            ui->card_12S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12S.GIF"));
            ui->card_12S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==13 && first->Suit().compare("S")==0){
            ui->card_13S->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13S.GIF"));
            ui->card_13S->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==1 && first->Suit().compare("D")==0){
            ui->card_1D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_1D.GIF"));
            ui->card_1D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==2 && first->Suit().compare("D")==0){
            ui->card_2D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_2D.GIF"));
            ui->card_2D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==3 && first->Suit().compare("D")==0){
            ui->card_3D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_3D.GIF"));
            ui->card_3D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==4 && first->Suit().compare("D")==0){
            ui->card_4D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_4D.GIF"));
            ui->card_4D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==5 && first->Suit().compare("D")==0){
            ui->card_5D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_5D.GIF"));
            ui->card_5D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==6 && first->Suit().compare("D")==0){
            ui->card_6D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_6D.GIF"));
            ui->card_6D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==7 && first->Suit().compare("D")==0){
            ui->card_7D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_7D.GIF"));
            ui->card_7D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==8 && first->Suit().compare("D")==0){
            ui->card_8D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_8D.GIF"));
            ui->card_8D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==9 && first->Suit().compare("D")==0){
            ui->card_9D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_9D.GIF"));
            ui->card_9D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==10 && first->Suit().compare("D")==0){
            ui->card_10D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_10D.GIF"));
            ui->card_10D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==11 && first->Suit().compare("D")==0){
            ui->card_11D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_11D.GIF"));
            ui->card_11D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==12 && first->Suit().compare("D")==0){
            ui->card_12D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_12D.GIF"));
            ui->card_12D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }else if(first->Num()==13 && first->Suit().compare("D")==0){
            ui->card_13D->setIcon(QIcon("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Card Fronts/Card Front_Regular/card_13D.GIF"));
            ui->card_13D->setIconSize(QSize(74, 97));
            first->SetFaceup(true);
        }
    }else{
        if(first->Num()==1 && first->Suit().compare("H")==0){
            ui->card_1H->setIcon(QIcon(cardBack));
            ui->card_1H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==2 && first->Suit().compare("H")==0){
            ui->card_2H->setIcon(QIcon(cardBack));
            ui->card_2H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==3 && first->Suit().compare("H")==0){
            ui->card_3H->setIcon(QIcon(cardBack));
            ui->card_3H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==4 && first->Suit().compare("H")==0){
            ui->card_4H->setIcon(QIcon(cardBack));
            ui->card_4H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==5 && first->Suit().compare("H")==0){
            ui->card_5H->setIcon(QIcon(cardBack));
            ui->card_5H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==6 && first->Suit().compare("H")==0){
            ui->card_6H->setIcon(QIcon(cardBack));
            ui->card_6H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==7 && first->Suit().compare("H")==0){
            ui->card_7H->setIcon(QIcon(cardBack));
            ui->card_7H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==8 && first->Suit().compare("H")==0){
            ui->card_8H->setIcon(QIcon(cardBack));
            ui->card_8H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==9 && first->Suit().compare("H")==0){
            ui->card_9H->setIcon(QIcon(cardBack));
            ui->card_9H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==10 && first->Suit().compare("H")==0){
            ui->card_10H->setIcon(QIcon(cardBack));
            ui->card_10H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==11 && first->Suit().compare("H")==0){
            ui->card_11H->setIcon(QIcon(cardBack));
            ui->card_11H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==12 && first->Suit().compare("H")==0){
            ui->card_12H->setIcon(QIcon(cardBack));
            ui->card_12H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==13 && first->Suit().compare("H")==0){
            ui->card_13H->setIcon(QIcon(cardBack));
            ui->card_13H->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==1 && first->Suit().compare("C")==0){
            ui->card_1C->setIcon(QIcon(cardBack));
            ui->card_1C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==2 && first->Suit().compare("C")==0){
            ui->card_2C->setIcon(QIcon(cardBack));
            ui->card_2C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==3 && first->Suit().compare("C")==0){
            ui->card_3C->setIcon(QIcon(cardBack));
            ui->card_3C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==4 && first->Suit().compare("C")==0){
            ui->card_4C->setIcon(QIcon(cardBack));
            ui->card_4C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==5 && first->Suit().compare("C")==0){
            ui->card_5C->setIcon(QIcon(cardBack));
            ui->card_5C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==6 && first->Suit().compare("C")==0){
            ui->card_6C->setIcon(QIcon(cardBack));
            ui->card_6C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==7 && first->Suit().compare("C")==0){
            ui->card_7C->setIcon(QIcon(cardBack));
            ui->card_7C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==8 && first->Suit().compare("C")==0){
            ui->card_8C->setIcon(QIcon(cardBack));
            ui->card_8C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==9 && first->Suit().compare("C")==0){
            ui->card_9C->setIcon(QIcon(cardBack));
            ui->card_9C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==10 && first->Suit().compare("C")==0){
            ui->card_10C->setIcon(QIcon(cardBack));
            ui->card_10C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==11 && first->Suit().compare("C")==0){
            ui->card_11C->setIcon(QIcon(cardBack));
            ui->card_11C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==12 && first->Suit().compare("C")==0){
            ui->card_12C->setIcon(QIcon(cardBack));
            ui->card_12C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==13 && first->Suit().compare("C")==0){
            ui->card_13C->setIcon(QIcon(cardBack));
            ui->card_13C->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==1 && first->Suit().compare("S")==0){
            ui->card_1S->setIcon(QIcon(cardBack));
            ui->card_1S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==2 && first->Suit().compare("S")==0){
            ui->card_2S->setIcon(QIcon(cardBack));
            ui->card_2S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==3 && first->Suit().compare("S")==0){
            ui->card_3S->setIcon(QIcon(cardBack));
            ui->card_3S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==4 && first->Suit().compare("S")==0){
            ui->card_4S->setIcon(QIcon(cardBack));
            ui->card_4S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==5 && first->Suit().compare("S")==0){
            ui->card_5S->setIcon(QIcon(cardBack));
            ui->card_5S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==6 && first->Suit().compare("S")==0){
            ui->card_6S->setIcon(QIcon(cardBack));
            ui->card_6S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==7 && first->Suit().compare("S")==0){
            ui->card_7S->setIcon(QIcon(cardBack));
            ui->card_7S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==8 && first->Suit().compare("S")==0){
            ui->card_8S->setIcon(QIcon(cardBack));
            ui->card_8S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==9 && first->Suit().compare("S")==0){
            ui->card_9S->setIcon(QIcon(cardBack));
            ui->card_9S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==10 && first->Suit().compare("S")==0){
            ui->card_10S->setIcon(QIcon(cardBack));
            ui->card_10S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==11 && first->Suit().compare("S")==0){
            ui->card_11S->setIcon(QIcon(cardBack));
            ui->card_11S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==12 && first->Suit().compare("S")==0){
            ui->card_12S->setIcon(QIcon(cardBack));
            ui->card_12S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==13 && first->Suit().compare("S")==0){
            ui->card_13S->setIcon(QIcon(cardBack));
            ui->card_13S->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==1 && first->Suit().compare("D")==0){
            ui->card_1D->setIcon(QIcon(cardBack));
            ui->card_1D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==2 && first->Suit().compare("D")==0){
            ui->card_2D->setIcon(QIcon(cardBack));
            ui->card_2D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==3 && first->Suit().compare("D")==0){
            ui->card_3D->setIcon(QIcon(cardBack));
            ui->card_3D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==4 && first->Suit().compare("D")==0){
            ui->card_4D->setIcon(QIcon(cardBack));
            ui->card_4D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==5 && first->Suit().compare("D")==0){
            ui->card_5D->setIcon(QIcon(cardBack));
            ui->card_5D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==6 && first->Suit().compare("D")==0){
            ui->card_6D->setIcon(QIcon(cardBack));
            ui->card_6D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==7 && first->Suit().compare("D")==0){
            ui->card_7D->setIcon(QIcon(cardBack));
            ui->card_7D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==8 && first->Suit().compare("D")==0){
            ui->card_8D->setIcon(QIcon(cardBack));
            ui->card_8D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==9 && first->Suit().compare("D")==0){
            ui->card_9D->setIcon(QIcon(cardBack));
            ui->card_9D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==10 && first->Suit().compare("D")==0){
            ui->card_10D->setIcon(QIcon(cardBack));
            ui->card_10D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==11 && first->Suit().compare("D")==0){
            ui->card_11D->setIcon(QIcon(cardBack));
            ui->card_11D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==12 && first->Suit().compare("D")==0){
            ui->card_12D->setIcon(QIcon(cardBack));
            ui->card_12D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }else if(first->Num()==13 && first->Suit().compare("D")==0){
            ui->card_13D->setIcon(QIcon(cardBack));
            ui->card_13D->setIconSize(QSize(74, 97));
            first->SetFaceup(false);
        }
    }

}

//Moves the button based on the node
void MainWindow::moveButton(Node* n, int x, int y)   {
    int num = n->Num();
    string suit = n->Suit();

    //Assign Each Node to move a QPushButton
    if(suit == "S" && num == 1)    {
       ui->card_1S->move(x, y);
    }
    else if(suit == "S" && num == 2)   {
        ui->card_2S->move(x, y);
    }
    else if(suit == "S" && num == 3)   {
        ui->card_3S->move(x, y);
    }
    else if(suit == "S" && num == 4)   {
        ui->card_4S->move(x, y);
    }
    else if(suit == "S" && num == 5)   {
        ui->card_5S->move(x, y);
    }
    else if(suit == "S" && num == 6)   {
        ui->card_6S->move(x, y);
    }
    else if(suit == "S" && num == 7)   {
        ui->card_7S->move(x, y);
    }
    else if(suit == "S" && num == 8)   {
        ui->card_8S->move(x, y);
    }
    else if(suit == "S" && num == 9)   {
        ui->card_9S->move(x, y);
    }
    else if(suit == "S" && num == 10)   {
        ui->card_10S->move(x, y);
    }
    else if(suit == "S" && num == 11)   {
        ui->card_11S->move(x, y);
    }
    else if(suit == "S" && num == 12)   {
        ui->card_12S->move(x, y);
    }
    else if(suit == "S" && num == 13)   {
        ui->card_13S->move(x, y);
    }
    else if(suit == "D" && num == 1)   {
        ui->card_1D->move(x, y);
    }
    else if(suit == "D" && num == 2)   {
        ui->card_2D->move(x, y);
    }
    else if(suit == "D" && num == 3)   {
        ui->card_3D->move(x, y);
    }
    else if(suit == "D" && num == 4)   {
        ui->card_4D->move(x, y);
    }
    else if(suit == "D" && num == 5)   {
        ui->card_5D->move(x, y);
    }
    else if(suit == "D" && num == 6)   {
        ui->card_6D->move(x, y);
    }
    else if(suit == "D" && num == 7)   {
        ui->card_7D->move(x, y);
    }
    else if(suit == "D" && num == 8)   {
        ui->card_8D->move(x, y);
    }
    else if(suit == "D" && num == 9)   {
        ui->card_9D->move(x, y);
    }
    else if(suit == "D" && num == 10)   {
        ui->card_10D->move(x, y);
    }
    else if(suit == "D" && num == 11)   {
        ui->card_11D->move(x, y);
    }
    else if(suit == "D" && num == 12)   {
        ui->card_12D->move(x, y);
    }
    else if(suit == "D" && num == 13)   {
        ui->card_13D->move(x, y);
    }
    else if(suit == "H" && num == 1)   {
        ui->card_1H->move(x, y);
    }
    else if(suit == "H" && num == 2)   {
        ui->card_2H->move(x, y);
    }
    else if(suit == "H" && num == 3)   {
        ui->card_3H->move(x, y);
    }
    else if(suit == "H" && num == 4)   {
        ui->card_4H->move(x, y);
    }
    else if(suit == "H" && num == 5)   {
        ui->card_5H->move(x, y);
    }
    else if(suit == "H" && num == 6)   {
        ui->card_6H->move(x, y);
    }
    else if(suit == "H" && num == 7)   {
        ui->card_7H->move(x, y);
    }
    else if(suit == "H" && num == 8)   {
        ui->card_8H->move(x, y);
    }
    else if(suit == "H" && num == 9)   {
        ui->card_9H->move(x, y);
    }
    else if(suit == "H" && num == 10)   {
        ui->card_10H->move(x, y);
    }
    else if(suit == "H" && num == 11)   {
        ui->card_11H->move(x, y);
    }
    else if(suit == "H" && num == 12)   {
        ui->card_12H->move(x, y);
    }
    else if(suit == "H" && num == 13)   {
        ui->card_13H->move(x, y);
    }
    else if(suit == "C" && num == 1)   {
        ui->card_1C->move(x, y);
    }
    else if(suit == "C" && num == 2)   {
        ui->card_2C->move(x, y);
    }
    else if(suit == "C" && num == 3)   {
        ui->card_3C->move(x, y);
    }
    else if(suit == "C" && num == 4)   {
        ui->card_4C->move(x, y);
    }
    else if(suit == "C" && num == 5)   {
        ui->card_5C->move(x, y);
    }
    else if(suit == "C" && num == 6)   {
        ui->card_6C->move(x, y);
    }
    else if(suit == "C" && num == 7)   {
        ui->card_7C->move(x, y);
    }
    else if(suit == "C" && num == 8)   {
        ui->card_8C->move(x, y);
    }
    else if(suit == "C" && num == 9)   {
        ui->card_9C->move(x, y);
    }
    else if(suit == "C" && num == 10)   {
        ui->card_10C->move(x, y);
    }
    else if(suit == "C" && num == 11)   {
        ui->card_11C->move(x, y);
    }
    else if(suit == "C" && num == 12)   {
        ui->card_12C->move(x, y);
    }
    else if(suit == "C" && num == 13)   {
        ui->card_13C->move(x, y);
    }
}

//Raises the Button up a layer, so that it is visible
void MainWindow::raiseButton(Node* n)   {
    int num = n->Num();
    string suit = n->Suit();

    //Assign Each Node to move a QPushButton
    if(suit == "S" && num == 1)    {
       ui->card_1S->raise();
    }
    else if(suit == "S" && num == 2)   {
        ui->card_2S->raise();
    }
    else if(suit == "S" && num == 3)   {
        ui->card_3S->raise();
    }
    else if(suit == "S" && num == 4)   {
        ui->card_4S->raise();
    }
    else if(suit == "S" && num == 5)   {
        ui->card_5S->raise();
    }
    else if(suit == "S" && num == 6)   {
        ui->card_6S->raise();
    }
    else if(suit == "S" && num == 7)   {
        ui->card_7S->raise();
    }
    else if(suit == "S" && num == 8)   {
        ui->card_8S->raise();
    }
    else if(suit == "S" && num == 9)   {
        ui->card_9S->raise();
    }
    else if(suit == "S" && num == 10)   {
        ui->card_10S->raise();
    }
    else if(suit == "S" && num == 11)   {
        ui->card_11S->raise();
    }
    else if(suit == "S" && num == 12)   {
        ui->card_12S->raise();
    }
    else if(suit == "S" && num == 13)   {
        ui->card_13S->raise();
    }
    else if(suit == "D" && num == 1)   {
        ui->card_1D->raise();
    }
    else if(suit == "D" && num == 2)   {
        ui->card_2D->raise();
    }
    else if(suit == "D" && num == 3)   {
        ui->card_3D->raise();
    }
    else if(suit == "D" && num == 4)   {
        ui->card_4D->raise();
    }
    else if(suit == "D" && num == 5)   {
        ui->card_5D->raise();
    }
    else if(suit == "D" && num == 6)   {
        ui->card_6D->raise();
    }
    else if(suit == "D" && num == 7)   {
        ui->card_7D->raise();
    }
    else if(suit == "D" && num == 8)   {
        ui->card_8D->raise();
    }
    else if(suit == "D" && num == 9)   {
        ui->card_9D->raise();
    }
    else if(suit == "D" && num == 10)   {
        ui->card_10D->raise();
    }
    else if(suit == "D" && num == 11)   {
        ui->card_11D->raise();
    }
    else if(suit == "D" && num == 12)   {
        ui->card_12D->raise();
    }
    else if(suit == "D" && num == 13)   {
        ui->card_13D->raise();
    }
    else if(suit == "H" && num == 1)   {
        ui->card_1H->raise();
    }
    else if(suit == "H" && num == 2)   {
        ui->card_2H->raise();
    }
    else if(suit == "H" && num == 3)   {
        ui->card_3H->raise();
    }
    else if(suit == "H" && num == 4)   {
        ui->card_4H->raise();
    }
    else if(suit == "H" && num == 5)   {
        ui->card_5H->raise();
    }
    else if(suit == "H" && num == 6)   {
        ui->card_6H->raise();
    }
    else if(suit == "H" && num == 7)   {
        ui->card_7H->raise();
    }
    else if(suit == "H" && num == 8)   {
        ui->card_8H->raise();
    }
    else if(suit == "H" && num == 9)   {
        ui->card_9H->raise();
    }
    else if(suit == "H" && num == 10)   {
        ui->card_10H->raise();
    }
    else if(suit == "H" && num == 11)   {
        ui->card_11H->raise();
    }
    else if(suit == "H" && num == 12)   {
        ui->card_12H->raise();
    }
    else if(suit == "H" && num == 13)   {
        ui->card_13H->raise();
    }
    else if(suit == "C" && num == 1)   {
        ui->card_1C->raise();
    }
    else if(suit == "C" && num == 2)   {
        ui->card_2C->raise();
    }
    else if(suit == "C" && num == 3)   {
        ui->card_3C->raise();
    }
    else if(suit == "C" && num == 4)   {
        ui->card_4C->raise();
    }
    else if(suit == "C" && num == 5)   {
        ui->card_5C->raise();
    }
    else if(suit == "C" && num == 6)   {
        ui->card_6C->raise();
    }
    else if(suit == "C" && num == 7)   {
        ui->card_7C->raise();
    }
    else if(suit == "C" && num == 8)   {
        ui->card_8C->raise();
    }
    else if(suit == "C" && num == 9)   {
        ui->card_9C->raise();
    }
    else if(suit == "C" && num == 10)   {
        ui->card_10C->raise();
    }
    else if(suit == "C" && num == 11)   {
        ui->card_11C->raise();
    }
    else if(suit == "C" && num == 12)   {
        ui->card_12C->raise();
    }
    else if(suit == "C" && num == 13)   {
        ui->card_13C->raise();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Options and Main Menu Buttons
void MainWindow::on_mainMenu_optionsButton_clicked()
{
    ui->optionsMenu->setVisible(true);
    ui->mainMenu->setVisible(false);
    ui->gameplay->setVisible(false);
    ui->cardBackMenu->setVisible(false);
}
void MainWindow::on_optionsMenu_backToMainMenuButton_clicked()
{
    ui->mainMenu->setVisible(true);
    ui->optionsMenu->setVisible(false);
    ui->gameplay->setVisible(false);
    ui->cardBackMenu->setVisible(false);
}
void MainWindow::on_mainMenu_startNewGameButton_clicked()
{
    ui->gameplay->setVisible(true);
    ui->mainMenu->setVisible(false);
    ui->optionsMenu->setVisible(false);
    ui->cardBackMenu->setVisible(false);
    clockTime = 0;
}
void MainWindow::on_gameplay_quitGameButton_clicked()
{
    ui->mainMenu->setVisible(true);
    ui->optionsMenu->setVisible(false);
    ui->gameplay->setVisible(false);
    ui->cardBackMenu->setVisible(false);
    QPixmap background("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/defaultBackground.jpg");
    ui->gameplay_background->setPixmap(background);
}
void MainWindow::on_optionsMenu_changeCardBackDesignButton_clicked()
{
    ui->cardBackMenu->setVisible(true);
    ui->mainMenu->setVisible(false);
    ui->optionsMenu->setVisible(false);
    ui->gameplay->setVisible(false);
}
void MainWindow::on_cardBackMenu_returnToOptionsMenuButton_clicked()
{
    ui->cardBackMenu->setVisible(false);
    ui->mainMenu->setVisible(false);
    ui->optionsMenu->setVisible(true);
    ui->gameplay->setVisible(false);
}
void MainWindow::on_optionsMenu_changeBackgroundButton_clicked()
{
    ui->cardBackMenu->setVisible(false);
    ui->mainMenu->setVisible(false);
    ui->optionsMenu->setVisible(false);
    ui->gameplay->setVisible(false);
    ui->backgroundMenu->setVisible(true);
}
void MainWindow::on_backgroundMenu_returnToOptionsMenuButton_clicked()
{
    ui->cardBackMenu->setVisible(false);
    ui->mainMenu->setVisible(false);
    ui->optionsMenu->setVisible(true);
    ui->gameplay->setVisible(false);
    ui->backgroundMenu->setVisible(false);
}

//Background Change Functions
void MainWindow::on_backgroundMenu_setWoodBackgroundButton_clicked()
{
    QPixmap backgroundWood("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundWood.jpg");
    ui->gameplay_background->setPixmap(backgroundWood);
}
void MainWindow::on_backgroundMenu_setVelvetBackgroundButton_clicked()
{
    QPixmap backgroundVelvet("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundVelvet.jpg");
    ui->gameplay_background->setPixmap(backgroundVelvet);
}
void MainWindow::on_backgroundMenu_setCircuitBackgroundButton_clicked()
{
    QPixmap backgroundCircuit("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundCircuit.jpg");
    ui->gameplay_background->setPixmap(backgroundCircuit);
}
void MainWindow::on_backgroundMenu_setChalkboardBackgroundButton_clicked()
{
    QPixmap backgroundChalkboard("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundChalkboard.jpg");
    ui->gameplay_background->setPixmap(backgroundChalkboard);
}
void MainWindow::on_backgroundMenu_setStarWarsBackgroundButton_clicked()
{
    QPixmap backgroundStarWars("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundStarWars.jpg");
    ui->gameplay_background->setPixmap(backgroundStarWars);
}
void MainWindow::on_backgroundMenu_setMemeBackgroundButton_clicked()
{
    QPixmap backgroundMeme("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Backgrounds/backgroundMeme.jpg");
    ui->gameplay_background->setPixmap(backgroundMeme);
}
void MainWindow::on_mainMenu_easterEggButton_clicked()
{
    ui->DoctaLiu->setVisible(true);
}


//Change Card Backs based on options menu clicked
void MainWindow::on_setBackOne_clicked()
{
    cardBack = backOne;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}
void MainWindow::on_setBackTwo_clicked()
{
    cardBack = backTwo;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}
void MainWindow::on_setBackThree_clicked()
{
    cardBack = backThree;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}
void MainWindow::on_setBackFour_clicked()
{
    cardBack = backFour;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}
void MainWindow::on_setBackFive_clicked()
{
    cardBack = backFive;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}
void MainWindow::on_setBackSix_clicked()
{
    cardBack = backSix;
    for(int i = 0 ; i < col1.size()-1 ; i++){
        if(col1.at(i)->Faceup() == false){
            flipCard(col1.at(i), false);
        }
    }
    for(int i = 0 ; i < col2.size()-1 ; i++){
        if(col2.at(i)->Faceup() == false){
            flipCard(col2.at(i), false);
        }
    }
    for(int i = 0 ; i < col3.size()-1 ; i++){
        if(col3.at(i)->Faceup() == false){
            flipCard(col3.at(i), false);
        }
    }
    for(int i = 0 ; i < col4.size()-1 ; i++){
        if(col4.at(i)->Faceup() == false){
            flipCard(col4.at(i), false);
        }
    }
    for(int i = 0 ; i < col5.size()-1 ; i++){
        if(col5.at(i)->Faceup() == false){
            flipCard(col5.at(i), false);
        }
    }
    for(int i = 0 ; i < col6.size()-1 ; i++){
        if(col6.at(i)->Faceup() == false){
            flipCard(col6.at(i), false);
        }
    }
    for(int i = 0 ; i < col7.size()-1 ; i++){
        if(col7.at(i)->Faceup() == false){
            flipCard(col7.at(i), false);
        }
    }
}

//Show Timer function
void MainWindow::showTime()
{
    QString time_text = QString::number(clockTime);
    clockTime++;
    ui->gameplay_timerCount->setText(time_text);
}

//Remove the timer from the game screen
void MainWindow::on_optionsMenu_removeTimerButton_clicked()
{
    if(visibleTimer)
    {
        ui->gameplay_timerCount->setVisible(false);
        ui->gameplay_timerButtonTemplate->setVisible(false);
        ui->gameplay_timerLabel->setVisible(false);
        ui->optionsMenu_removeTimerButton->setText("Add Timer");
        visibleTimer = false;
    }
    else
    {
        ui->gameplay_timerCount->setVisible(true);
        ui->gameplay_timerButtonTemplate->setVisible(true);
        ui->gameplay_timerLabel->setVisible(true);
        ui->optionsMenu_removeTimerButton->setText("Remove Timer");
        visibleTimer = true;
    }
}

//ButtonClicks
//Hearts
void MainWindow::on_card_1H_clicked()
{
    if(selected){
        second = ui->card_1H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_1H;
        selected = true;
    }
}
void MainWindow::on_card_2H_clicked()
{
    if(selected){
        second = ui->card_2H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_2H;
        selected = true;
    }
}
void MainWindow::on_card_3H_clicked()
{
    if(selected){
        second = ui->card_3H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_3H;
        selected = true;
    }
}
void MainWindow::on_card_4H_clicked()
{
    if(selected){
        second = ui->card_4H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_4H;
        selected = true;
    }
}
void MainWindow::on_card_5H_clicked()
{
    if(selected){
        second = ui->card_5H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_5H;
        selected = true;
    }
}
void MainWindow::on_card_6H_clicked()
{
    if(selected){
        second = ui->card_6H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_6H;
        selected = true;
    }
}
void MainWindow::on_card_7H_clicked()
{
    if(selected){
        second = ui->card_7H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_7H;
        selected = true;
    }
}
void MainWindow::on_card_8H_clicked()
{
    if(selected){
        second = ui->card_8H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_8H;
        selected = true;
    }
}
void MainWindow::on_card_9H_clicked()
{
    if(selected){
        second = ui->card_9H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_9H;
        selected = true;
    }
}
void MainWindow::on_card_10H_clicked()
{
    if(selected){
        second = ui->card_10H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_10H;
        selected = true;
    }
}
void MainWindow::on_card_11H_clicked()
{
    if(selected){
        second = ui->card_11H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_11H;
        selected = true;
    }
}
void MainWindow::on_card_12H_clicked()
{
    if(selected){
        second = ui->card_12H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_12H;
        selected = true;
    }
}
void MainWindow::on_card_13H_clicked()
{
    if(selected){
        second = ui->card_13H;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_13H;
        selected = true;
    }
}
//Diamonds
void MainWindow::on_card_1D_clicked()
{
    if(selected){
        second = ui->card_1D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_1D;
        selected = true;
    }
}
void MainWindow::on_card_2D_clicked()
{
    if(selected){
        second = ui->card_2D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_2D;
        selected = true;
    }
}
void MainWindow::on_card_3D_clicked()
{
    if(selected){
        second = ui->card_3D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_3D;
        selected = true;
    }
}
void MainWindow::on_card_4D_clicked()
{
    if(selected){
        second = ui->card_4D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_4D;
        selected = true;
    }
}
void MainWindow::on_card_5D_clicked()
{
    if(selected){
        second = ui->card_5D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_5D;
        selected = true;
    }
}
void MainWindow::on_card_6D_clicked()
{
    if(selected){
        second = ui->card_6D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_6D;
        selected = true;
    }
}
void MainWindow::on_card_7D_clicked()
{
    if(selected){
        second = ui->card_7D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_7D;
        selected = true;
    }
}
void MainWindow::on_card_8D_clicked()
{
    if(selected){
        second = ui->card_8D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_8D;
        selected = true;
    }
}
void MainWindow::on_card_9D_clicked()
{
    if(selected){
        second = ui->card_9D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_9D;
        selected = true;
    }
}
void MainWindow::on_card_10D_clicked()
{
    if(selected){
        second = ui->card_10D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_10D;
        selected = true;
    }
}
void MainWindow::on_card_11D_clicked()
{
    if(selected){
        second = ui->card_11D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_11D;
        selected = true;
    }
}
void MainWindow::on_card_12D_clicked()
{
    if(selected){
        second = ui->card_12D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_12D;
        selected = true;
    }
}
void MainWindow::on_card_13D_clicked()
{
    if(selected){
        second = ui->card_13D;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_13D;
        selected = true;
    }
}
//Spades
void MainWindow::on_card_1S_clicked()
{
    if(selected){
        second = ui->card_1S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_1S;
        selected = true;
    }
}
void MainWindow::on_card_2S_clicked()
{
    if(selected){
        second = ui->card_2S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_2S;
        selected = true;
    }
}
void MainWindow::on_card_3S_clicked()
{
    if(selected){
        second = ui->card_3S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_3S;
        selected = true;
    }
}
void MainWindow::on_card_4S_clicked()
{
    if(selected){
        second = ui->card_4S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_4S;
        selected = true;
    }
}
void MainWindow::on_card_5S_clicked()
{
    if(selected){
        second = ui->card_5S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_5S;
        selected = true;
    }
}
void MainWindow::on_card_6S_clicked()
{
    if(selected){
        second = ui->card_6S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_6S;
        selected = true;
    }
}
void MainWindow::on_card_7S_clicked()
{
    if(selected){
        second = ui->card_7S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_7S;
        selected = true;
    }
}
void MainWindow::on_card_8S_clicked()
{
    if(selected){
        second = ui->card_8S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_8S;
        selected = true;
    }
}
void MainWindow::on_card_9S_clicked()
{
    if(selected){
        second = ui->card_9S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_9S;
        selected = true;
    }
}
void MainWindow::on_card_10S_clicked()
{
    if(selected){
        second = ui->card_10S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_10S;
        selected = true;
    }
}
void MainWindow::on_card_11S_clicked()
{
    if(selected){
        second = ui->card_11S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_11S;
        selected = true;
    }
}
void MainWindow::on_card_12S_clicked()
{
    if(selected){
        second = ui->card_12S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_12S;
        selected = true;
    }
}
void MainWindow::on_card_13S_clicked()
{
    if(selected){
        second = ui->card_13S;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_13S;
        selected = true;
    }
}
//Clubs
void MainWindow::on_card_1C_clicked()
{
    if(selected){
        second = ui->card_1C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_1C;
        selected = true;
    }
}
void MainWindow::on_card_2C_clicked()
{
    if(selected){
        second = ui->card_2C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_2C;
        selected = true;
    }
}
void MainWindow::on_card_3C_clicked()
{
    if(selected){
        second = ui->card_3C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_3C;
        selected = true;
    }
}
void MainWindow::on_card_4C_clicked()
{
    if(selected){
        second = ui->card_4C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_4C;
        selected = true;
    }
}
void MainWindow::on_card_5C_clicked()
{
    if(selected){
        second = ui->card_5C;
            moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_5C;
        selected = true;
    }
}
void MainWindow::on_card_6C_clicked()
{
    if(selected){
        second = ui->card_6C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_6C;
        selected = true;
    }
}
void MainWindow::on_card_7C_clicked()
{
    if(selected){
        second = ui->card_7C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_7C;
        selected = true;
    }
}
void MainWindow::on_card_8C_clicked()
{
    if(selected){
        second = ui->card_8C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_8C;
        selected = true;
    }
}
void MainWindow::on_card_9C_clicked()
{
    if(selected){
        second = ui->card_9C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_9C;
        selected = true;
    }
}
void MainWindow::on_card_10C_clicked()
{
    if(selected){
        second = ui->card_10C;
            moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_10C;
        selected = true;
    }
}
void MainWindow::on_card_11C_clicked()
{
    if(selected){
        second = ui->card_11C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_11C;
        selected = true;
    }
}
void MainWindow::on_card_12C_clicked()
{
    if(selected){
        second = ui->card_12C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_12C;
        selected = true;
    }
}
void MainWindow::on_card_13C_clicked()
{
    if(selected){
        second = ui->card_13C;
        moveColumn(first,second);
        selected = false;
        first = NULL;
        second = NULL;
    }
    else{
        first = ui->card_13C;
        selected = true;
    }
}

//Foundation Buttons: (For moving a card to an empty foundation)
void MainWindow::on_foundation_club_clicked()
{
    if(selected){
        second = ui->foundation_club;
        moveCardtoFoundation(first,second);
        first->raise();
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_foundation_spade_clicked()
{
    if(selected){
        second = ui->foundation_spade;
        moveCardtoFoundation(first,second);
        first->raise();
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_foundation_heart_clicked()
{
    if(selected){
        second = ui->foundation_heart;
        moveCardtoFoundation(first,second);
        first->raise();
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_foundation_diamond_clicked()
{
    if(selected){
        second = ui->foundation_diamond;
        moveCardtoFoundation(first,second);
        first->raise();
        selected = false;
        first = NULL;
        second = NULL;
    }
}

//Tableau Buttons: (For moving a card to an empty tableau)
void MainWindow::on_tableau_1_clicked()
{
    if(selected){
        second = ui->tableau_1;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_2_clicked()
{
    if(selected){
        second = ui->tableau_2;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_3_clicked()
{
    if(selected){
        second = ui->tableau_3;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_4_clicked()
{
    if(selected){
        second = ui->tableau_4;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_5_clicked()
{
    if(selected){
        second = ui->tableau_5;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_6_clicked()
{
    if(selected){
        second = ui->tableau_6;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}
void MainWindow::on_tableau_7_clicked()
{
    if(selected){
        second = ui->tableau_7;
        if(first != NULL && second != NULL){
            moveCardtoTableauOrDeck(first,second);
        }
        selected = false;
        first = NULL;
        second = NULL;
    }
}

//Move Functions
//moveCard deals with only moving one card at a time
void MainWindow::moveCard(QPushButton *first, QPushButton *second){
    if(second->y() == 40){
        first->move(second->x(),second->y());
    }
    else    {
        first->move(second->x(),second->y() +30);
    }
    checkWin();
}

//moveCardDeckTableau moves from the deck to the tableau
void MainWindow::moveCardDeckTableau(QPushButton *first, QPushButton *second)   {
    first->move(second->x(),second->y());
    checkWin();
}

//moveCardtoTableau deals with moving a card to an empty tableau (can take multiple at a time)
void MainWindow::moveCardtoTableauOrDeck(QPushButton *first, QPushButton *second){
    QPushButton *buttons[52] = { ui->card_1H, ui->card_2H, ui->card_3H, ui->card_4H, ui->card_5H, ui->card_6H, ui->card_7H, ui->card_8H, ui->card_9H, ui->card_10H, ui->card_11H, ui->card_12H, ui->card_13H,
                                ui->card_1S, ui->card_2S, ui->card_3S, ui->card_4S, ui->card_5S, ui->card_6S, ui->card_7S, ui->card_8S, ui->card_9S, ui->card_10S, ui->card_11S, ui->card_12S, ui->card_13S,
                                ui->card_1C, ui->card_2C, ui->card_3C, ui->card_4C, ui->card_5C, ui->card_6C, ui->card_7C, ui->card_8C, ui->card_9C, ui->card_10C, ui->card_11C, ui->card_12C, ui->card_13C,
                                ui->card_1D, ui->card_2D, ui->card_3D, ui->card_4D, ui->card_5D, ui->card_6D, ui->card_7D, ui->card_8D, ui->card_9D, ui->card_10D, ui->card_11D, ui->card_12D, ui->card_13D };

    if(fixTablaeuOrFoundation(first, second))   {
        vector<int> cardsToRaise;
        int initialX = first->x();
        int initialY = first->y();
        int newY = initialY;
        int increment = 30;
        int numOfCardsNeededToRaise = 0;

        //Number of Cards to Raise
        for(int i = 0; i < 52; i++){
            if(buttons[i]->x() == initialX){
                if(buttons[i]->y() >= initialY){
                    numOfCardsNeededToRaise++;
                }
            }
        }

        int finalNumOfCardsNeededToRaise = numOfCardsNeededToRaise;

        //Number of Cards to Raise in Order
        for(int i = 0; i < 52; i++){
            if(buttons[i]->x() == initialX){
                if(buttons[i]->y() == initialY){
                    cardsToRaise.push_back(i);
                    numOfCardsNeededToRaise--;
                }
            }
        }

        while(numOfCardsNeededToRaise > 0){
            for(int i = 0; i < 52; i++){
                if(buttons[i]->x() == initialX){
                    if((buttons[i]->y() > newY) && (buttons[i]->y() < newY + 40)){
                        cardsToRaise.push_back(i);
                        numOfCardsNeededToRaise--;
                        newY = buttons[i]->y();
                    }
                }
            }
        }

        numOfCardsNeededToRaise = finalNumOfCardsNeededToRaise;

        for(unsigned int i = 0; i < cardsToRaise.size(); i++){
            buttons[cardsToRaise.at(i)]->move(second->x(), second->y() + increment-30);
            buttons[cardsToRaise.at(i)]->raise();
            increment = increment + 30;
        }
        checkWin();
    }
}

//moveCardtoFoundation deals with moving a card to an empty foundation (one at a time)
void MainWindow::moveCardtoFoundation(QPushButton *first, QPushButton *second){
    if(fixTablaeuOrFoundation(first, second))    {
        first->move(second->x(), second->y());
        checkWin();
    }
}

//Checks for if the move is valid based on vectors
bool MainWindow::fixVector(QPushButton *first, QPushButton *second)    {
    string suit1 = "";
    string suit2 = "";
    int num1 = 0;
    int num2 = 0;
    bool status = true;

    if(first->objectName().toStdString().compare("card_1H")==0)   {
        suit1 = "H";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_2H")==0)   {
        suit1 = "H";
        num1 = 2;
    }
    else if(first->objectName().toStdString().compare("card_3H")==0)   {
        suit1 = "H";
        num1 = 3;
    }
    else if(first->objectName().toStdString().compare("card_4H")==0)   {
        suit1 = "H";
        num1 = 4;
    }
    else if(first->objectName().toStdString().compare("card_5H")==0)   {
        suit1 = "H";
        num1 = 5;
    }
    else if(first->objectName().toStdString().compare("card_6H")==0)   {
        suit1 = "H";
        num1 = 6;
    }
    else if(first->objectName().toStdString().compare("card_7H")==0)   {
        suit1 = "H";
        num1 = 7;
    }
    else if(first->objectName().toStdString().compare("card_8H")==0)   {
        suit1 = "H";
        num1 = 8;
    }
    else if(first->objectName().toStdString().compare("card_9H")==0)   {
        suit1 = "H";
        num1 = 9;
    }
    else if(first->objectName().toStdString().compare("card_10H")==0)   {
        suit1 = "H";
        num1 = 10;
    }
    else if(first->objectName().toStdString().compare("card_11H")==0)   {
        suit1 = "H";
        num1 = 11;
    }
    else if(first->objectName().toStdString().compare("card_12H")==0)   {
        suit1 = "H";
        num1 = 12;
    }
    else if(first->objectName().toStdString().compare("card_13H")==0)   {
        suit1 = "H";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_1S")==0)   {
        suit1 = "S";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_2S")==0)   {
        suit1 = "S";
        num1 = 2;
    }
    else if(first->objectName().toStdString().compare("card_3S")==0)   {
        suit1 = "S";
        num1 = 3;
    }
    else if(first->objectName().toStdString().compare("card_4S")==0)   {
        suit1 = "S";
        num1 = 4;
    }
    else if(first->objectName().toStdString().compare("card_5S")==0)   {
        suit1 = "S";
        num1 = 5;
    }
    else if(first->objectName().toStdString().compare("card_6S")==0)   {
        suit1 = "S";
        num1 = 6;
    }
    else if(first->objectName().toStdString().compare("card_7S")==0)   {
        suit1 = "S";
        num1 = 7;
    }
    else if(first->objectName().toStdString().compare("card_8S")==0)   {
        suit1 = "S";
        num1 = 8;
    }
    else if(first->objectName().toStdString().compare("card_9S")==0)   {
        suit1 = "S";
        num1 = 9;
    }
    else if(first->objectName().toStdString().compare("card_10S")==0)   {
        suit1 = "S";
        num1 = 10;
    }
    else if(first->objectName().toStdString().compare("card_11S")==0)   {
        suit1 = "S";
        num1 = 11;
    }
    else if(first->objectName().toStdString().compare("card_12S")==0)   {
        suit1 = "S";
        num1 = 12;
    }
    else if(first->objectName().toStdString().compare("card_13S")==0)   {
        suit1 = "S";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_1D")==0)   {
        suit1 = "D";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_2D")==0)   {
        suit1 = "D";
        num1 = 2;
    }
    else if(first->objectName().toStdString().compare("card_3D")==0)   {
        suit1 = "D";
        num1 = 3;
    }
    else if(first->objectName().toStdString().compare("card_4D")==0)   {
        suit1 = "D";
        num1 = 4;
    }
    else if(first->objectName().toStdString().compare("card_5D")==0)   {
        suit1 = "D";
        num1 = 5;
    }
    else if(first->objectName().toStdString().compare("card_6D")==0)   {
        suit1 = "D";
        num1 = 6;
    }
    else if(first->objectName().toStdString().compare("card_7D")==0)   {
        suit1 = "D";
        num1 = 7;
    }
    else if(first->objectName().toStdString().compare("card_8D")==0)   {
        suit1 = "D";
        num1 = 8;
    }
    else if(first->objectName().toStdString().compare("card_9D")==0)   {
        suit1 = "D";
        num1 = 9;
    }
    else if(first->objectName().toStdString().compare("card_10D")==0)   {
        suit1 = "D";
        num1 = 10;
    }
    else if(first->objectName().toStdString().compare("card_11D")==0)   {
        suit1 = "D";
        num1 = 11;
    }
    else if(first->objectName().toStdString().compare("card_12D")==0)   {
        suit1 = "D";
        num1 = 12;
    }
    else if(first->objectName().toStdString().compare("card_13D")==0)   {
        suit1 = "D";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_1C")==0)   {
        suit1 = "C";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_2C")==0)   {
        suit1 = "C";
        num1 = 2;
    }
    else if(first->objectName().toStdString().compare("card_3C")==0)   {
        suit1 = "C";
        num1 = 3;
    }
    else if(first->objectName().toStdString().compare("card_4C")==0)   {
        suit1 = "C";
        num1 = 4;
    }
    else if(first->objectName().toStdString().compare("card_5C")==0)   {
        suit1 = "C";
        num1 = 5;
    }
    else if(first->objectName().toStdString().compare("card_6C")==0)   {
        suit1 = "C";
        num1 = 6;
    }
    else if(first->objectName().toStdString().compare("card_7C")==0)   {
        suit1 = "C";
        num1 = 7;
    }
    else if(first->objectName().toStdString().compare("card_8C")==0)   {
        suit1 = "C";
        num1 = 8;
    }
    else if(first->objectName().toStdString().compare("card_9C")==0)   {
        suit1 = "C";
        num1 = 9;
    }
    else if(first->objectName().toStdString().compare("card_10C")==0)   {
        suit1 = "C";
        num1 = 10;
    }
    else if(first->objectName().toStdString().compare("card_11C")==0)   {
        suit1 = "C";
        num1 = 11;
    }
    else if(first->objectName().toStdString().compare("card_12C")==0)   {
        suit1 = "C";
        num1 = 12;
    }
    else if(first->objectName().toStdString().compare("card_13C")==0)   {
        suit1 = "C";
        num1 = 13;
    }

    if(second->objectName().toStdString().compare("card_1H")==0)   {
        suit2 = "H";
        num2 = 1;
    }
    else if(second->objectName().toStdString().compare("card_2H")==0)   {
        suit2 = "H";
        num2 = 2;
    }
    else if(second->objectName().toStdString().compare("card_3H")==0)   {
        suit2 = "H";
        num2 = 3;
    }
    else if(second->objectName().toStdString().compare("card_4H")==0)   {
        suit2 = "H";
        num2 = 4;
    }
    else if(second->objectName().toStdString().compare("card_5H")==0)   {
        suit2 = "H";
        num2 = 5;
    }
    else if(second->objectName().toStdString().compare("card_6H")==0)   {
        suit2 = "H";
        num2 = 6;
    }
    else if(second->objectName().toStdString().compare("card_7H")==0)   {
        suit2 = "H";
        num2 = 7;
    }
    else if(second->objectName().toStdString().compare("card_8H")==0)   {
        suit2 = "H";
        num2 = 8;
    }
    else if(second->objectName().toStdString().compare("card_9H")==0)   {
        suit2 = "H";
        num2 = 9;
    }
    else if(second->objectName().toStdString().compare("card_10H")==0)   {
        suit2 = "H";
        num2 = 10;
    }
    else if(second->objectName().toStdString().compare("card_11H")==0)   {
        suit2 = "H";
        num2 = 11;
    }
    else if(second->objectName().toStdString().compare("card_12H")==0)   {
        suit2 = "H";
        num2 = 12;
    }
    else if(second->objectName().toStdString().compare("card_13H")==0)   {
        suit2 = "H";
        num2 = 13;
    }
    else if(second->objectName().toStdString().compare("card_1S")==0)   {
        suit2 = "S";
        num2 = 1;
    }
    else if(second->objectName().toStdString().compare("card_2S")==0)   {
        suit2 = "S";
        num2 = 2;
    }
    else if(second->objectName().toStdString().compare("card_3S")==0)   {
        suit2 = "S";
        num2 = 3;
    }
    else if(second->objectName().toStdString().compare("card_4S")==0)   {
        suit2 = "S";
        num2 = 4;
    }
    else if(second->objectName().toStdString().compare("card_5S")==0)   {
        suit2 = "S";
        num2 = 5;
    }
    else if(second->objectName().toStdString().compare("card_6S")==0)   {
        suit2 = "S";
        num2 = 6;
    }
    else if(second->objectName().toStdString().compare("card_7S")==0)   {
        suit2 = "S";
        num2 = 7;
    }
    else if(second->objectName().toStdString().compare("card_8S")==0)   {
        suit2 = "S";
        num2 = 8;
    }
    else if(second->objectName().toStdString().compare("card_9S")==0)   {
        suit2 = "S";
        num2 = 9;
    }
    else if(second->objectName().toStdString().compare("card_10S")==0)   {
        suit2 = "S";
        num2 = 10;
    }
    else if(second->objectName().toStdString().compare("card_11S")==0)   {
        suit2 = "S";
        num2 = 11;
    }
    else if(second->objectName().toStdString().compare("card_12S")==0)   {
        suit2 = "S";
        num2 = 12;
    }
    else if(second->objectName().toStdString().compare("card_13S")==0)   {
        suit2 = "S";
        num2 = 13;
    }
    else if(second->objectName().toStdString().compare("card_1D")==0)   {
        suit2 = "D";
        num2 = 1;
    }
    else if(second->objectName().toStdString().compare("card_2D")==0)   {
        suit2 = "D";
        num2 = 2;
    }
    else if(second->objectName().toStdString().compare("card_3D")==0)   {
        suit2 = "D";
        num2 = 3;
    }
    else if(second->objectName().toStdString().compare("card_4D")==0)   {
        suit2 = "D";
        num2 = 4;
    }
    else if(second->objectName().toStdString().compare("card_5D")==0)   {
        suit2 = "D";
        num2 = 5;
    }
    else if(second->objectName().toStdString().compare("card_6D")==0)   {
        suit2 = "D";
        num2 = 6;
    }
    else if(second->objectName().toStdString().compare("card_7D")==0)   {
        suit2 = "D";
        num2 = 7;
    }
    else if(second->objectName().toStdString().compare("card_8D")==0)   {
        suit2 = "D";
        num2 = 8;
    }
    else if(second->objectName().toStdString().compare("card_9D")==0)   {
        suit2 = "D";
        num2 = 9;
    }
    else if(second->objectName().toStdString().compare("card_10D")==0)   {
        suit2 = "D";
        num2 = 10;
    }
    else if(second->objectName().toStdString().compare("card_11D")==0)   {
        suit2 = "D";
        num2 = 11;
    }
    else if(second->objectName().toStdString().compare("card_12D")==0)   {
        suit2 = "D";
        num2 = 12;
    }
    else if(second->objectName().toStdString().compare("card_13D")==0)   {
        suit2 = "D";
        num2 = 13;
    }
    else if(second->objectName().toStdString().compare("card_1C")==0)   {
        suit2 = "C";
        num2 = 1;
    }
    else if(second->objectName().toStdString().compare("card_2C")==0)   {
        suit2 = "C";
        num2 = 2;
    }
    else if(second->objectName().toStdString().compare("card_3C")==0)   {
        suit2 = "C";
        num2 = 3;
    }
    else if(second->objectName().toStdString().compare("card_4C")==0)   {
        suit2 = "C";
        num2 = 4;
    }
    else if(second->objectName().toStdString().compare("card_5C")==0)   {
        suit2 = "C";
        num2 = 5;
    }
    else if(second->objectName().toStdString().compare("card_6C")==0)   {
        suit2 = "C";
        num2 = 6;
    }
    else if(second->objectName().toStdString().compare("card_7C")==0)   {
        suit2 = "C";
        num2 = 7;
    }
    else if(second->objectName().toStdString().compare("card_8C")==0)   {
        suit2 = "C";
        num2 = 8;
    }
    else if(second->objectName().toStdString().compare("card_9C")==0)   {
        suit2 = "C";
        num2 = 9;
    }
    else if(second->objectName().toStdString().compare("card_10C")==0)   {
        suit2 = "C";
        num2 = 10;
    }
    else if(second->objectName().toStdString().compare("card_11C")==0)   {
        suit2 = "C";
        num2 = 11;
    }
    else if(second->objectName().toStdString().compare("card_12C")==0)   {
        suit2 = "C";
        num2 = 12;
    }
    else if(second->objectName().toStdString().compare("card_13C")==0)   {
        suit2 = "C";
        num2 = 13;
    }

    vector<Node*> locationFirst;
    vector<Node*> locationSecond;
    vector<Node*> nonmoving;
    vector<Node*> moving;
    int indexFirst = 0;
    int indexSecond = 0;
    string name1 = "";
    string name2 = "";

    for(int i = 0; i < col1.size(); i++)    {
        if(col1.at(i)->Num() == num1 && col1.at(i)->Suit() == suit1)    {
            locationFirst = col1;
            name1 = "col1";
            indexFirst = i;
        }
        if(col1.at(i)->Num() == num2 && col1.at(i)->Suit() == suit2)    {
            locationSecond = col1;
            name2 = "col1";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col2.size(); i++)    {
        if(col2.at(i)->Num() == num1 && col2.at(i)->Suit() == suit1)    {
            locationFirst = col2;
            name1 = "col2";
            indexFirst = i;
        }
        if(col2.at(i)->Num() == num2 && col2.at(i)->Suit() == suit2)    {
            locationSecond = col2;
            name2 = "col2";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col3.size(); i++)    {
        if(col3.at(i)->Num() == num1 && col3.at(i)->Suit() == suit1)    {
            locationFirst = col3;
            name1 = "col3";
            indexFirst = i;
        }
        if(col3.at(i)->Num() == num2 && col3.at(i)->Suit() == suit2)    {
            locationSecond = col3;
            name2 = "col3";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col4.size(); i++)    {
        if(col4.at(i)->Num() == num1 && col4.at(i)->Suit() == suit1)    {
            locationFirst = col4;
            name1 = "col4";
            indexFirst = i;
        }
        if(col4.at(i)->Num() == num2 && col4.at(i)->Suit() == suit2)    {
            locationSecond = col4;
            name2 = "col4";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col5.size(); i++)    {
        if(col5.at(i)->Num() == num1 && col5.at(i)->Suit() == suit1)    {
            locationFirst = col5;
            name1 = "col5";
            indexFirst = i;
        }
        if(col5.at(i)->Num() == num2 && col5.at(i)->Suit() == suit2)    {
            locationSecond = col5;
            name2 = "col5";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col6.size(); i++)    {
        if(col6.at(i)->Num() == num1 && col6.at(i)->Suit() == suit1)    {
            locationFirst = col6;
            name1 = "col6";
            indexFirst = i;
        }
        if(col6.at(i)->Num() == num2 && col6.at(i)->Suit() == suit2)    {
            locationSecond = col6;
            name2 = "col6";
            indexSecond = i;
        }
    }

    for(int i = 0; i < col7.size(); i++)    {
        if(col7.at(i)->Num() == num1 && col7.at(i)->Suit() == suit1)    {
            locationFirst = col7;
            name1 = "col7";
            indexFirst = i;
        }
        if(col7.at(i)->Num() == num2 && col7.at(i)->Suit() == suit2)    {
            locationSecond = col7;
            name2 = "col7";
            indexSecond = i;
        }
    }

    for(int i = 0; i < foundDrawn.size(); i++)   {
        if(foundDrawn.at(i)->Num() == num1 && foundDrawn.at(i)->Suit() == suit1)    {
            locationFirst = foundDrawn;
            name1 = "deck";
            indexFirst = i;
        }
        if(foundDrawn.at(i)->Num() == num2 && foundDrawn.at(i)->Suit() == suit2)    {
            return false;
        }
    }

    for(int i = 0; i < foundClubs.size(); i++) {
        if(foundClubs.at(i)->Num() == num1 && foundClubs.at(i)->Suit() == suit1)    {
            locationFirst = foundClubs;
            name1 = "clubs";
            indexFirst = i;
        }
        if(foundClubs.at(i)->Num() == num2 && foundClubs.at(i)->Suit() == suit2)    {
            locationSecond = foundClubs;
            name2 = "clubs";
            indexSecond = i;
        }
    }

    for(int i = 0; i < foundHearts.size(); i++) {
        if(foundHearts.at(i)->Num() == num1 && foundHearts.at(i)->Suit() == suit1)    {
            locationFirst = foundHearts;
            name1 = "hearts";
            indexFirst = i;
        }
        if(foundHearts.at(i)->Num() == num2 && foundHearts.at(i)->Suit() == suit2)    {
            locationSecond = foundHearts;
            name2 = "hearts";
            indexSecond = i;
        }
    }

    for(int i = 0; i < foundDiamonds.size(); i++) {
        if(foundDiamonds.at(i)->Num() == num1 && foundDiamonds.at(i)->Suit() == suit1)    {
            locationFirst = foundDiamonds;
            name1 = "diamonds";
            indexFirst = i;
        }
        if(foundDiamonds.at(i)->Num() == num2 && foundDiamonds.at(i)->Suit() == suit2)    {
            locationSecond = foundDiamonds;
            name2 = "diamonds";
            indexSecond = i;
        }
    }

    for(int i = 0; i < foundSpades.size(); i++) {
        if(foundSpades.at(i)->Num() == num1 && foundSpades.at(i)->Suit() == suit1)    {
            locationFirst = foundSpades;
            name1 = "spades";
            indexFirst = i;
        }
        if(foundSpades.at(i)->Num() == num2 && foundSpades.at(i)->Suit() == suit2)    {
            locationSecond = foundSpades;
            name2 = "spades";
            indexSecond = i;
        }
    }

    if(indexSecond != locationSecond.size()-1)  {
        return false;
    }

    if(name1.compare("col1")==0)    {
        if(name2.compare("col1")==0)    {
            return false;
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(col1.at(indexFirst), col2.at(indexSecond)))    {

                for(int i = 0; i < indexFirst; i++){
                    nonmoving.push_back(col1.at(i));
                }

                for(int i = indexFirst; i < col1.size(); i++){
                    moving.push_back(col1.at(i));

                }

                for(int i = 0 ; i < moving.size(); i++){
                    col2.push_back(moving.at(i));
                }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col1.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col1.at(i));
            }

                for(int i = indexFirst; i < col1.size(); i++){
                moving.push_back(col1.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col1.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col1.at(i));
            }

                for(int i = indexFirst; i < col1.size(); i++){
                moving.push_back(col1.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(col1.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col1.at(i));
            }

                for(int i = indexFirst; i < col1.size(); i++){
                moving.push_back(col1.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col1.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col1.at(i));
            }

                for(int i = indexFirst; i < col1.size(); i++){
                moving.push_back(col1.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col1.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col1.at(i));
            }

                for(int i = indexFirst; i < col1.size(); i++){
                moving.push_back(col1.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col1 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col1.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col1.at(indexFirst));
                col1.erase(col1.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col1.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col1.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col1.at(indexFirst));
                col1.erase(col1.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col1.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col1.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col1.at(indexFirst));
                col1.erase(col1.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col1.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col1.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col1.at(indexFirst));
                col1.erase(col1.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col1.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col2")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col2.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }

                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
                }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            return false;
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col2.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }


                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col2.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }


                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(col2.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }


                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col2.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }


                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col2.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col2.at(i));
            }


                for(int i = indexFirst; i < col2.size(); i++){
                moving.push_back(col2.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col2 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col2.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col2.at(indexFirst));
                col2.erase(col2.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col2.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col2.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col2.at(indexFirst));
                col2.erase(col2.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col2.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col2.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col2.at(indexFirst));
                col2.erase(col2.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col2.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col2.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col2.at(indexFirst));
                col2.erase(col2.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col2.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col3")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col3.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }


                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
            }
                col3 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(col3.at(indexFirst), col2.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }

                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col2.push_back(moving.at(i));
            }
                col3 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)  {
            return false;
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col3.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }


                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col3 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(col3.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }


                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col3 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col3.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }


                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));

            }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }
                col3 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col3.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col3.at(i));
            }

                for(int i = indexFirst; i < col3.size(); i++){
                moving.push_back(col3.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col3 = nonmoving;
             }
             else  {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col3.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col3.at(indexFirst));
                col3.erase(col3.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col3.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col3.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col3.at(indexFirst));
                col3.erase(col3.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col3.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col3.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col3.at(indexFirst));
                col3.erase(col3.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col3.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col3.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col3.at(indexFirst));
                col3.erase(col3.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col3.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col4")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col4.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
            }
                col4 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
             if(checkMove(col4.at(indexFirst), col2.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col2.push_back(moving.at(i));
            }
                    col4 = nonmoving;
              }
             else   {
                 return false;
             }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col4.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col4 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            return false;
        }
        else if(name2.compare("col5")==0)   {
             if(checkMove(col4.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                 for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col4 = nonmoving;
            }
            else    {
                 return false;
             }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col4.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }

                col4 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col4.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col4.at(i));
            }

                for(int i = indexFirst; i < col4.size(); i++){
                moving.push_back(col4.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col4 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col4.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col4.at(indexFirst));
                col4.erase(col4.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col4.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col4.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col4.at(indexFirst));
                col4.erase(col4.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col4.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col4.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col4.at(indexFirst));
                col4.erase(col4.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col4.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col4.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col4.at(indexFirst));
                col4.erase(col4.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col4.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col5")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col5.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(col5.at(indexFirst), col2.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col2.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col5.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col5.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            return false;
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col5.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col5.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col5.at(i));
            }

                for(int i = indexFirst; i < col5.size(); i++){
                moving.push_back(col5.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col5 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col5.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col5.at(indexFirst));
                col5.erase(col5.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col5.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col5.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col5.at(indexFirst));
                col5.erase(col5.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col5.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col5.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col5.at(indexFirst));
                col5.erase(col5.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col5.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col5.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col5.at(indexFirst));
                col5.erase(col5.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col5.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col6")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col6.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }

                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(col6.at(indexFirst), col2.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }

                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col2.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col6.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }

                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col6.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }
                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(col6.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }

                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            return false;
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(col6.at(indexFirst), col7.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col6.at(i));
            }

                for(int i = indexFirst; i < col6.size(); i++){
                moving.push_back(col6.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col7.push_back(moving.at(i));
            }
                col6 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col6.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col6.at(indexFirst));
                col6.erase(col6.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col6.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col6.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col6.at(indexFirst));
                col6.erase(col6.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col6.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col6.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col6.at(indexFirst));
                col6.erase(col6.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col6.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col6.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col6.at(indexFirst));
                col6.erase(col6.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col6.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("col7")==0)   {
        if(name2.compare("col1")==0)   {
            if(checkMove(col7.at(indexFirst), col1.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col7.at(i));
            }

                for(int i = indexFirst; i < col7.size(); i++){
                moving.push_back(col7.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col1.push_back(moving.at(i));
            }
                col7 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(col7.at(indexFirst), col2.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col7.at(i));
            }
                for(int i = indexFirst; i < col7.size(); i++){
                moving.push_back(col7.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col2.push_back(moving.at(i));
            }
                col7 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(col7.at(indexFirst), col3.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col7.at(i));
            }

                for(int i = indexFirst; i < col7.size(); i++){
                moving.push_back(col7.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col3.push_back(moving.at(i));
            }
                col7 = nonmoving;
             }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(col7.at(indexFirst), col4.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col7.at(i));
            }

                for(int i = indexFirst; i < col7.size(); i++){
                moving.push_back(col7.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col4.push_back(moving.at(i));
            }
                col7 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(col7.at(indexFirst), col5.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                nonmoving.push_back(col7.at(i));
            }

                for(int i = indexFirst; i < col7.size(); i++){
                moving.push_back(col7.at(i));
            }

                for(int i = 0 ; i < moving.size(); i++){
                col5.push_back(moving.at(i));
            }
                col7 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(col7.at(indexFirst), col6.at(indexSecond)))    {
                for(int i = 0; i < indexFirst; i++){
                    nonmoving.push_back(col7.at(i));
                }

                for(int i = indexFirst; i < col7.size(); i++){
                    moving.push_back(col7.at(i));
                }

                for(int i = 0 ; i < moving.size(); i++){
                col6.push_back(moving.at(i));
            }
                col7 = nonmoving;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            return false;
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(col7.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(col7.at(indexFirst));
                col7.erase(col7.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col7.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(col7.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(col7.at(indexFirst));
                col7.erase(col7.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col7.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(col7.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(col7.at(indexFirst));
                col7.erase(col7.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col7.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(col7.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(col7.at(indexFirst));
                col7.erase(col7.begin() + indexFirst);
                moveCard(first, second); first->raise();
                if(indexFirst != 0)    {
                    flipCard(col7.at(indexFirst-1), true);
                }
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("deck")==0)   {
        if(name2.compare("col1")==0)    {
            if(checkMove(foundDrawn.at(indexFirst), col1.at(indexSecond)))    {
                col1.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                if(indexSecond)
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col2.at(indexSecond)))    {
                col2.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col3.at(indexSecond)))    {
                col3.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col4.at(indexSecond)))    {
                col4.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col5.at(indexSecond)))    {
                col5.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col6.at(indexSecond)))    {
                col6.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(foundDrawn.at(indexFirst), col7.at(indexSecond)))    {
                col7.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            if(checkFoundationMove(foundDrawn.at(indexFirst), foundClubs.at(indexSecond)))    {
                foundClubs.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("hearts")==0)  {
            if(checkFoundationMove(foundDrawn.at(indexFirst), foundHearts.at(indexSecond)))    {
                foundHearts.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("diamonds")==0)  {
            if(checkFoundationMove(foundDrawn.at(indexFirst), foundDiamonds.at(indexSecond)))    {
                foundDiamonds.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("spades")==0)  {
            if(checkFoundationMove(foundDrawn.at(indexFirst), foundSpades.at(indexSecond)))    {
                foundSpades.push_back(foundDrawn.at(indexFirst));
                foundDrawn.erase(foundDrawn.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
    }
    else if(name1.compare("clubs")==0)  {
        if(name2.compare("col1")==0)    {
            if(checkMove(foundClubs.at(indexFirst), col1.at(indexSecond)))    {
                col1.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col2.at(indexSecond)))    {
                col2.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col3.at(indexSecond)))    {
                col3.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col4.at(indexSecond)))    {
                col4.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col5.at(indexSecond)))    {
                col5.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col6.at(indexSecond)))    {
                col6.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(foundClubs.at(indexFirst), col7.at(indexSecond)))    {
                col7.push_back(foundClubs.at(indexFirst));
                foundClubs.erase(foundClubs.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            return false;
        }
        else if(name2.compare("hearts")==0)  {
            return false;
        }
        else if(name2.compare("diamonds")==0)  {
            return false;
        }
        else if(name2.compare("spades")==0)  {
            return false;
        }
    }
    else if(name1.compare("hearts")==0) {
        if(name2.compare("col1")==0)    {
            if(checkMove(foundHearts.at(indexFirst), col1.at(indexSecond)))    {
                col1.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col2.at(indexSecond)))    {
                col2.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col3.at(indexSecond)))    {
                col3.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col4.at(indexSecond)))    {
                col4.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col5.at(indexSecond)))    {
                col5.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col6.at(indexSecond)))    {
                col6.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(foundHearts.at(indexFirst), col7.at(indexSecond)))    {
                col7.push_back(foundHearts.at(indexFirst));
                foundHearts.erase(foundHearts.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            return false;
        }
        else if(name2.compare("hearts")==0)  {
            return false;
        }
        else if(name2.compare("diamonds")==0)  {
            return false;
        }
        else if(name2.compare("spades")==0)  {
            return false;
        }
    }
    else if(name1.compare("diamonds")==0)   {
        if(name2.compare("col1")==0)    {
            if(checkMove(foundDiamonds.at(indexFirst), col1.at(indexSecond)))    {
                col1.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col2.at(indexSecond)))    {
                col2.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col3.at(indexSecond)))    {
                col3.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col4.at(indexSecond)))    {
                col4.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col5.at(indexSecond)))    {
                col5.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col6.at(indexSecond)))    {
                col6.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(foundDiamonds.at(indexFirst), col7.at(indexSecond)))    {
                col7.push_back(foundDiamonds.at(indexFirst));
                foundDiamonds.erase(foundDiamonds.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            return false;
        }
        else if(name2.compare("hearts")==0)  {
            return false;
        }
        else if(name2.compare("diamonds")==0)  {
            return false;
        }
        else if(name2.compare("spades")==0)  {
            return false;
        }}
    else if(name1.compare("spades")==0) {
        if(name2.compare("col1")==0)    {
            if(checkMove(foundSpades.at(indexFirst), col1.at(indexSecond)))    {
                col1.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col2")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col2.at(indexSecond)))    {
                col2.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col3")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col3.at(indexSecond)))    {
                col3.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col4")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col4.at(indexSecond)))    {
                col4.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col5")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col5.at(indexSecond)))    {
                col5.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col6")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col6.at(indexSecond)))    {
                col6.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("col7")==0)   {
            if(checkMove(foundSpades.at(indexFirst), col7.at(indexSecond)))    {
                col7.push_back(foundSpades.at(indexFirst));
                foundSpades.erase(foundSpades.begin() + indexFirst);
                moveCard(first, second); first->raise();
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name2.compare("clubs")==0)  {
            return false;
        }
        else if(name2.compare("hearts")==0)  {
            return false;
        }
        else if(name2.compare("diamonds")==0)  {
            return false;
        }
        else if(name2.compare("spades")==0)  {
            return false;
        }
    }

    if(status)  {
        if(name1.compare("col1")==0 && indexFirst != 0)    {
            flipCard(col1.at(indexFirst-1), true);
        }
        else if(name1.compare("col2")==0 && indexFirst != 0)  {
            flipCard(col2.at(indexFirst-1), true);
        }
        else if(name1.compare("col3")==0 && indexFirst != 0)   {
            flipCard(col3.at(indexFirst-1), true);
        }
        else if(name1.compare("col4")==0 && indexFirst != 0)   {
            flipCard(col4.at(indexFirst-1), true);
        }
        else if(name1.compare("col5")==0 && indexFirst != 0)   {
            flipCard(col5.at(indexFirst-1), true);
        }
        else if(name1.compare("col6")==0 && indexFirst != 0)   {
            flipCard(col6.at(indexFirst-1), true);
        }
        else if(name1.compare("col7")==0 && indexFirst != 0)   {
            flipCard(col7.at(indexFirst-1), true);
        }
    }

    return status;
}
bool MainWindow::fixTablaeuOrFoundation(QPushButton *first, QPushButton *second) {
    string suit1 = "";
    string suit2 = "";
    string name1 = "";
    string name2 = "";
    int indexFirst = 0;
    int num1 = 0;
    bool status = true;

    if(first->objectName().toStdString().compare("card_1H")==0)   {
        suit1 = "H";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_1S")==0)   {
        suit1 = "S";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_1D")==0)   {
        suit1 = "D";
        num1 = 1;
    }
    else if(first->objectName().toStdString().compare("card_1C")==0)   {
        suit1 = "C";
        num1 = 1;}
    else if(first->objectName().toStdString().compare("card_13H")==0)   {
        suit1 = "H";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_13S")==0)   {
        suit1 = "S";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_13D")==0)   {
        suit1 = "D";
        num1 = 13;
    }
    else if(first->objectName().toStdString().compare("card_13C")==0)   {
        suit1 = "C";
        num1 = 13;}

    if(second->objectName().toStdString().compare("foundation_heart")==0)   {
        suit2 = "H";
        name2 = "hearts";
    }
    else if(second->objectName().toStdString().compare("foundation_spade")==0)   {
        suit2 = "S";
        name2 = "spades";
    }
    else if(second->objectName().toStdString().compare("foundation_diamond")==0)   {
        suit2 = "D";
        name2 = "diamonds";
    }
    else if(second->objectName().toStdString().compare("foundation_club")==0)   {
        suit2 = "C";
        name2 = "clubs";
    }
    else if(second->objectName().toStdString().compare("tableau_1")==0) {
        name2 = "col1";
    }
    else if(second->objectName().toStdString().compare("tableau_2")==0) {
        name2 = "col2";
    }
    else if(second->objectName().toStdString().compare("tableau_3")==0) {
        name2 = "col3";
    }
    else if(second->objectName().toStdString().compare("tableau_4")==0) {
        name2 = "col4";
    }
    else if(second->objectName().toStdString().compare("tableau_5")==0) {
        name2 = "col5";
    }
    else if(second->objectName().toStdString().compare("tableau_6")==0) {
        name2 = "col6";
    }
    else if(second->objectName().toStdString().compare("tableau_7")==0) {
        name2 = "col7";
    }

    for(unsigned int i = 0; i < col1.size(); i++)    {
        if(col1.at(i)->Num() == num1 && col1.at(i)->Suit() == suit1)    {
            name1 = "col1";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col2.size(); i++)    {
        if(col2.at(i)->Num() == num1 && col2.at(i)->Suit() == suit1)    {
            name1 = "col2";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col3.size(); i++)    {
        if(col3.at(i)->Num() == num1 && col3.at(i)->Suit() == suit1)    {
            name1 = "col3";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col4.size(); i++)    {
        if(col4.at(i)->Num() == num1 && col4.at(i)->Suit() == suit1)    {
            name1 = "col4";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col5.size(); i++)    {
        if(col5.at(i)->Num() == num1 && col5.at(i)->Suit() == suit1)    {
            name1 = "col5";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col6.size(); i++)    {
        if(col6.at(i)->Num() == num1 && col6.at(i)->Suit() == suit1)    {
            name1 = "col6";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < col7.size(); i++)    {
        if(col7.at(i)->Num() == num1 && col7.at(i)->Suit() == suit1)    {
            name1 = "col7";
            indexFirst = i;
        }
    }

    for(unsigned int i = 0; i < foundDrawn.size(); i++)   {
        if(foundDrawn.at(i)->Num() == num1 && foundDrawn.at(i)->Suit() == suit1)    {
            name1 = "deck";
            indexFirst = i;
        }
    }

    if(num1 == 1)   {
        if(name1.compare("col1")==0)    {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col1.at(indexFirst), "C"))    {
                    foundClubs.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col1.at(indexFirst), "H"))    {
                    foundHearts.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col1.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col1.at(indexFirst), "S"))    {
                    foundSpades.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col2")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col2.at(indexFirst), "C"))    {
                    foundClubs.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col2.at(indexFirst), "H"))    {
                    foundHearts.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col2.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col2.at(indexFirst), "S"))    {
                    foundSpades.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col3")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col3.at(indexFirst), "C"))    {
                    foundClubs.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col3.at(indexFirst), "H"))    {
                    foundHearts.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col3.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col3.at(indexFirst), "S"))    {
                    foundSpades.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col4")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col4.at(indexFirst), "C"))    {
                    foundClubs.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col4.at(indexFirst), "H"))    {
                    foundHearts.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col4.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col4.at(indexFirst), "S"))    {
                    foundSpades.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col5")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col5.at(indexFirst), "C"))    {
                    foundClubs.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col5.at(indexFirst), "H"))    {
                    foundHearts.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col5.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col5.at(indexFirst), "S"))    {
                    foundSpades.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col6")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col6.at(indexFirst), "C"))    {
                    foundClubs.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col6.at(indexFirst), "H"))    {
                    foundHearts.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col6.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col6.at(indexFirst), "S"))    {
                    foundSpades.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col7")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(col7.at(indexFirst), "C"))    {
                    foundClubs.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(col7.at(indexFirst), "H"))    {
                    foundHearts.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(col7.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(col7.at(indexFirst), "S"))    {
                    foundSpades.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("deck")==0)   {
            if(name2.compare("clubs")==0)  {
                if(checkFirstFoundation(foundDrawn.at(indexFirst), "C"))    {
                    foundClubs.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("hearts")==0)  {
                if(checkFirstFoundation(foundDrawn.at(indexFirst), "H"))    {
                    foundHearts.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("diamonds")==0)  {
                if(checkFirstFoundation(foundDrawn.at(indexFirst), "D"))    {
                    foundDiamonds.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("spades")==0)  {
                if(checkFirstFoundation(foundDrawn.at(indexFirst), "S"))    {
                    foundSpades.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
    }
    else if(num1 == 13)  {
        if(name1.compare("col1")==0)    {
            if(name2.compare("col1")==0)    {
                return false;
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col2.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col3.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col4.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col5.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col6.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col1.at(indexFirst)))    {
                    col7.push_back(col1.at(indexFirst));
                    col1.erase(col1.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }else    {
                return false;
            }
        }
        else if(name1.compare("col2")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col1.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                return false;
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col3.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col4.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col5.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col6.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col2.at(indexFirst)))    {
                    col7.push_back(col2.at(indexFirst));
                    col2.erase(col2.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("col3")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col1.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col2.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                return false;
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col4.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col5.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col6.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col3.at(indexFirst)))    {
                    col7.push_back(col3.at(indexFirst));
                    col3.erase(col3.begin() + indexFirst);
                }
                else    {
                    return false;
                }  }
            else    {
                return false;
            }
        }
        else if(name1.compare("col4")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col1.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col2.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col3.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                return false;
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col5.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col6.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col4.at(indexFirst)))    {
                    col7.push_back(col4.at(indexFirst));
                    col4.erase(col4.begin() + indexFirst);
                }
                else    {
                    return false;
                }  }
            else    {
                return false;
            }
        }
        else if(name1.compare("col5")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col1.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col2.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col3.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col4.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                return false;
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col6.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col5.at(indexFirst)))    {
                    col7.push_back(col5.at(indexFirst));
                    col5.erase(col5.begin() + indexFirst);
                }
                else    {
                    return false;
                }  }
            else    {
                return false;
            }
        }
        else if(name1.compare("col6")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col1.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col2.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col3.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col4.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col5.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                return false;
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(col6.at(indexFirst)))    {
                    col7.push_back(col6.at(indexFirst));
                    col6.erase(col6.begin() + indexFirst);
                }
                else    {
                    return false;
                }  }
            else    {
                return false;
            }
        }
        else if(name1.compare("col7")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col1.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col2.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col3.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col4.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col5.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(col7.at(indexFirst)))    {
                    col6.push_back(col7.at(indexFirst));
                    col7.erase(col7.begin() + indexFirst);
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                return false;
            }
            else    {
                return false;
            }
        }
        else if(name1.compare("deck")==0)   {
            if(name2.compare("col1")==0)    {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col1.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col2")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col2.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col3")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col3.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col4")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col4.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col5")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col5.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col6")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col6.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else if(name2.compare("col7")==0)   {
                if(checkFirstTableau(foundDrawn.at(indexFirst)))    {
                    col7.push_back(foundDrawn.at(indexFirst));
                    foundDrawn.erase(foundDrawn.begin() + indexFirst);
                    moveCardDeckTableau(first, second);
                    first->raise();
                    return false;
                }
                else    {
                    return false;
                }
            }
            else    {
                return false;
            }
        }
    }
    else    {
        return false;
    }

    if(status)  {
        if(name1.compare("col1")==0 && indexFirst != 0)    {
            flipCard(col1.at(indexFirst-1), true);
        }
        else if(name1.compare("col2")==0 && indexFirst != 0)  {
            flipCard(col2.at(indexFirst-1), true);
        }
        else if(name1.compare("col3")==0 && indexFirst != 0)   {
            flipCard(col3.at(indexFirst-1), true);
        }
        else if(name1.compare("col4")==0 && indexFirst != 0)   {
            flipCard(col4.at(indexFirst-1), true);
        }
        else if(name1.compare("col5")==0 && indexFirst != 0)   {
            flipCard(col5.at(indexFirst-1), true);
        }
        else if(name1.compare("col6")==0 && indexFirst != 0)   {
            flipCard(col6.at(indexFirst-1), true);
        }
        else if(name1.compare("col7")==0 && indexFirst != 0)   {
            flipCard(col7.at(indexFirst-1), true);
        }
    }

    return status;
}

//moveColumn deals with moving a whole stack from card to card movement
void MainWindow::moveColumn(QPushButton *first, QPushButton *second)    {
   QPushButton *buttons[52] = { ui->card_1H, ui->card_2H, ui->card_3H, ui->card_4H, ui->card_5H, ui->card_6H, ui->card_7H, ui->card_8H, ui->card_9H, ui->card_10H, ui->card_11H, ui->card_12H, ui->card_13H,
                            ui->card_1S, ui->card_2S, ui->card_3S, ui->card_4S, ui->card_5S, ui->card_6S, ui->card_7S, ui->card_8S, ui->card_9S, ui->card_10S, ui->card_11S, ui->card_12S, ui->card_13S,
                            ui->card_1C, ui->card_2C, ui->card_3C, ui->card_4C, ui->card_5C, ui->card_6C, ui->card_7C, ui->card_8C, ui->card_9C, ui->card_10C, ui->card_11C, ui->card_12C, ui->card_13C,
                            ui->card_1D, ui->card_2D, ui->card_3D, ui->card_4D, ui->card_5D, ui->card_6D, ui->card_7D, ui->card_8D, ui->card_9D, ui->card_10D, ui->card_11D, ui->card_12D, ui->card_13D };

    if(fixVector(first, second))    {
        vector<int> cardsToRaise;
        int initialX = first->x();
        int initialY = first->y();
        int newY = initialY;
        int increment = 30;
        int numOfCardsNeededToRaise = 0;

        //Number of Cards to Raise
        for(int i = 0; i < 52; i++){
            if(buttons[i]->x() == initialX){
                if(buttons[i]->y() >= initialY){
                    numOfCardsNeededToRaise++;
                }
            }
        }

        int finalNumOfCardsNeededToRaise = numOfCardsNeededToRaise;

        //Number of Cards to Raise in Order
        for(int i = 0; i < 52; i++){
            if(buttons[i]->x() == initialX){
                if(buttons[i]->y() == initialY){
                    cardsToRaise.push_back(i);
                    numOfCardsNeededToRaise--;
                }
            }
        }

        while(numOfCardsNeededToRaise > 0){
            for(int i = 0; i < 52; i++){
                if(buttons[i]->x() == initialX){
                    if((buttons[i]->y() > newY) && (buttons[i]->y() < newY + 40)){
                        cardsToRaise.push_back(i);
                        numOfCardsNeededToRaise--;
                        newY = buttons[i]->y();
                    }
                }
            }
        }

        numOfCardsNeededToRaise = finalNumOfCardsNeededToRaise;

        for(int i = 0; i < cardsToRaise.size(); i++){
            buttons[cardsToRaise.at(i)]->move(second->x(), second->y() + increment);
            buttons[cardsToRaise.at(i)]->raise();
            increment = increment + 30;
        }
    }
}

//Backend Boolean checks for game rules for specific moves
bool MainWindow::checkMove(Node* first, Node* second){
    string firstSuit = first->Suit();
    int firstNum = first->Num();
    string secondSuit = second->Suit();
    int secondNum = second->Num();
    bool status = true;

    if(firstNum != secondNum-1){
        return false;
    }
    if(firstSuit.compare("C") == 0){
        if(!(secondSuit.compare("D")==0 || secondSuit.compare("H")==0)){
            return false;
        }
    }
    if(firstSuit.compare("S") == 0){
        if(!(secondSuit.compare("D")==0 || secondSuit.compare("H")==0)){
            return false;
        }
    }
    if(firstSuit.compare("D") == 0){
        if(!(secondSuit.compare("S")==0 || secondSuit.compare("C")==0)){
            return false;
        }
    }
    if(firstSuit.compare("H") == 0){
        if(!(secondSuit.compare("S")==0 || secondSuit.compare("C")==0)){
            return false;
        }
    }
    if(firstSuit.compare(secondSuit)==0 && firstNum == secondNum){
        return false;
    }

    return status;
}
bool MainWindow::checkFoundationMove(Node* first, Node* second) {
    string firstSuit = first->Suit();
    int firstNum = first->Num();
    string secondSuit = second->Suit();
    int secondNum = second->Num();
    bool status = true;

    if(firstNum != secondNum+1){
        return false;
    }
    if(firstSuit.compare("C") == 0){
        if(!(secondSuit.compare("C")==0)){
            return false;
        }
    }
    if(firstSuit.compare("S") == 0){
        if(!(secondSuit.compare("S")==0)){
            return false;
        }
    }
    if(firstSuit.compare("D") == 0){
        if(!(secondSuit.compare("D")==0)){
            return false;
        }
    }
    if(firstSuit.compare("H") == 0){
        if(!(secondSuit.compare("H")==0)){
            return false;
        }
    }
    if(firstSuit.compare(secondSuit)==0 && firstNum == secondNum){
        return false;
    }

    return status;
}
bool MainWindow::checkFirstFoundation(Node* first, string suit2)    {
    string suit1 = first->Suit();
    int num1 = first->Num();
    bool status = true;

    if(num1 != 1)   {
        return false;
    }

    if(!(suit1.compare(suit2)==0))    {
        return false;
    }
    return status;
}
bool MainWindow::checkFirstTableau(Node* first)  {
    string suit1 = first->Suit();
    int num1 = first->Num();
    bool status = true;

    if(num1 != 13)   {
        return false;
    }

    return status;
}

//Deck Button to cycle through the deck and draw cards
void MainWindow::on_deck_clicked()  {
    int x = 670;
    int y = 40;
    if(!foundDeck.empty())  {
        moveButton(foundDeck.at(foundDeck.size()-1), x, y);
        raiseButton(foundDeck.at(foundDeck.size()-1));
        foundDrawn.push_back(foundDeck.at(foundDeck.size()-1));
        foundDeck.pop_back();
    }
    else    {
        for(int i = foundDrawn.size()-1; i >= 0; i--)   {
            moveButton(foundDrawn.at(i), x+90, y);
            ui->deck->raise();
            foundDeck.push_back(foundDrawn.at(i));
            foundDrawn.pop_back();
        }
    }
}

//Check if all of the vectors are empty to win the game
void MainWindow::checkWin(){
    if(col1.empty()){
        if(col2.empty()){
            if(col3.empty()){
                if(col4.empty()){
                    if(col5.empty()){
                        if(col6.empty()){
                            if(col7.empty()){
                                if(foundDrawn.empty()){
                                    if(foundDeck.empty()){
                                      ui->winScreen->raise();
                                      ui->winScreen->setPixmap(QPixmap("/Users/chandlergriffin/Documents/School Work/UF/Spring 16/COP3503/SoLITaire/Extra Graphics/winnerNew.png"));
                                      ui->gameplay_quitGameButton->raise();
                                      ui->gameplay_quitGameButton->setText("Return to Main Menu");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
