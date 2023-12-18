#include "GameBoard.h"
//Card Hash structure, this struct is only used in the createSets() Function
struct CardHash {//takes a Card object and returns a hash based on the value member of the Card class. 
    std::size_t operator()(const Card& card) const {
   
        return std::hash<int>()(card.value);
    }
};
struct CardHasValue {//Card Hash structure, this struct is only used in the createSets() Function
    int targetValue;
    //helps find card value
    CardHasValue(int value) : targetValue(value) {}

    bool operator()(const Card& card) const {
        return card.value == targetValue;
    }
};

//Class definitions begin
GameBoard::GameBoard(){//default constructor
};
GameBoard::GameBoard(DeckofCards primeDeck) {//takes DeckofCard object 
    for (int i = 0; i < 2; i++) {//initializes queue called q 
       q.push((rand() % 2)+1);//inserts 2 integer randomized from 1-2
     }//this queue will be used in createSet()
        
    card2 = primeDeck;//transfers the deck of Card objects to GameBoard 
    //initializes all the maps needed to create the cards art and track of the empty decks
       sp.insert(std::make_pair("Spades", "♤"));
       sp.insert(std::make_pair("Clubs", "♧"));
       sp.insert(std::make_pair("Diamonds", "\u2666"));
       sp.insert(std::make_pair("Hearts", "\u2665"));
       rp.insert(std::make_pair(1, "A"));
       rp.insert(std::make_pair(2, "2"));
       rp.insert(std::make_pair(3, "3"));
       rp.insert(std::make_pair(4, "4"));
       rp.insert(std::make_pair(5, "5"));
       rp.insert(std::make_pair(6, "6"));
       rp.insert(std::make_pair(7, "7"));
       rp.insert(std::make_pair(8, "8"));
       rp.insert(std::make_pair(9, "9"));
       rp.insert(std::make_pair(10, "10"));
       rp.insert(std::make_pair(11, "J"));
       rp.insert(std::make_pair(12, "Q"));
       rp.insert(std::make_pair(13, "K"));
       ap.insert(std::make_pair(1, false));
       ap.insert(std::make_pair(2, false));
       ap.insert(std::make_pair(3, false));
       ap.insert(std::make_pair(4, false));
       ap.insert(std::make_pair(5, false));
       ap.insert(std::make_pair(6, false));
       ap.insert(std::make_pair(7, false));
       ap.insert(std::make_pair(8, false));
}
/********************************************************
 *createDeck() golf solitaire splits a normal deck of cards
 * into 5 decks having 5 cards a stock pile with the remainding
 * cards and a user pile which the player fills each time he takes
 * a card from one of the 5 decks or the stock
 ********************************************************/
void GameBoard::createDecks(){
    for(int a= 0; a < 5;a++){
        deck1.push_back(card2.deck[a]);
    }
    for(int a= 5; a < 10;a++){
        deck2.push_back(card2.deck[a]);
    }
    for(int a= 10; a < 15;a++){
        deck3.push_back(card2.deck[a]);
    }
    for(int a= 15; a < 20;a++){
        deck4.push_back(card2.deck[a]);
    }
    for(int a= 20; a < 25;a++){
        deck5.push_back(card2.deck[a]);
    }
    for(int a= 25; a < 51;a++){
        stock.push_back(card2.deck[a]);
    }
    for(int a= 51; a < 52;a++){
        userdeck.push_back(card2.deck[a]);
    }
    for(int a= 25; a < 51;a++){
        ddeck.push(card2.deck[a]);
    }
}
void GameBoard::makeBoard(){
    //iterator to traverse each deck
    list<Card>::iterator pos;//iterator for the front of a deck
    list<Card>::iterator end;//iterator for the back of a deck
    
    for(int a = 0;  a < 3; a++)//for loop to iterate through one deck three times
    {//since one card will take three rows to print on the console
        pos = deck1.begin();//assigns iterators to front and end of deck assigned
        end = deck1.end();
        for(pos; pos!=end; ++pos)//prints out in a visual representation the value of the card in each deck by order 
        {
            string u = pos->suit;
            int v = pos->value;
            if(a%2==0)
            {//designs the card
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
            }
        }
        cout << endl ;
    }
    //repeats the process for the rest of the decks to be seen on the board by the user
    cout<<endl;
    for(int a = 0;  a < 3; a++)
    {
        pos = deck2.begin();
        end = deck2.end();
        for(pos; pos!=end; ++pos)
        {
            string u = pos->suit;
            int v = pos->value;
            if(a%2==0)
            {
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
            }
        }
        cout << endl ;
    }
    cout<<endl;
    for(int a = 0;  a < 3; a++)
    {
        pos = deck3.begin();
        end = deck3.end();
        for(pos; pos!=end; ++pos)
        {
            string u = pos->suit;
            int v = pos->value;
            if(a%2==0)
            {
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
            }
        }
        cout << endl ;
    }
    cout<<endl;
    for(int a = 0;  a < 3; a++)
    {
        pos = deck4.begin();
        end = deck4.end();
        for(pos; pos!=end; ++pos)
        {
            string u = pos->suit;
            int v = pos->value;
            if(a%2==0)
            {
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
            }
        }
        cout << endl ;
    }
    cout<<endl;
    for(int a = 0;  a < 3; a++)
    {
        pos = deck5.begin();
        end = deck5.end();
        for(pos; pos!=end; ++pos)
        {
            string u = pos->suit;
            int v = pos->value;
            if(a%2==0)
            {
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
            }
        }
        cout << endl ;
    }
    cout<<endl;
    
    //displays the users deck waste it grows as he pops from stock or rows of cards
    int num1 = 1;
    cout << "USER WASTE DECK"<<endl;
        for(pos = userdeck.begin(); pos!=userdeck.end(); ++pos){
            string u = pos->suit;
            int v = pos->value;
            cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            if(num1%9==0){
                cout<<endl;
            }
            num1++;
        }
    cout<< " front of waste";
    cout<<endl<<endl;
    //displays the stock and how many card left in the stock for player to know
    cout << "----------" << endl;
    cout << "|        |"<< endl;
    cout << "|   S    | stock left: " <<ddeck.size()<< endl;
    cout << "|        |" << endl;
    cout << "----------" << endl;
    cout<<endl;
}
/********************************************************
 *makeBoard() prints out the board, however it takes a 
 *parameter, an array of Card objects, it prints the deck 
 * differently as it does not make the board only prints a
 * visual representation of all the cards in an array to ensure
 * all the cards are there, then proceeds to print four rows
 * of 13 cards
 ********************************************************/
void GameBoard::makeBoard(Card deck[]){
    int b1=0;
    int c = 0;
    for(int a = 0; a < 3; a++ )
    {
        for(int b = b1; b < b1+13; b++ )
        {
            string u = deck[b].suit;
            int v = deck[b].value;
            if(a%2==0){
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                if(b==12+b1){
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" << setw(2) << "D" <<c ;
                }
                else{
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
                }
            }
            
        }
        cout << endl;
    }
    cout << endl;
    b1 = b1+13;
    c++;
    for(int a = 0; a < 3; a++ )
    {
        for(int b = b1; b < b1+13; b++ )
        {
            string u = deck[b].suit;
            int v = deck[b].value;
            if(a%2==0){
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                if(b==12+b1){
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" << setw(2) << "D" <<c ;
                }
                else{
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    b1 = b1+13;
    c++;
    for(int a = 0; a < 3; a++ )
    {
        for(int b = b1; b < b1+13; b++ )
        {
            string u = deck[b].suit;
            int v = deck[b].value;
            if(a%2==0){
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                if(b==12+b1){
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" << setw(2) << "D" <<c ;
                }
                else{
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    b1 = b1+13;
    c++;
    for(int a = 0; a < 3; a++ )
    {
        for(int b = b1; b < b1+13; b++ )
        {
            string u = deck[b].suit;
            int v = deck[b].value;
            if(a%2==0){
                cout <<setw(2) << "|"<< sp[u] << setw(2)<< rp[v] << "|" ;
            }
            else{
                if(b==12+b1){
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" << setw(2) << "D" <<c ;
                }
                else{
                    cout <<setw(2) << "|" << setw(4)<< sp[u] << setw(2)  << "|" ;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}
void GameBoard::PopfromStack(){
    //PopfromStack simply pops the last card in one of the decks found within GameBoard
    //it pops the last card of the deck the user inputted 
    
    //if user asks to pop from deck1, it will add the Card object to the userdeck
    if(six==1){
        userdeck.push_back(deck1.back());
        deck1.pop_back();
        if(deck1.empty()){//if deck1 is empty then the map will update to true 
            //this ensures that the deck can no longer be used since there are 
            //no remainding cards
            ap[six]= true;
        }
    }
    //same process just tailored to each deck in the game
    if(six==2){
        userdeck.push_back(deck2.back());
        deck2.pop_back();
        if(deck2.empty()){
            ap[six]= true;
        }
    }
    if(six==3){
        userdeck.push_back(deck3.back());
        deck3.pop_back();
        if(deck3.empty()){
            ap[six]= true;
        }
    }
    if(six==4){
        userdeck.push_back(deck4.back());
        deck4.pop_back();
        if(deck4.empty()){
            ap[six]= true;
        }
    }
    if(six==5){
        userdeck.push_back(deck5.back());
        deck5.pop_back();
        if(deck5.empty()){
            ap[six]= true;
        }
    }
    //this deck correlates to the stock
    if(six==6){//if the user wants to pop from stock, it puts the last card in the stock
        userdeck.push_back(ddeck.top());//in the userdeck waste pile
        ddeck.pop();
        if(ddeck.empty()){
            ap[6]= true;
            cout<<ap[6];
        }
        stock.pop_back();
    }
}
void GameBoard::wonMenu(){//winning menu
    cout<<"CONGRATULATIONS, YOU WON THE" <<endl;
    cout<<" ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout<<" ███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀" << endl;
    cout<<" ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼" << endl;
    cout<<" ██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀" << endl;
    cout<<" ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼" << endl;
    cout<<" ███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄" << endl;
    cout<<" ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
}
void GameBoard::gameOverMenu(){//loss menu
    cout<<" ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout<<" ███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀" << endl;
    cout<<" ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼" << endl;
    cout<<" ██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀" << endl;
    cout<<" ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼" << endl;
    cout<<" ███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄" << endl;
    cout<<" ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout<<" ███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼" << endl;
    cout<<" ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
    cout<<" ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼" << endl;
    cout<<" ██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
    cout<<" ███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄" << endl;
    cout<<" ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    cout <<endl<<"    YOU HAVE NO MORE MOVES LEFT!!!"<<endl;
}
/********************************************************
 *AskUser() is one of the most important functions as it 
 * asks and records the users/players responds relate to 
 * how they wish to move the cards within the board
 * the function first ensures that the responds are valid 
 * and the user can only respond with the options presented 
 * to him, it also check if the user responds with a valid 
 * option whether the move is even possible. If not asks user
 * to do a different move. This in turn records the move and
 * when the PopfromStack() function is called it knows how 
 * to moves the cards and in turn can properly update the 
 * game board
 ********************************************************/
void GameBoard::AskUser(){
    //checks whether the user actually gives a number responds
    cout << "Which row do you want to pop off? enter 1-5, and press 6 if you want to pop from stock";
    while(!(cin >> six)){
        cout << "Please only enter a digit from 1-6 ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    //checks if the values is within the proper range
    while(1>six || six>6){
        cout << "you cant pick the spot, it is not an option!!!"<< endl;
        cout << "Which row do you want to pop off?";
        while(!(cin >> six)){//ensures if not within the proper range the user can only chose a number
            cout << "Please only enter a digit from 1-6";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    while(ap[six]){//if the user chooses to move a card from a deck that is empty 
        //it will ask it to choose another spot
        cout << "you cant pick the spot, it is empty!!"<< endl;
        cout << "Which row do you want to pop off?";
        while(!(cin >> six)){//ensures the user only gives a number answer
            cout << "Please only enter a digit from 1-6";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    
    list<Card>::iterator end;//iterator to point to the last card in appointed deck
    switch (six) {//assigns iterator to last card in the deck the user chose
        //this will allow the program to compare if the last card deck the user chose
        //is allowed to be popped off and put into the users waste pile
        case 1:
            end = std::prev(deck1.end());
            break;
        case 2:
            end = std::prev(deck2.end());
            break;
        case 3:
            end = std::prev(deck3.end());
            break;
        case 4:
            end = std::prev(deck4.end());
            break;
        case 5:
            end = std::prev(deck5.end());
            break;
        case 6:
            break;
        default:
            cout<<"unexpected input";
            break;
    }
    if(six!=6)//if the user did not chose to pop a card from stock rather one of the five decks on the board
    {
        //checks whether the move is possible 
        while(notValidMove(&(*end), userdeck)&&(six!=6))
        {
            cout<< "user waste- value: "<<userdeck.back().value<<endl;
            cout <<"deck value: "<< end->value<<endl;
            cout<<"not valid move, try again?";
            while(!(cin >> six)){
                cout << "Please only enter a digit from 1-6 ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            while(1>six || six>6)
            {
                cout << "you cant pick the spot, it is not an option!!!"<< endl;
                cout << "Which row do you want to pop off?";
                cin >>six;
            
            }
            switch (six) {
                case 1:
                    end = std::prev(deck1.end());
                    break;
                case 2:
                    end = std::prev(deck2.end());
                    break;
                case 3:
                    end = std::prev(deck3.end());
                    break;
                case 4:
                    end = std::prev(deck4.end());
                    break;
                case 5:
                    end = std::prev(deck5.end());
                    break;
                case 6:
                    break;
                default:
                    cout<<"unexpected input";
                    break;
            }
        }
    }
}
bool GameBoard::notValidMove(Card *end,list<Card>stack){
    //validates and returns true whether the two cards are either one value below
    //value above, otherwise false
    if((end->value+1)==stack.back().value)
    {
        return false;
    }
    if((end->value-1)==stack.back().value)
    {
        return false;
    }
    if((end->value-12)==stack.back().value)
    {
        return false;
    }
    if((end->value+12)==stack.back().value)
    {
        return false;
    }
    return true;
}
/********************************************************
 *checkLossCondition()if checks if the stock is empty,
 * otherwise the player can still make moves and it 
 * is not possible to loss in the turn, therefore 
 * returns false. If the stock is empty then it actually 
 * validates whether the player can even make a move,
 * if the player cannot and there are still cards on the
 * board while the stock is empty the player lost
 *******************************************************/
bool GameBoard::checkLossCondition(){
    
    bool endgame = true;
    if(ap[6])//if stock not empty 
    {
        for(int i = 1; i <=5; i++ )//goes through all 5 decks
        {
            if(!ap[i])//if the deck is not empty
            {
                list<Card>::iterator end;
                switch (i){
                    case 1:
                        end = std::prev(deck1.end());
                        break;
                    case 2:
                        end = std::prev(deck2.end());
                        break;
                    case 3:
                        end = std::prev(deck3.end());
                        break;
                    case 4:
                        end = std::prev(deck4.end());
                        break;
                    case 5:
                        end = std::prev(deck5.end());
                        break;
                    default:
                        cout<<"unexcepted input";
                        break;
                }
                //check whether one of the decks can produce a valid move
                //if so then endgame is false and the player can continue
                if(!notValidMove(&(*end), userdeck))
                {
                    endgame = false;
                }
            }
        }
    }
    else{//otherwise fo not end the game yet
        endgame = false;
    }
    return endgame;
}
bool GameBoard::checkWinCondition(){
    bool result = true;
    //if all decks are empty then the player wins 
    //will return true
    for(int i = 1; i <=5; i++ ){
        if(!ap[i]){
            result = false;
        }
    }
    return result;
}
bool GameBoard::isValid(string &choice, int min, int max){
    //checks if answer is valid within a certain range
    bool validity = true;
    for(char c: choice){//checks if its a number response
        if(!isdigit(c)){
            validity= false;
        }
    }
    if(validity){
        int num = stoi(choice);//checks if the number falls within selected range
        if ( !((num >= min)&&(num <= max)) )
        {
            validity =false;
        }
    }
    return validity;
}
/********************************************************
 *MainMenu()displays a menu with the option to start, 
 *read the rules, or quit the game. ensures the the player
 *answers correctly  
 ********************************************************/
void GameBoard::mainMenu(string &choice){
    string strAry[] = {" __        __   _                            _           ____       _  __ ",
        " \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___    / ___| ___ | |/ _|",
        "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | |  _ / _ \\| | |_ ",
        "   \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |_| | (_) | |  _|",
        "  __\\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \\____|\\___/|_|_|",
        " / ___|  ___ | (_) |_ __ _(_)_ __ ___  ",
        " \\___ \\ / _ \\| | | __/ _` | | '__/ _ \\ ",
        "  ___) | (_) | | | || (_| | | | |  __/ ",
        " |____/ \\___/|_|_|\\__\\__,_|_|_|  \\___| "
    };
    
    for (int i = 0; i <9 ;i++){
        cout << strAry[i]<<endl;
        std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));//pauses
    }
    cout<<endl;
    cout<<"1. Start"<<endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    cout<<"2. Rules"<<endl;
     std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    cout<<"3. Check adjacency of Cards"<<endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    cout<<"4. Quit"<<endl;
    cin >> choice;
    while(!isValid(choice,1,4)){//messages based on responds
        cout<< "Please only chose one of our options";
        cin >> choice;
    }
    if(choice =="2"){
        cout<< endl << "==========================RULES========================"<<endl;
        cout <<"Golf Solitaire features a game board with seven columns,\neach containing five face-up cards,alongside the\nStock (a facedown pile in the bottom left) and the\nWaste (an initially empty faceup pile next to the Stock).\nThe goal is to transfer all column cards to the Waste. "<< endl;
        cout << "Only the top card of each column can be moved, and it\nmust be one rank higher or lower than the current top\ncard on the Waste. When the columns have no playable cards,\ncards from the Stock can be drawn, with only one pass\nallowed. The game is won when all column cards are on the\nWaste, irrespective of the Stock's remaining cards.\nIf no moves are possible and the Stock is depleted, the\ngame is lost"<<endl;
        
    }
    if(choice =="3"){
        seeAdjancacy();

    }
    if(choice =="4"){
        cout << "ok, see ya next time!" << endl;
    }
}
/********************************************************
 *createSet() is a very unique function, sometimes the stock
 * is almost depleted and the user is nowhere close to winning
 * so createSet() helps the user two times by randomly allowing
 * the player to either see some of the card values coming up
 * or specifically know when a certain card is coming up since the 
 * stock is upside down the player does not know the next card 
 * they will draw. The breakdown of the process starts with 
 * a queue that hold two values, the values are given at random 
 * with either being 1 or 2. each time the function is called the first
 * value is popped off. 1 or 2 is important since it determines how createSet()
 * will help the player. if the value 1 is selected then it uses unordered sets 
 * and the CardHash struct to tell the user all the values that are left in the 
 * stock, however they values are not repeated and displayed in random order.
 * enough help to not be overpowered. if the value 2 is selected the user
 * can ask to see if a specific value if found in the deck and how far into 
 * the stock is it. 
 ********************************************************/
void GameBoard::createSet() {
    std::string user;
    
    if (!ap[7]) {//if the queue is not empty continue
        std::cout << "This is random help, type y if you want random peek into stock else click any key";
        std::cin >> user;
        if (user == "y") {
            if (q.front() == 1) {//if the value in the queue is one
                q.pop();//pops of value
                if (q.empty()) {// if the queue is empty, updates the map to inform it
                    ap[7] = true;
                }
                std::unordered_set<Card, CardHash> myUnorderedSet;//creates sets
                std::list<Card>::iterator pos;//iterator to traverse the stock deck
                std::list<Card>::iterator end;
                pos = stock.begin();
                end = stock.end();
                for (; pos != end; ++pos) {//traverse from begin to end of the stock
                    myUnorderedSet.insert(*pos);//inserts the cards from the dock to the set
                }
                //without duplicates and at no particular order displays the values left in the stock and simplifies the code 
                //through using unordered sets
                std::cout << "values found in stock without duplicates at random order:" << std::endl;
                for (std::unordered_set<Card,CardHash>::const_iterator iter = myUnorderedSet.begin(); iter != myUnorderedSet.end(); ++iter) {
                    std::cout << iter->value << std::endl;
                }
            } else if (q.front() == 2) 
            {//if the value in the queue is two
                q.pop();//pops value
                if (q.empty()) {// if the queue is empty, updates the map to inform it
                    ap[7] = true;
                }
                
                //asks user which card value does it want to check in the remainding stock
                std::string vals;
                std::cout << "which value do you want to find?" << std::endl;
                std::cin >> vals;
                while (!isValid(vals, 1, 13)) {//validates
                    std::cout << "Please only choose one of our options";
                    std::cin >> vals;
                }
                 int val = std::stoi(vals);

    // Use std::find to search for the card with the specified value
     std::list<Card>::iterator it = std::find_if(stock.begin(), stock.end(), CardHasValue(val));

                if (it != stock.end())
                {
                     int index = std::distance(stock.begin(), it);
                     std::cout << "Card with value " << vals << " found and is coming in " << stock.size() - index << " cards from stock." << std::endl;
                } 
                else 
                {
                 std::cout << "Card with that value is not found in stock." << std::endl;
                }
            }
        }
    }
}

void GameBoard::seeAdjancacy(){
    
    
     DeckofCards deck;
     deck.MakeDeck();
    

    // Create a graph based on adjacency of cards with values differing by 1 or 12
    Graph cardGraph;

    for (int i = 0; i < 51; ++i) {
        int j = i + 1;  // Consider only the next card
        int valueDiff = std::abs(deck.deck[i].getIntValue() - deck.deck[j].getIntValue());
        if (valueDiff == 1 || valueDiff == 12) {
            cardGraph.addEdge(deck.deck[i], deck.deck[j]);
        }
    }

    // Print the adjacency list
    cardGraph.printGraph();
    
    
}