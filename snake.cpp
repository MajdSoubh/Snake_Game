#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctime>

using namespace std;
static int y=0;
class snake
{
private:
    struct tail
    {
        char *point;
        tail *next;
    };
    char board[30][40];
    char key='w';
    char prevkey='w';
    tail *first;
    tail *last;
    int sc;
public:
    snake();
    char keyboard();
    void apple();
    bool game();
    void graphic();
    bool move(short);
    tail* reverse(tail *p);

};



snake::tail * snake::reverse(tail * p)
{

static int  count=0;
    if(!p)
return 0;
tail *q=p;
   count++;
   tail* n=reverse(p->next);
   if(n==0){
        count--;
    last=p;}
    else{
        count--;
            n->next=p;
    if(count==0){
    p->next=0;
   first=p;
    }
    }


    return p;
}
bool snake::move(short size)
{



    tail *newtail=new tail;
    newtail->point=(first->point)+size;
    if(*(newtail->point)=='#'||*(newtail->point)=='O')
        return false;


first->next=newtail;
if(*(newtail->point)==' '){

        *(last->point)=' ';
last=last->next;

}
else if(*(newtail->point)=='M'){
   sc++;
    apple();
    }
    newtail->next=0;

    first=newtail;


*(newtail->point)='O';




return true;



}
void snake::apple()
{
    int x=0,y=0;
    while(board[x][y]=='#'||board[x][y]=='O')
    {
        x=rand()%29+1;
        y=rand()%38+1;
    }
    board[x][y]='M';

}

bool snake::game()
{


    if(key=='w'&&prevkey=='s')
    {
        reverse(last);

       if (!move(-40))
 return 0;
         prevkey='w';
    }
    else if(key=='s'&&prevkey=='w')
    {
reverse(last);
       if(!move(40))
         return 0;
         prevkey='s';
    }
    else if(key=='d'&&prevkey=='a')
    {
reverse(last);
        if(!move(1))
             return 0;;
         prevkey='d';
    }
    else if(key=='a'&&prevkey=='d')
    {
reverse(last);
        if(!move(-1))
             return 0;;
         prevkey='a';
    }
    else if(key=='a')
    {
        if(!move(-1))
             return 0;;
        prevkey='a';
    }
    else if(key=='w')
    {
        if(!move(-40))
             return 0;;
        prevkey='w';
    }
    else if(key=='s')
    {
        if(!move(40))
             return 0;;
        prevkey='s';
    }
    else if(key=='d')
    {
        if(!move(+1))
             return 0;;
        prevkey='d';
    }

return 1;
}

void snake::graphic()
{
    system("cls");
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<40; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
     cout<<endl<<"\t\tSCORE : "<<sc;
}

snake::snake()
{
    for(int i=0; i<30; i++)
        for(int j=0; j<40; j++)
        {
            if(i==0)
                board[0][j]='#';
            else if(i==29)
                board[29][j]='#';
            else if(j==0)
                board[i][0]='#';
            else if(j==39)
                board[i][39]='#';
            else
                board[i][j]=' ';
        }
    board[25][20]='O';
    first=new tail;

    first->point=&board[25][20];
    first->next=0;

    last=first;
    apple();
    graphic();
    sc=0;
    while (1)
    {

        keyboard();

        if(!game()){
            cout<<"\n\n\t\tGAMEOVER\n\n";
            break;}
        graphic();


    }

}


char snake::keyboard()
{
    if(_kbhit())
    {
        key=_getch();
        return key ;

    }
    return  prevkey;

}






int main()
{
    srand(time(0));

    snake s;


}
