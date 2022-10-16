#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
/***********Functions********/

///Menu Display Function
void menu(){
    cout<<"******************\n*\t\t *\n*"<<setw(20)<<left<<"   Snake Ladder *"
    <<"\n\n******************";
}
///random number generator
void randGenerator(int *num){
    srand(time(0)); *num=rand()%6+1;
}
void snakeLadder(int *pts){
    if(*pts==2)
        *pts+=20;
    else if(*pts==25){
        *pts-=21; cout<<"\nYou Landed On The Snake.\n"; }
    else if(*pts==50){
        *pts+=20; cout<<"\nYou Landed On The Ladder.\n"; }
    else if(*pts==55){
        *pts-=30; cout<<"\nYou Landed On The Snake.\n"; }
    else if(*pts==80){
        *pts+=12; cout<<"\nYou Landed On The Ladder.\n"; }
    else if(*pts==98){
        *pts-=30; cout<<"\nYou Landed On The Snake.\n"; }
}
/*********************/
int main(){
    int Player1pts=0,Player2pts=0,dice;
    menu();
    cout<<endl;
    while(1){
        int counter1=0,counter2=0,temp;
    /*******Player 1 Turn**********/
    cout<<"\nPlayer 1 Turn>>Rolling Dice....\n";
    temp=Player1pts;
    do{
    randGenerator(&dice);
    cout<<"\nDice: "<<dice;
    if(!((Player1pts+dice)>101)){
    Player1pts+=dice;
    snakeLadder(&Player1pts); }
    counter1++;
    if (counter1==3) Player1pts=temp;  ///for 3 consistent 6's ponits will be reset to previous
    cout<<"\nPlayer 1 Points: "<<Player1pts<<endl;
    } while(dice==6 && counter1<3);
    if(Player1pts==101){
        cout<<"Player 1 Wins!"; break; }
    cout<<endl;
    system("pause");
    /***********Player 2 Turn*************/
    cout<<"\nPlayer 2 Turn>>Rolling Dice....\n";
    temp=Player2pts;
    do{
    randGenerator(&dice);
    cout<<"\nDice: "<<dice;
    if(!((Player2pts+dice)>101)){
    Player2pts+=dice;
    snakeLadder(&Player2pts); }
    counter2++;
    if (counter2==3) Player2pts=temp;  ///for 3 consistent 6's ponits will be reset to previous
    cout<<"\nPlayer 2 Points: "<<Player2pts<<endl;
     } while(dice==6 && counter2<3);
    ///do while ends...
    if(Player2pts==101){
        cout<<"Player 2 Wins!"; break; }
    cout<<endl;
    system("pause"); }
return 0;}
