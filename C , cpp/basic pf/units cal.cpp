// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

string getComputerChoice() {
    string choices[] = {"rock", "paper", "scissors"};
    int index = rand() % 3;
    return choices[index];
}
string yourchoice()
{
 string chose;
    cout<<"1.rock\n 2.paper\n 3.scissors\n 4.exit\n enter your choice: ";
    cin>>chose;
    while(chose!="rock" && chose!="paper" && chose!="scissors")
    {
        cout<<"invalid choice!. choose again(rock, paper, scissor)";
        cin>>chose;
    }
    return chose;

}
string winner(string userChoice, string computerChoice)
{
   if (userChoice==computerChoice)
   {
       return "it's a draw!" ;
   }
    if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "paper" && computerChoice == "rock") ||
        (userChoice == "scissors" && computerChoice == "paper"))
        return "You win!";
    else
        return "Computer wins!";
}
int main ()
{
    srand(time(0));

    string name;
    cout<<"enter your name:";
    cin>>name;

   string userChoice= yourchoice();
    string computerChoice=getComputerChoice();

    cout<<"name:"<<name<<"\nchose: "<<yourchoice<<endl;
    cout<<"computer chose: "<<computerChoice<<endl;

    cout << winner(userChoice, computerChoice) << endl;

}


