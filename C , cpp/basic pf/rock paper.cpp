#include <iostream>
#include <ctime>
#include<cstdlib>
#include<string>

using namespace std;

string UserInput()
{
 string choice;
  cout<<"enter your choice=";
  cin>>choice;

  for (char &c: choice)c=tolower(c);
  if(choice=="rock" || choice=="paper" || choice=="scissors" )
  {
    return choice;
  }   
  else {
    cout<<"invalid choice. try again\n";
    return UserInput();
  }
}
string computerChoice()
{
string choices[]={"rock","paper","scissors"};
return choices[rand()%3];
}

void chooseWinner(string user, string computer)
{
    cout<<"you chose:"<<user<<"\n";
    cout<<"computer chose:"<<computer<<"\n";

    if(user==computer)
    {
        cout<<"its a draw!\n";
    }
    else if (
        (user == "rock" && computer == "scissors") ||
        (user == "paper" && computer == "rock") ||
        (user == "scissors" && computer == "paper") 
    )
    {
        cout<<"you win!\n";
    }
    else{
        cout<<"you lose!\n";
    }
}
int main()
{
  cout<<"lets play rock,paper,scissor"<<endl;
  srand(time(0));
  string user=UserInput();
  string computer=computerChoice();
  chooseWinner(user,computer);  
  }