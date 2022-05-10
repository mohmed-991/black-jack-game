#include <iostream>

using namespace std;

class card{

private:
    int suit;
    int cardRank;
    int value;

    string suitText = "null";
    string rankText = "null";

public:

    card(int s, int r, int v){
        suit = s;
        cardRank = r;
        value = v;

        setText();
    }

    card(){
        suit = -1;
        cardRank = -1;
        value = -1;
    }

    int getCardSuit(){
        return suit;
    }
    int getCardRank(){
        return cardRank;
    }
    int getCardValue(){
        return value;
    }

    void setText(){
        switch(suit){
        case 0:
            suitText = "Club";
            break;
        case 1:
            suitText = "Diamond";
            break;
        case 2:
            suitText = "Heart";
            break;
        case 3:
            suitText = "Spade";
            break;
        default:
            suitText = "Empty";
        }

    switch(cardRank){
        case 0:
            rankText = "Ace";
            break;
        case 1:
            rankText = "2";
            break;
        case 2:
            rankText = "3";
            break;
        case 3:
            rankText = "4";
            break;
        case 4:
            rankText = "5";
            break;
        case 5:
            rankText = "6";
            break;
        case 6:
            rankText = "7";
            break;
        case 7:
            rankText = "8";
            break;
        case 8:
            rankText = "9";
            break;
        case 9:
            rankText = "10";
            break;
        case 10:
            rankText = "Jack";
            break;
        case 11:
            rankText = "Queen";
            break;
        case 12:
            rankText = "King";
            break;
        default:
            rankText = "Empty";
        }

    }
    /// replace with operator overloading
    void displayCard(){
        cout<<"( "<<suitText<<" "<<rankText<<" )"<<endl;
    }

    bool operator==(card c){
        if(suit == c.getCardRank()
        && (cardRank == c.getCardRank()
        && value == c.getCardValue())){
            return true;
        }else{
            return false;
        }
    }

};

class player{

private:
    string name;
    int score = 0;
    card hand[13];
    int cardCount = 0;

public:

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    int getScore(){
        return score;
    }

    void addCard(card c){

        hand[cardCount] = c;
        score += c.getCardValue();
        cardCount++;

    }

};

class Game{

public:
    player players[4];
    card deck[52];
    int numOfCards = 0;
    int winner = -1;
    int winnerScore = 0;

    void generateDeck(){
        for(int i = 0; i<4; i++){
            for(int j = 0; j<13; j++){

                int val;
                if(j >= 10){
                    val = 10;
                }else{
                    val = j + 1;
                }

                card c(i, j, val);

                deck[numOfCards] = c;
                numOfCards++;
            }
        }
    }

    void displayDeck(){
        for(int i = 0; i<52; i++){
            deck[i].displayCard();
        }
    }

    card emptyCard; /// -1 -1 -1

    card draw(){
        card c;

        if(numOfCards <= 0){
            throw "no cards left";
        }else{

            do{
                int random = rand()%52;
                c = deck[random];
                deck[random] = emptyCard;
            }while(c == emptyCard);
        }
        c.displayCard();
        return c;
    }

    void setInfo(){
        string name;

        for(int i = 0; i<4; i++){
            getline(cin, name);
            players[i].setName(name);
            card c1 = draw();
            card c2 = draw();

            players[i].addCard(c1);
            players[i].addCard(c2);

            cout<<"========= player "<<i+1<<" set !========="<<endl;

        }
    }

    void gameResult(){
        for(int i = 0; i<4; i++){
            if(players[i].getScore() > winnerScore && players[i].getScore()<=21){
                winner = i;
                winnerScore = players[i].getScore();
            }
        }
        if(winner == -1){
            cout<<endl<<"========================================="<<endl;
            cout<<"============ all players lost! =========="<<endl;
            cout<<"========================================="<<endl;

        }else{
            cout<<endl<<"========================================="<<endl;
            cout<<"========================================="<<endl;
            cout<<"\t winner is "<<players[winner].getName()<<endl;
            cout<<"\t with score of "<<players[winner].getScore()<<endl;
            cout<<"========================================="<<endl;
            cout<<"========================================="<<endl;

        }
    }

};

int main()
{

    Game game;

    game.generateDeck();

    game.setInfo();

        for(int i = 0; i<4; i++){
        string input;
            cout<<endl<<"========================================="<<endl;
            cout<<"\t "<<game.players[i].getName()<<"'s turn"<<endl;
            cout<<"\t current score : "<<game.players[i].getScore()<<endl;
            cout<<"========================================="<<endl;
        while(true){
            cout<<endl<<"type {hit} or {stand}"<<endl;
            cin>>input;
            if(input == "hit"){
                card c = game.draw();
                game.players[i].addCard(c);
                cout<<"----- current score : "<<game.players[i].getScore()<<"--------"<<endl;
            }else{
                break;
            }

        }

    }

    game.gameResult();

    return 0;
}
