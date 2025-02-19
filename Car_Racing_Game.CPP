
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>

//*******************************GLOBAL AREA************************************
struct dosdate_t d;
struct dostime_t t;
int a4=1,X6=80,X7=280,twink=0,r1,r2=0,score=0,a1, x,y,A,a,i,l,m=0,h=0,o,p,f=1,v=1,l1=1,life=3,u1=0;
float n=-1000,b=0,j=0,z,e,s=0;
int display_score(int ,int ,int );
char ch;

//*******************************DASH FUNCTION***********************************
void dash(int l)
{for(l=n;l<600;)
 {line(x-180,l,x-180,(l+18));
  line(x-179,l,x-179,(l+18));
  line(x-60,l,x-60,(l+18));
  line(x-59,l,x-59,(l+18));
  line(x+60,l,x+60,(l+18));
  line(x+61,l,x+61,(l+18));
  l=l+36;
 }
}

//*************************************ROAD FUNCTION*****************************
void road()
{int w=getmaxy();

 int poly[]={x-240,0,x-240,w,x+120,w,x+120,0,x-240,0};
 setfillstyle(SOLID_FILL,8);
 fillpoly(5,poly);
 line(x,0,x,y);//centre right line
 line(x+3,0,x+3,y);//centre right line
 line(x+120,0,x+120,y);//right line
 line(x+123,0,x+123,y);//right line
 line(x-120,0,x-120,y);//central left line
 line(x-117,0,x-117,y);//central left line
 line(x-240,0,x-240,y);//left line
 line(x-237,0,x-237,y);//left line
}

//***********************************MYCAR FUNCTION***********************************
void  mycar(int &h,int &s)
{
 int ar1[]={x-210+h,y-75-s,x-150+h,y-75-s,x-150+h,y-25-s,x-210+h,y-25-s,x-210+h,y-75-s};
 int ar2[]={x-205+h,y-105-s,x-155+h,y-105-s,x-155+h,y-90-s,x-205+h,y-90-s,x-205+h,y-105-s};
 int ar3[]={x-208+h,y-15-s,x-152+h,y-15-s,x-152+h,y-10-s,x-208+h,y-10-s,x-208+h,y-15-s};
 setfillstyle(SOLID_FILL,YELLOW);
 fillpoly(5,ar1);
 setfillstyle(SOLID_FILL,GREEN);
 fillpoly(5,ar2);
 setfillstyle(SOLID_FILL,GREEN);
 fillpoly(5,ar3);

 rectangle(x-210+h,y-75-s,x-150+h,y-25-s);//roof
 rectangle(x-205+h,y-105-s,x-155+h,y-90-s);//bonate
 line(x-210+h,y-75-s,x-205+h,y-90-s);//leftline connector upper
 line(x-150+h,y-75-s,x-155+h,y-90-s);//rightline connector upper
 rectangle(x-208+h,y-15-s,x-152+h,y-10-s);//dikky
 line(x-210+h,y-25-s,x-208+h,y-15-s);//leftline connector lower
 line(x-150+h,y-25-s,x-152+h,y-15-s);//rightline connector lower
 for(int k=10;k<60;)
 {setcolor(BLACK);
  line((x-210+h)+k,y-75-s,(x-210+h)+k,y-25-s);
  k=k+10;setcolor(WHITE);
 }
}

//************************************ENEMYCAR FUNCTION***************************************************
int enemycar(int A,int j,int r1)
{int ar1[]={x-210+A,y-425+j,x-150+A,y-425+j,x-150+A,y-475+j,x-210+A,y-475+j,x-210+A,y-425+j};
 int ar2[]={x-205+A,y-395+j,x-155+A,y-395+j,x-155+A,y-410+j,x-205+A,y-410+j,x-205+A,y-395+j};
 int ar3[]={x-208+A,y-485+j,x-152+A,y-485+j,x-152+A,y-490+j,x-208+A,y-490+j,x-208+A,y-485+j};

 setfillstyle(SOLID_FILL,r1);
 fillpoly(5,ar1);
 setfillstyle(SOLID_FILL,r1+2);
 fillpoly(5,ar2);
 setfillstyle(SOLID_FILL,r1+3);
 fillpoly(5,ar3);

 rectangle((x-210)+A,y-425+j,(x-150)+A,y-475+j);//roof
 rectangle(x-205+A,y-395+j,x-155+A,y-410+j);//bonate
 line(x-210+A,y-425+j,x-205+A,y-410+j);//leftline connector upper
 line(x-150+A,y-425+j,x-155+A,y-410+j);//rightline connector upper
 rectangle(x-208+A,y-485+j,x-152+A,y-490+j);//dikky
 line(x-210+A,y-475+j,x-208+A,y-485+j);//leftline connector lower
 line(x-150+A,y-475+j,x-152+A,y-485+j);//rightline connector lower
 line(x-210+A,y-425+j,x-150+A,y-475+j);
 line(x-210+A,y-475+j,x-150+A,y-425+j);
 line(x-180+A,y-475+j,x-180+A,y-425+j);
 return 1;
}

//************************************ACCIDENT FUNCTION*******************************************
int accident(int h,int A,int s,int j)
{ if((y-395+j)==(y-105-s))
  { int w=x-205+h;
   if(((w)==(x-205+A))||((w)==(x-175+A))||((x-155+h)==(x-185+A)))
    { score-=10;
    if(score<=0)
      score=0;
     settextstyle(1,0,4);
     if(life==1)
     { setgraphmode(2);
       for(int t1=0;t1<120;t1++)
       { setcolor(t1/10);
	 road();
	 dash(n);
	 circle(180,180,10+t1);
	 circle(230,230,10+t1);
	 circle(450,450,10+t1);
	 circle(430,430,10+t1);
	 circle(236,236,10+t1);
	 circle(312,312,10+t1);
	 circle(320,180,10+t1);
	 circle(330,30,10+t1);
	 circle(450,110,10+t1);
	 circle(250,250,10+t1);
	 circle(100,40,10+t1);
	 circle(150,60,10+t1);
	  delay(0);


	 cleardevice();
       }
       setcolor(YELLOW);
       line(185,206,445,206);
       line(185,235,445,235);
       outtextxy(180,200,"*--GAMEOVER--*");
       setcolor(WHITE);
       sleep(1);
     }life--;return -1;
    }
  }
  if(((x-210+h)==(x-180+A))||((x-150+h)==(x-180+A)))
   { if((y-105-s)==(y-490+j))
    { score-=10;
      if(score<=0)
      score=0;
     if(life==1)
     { setgraphmode(2);
       for(int t1=0;t1<120;t1++)
       { setcolor(t1/10);
	 road();
	 dash(n);
	 circle(180,180,10+t1);
	 circle(230,230,10+t1);
	 circle(450,450,10+t1);
	 circle(430,430,10+t1);
	 circle(236,236,10+t1);
	 circle(312,312,10+t1);
	 circle(320,180,10+t1);
	 circle(330,30,10+t1);
	 circle(450,110,10+t1);
	 circle(250,250,10+t1);
	 circle(100,40,10+t1);
	 circle(150,60,10+t1);

	 delay(0);
	 cleardevice();
       }
       setcolor(YELLOW);
       line(185,206,445,206);
       line(185,235,445,235);
       outtextxy(180,200,"*--GAMEOVER--*");
       setcolor(WHITE);
       sleep(1);
     }
     life--;return -1;
    }
   }

 rectangle(10,140,130,160);
 gotoxy(2,10);
 cout<<" LIFE REMAINS:"<<life;
}

//****************************************DISPLAY_SCORE FUNCTION*****************************************
int display_score(int s,int j,int m)
{
 if(((y-10-s)==(y-490+j))||((y-10-s)==(y-490+m)))
   { if((score==0)&&(score<=50))
    { score+=10;l1=1;}
    else if(score<=125)
    { score+=15;l1=2;}
    else
    { score+=20;l1=3;} }
    rectangle(10,55,90,80);
    gotoxy(1,5);
    cout<<"   SCORE:"<<score;
    rectangle(10,88,90,113);
    cout<<"\n\n   LEVEL:"<<l1;

    return l1;

}

//***********************************SHOWND FUNCTION*************************************
void showtnd()
{
 rectangle(2,10,130,50);
 gotoxy(2,2);
 _dos_getdate(&d);
 printf("DATE:%d-",d.day);
 printf("%d-",d.month);
 printf("%d\n",d.year);
 _dos_gettime(&t);
 printf(" TIME:%2d:%02d:%02d\n", t.hour, t.minute,t.second);
}



//****************************************MAIN FUNCTION**************************************
//*******************************************************************************************
void main()
{char ch3;
int y1=210,y2=240;
int gdriver=VGA,gmode=VGAHI;
 initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
 x=(getmaxx()/2)+60;
  y=getmaxy();
  setcolor(13);
 settextstyle(4,0,6);
 line(50,200,615,200);
 line(50,250,615,250);
 outtextxy(50,190,"*-F1 CAR RACING-*");
 sleep(1);
 settextstyle(2,0,6);
 setcolor(YELLOW);
 outtextxy(280,300,"LOADING...");
 outtextxy(212,345,"WAIT FOR FEW SECOND.....");
 rectangle(100,400,530,420);
 for(int y5=0;y5<430;y5++)
 {rectangle(100,400,100+y5,420);
  if(y5==215)
   sleep(1);
  delay(10);
 }

 cleardevice();

 menu:
 for(int l5=0;l5<40;l5++)
 {
  settextstyle(1,0,5);
  setcolor(11);
  line(135,90,462,90);
  line(135,125,462,125);
  outtextxy(135,80,"*-MAIN-MENU-*");
  settextstyle(1,0,3);
  outtextxy(230,210,"START GAME");
  outtextxy(270,260,"HELP");
  outtextxy(265,310,"ABOUT");
  outtextxy(265,360,"SCORE");
  outtextxy(238,410,"EXIT GAME");
  rectangle(220,y1,380,y2);//startgame;
  getch();
  if(kbhit())
   {ch3=getch();
    if(ch3==1)
    { y1=40;y2=80;}
    if(ch3==80)
    { if(y1<410)
    { y1+=50;y2+=50; }
      else
     { y1=210;y2=240;}
    }
    if(ch3==72)
    { if(y1>210)
    { y1-=50;y2-=50;}
    else
    {y1=410;y2=440;}
    }




     if(ch3==77)
   {if(y1==210)
    {cleardevice();
     settextstyle(2,0,6);
     setcolor(YELLOW);
     outtextxy(280,210,"LOADING...");
     setcolor(11);
     rectangle(100,235,530,255);
     for(int y5=0;y5<430;y5++)
     {rectangle(100,235,100+y5,255);
      if(y5==215)
      sleep(1);
      delay(10);
     }
    settextstyle(2,0,8);
    setcolor(10);
    outtextxy(185,330,"LETS ENJOY THE GAME!!!");
    setcolor(15);
    sleep(2);
    cleardevice();
    goto game;
    }
    if(y1==260)
    goto help;
    if(y1==310)
    goto about;
    if(y1==360)
    goto score;
    if(y1==410)
    exit(0);
   }
   }



  delay(20);
  cleardevice();
 }



 game:

 randomize();
 for(i=0;;i++)
 {r1=random(12);
  int c=(random(16)*20)+90;
  a=random(3);
  b=random(3);
  if(a==0||b==0)
  {a=0;
   b=random(3)*120;
  }
  else if(a==1||b==1)
  {a=120;
   b=random(3)*120;
  }
  else
  {a=240;
   b=random(3)*120;
  }
  n=-2000;
  if(i==0)
  j=0;else j=1;

 for(j;j<500+c;j++)
  {
   if(a4==1)
 {  z=x-210+h;
   e=x-150+h;
   o=y-90-s;
   p=y-15-s;
   if( kbhit())
   {ch=getch();
    if(ch==72)
    {if(o<=70);
      else
      s+=0.9;
    }
    if(ch==80)
    {if(p>=(getmaxy()-20));
     else
      s-=0.9;
    }
    if(ch==75)
    {
     if(z<=150);
     else
      h-=30;
    }
    if(ch==77)
    {
     if(e>=470);
     else
      h+=30;
    }
    if(ch==27)
    {cleardevice();
     goto menu;
    }
    if(ch==13)
    {gotoxy(35,12);
     system("pause");
    }
   }

   showtnd();
   n+=0.7;
   road();


   dash(n);

   mycar(h,s);

   if(f==enemycar(a,j,r1))
    u1=accident(h,a,s,j);
   if(u1==-1&&life>=1)
   {for(int p2=0;p2<40;p2++)
    {  mycar(h,s);
       road();
       dash(n);
       delay(10);

    }
   }
   m=j-c;
   if(v==enemycar(b,m,r2=r1+1))
    u1=accident(h,b,s,m);
   if(u1==-1&&life>=1)
   {for(int p2=0;p2<40;p2++)
    { mycar(h,s);
      road();
      dash(n);
      delay(10);
    }
   }
   a1=display_score(s,j,m);
   if(j==0)
   sleep(1);
   if(a1==1)
    delay(10);
   else if(a1==2)
    delay(5);
   else
    delay(3);
  }
  if(life==0)
    { a4=0;
      cleardevice();
      settextstyle(3,0,5);
      setcolor(11);
      outtextxy(200,60,"*-RESULT-*");
      settextstyle(1,0,2);
      setcolor(15);
      outtextxy(180,130,"YOUR SCORE IS");
      outtextxy(180,170,"LEVEL ACHIEVED:");
      setcolor(5);
      outtextxy(150,260,"THANKS FOR PLAYING GAME!!!");
      gotoxy(45,10);
      cout<<score;
      gotoxy(45,12);
      cout<<l1;
      setcolor(11);
      settextstyle(1,0,1);
      outtextxy(83,300,"RESTART THE GAME");
      outtextxy(353,300,"GO TO MAIN-MENU");
      rectangle(X6,300,X7,330);
      getch();
      if(kbhit())
      {char ch5=getch();
       if(ch5==75)
       {X6=80;X7=280;
       }
       if(ch5==77)
       {X6=350;X7=550;
       }
       if(ch5==72)
       {if(X6==80)
	{ score=0;
	  l1=0;
	  a4=1;
	  life=3;
	  cleardevice();
	  h=0;s=0;
	  goto game;}
	if(X6==350)
	{cleardevice();
	 goto menu;    }
       }
       else
       continue;
      }
    }

  }

 }
//**************************************HELP*******************************************
help:
 cleardevice();
 settextstyle(3,0,5);
  setcolor(11);
  outtextxy(230,50,"*-HELP-*");
  settextstyle(3,0,2);
  setcolor(12);
  outtextxy(130,130,"PRESS UPPER ARROW TO MOVE CAR FORWARD");
  outtextxy(130,165,"PRESS LOWER ARROW TO MOVE CAR BACKWARD");
  outtextxy(130,200,"PRESS <- TO MOVE CAR LEFT SIDE");
  outtextxy(130,235,"PRESS -> TO MOVE CAR RIGHT SIDE");
  outtextxy(130,270,"PRESS ENTER TO PAUSE THE GAME");
  outtextxy(130,305,"PRESS ESCAPE TO GO TO MENU");
  setcolor(5);
  outtextxy(130,340,"PRESS HOME TO GO IN MAIN-MENU");
  getch();
  if(kbhit())
  {char ch5=getch();
   if(ch5==77)
   { cleardevice();
   goto menu;
   }
   else
   goto help;
  }  getch();
//***************************************ABOUT**********************************************
  about:
    cleardevice();
    settextstyle(3,0,5);
    setcolor(11);
    outtextxy(220,50,"*-ABOUT-*");
    settextstyle(3,0,1);
    setcolor(12);
    outtextxy(130,130,"IT IS A  FASCINATING CAR RACING GAME.");
    outtextxy(130,165,"WHICH IS PREPARED BY IN THE GUIDENCE:");
    outtextxy(130,200,"MR.RAMAVTAR SIR (PGT COMPUTER SCIENCE)");
    outtextxy(130,235,"MADE BY:");
    outtextxy(230,270,"1.MA.BHAVESH PATIDAR");
    outtextxy(230,305,"2.MA.ABHISHEK PATIDAR");
    outtextxy(230,340,"3.MA.JATIN CARPENTER");
    settextstyle(3,0,2);
    setcolor(5);
    outtextxy(140,375,"PRESS HOME TO GO IN MAIN-MENU");
    getch();
    if(kbhit())
     { char ch5=getch();
     if(ch5==77)
     { cleardevice();
     goto menu;
     }
     else
     goto about;

    }
  score:
      cleardevice();
      settextstyle(3,0,5);
      setcolor(11);
      outtextxy(180,50,"*-SCORE-*");
      settextstyle(3,0,1);
      setcolor(12);
      outtextxy(200,180,"HIGHEST SCORE:1800");
      outtextxy(200,210,"LOWEST SCORE:20");
      settextstyle(3,0,2);
      setcolor(5);
      outtextxy(140,375,"PRESS HOME TO GO IN MAIN-MENU");

     getch();
     if(kbhit())
     {char ch6=getch();
     if(ch6==77)
     { cleardevice();
      goto menu;     }
      else
      goto score;	   }


}

//***********************************************************************************************
//***************************************END OF PROGRAM******************************************
//***********************************************************************************************