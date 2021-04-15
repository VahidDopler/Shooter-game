#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

class game
{
public:
    void Game();
};

class Char
{
private:
    int health;
    string name;

public:
    Char() { name=""; health=100; }
    void set_data (string input1);
    void Game(Char arr1[] , int size );
    string get_name() { return name;}
    void cost_health() { health=health-20;}
    int get_Health() { return health;}
    bool get_situation(); 
};

bool Char::get_situation()
{
    if (health <= 0 )
        return false;
    else
        return true;
}

void Char :: set_data(string input1 )
{
    name = input1;
}

int make_random(int num=4)
{
    int temp=0;
    srand((unsigned) time(0));
    temp=rand() % num ;
    return temp;
}

void Game (Char arr1[] , int size )
{
    int person1=0 , person2=0 ,  counter=size , number=0 , last=0;
    bool flag=true , flag2=true , player , flag3=true;
    while( flag2 ) 
    {
        while(flag)
        {
            person1=make_random();
            person2=make_random();
            if (( person1 != person2 ) && ( arr1[person1].get_situation() ) && ( arr1[person2].get_situation() ))
            {
            arr1[person2].cost_health();
            cout << endl << "The player " << arr1[person1].get_name() << " Shot the " <<
            arr1[person2].get_name() << ":" << arr1[person2].get_name() << " Health is : " << arr1[person2].get_Health() << endl;
            last=person1;
            if (arr1[person2].get_situation() != true)
                counter--; 
            flag=false;             
            }    
        }
        flag=true;
        if ( counter == 2)
            flag2=false;
    }
    
    while (player)
    {
        if (arr1[number].get_situation())
        {
            cout << endl <<"The player " << arr1[number].get_name() << " won the game !";
            player=false;
        }     
        else 
            number++;
    }
}


int main()
{
    int count=4;
    string input;
    Char arr[count];
    for (int i = 0; i < count; i++)
    {
        cout << endl << "Enter your player name " << endl;
        cin >> input;
        arr[i].set_data(input);
    }
    Game(arr , count);
}