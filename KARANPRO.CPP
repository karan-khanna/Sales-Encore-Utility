#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

int i=0;  //this variable controls the maximum number of employees(ADMIN/MONITOR)
int h=-1; //this variable controls the maximum number of prospects
int j=0;  //this variable indicate the current employee who has logined.


//************HOMEPAGE***********
void trans();
void boundary();
void develop();
void home(void);
void login();
void home_opt(int c);
//*******************************


void view_pros();
void pass_change();

//*************** ADMIN AREA
void admin_home();

void new_emp();
void view_emp();
void del_pros();


//******************  MONITOR AREA
void monitor_home();

void new_pros();
void search_pros();
void upd_pros();
//*****************************

void round_opt(int c);



struct employee
{
char name[20];
char role[10];
char pass[5];
char address[50];
char no[15];



}e[50];




struct prospect
{
char name[20];
char address[20];
char no[15];
char status[10];
}p[50];






void main()
{
clrscr();
strcpy(e[0].name,"karan");
strcpy(e[0].role,"admin");
strcpy(e[0].pass,"1234");
strcpy(e[0].address,"Rohini,DELHI");
strcpy(e[0].no,"8750385358");
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");

cleardevice();
home();

closegraph();





}



void home()
{
int c=1;
char ch;
cleardevice();

setfillstyle(1,WHITE);
bar(0,0,getmaxx(),getmaxy());

setfillstyle(1,RED);
bar(10,10,getmaxx()-10,getmaxy()-10);

setfillstyle(1,WHITE);
bar(65,55,575,165);

setfillstyle(1,RED);
bar(80,70,560,150);

setcolor(WHITE);

settextstyle(1,0,5);
outtextxy(87,90,"SALES ENCORE UTILITY");
home_opt(c);
ch=getch();
while(ch!=13)
{
if(ch==80)
c=c==3?1:c+1;
if(ch==72)
c=c==1?3:c-1;
home_opt(c);
ch=getch();
}
switch(c)
{
case 1:login();
	break;

case 2:develop();
	break;

case 3:exit(0);

default:cleardevice();
	outtextxy(100,100,"ERROR!!!");
}

}


void home_opt(int c)
{
int x=0;
setcolor(BLACK);
for(int i=1;i<=3;++i)
{
setfillstyle(1,BLACK);
if(i==c)
setfillstyle(1,CYAN);
fillellipse(240,265+x,10,10);
x=x+40;

}
setcolor(WHITE);
settextstyle(1,0,3);
outtextxy(260,250,"LOGIN");
outtextxy(260,290,"ABOUT");
outtextxy(260,330,"EXIT");

}



void login()
{
trans();
j=0;
char user[20];
char pass[5];
int flag=0;
int k=0;
//cleardevice();
boundary();
setfillstyle(1,RED);
bar(0,50,getmaxx(),110);
setcolor(15);
settextstyle(1,0,4);

outtextxy(240,55,"Login Page");
settextstyle(3,0,3);

outtextxy(200,198,"USERNAME: ");
outtextxy(200,248,"PASSWORD: ");
gotoxy(42,14);
fillellipse(180,220,10,10);
gets(user);
gotoxy(42,17);
for(j=0;j<=i;++j)
{
if(strcmp(e[j].name,user)==0)
{
flag=1;
fillellipse(180,265,10,10);
while(k<=3)
{
pass[k]=getche();
cout<<pass[k];
delay(100);
cout<<'\b';
cout<<"*";
++k;
}
pass[k]='\0';
if(strcmp(e[j].pass,pass)==0)
{
if(strcmp(e[j].role,"admin")==0)
{
outtextxy(250,350,"HELLO ADMIN");
delay(1800);
admin_home();
}
else if(strcmp(e[j].role,"monitor")==0)
{
outtextxy(250,350,"HELLO MONITOR");
delay(1800);
monitor_home();
}
}
else
{
settextstyle(1,0,2);
outtextxy(60,350,"WRONG PASSWORD....press any key to go to HOMEPAGE");

getch();
home();
}

 }
 }
if(flag==0)
{
settextstyle(1,0,1);
outtextxy(30,350,"No Such Username Exist !!...press any key to go to HOMEPAGE");
getch();
home();
}
getch();
}



//**************************** ADMIN AREA **********************


void admin_home()
{
trans();
char ch;
int c=1;
//cleardevice();
boundary();
outtextxy(getmaxx()-250,getmaxy()-30,"WELCOME:");
outtextxy(getmaxx()-125,getmaxy()-30,e[j].name);

setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
setcolor(15);
outtextxy(getmaxx()-250,getmaxy()-30,"WELCOME:");
outtextxy(getmaxx()-125,getmaxy()-30,e[j].name);

settextstyle(1,0,4);
outtextxy(160,60,"ADMINISTRATOR HOME");
settextstyle(3,0,3);
outtextxy(170,160,"1.Add new MONITOR/ADMINISTRATOR");
outtextxy(170,200,"2.View all EMPLOYEES");
outtextxy(170,240,"3.View all PROSPECTUS");
outtextxy(170,280,"4.Change Password");
outtextxy(170,320,"5.Delete Prospectus");
outtextxy(170,360,"6.SIGN OUT");


round_opt(c);

ch=getch();
while(ch!=13)
{
if(ch==80)
c=c==6?1:c+1;
if(ch==72)
c=c==1?6:c-1;
round_opt(c);
ch=getch();
}
switch(c)
{
case 1:new_emp();
	break;

case 2:view_emp();
	break;

case 3:view_pros();
	break;

case 4:pass_change();
	break;

case 5:del_pros();
	break;
case 6:home();
	break;

default:cleardevice();
	outtextxy(100,100,"ERROR!!!");
}

getch();
}

void round_opt(int c)
{
int x=0;
setcolor(BLACK);
for(int i=1;i<=6;++i)
{
setfillstyle(1,BLACK);
if(i==c)
setfillstyle(1,CYAN);
fillellipse(150,175+x,10,10);
x=x+40;

}

}


void new_emp()
{

++i;
trans();
b:
randomize();
cleardevice();
boundary();
setfillstyle(1,RED);
bar(0,50,getmaxx(),90);

setcolor(15);
settextstyle(1,0,3);
outtextxy(130,60,"ADD NEW MONITOR/ADMINISTRATOR");
settextstyle(3,0,3);
outtextxy(30,150,"USERNAME:");
outtextxy(30,185,"ROLE(monitor/admin):");
outtextxy(30,230,"ADDRESS:");
outtextxy(30,262,"Contact No:");

fillellipse(15,168,10,10);
gotoxy(20,11);
gets(e[i].name);
//FOR SAME USERNAME
for(int y=0;y<i;++y)
{
if(strcmp(e[y].name,e[i].name)==0)
{
outtextxy(120,100,"USERNAME ALREADY EXIST!!  ..TRY AGAIN ");
delay(1000);
goto b;
}
}
c:

setfillstyle(1,BLACK);
bar(275,180,600,300);

setfillstyle(1,RED);
fillellipse(15,200,10,10);

gotoxy(36,13);
gets(e[i].role);
if(strcmp(e[i].role,"monitor")!=0 && strcmp(e[i].role,"admin")!=0 )
goto c;


fillellipse(15,245,10,10);
gotoxy(18,16);
gets(e[i].address);

fillellipse(16,280,10,10);
gotoxy(21,18);
gets(e[i].no);

outtextxy(150,310,"ACCOUNT SUCCESFULLY CREATED!!");
outtextxy(150,350,"YOUR USERNAME IS>");
outtextxy(150,400,"YOUR PASSWORD IS>");
long int rno;
char r[5];
a:
rno=rand()%10000;

      if(rno<=1000 || rno>=9999 )
      {
      goto a;
      }
      else
      {
      sprintf(r,"%ld",rno);
      strcpy(e[i].pass,r);
      outtextxy(400,350,e[i].name);
      outtextxy(400,400,e[i].pass);



      }

getch();
admin_home();
}

void view_emp()
{
//cleardevice();
trans();
boundary();
char temp[20];
int f=0;
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
setcolor(15);
settextstyle(1,0,4);
outtextxy(140,60,"LIST OF ALL EMPLOYEES");
settextstyle(3,0,2);
setcolor(WHITE);
setfillstyle(1,CYAN);
bar(20,120,getmaxx()-20,getmaxy()-30);
line(20,120,getmaxx()-20,120);
line(20,120,20,getmaxy()-30);
line(20,getmaxy()-30,getmaxx()-20,getmaxy()-30);
line(getmaxx()-20,120,getmaxx()-20,getmaxy()-30);
setcolor(BLACK);
line(20,150,getmaxx()-20,150);
line(180,120,180,getmaxy()-30);
line(340,120,340,getmaxy()-30);
line(520,120,520,getmaxy()-30);

outtextxy(60,120,"USERNAME");
outtextxy(230,120,"ADDRESS");
outtextxy(380,120,"PHONE");
outtextxy(535,120,"ROLE");

for(int y=0;y<=i;++y)
{
outtextxy(30,170+f,e[y].name);
outtextxy(190,170+f,e[y].address);
outtextxy(345,170+f,e[y].no);
outtextxy(530,170+f,e[y].role);



f=f+20;
}

getch();
admin_home();
}


void view_pros()
{

//cleardevice();
trans();
boundary();
char temp[20];
int f=0;
setfillstyle(1,RED);
bar(0,50,getmaxx(),90);
setcolor(15);
settextstyle(1,0,4);
outtextxy(170,60,"LIST OF ALL PROSPECTS");
setcolor(WHITE);
settextstyle(3,0,2);
setfillstyle(1,CYAN);
bar(20,120,getmaxx()-20,getmaxy()-30);
line(20,120,getmaxx()-20,120);
line(20,120,20,getmaxy()-30);
line(20,getmaxy()-30,getmaxx()-20,getmaxy()-30);
line(getmaxx()-20,120,getmaxx()-20,getmaxy()-30);
setcolor(BLACK);
line(20,150,getmaxx()-20,150);
line(180,120,180,getmaxy()-30);
line(340,120,340,getmaxy()-30);
line(520,120,520,getmaxy()-30);

outtextxy(80,115,"NAME");
outtextxy(230,115,"ADDRESS");
outtextxy(380,115,"PHONE");
outtextxy(520,115,"STATUS");

for(int y=0;y<=h;++y)
{
outtextxy(30,170+f,p[y].name);
outtextxy(190,170+f,p[y].address);
outtextxy(345,170+f,p[y].no);
outtextxy(530,170+f,p[y].status);
f=f+20;

}
getch();
if(strcmp(e[j].role,"admin")==0)
admin_home();
else
monitor_home();

}


void pass_change()
{
//cleardevice();
trans();
boundary();
int flag=0;
char opass[5];
char pass[5];
char user[25];
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
setcolor(15);
settextstyle(1,0,4);
outtextxy(165,60,"CHANGE PASSWORD");
settextstyle(3,0,3);
outtextxy(155,200,"Your Usename is:");
outtextxy(380,200,e[j].name);
int k=0;
outtextxy(148,250,"Enter The OLD PASSWORD:");
gotoxy(58,17);
gets(opass);
if(strcmp(e[j].pass,opass)==0)
{
outtextxy(145,300,"Enter NEW PASSWORD:");
gotoxy(50,20);
while(k<=3)
{
pass[k]=getche();
cout<<pass[k];
delay(100);
cout<<'\b';
cout<<"*";
++k;
}
pass[k]='\0';
strcpy(e[j].pass,pass);
outtextxy(130,getmaxy()-50,"Password Change SUCCESSFULL!!");

}
else if(strcmp(e[j].pass,opass)!=0)
{
outtextxy(80,150,"OLD PASSWORD MISMATCH");
outtextxy(80,getmaxy()-50,"....press any key to go to HOME");
}

getch();
if(strcmp(e[j].role,"admin")==0)
admin_home();
else
monitor_home();

}





void del_pros()
{

//cleardevice();
trans();
boundary();
int flag=0;
setcolor(WHITE);
char user[25];
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
settextstyle(1,0,4);
outtextxy(165,60,"DELETE PROSPECTS");
settextstyle(3,0,3);
outtextxy(148,200,"Enter The name:");
gotoxy(48,14);
gets(user);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,user)==0)
{
flag=1;
int k=0;
for(int x=y;x<h;++x)
{
strcpy(p[x].name,p[x+1].name);
strcpy(p[x].status,p[x+1].status);
strcpy(p[x].address,p[x+1].address);
strcpy(p[x].no,p[x+1].no);
}
outtextxy(150,300,"RECORD DELETED");
--h;
}
}

if(flag==0)
{
outtextxy(80,150,"NO SUCH PROSPECT EXIST IN RECORDS");
outtextxy(80,getmaxy()-50,"....press any key to go to ADMIN HOME");
}

getch();
admin_home();

}




//*************************  MONITOR AREA  **************************




void monitor_home()
{
trans();
boundary();
char ch;
int c=1;
//cleardevice();
setfillstyle(1,RED);
bar(0,50,getmaxx(),90);
setcolor(15);
outtextxy(getmaxx()-250,getmaxy()-30,"WELCOME:");
outtextxy(getmaxx()-125,getmaxy()-30,e[j].name);
settextstyle(1,0,4);
outtextxy(120,55,"PROSPECT MONITOR HOME");
settextstyle(3,0,3);
outtextxy(170,160,"1.Add new PROSPECTUS");
outtextxy(170,200,"2.View all PROSPECTUS");
outtextxy(170,240,"3.Search PROSPECTUS");
outtextxy(170,280,"4.Change Password");
outtextxy(170,320,"5.Update Prospectus CONTACT No:");
outtextxy(170,360,"6.SIGN OUT");


round_opt(c);
ch=getch();
while(ch!=13)
{
if(ch==80)
c=c==6?1:c+1;
if(ch==72)
c=c==1?6:c-1;
round_opt(c);
ch=getch();
}
switch(c)
{
case 1:new_pros();
	break;

case 2:view_pros();
	break;

case 3:search_pros();
	break;

case 4:pass_change();
	break;

case 5:upd_pros();
	break;
case 6:home();
	break;

default:cleardevice();
	outtextxy(100,100,"ERROR!!!");
}

getch();
}




void new_pros()
{

++h;


//cleardevice();
trans();
boundary();
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
setcolor(15);
settextstyle(1,0,4);
outtextxy(160,60,"ADD NEW PROSPECT");
settextstyle(3,0,3);
outtextxy(30,150,"NAME:");
outtextxy(30,185,"STATUS(HOT/WARM/COLD):");
outtextxy(30,230,"ADDRESS:");
outtextxy(30,262,"Contact No:");

fillellipse(15,168,10,10);
gotoxy(15,11);
gets(p[h].name);

fillellipse(15,200,10,10);

c:
setfillstyle(1,BLACK);
bar(350,180,600,220);
gotoxy(45,13);
gets(p[h].status);
if(strcmp(p[h].status,"hot")!=0 && strcmp(p[h].status,"cold")!=0 && strcmp(p[h].status,"warm")!=0 )
goto c;

setfillstyle(1,RED);
fillellipse(15,245,10,10);
gotoxy(18,16);
gets(p[h].address);

fillellipse(16,280,10,10);
gotoxy(21,18);
gets(p[h].no);

outtextxy(150,310,"ACCOUNT SUCCESFULLY CREATED!!");
getch();
monitor_home();

}


void search_pros()
{

//cleardevice();
trans();
boundary();
int flag=0;
char temp[20];
setcolor(WHITE);
char pname[25];
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
settextstyle(1,0,4);
outtextxy(165,60,"SEARCH PROSPECT");
settextstyle(3,0,3);
outtextxy(148,200,"Enter The NAME to search:");
gotoxy(58,14);
gets(pname);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,pname)==0)
{
flag=1;
outtextxy(155,250,"PROSPECTUS FOUND....DETAILS:");
outtextxy(130,280,"NAME:");
outtextxy(250,280,p[y].name);

outtextxy(130,305,"STATUS:");
outtextxy(250,305,p[y].status);

outtextxy(130,330,"ADDRESS:");
outtextxy(250,330,p[y].address);

outtextxy(130,355,"Contact No:");
outtextxy(270,355,p[y].no);
}
}
if(flag==0)
{
outtextxy(80,150,"NO SUCH Prospectus EXIST IN RECORDS");
outtextxy(80,getmaxy()-50,"....press any key to go to MONITOR HOME");

}
getch();
monitor_home();


}


void upd_pros()
{
//cleardevice();
trans();
boundary();
int flag=0;
char temp[20];
setcolor(WHITE);
char pname[25];
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
settextstyle(1,0,3);
outtextxy(140,60,"CHANGE PROSPECT ' S CONTACT");
settextstyle(3,0,3);
outtextxy(148,200,"Enter The NAME to search:");
gotoxy(58,14);
gets(pname);
for(int y=0;y<=h;++y)
{
if(strcmp(p[y].name,pname)==0)
{
flag=1;
outtextxy(155,250,"PROSPECT FOUND.....DETAILS:");
outtextxy(130,290,"NAME:");
outtextxy(250,290,p[y].name);

outtextxy(130,315,"PREVIOUS Contact No:");
outtextxy(380,315,p[y].no);

outtextxy(130,340,"NEW Contact No:");
gotoxy(42,23);
gets(p[y].no);
}
}
if(flag==0)
{
outtextxy(80,150,"NO SUCH Prospect EXIST IN RECORDS !!");
outtextxy(80,getmaxy()-50,"....press any key to go to MONITOR HOME");

}
getch();
monitor_home();



}


void boundary()
{
setfillstyle(1,RED);
bar(0,0,getmaxx(),getmaxy());

setfillstyle(1,BLACK);
bar(5,5,getmaxx()-5,getmaxy()-5);


}



void trans()
{
setcolor(BLACK);
int e;
e=10;
setfillstyle(1,BLACK);

while(e<=getmaxx()/1.5)
{
fillellipse(getmaxx()/2,getmaxy()/2,e,e);
delay(5);
e=e+20;
}
}


void develop()
{
trans();
boundary();
setfillstyle(1,RED);
bar(0,50,getmaxx(),100);
setcolor(15);
settextstyle(1,0,4);
outtextxy(160,60,"DEVELOPED BY:");
settextstyle(3,0,3);
outtextxy(280,300,"KARAN KHANNA");
outtextxy(280,350,"B.TECH/CSE  1st YEAR");
getch();
home();

}




/*

I DID A NYC JOB :)

		 -karan khanna
		 (CEO)


*/
