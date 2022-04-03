#include <iostream>
using namespace std;

void Pickup(int amount, int& stack)
{
    stack = stack - amount;
}

void PlayerTurn(int& pickUpNum, int& stack)
{
    
    cout << "How many you would like to pick up?" << endl;
    cin >> pickUpNum;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Need to choose at between 1-4 bottle(s)" << endl;
        cin >> pickUpNum;
    }
    while (pickUpNum > stack || (pickUpNum < 1 || pickUpNum > 4))
    {
        cin.clear();
        cin.ignore(256,'\n');
        if(pickUpNum < 1 || pickUpNum > 4)
        {
            cout << "Need to choose at between 1-4 bottle(s)" << endl;
            cout << "The bottles remaining are: " << stack << endl;
        }
        else
        {
            cout << "Not enough bottles left!" << endl;
            cout << "Please, choose " << stack << " or less " << endl;
        }
        cin >> pickUpNum;
    }
    

    Pickup(pickUpNum, stack);
}

void ComputerTurn(int& pickUpNum, int& stack)
{
    int num;
    if(stack == 1)
        num = 1;
    else if(stack < 6)
        num = stack-1;
    else
        num = 5 - pickUpNum;

    Pickup(num, stack);
    cout << "Computer has picked " << num << endl;
}

void Turn(int& pickUpNum, bool isPlayer, int& stack)
{
    if(isPlayer)
        PlayerTurn(pickUpNum, stack);
    else
        ComputerTurn(pickUpNum, stack);

    cout << "The bottles remaining are: " << stack << endl;

}

int main()
{
    char first;
    
    int bottleCount = 21;
    int pickUpNum;

    cout << "There are 21 beer bottles..." << endl;
    cout << "There are 2 players - Computer and you." << endl;
    cout << "At a time, each one can pick up any no. of bottles" << endl;
    cout << "between 1 and 4 (inclusive)" << endl;
    cout << "Will you like to play first?" << endl;

    cin >> first;
    bool isPlayer;

    while(tolower(first) != 'y' && tolower(first) != 'n')
    {
        cout << "Please, Enter Y (Yes) or N (No)!"<< endl;
        cin >> first;
    }
    if(tolower(first) == 'y')
        isPlayer = true;
    else if(tolower(first) == 'n')
    {
        isPlayer = false;
        pickUpNum = 3;
    }
   
    while (bottleCount > 1)
    {
        Turn(pickUpNum, isPlayer, bottleCount);
        isPlayer = !isPlayer;
    }
    
    if(isPlayer == true)
        cout << "You will have to pick up the last... you are the loser" << endl;
    else
        cout << "The Computer will have to pick up the last... you are the winner" << endl;
    
    return 0;
}