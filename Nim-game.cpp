#include <bits/stdc++.h>
using namespace std;
#define NO_GOOD_MOVE 0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0
#define fR_c 3
#define sR_c 4
#define thR_c 5
#define P1 1
void start_v1();
int choose_v1();
void play_variant_1(int choice);
void start_v2();
vector<int> choose_v2(vector<int>&s);
void play_variant_2(vector<int>choice);
int findGoodMove(int nCoins);
bool isBadPosition(int nCoins);


int main()
{
    vector<int>rows;

    //start_v1();
    //play_variant_1(choose_v1());
    start_v2();
    play_variant_2(choose_v2(rows));

}

void start_v1()
{
  system("cls");
    cout<<"Welcome to Nim Game."<<endl;
    cout<<"We start with "<<N_COINS<<" coins"<<endl;
    cout<<"Each player can pick from 1 to "<<MAX_MOVE<<" coins"<<endl;

}

int choose_v1()
{
    int choice;
    cout<<"Do you want Player(1) or computer(2) to start game? ";
    cin>>choice;
    while (!(choice==1 || choice==2))
    {
    cout<<"WRONG choice!!..please choose correct choice: ";
    cin>>choice;
    }
  return choice;
}

void play_variant_1(int choice)
{
    int computer_picked;
    int computer_piles=0;
    int player_picked;
    int player_piles=0;
    int num_of_coins=N_COINS;
    if(choice==1)
    {
      system("cls");
      cout<<"OK..Player starts"<<endl;
      while (num_of_coins>=1)
      {
        cout<<"Please pick from 1 to 3 coins and <= remaining coins:"; 
        cin>>player_picked;
        while (!(player_picked==1&& player_picked<=num_of_coins || player_picked==2 && player_picked<=num_of_coins || player_picked==3 && player_picked<=num_of_coins))
        {
          cout<<"WRONG choice!!..please choose correct choice form 1 to 3 and <= remaining coins : ";
        cin>>player_picked;
        }
        num_of_coins-=player_picked;
        player_piles+=player_picked;
        cout<<"player takes : "<<player_picked<<" coins"<<endl;
        cout<<"num of coins after player choice become : "<<num_of_coins<<endl;
        cout<<"player pile contains : "<<player_piles<<endl;
      if(num_of_coins!=0)
      {
        computer_picked=findGoodMove(num_of_coins);
        if (!computer_picked)
        {
          computer_picked = 1;
        }
        num_of_coins-=computer_picked;
        computer_piles+=computer_picked;
        cout << "\nComputer takes : " << computer_picked << " coins " <<endl;
        cout<<"num of coins after computer choice become : "<<num_of_coins<<endl;
        cout<<"computer pile contains : "<<computer_piles<<endl;
      }
      else
      {
        if(player_piles%2==0 && computer_piles%2!=0)
        {
          cout<<"\nThe Winner is player "<<endl;
        }
        else if(player_piles%2!=0 && computer_piles%2==0)
        {
          cout<<"\nThe Winner is Computer "<<endl;
        }
        else
        {
          cout<<"\nGame Over!! "<<endl;
        }
      }
    }
  }
  else if(choice==2)
  {
      system("cls");
      cout<<"OK..Computer starts"<<endl;
      while (num_of_coins>=1)
      {
        computer_picked=findGoodMove(num_of_coins);
        if (!computer_picked)
        {
          computer_picked = 1;
        }
        num_of_coins-=computer_picked;
        computer_piles+=computer_picked;
        cout << "\nComputer takes : " << computer_picked << " coins " <<endl;
        cout<<"num of coins after computer choice become : "<<num_of_coins<<endl;
        cout<<"computer pile contains : "<<computer_piles<<endl;
        cout<<"Please pick from 1 to 3 coins and <= remaining coins:"; 
        cin>>player_picked;
        while (!(player_picked==1&& player_picked<=num_of_coins || player_picked==2 && player_picked<=num_of_coins || player_picked==3 && player_picked<=num_of_coins))
        {
          cout<<"WRONG choice!!..please choose correct choice form 1 to 3 and <= remaining coins : ";
          cin>>player_picked;
        }
        num_of_coins-=player_picked;
        player_piles+=player_picked;
        cout<<"player takes : "<<player_picked<<" coins"<<endl;
        cout<<"num of coins after player choice become : "<<num_of_coins<<endl;
        cout<<"player pile contains : "<<player_piles<<endl;
      }
      if(player_piles%2==0 && computer_piles%2!=0)
      {
        cout<<"\nThe Winner is player "<<endl;
      }
      else if(player_piles%2!=0 && computer_piles%2==0)
      {
        cout<<"\nThe Winner is Computer "<<endl;
      }
      else
      {
        cout<<"\nGame Over!! "<<endl;
      }
  }
}
void start_v2()
{
    system("cls");
    cout<<"Welcome to Nim Game Variant 2."<<endl;
    cout<<"We start with 3 boxes with (3,4,5) coins "<<endl;
    cout<<"Each player can pick from 1 to "<<MAX_MOVE<<" coins from his box "<<endl;
}
vector<int> choose_v2(vector<int>&s)
{
    int player1_box;
    int player2_box;
    cout<<"player 1 enter the num of box you want to pick from 1 to 3 : ";
    cin>>player1_box;
    while ((player1_box>3 || player1_box<=0))
    {
      cout<<"WRONG!!.. player1 must choose box from 1 to 3 "<<endl;
      cout<<"player 1 enter the num of different box you want to pick : ";
      cin>>player1_box;
    }
    cout<<"player 2 enter the num of box you want to pick and different from player1("<<player1_box<<") : ";
    cin>>player2_box;
    while ((player1_box==player2_box || player2_box>3 || player2_box<=0 ))
    {
      cout<<"WRONG!!.. player2 must choose different box and from 1 to 3 "<<endl;
      cout<<"player 2 enter the num of different box you want to pick from 1 to 3 : ";
      cin>>player2_box;
    }
    s.push_back(player1_box);
    s.push_back(player2_box);
    system("cls");
    return s;
}

void play_variant_2(vector<int>choice)
{
    int current_player=P1;
    int num_of_coins_p1;
    int num_of_coins_p2;
    int player1_picked;
    int player2_picked;
    int player1_choice;
    int player2_choice;
    player1_choice=choice[0];
    player2_choice=choice[1];
    if(player1_choice==1)
    {
        num_of_coins_p1= fR_c;

    }
    else if(player1_choice==2)
    {
        num_of_coins_p1=sR_c;

    }
    else
    {
        num_of_coins_p1=thR_c;

    }

    if(player2_choice==1)
    {
        num_of_coins_p2=fR_c;

    }
    else if(player2_choice==2)
    {
        num_of_coins_p2=sR_c;

    }
    else
    {
        num_of_coins_p2=thR_c;

    }
    int tmep1=num_of_coins_p1;
    int temp2= num_of_coins_p2;

    while (num_of_coins_p1>=1 && num_of_coins_p2>=1)
    {
        cout<<"player 1 pick from 1 to 3 coins and <= remaining coins in your box("<<tmep1<<") : "; 
        cin>>player1_picked;
        while (!(player1_picked==1&& player1_picked<=num_of_coins_p1|| player1_picked==2 && player1_picked<=num_of_coins_p1 || player1_picked==3 && player1_picked<=num_of_coins_p1))
        {
          cout<<"WRONG choice!!..please choose correct choice form 1 to 3 and <= remaining coins in your box : ";
          cin>>player1_picked;
        }
        num_of_coins_p1-=player1_picked;
        cout<<"player 1 takes : "<<player1_picked<<" coins"<<endl;
        cout<<"num of coins after player 1 choice become : "<<num_of_coins_p1<<endl;
        if(num_of_coins_p1==0)
        {
          break;
        }
        else
        {
          cout<<"player 2 pick from 1 to 3 coins and <= remaining coins in your box("<<temp2<<") : "; 
          cin>>player2_picked;
          while (!(player2_picked==1&& player2_picked<=num_of_coins_p2|| player2_picked==2 && player2_picked<=num_of_coins_p2 || player2_picked==3 && player2_picked<=num_of_coins_p2))
          {
          cout<<"WRONG choice!!..please choose correct choice form 1 to 3 and <= remaining coins in your box : ";
          cin>>player2_picked;
          }
          num_of_coins_p2-=player2_picked;
          cout<<"player 2 takes : "<<player2_picked<<" coins"<<endl;
          cout<<"num of coins after player 2 choice become : "<<num_of_coins_p2<<endl;
        }
    }
    if(num_of_coins_p1>num_of_coins_p2)
    {
      cout<<"\nThe Winner is Player 2 "<<endl;
    }
    else if(num_of_coins_p1<num_of_coins_p2)
    {
      cout<<"\nThe Winner is Player 1 "<<endl;
    }
    else
    {
      cout<<"GAME OVER"<<endl;
    }
    

}

int findGoodMove(int nCoins)
{
	for (int n = 1; n <= MAX_MOVE; n++)
    {
        if (isBadPosition(nCoins - n))
        {
            return n;
        }
    }	
	return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins) 
{
    if (nCoins == 1)
    {
        return true;
    }
    return findGoodMove(nCoins) == NO_GOOD_MOVE;
}