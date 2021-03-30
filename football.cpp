#include <cstdlib>
#include <iostream>
#include <graphics.h>
#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
using namespace std;

int main(int argc, char *argv[])
{
    int i,team1,team2,ball;
    char inp,goal1[1]={'0'},goal2[1]={'0'};
    
    //Defining player details
    struct player{
           int x;
           int y;
           int take;
           }ap[2],bp[2];
    ball=1;
    reset:
    ap[1].x=100;
    ap[2].x=100;
    ap[1].y=200;
    ap[2].y=500;
    bp[1].x=800;
    bp[2].x=800;
    bp[1].y=200;
    bp[2].y=500;
    ap[1].take=1;
    ap[2].take=0;
    bp[1].take=0;
    bp[2].take=0;
    team1=1;
    team2=1;
    //Graphics part begins
    initwindow(1000,700);
    
    for (i=0;i<1000;i++)
    {
        
        if (ap[team1].x==bp[team2].x&&ap[team1].y==bp[team2].y)
        {
                     if (ball==1)
                     ball=2;
                     else
                     ball=1;
                     
                     goto reset;
                     }
        else 
        {}
        
        //Score
        outtextxy(490,10,goal1);
        outtextxy(500,10,goal2);
        //Goals
        rectangle(0,250,20,450);
        rectangle(980,250,1000,450);
        
        //Ball
        if (ball==1)
        {
                    circle(ap[team1].x+75,ap[team1].y+25,10);
                    }
        else
        {
                    circle(bp[team2].x-25,bp[team2].y+25,10);
                    }      
        //Displaying players
        rectangle(ap[1].x,ap[1].y,ap[1].x+50,ap[1].y+50);
        rectangle(ap[2].x,ap[2].y,ap[2].x+50,ap[2].y+50) ;
        rectangle(bp[1].x,bp[1].y,bp[1].x+50,bp[1].y+50) ;
        rectangle(bp[2].x,bp[2].y,bp[2].x+50,bp[2].y+50) ;
        
        inp=getch();
        
        //MOVEMENT
    
        
        //input - w
        if (inp==87||inp==119)
        {
                    ap[team1].y=ap[team1].y-10;
                    
                    cleardevice();
                    
                    }
                    
        //input - a
        else if (inp==65||inp==97)
        {
                    ap[team1].x=ap[team1].x-10;
                    
                    cleardevice();
                    
                    }
        
        //input - d
        else if (inp==68||inp==100)
        {
                    ap[team1].x=ap[team1].x+10;
                    
                    cleardevice();
                    
                    }
                    
        //input - s
        else if (inp==83||inp==115)
        {
                    ap[team1].y=ap[team1].y+10;
                    
                    cleardevice();
                    
                    }
        
        //Team B
        
        //input - UP_ARRROW
        else if (inp==72)
        {
                    bp[team2].y=bp[team2].y-10;
                    
                    cleardevice();
                    
                    }
                    
        //input - DOWN_ARROW
        else if (inp==80)
        {
                    bp[team2].y=bp[team2].y+10;
                    
                    cleardevice();
                    
                    }
        
        //input - LEFT_ARROW
        else if (inp==75)
        {
                    bp[team2].x=bp[team2].x-10;
                    
                    cleardevice();
                    
                    }
        
        //input - RIGHT_ARROW
        else if (inp==77)
        {
                    bp[team2].x=bp[team2].x+10;
                    
                    cleardevice();
                    
                    }
                   
        //MOVEMENT ENDS
        
        //PLAYER CHANGING / PASSING
        
        //input - TAB
        else if (inp==9)
        {
                    if (team1==1)
                    team1=2;
                    else
                    team1=1;
                    
                    }
                    
        //input - ENTER
        else if (inp==13)
        {
                    if (team2==1)
                    team2=2;
                    else
                    team2=1;
                    
                    }
        
        //SHOOTING 
        
        //input - SPACE
        else if (inp==32)
        {
                    if (ap[team1].y==bp[team2].y)
                    {
                    outtextxy(500,350,"S  A  V  E  ! ! !");
                    goto reset; 
                    }
                    else 
                    {
                    outtextxy(500,350,"G  O  A  L  ! ! !");
                    goto reset; 
                    }
                    //goal1++;
                    }
        
        //input - ZERO
        else if (inp==48)
        {
                    if (ap[team1].y==bp[team2].y)
                    {
                    outtextxy(500,350,"S  A  V  E  ! ! !");
                    goto reset; 
                    }
                    else 
                    {
                    outtextxy(500,350,"G  O  A  L  ! ! !");
                    goto reset; 
                    }
                    //goal2++;
                    }
                    
        
                    
        }
}
