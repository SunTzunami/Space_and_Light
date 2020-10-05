#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
void hsmile();
void ssmile();
void planets();
void stars();
void timer(int &a,int &bonus,char q[])   #timer to keep allocate more points for swifter and accurate responses
{
	cleardevice();
	stars();
	planets();
	int fl=0;
	for(int i=109;i>=0;--i)
	{

		if(i==99)
		{
			cleardevice();
			stars();
			planets();
		}
		a=666;
		setcolor(RED);
		if(i>100)
		{
			bonus=10;
		}
		else if(i>90)
		{
			bonus=9;
		}
		else if(i>80)
		{
			bonus=8;
		}
		else if(i>70)
		{
			bonus=7;
		}
		else if(i>60)
		{
			bonus=6;
		}
		else if(i>50)
		{
			bonus=5;
		}
		else if(i>40)
		{
			bonus=4;
		}
		else if(i>30)
		{
			bonus=3;
		}
		else if(i>20)
		{
			bonus=2;
		}
		else bonus=1;
		//////
		setcolor(RED);
		settextstyle(0,HORIZ_DIR,8);
		outtextxy(80,50,"QUIZ");
		gotoxy(5,12);
		cout<<"\nQuestion- ";
		cout<<q;
		cout<<"\nPress any key to attempt-";
		if(kbhit())
		{

			gotoxy(5,14);
			cout<<"\nInput answer-";
			cin>>a;
			 fl=1;
			break;
		}
		float ba=109-i;
//		gotoxy(5,6);
		gotoxy(72,6);
		int k=i/10;
//		circle(572,88,20);
		setcolor(RED);
		gotoxy(34,22);
		if(i<100)
		{
			circle(268,342,90-ba*0.8);
		}
		if(i%10==0)
		{
			cout<<k;
			delay(800);
		}
	}
	if(fl==0)
	{
		delay(40);
		cleardevice();
		circle(572,88,20);
		gotoxy(72,6);
		cout<<0;
		settextstyle(0,HORIZ_DIR,3);
		outtextxy(235,230,"TIME UP!");
	   }
	   else
	   return;
}
class qa       //accessible by only admin
{
	char q[100];   //data members
	int ans,qid;
	public:
	void init()                      //memb functions
	{
		cout<<"\n\tInput question id- ";
		cin>>qid;
		cout<<"\n\tInput the question- ";
		gets(q);
		cout<<"\n\tInput the answer- ";
		cin>>ans;
	}
	void dispad()
	{
		cout<<endl;
		cout<<"\n\tQuestion id- ";
		cout<<qid;
		cout<<"\n\tQuestion- ";
		cout<<q;
		cout<<"\n\tAnswer- ";
		cout<<ans;
	}
	int dispu()
	{
		gotoxy(4,12);
		cleardevice();
		stars();
		planets();
		int a=666,bonus=1;
		setcolor(RED);
		settextstyle(0,HORIZ_DIR,9);
		outtextxy(180,50,"QUIZ");
		gotoxy(5,12);
		cout<<"\nQuestion- ";
		cout<<q;
		delay(1500);
//		cout<<"\nInput the answer- ";
		timer(a,bonus,q);
		if(a==ans)
		{
			gotoxy(4,12);
			cleardevice();
			stars();
			planets();
			setcolor(RED);
			settextstyle(0,HORIZ_DIR,9);
			outtextxy(80,50,"QUIZ");
			hsmile();
			cout<<"\n\tCorrect answer!";
			delay(700);
			return 1*bonus;
		}
		else
		{
			gotoxy(4,12);
			cleardevice();
			stars();
			planets();
			settextstyle(0,HORIZ_DIR,9);
			setcolor(RED);
			outtextxy(180,50,"QUIZ");
			ssmile();
			cout<<"\n\tThe correct answer was- "<<ans;
			delay(1200);
			if(a!=666)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
	int retid()
	{
		return qid;
	}
}S;
class highscore
{
	int highscore;
	char name[50];
	public:
	void init(int x)
	{
		cout<<"\nInput your name- ";
		cin>>name;
		highscore=x;
	}
	void disp()
	{
		cout<<"\nName- "<<name;
		cout<<"\nScore- "<<highscore;
	}
}h;
void hsmile()
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(300,290,40,40);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(280,280,5,5);
	fillellipse(320,280,5,5);
	setcolor(BLACK);
	arc(300,285,225,315,30);
}//joyous
void ssmile()
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(300,320,40,40);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(280,310,5,5);
	fillellipse(320,310,5,5);
	setcolor(BLACK);
	arc(300,360,45,135,30);
}//sad
void hsi()                      //writing high scores
{
	fstream fout("hs.dat",ios::binary|ios::app|ios::out);
	if(!fout)
	{
		cout<<"Error\n";
		return;
	}
	fout.write((char*)&h,sizeof(h));
	fout.close();
	return;
}
void hso()                    //reading high scores
{
	cleardevice();
	settextstyle(7,HORIZ_DIR,4);
	setcolor(RED);
	outtextxy(200,30,"HIGHSCORES");
	fstream fin("hs.dat",ios::binary|ios::in);
	gotoxy(2,5);
	while(!fin.eof())
	{
		fin.read((char*)&h,sizeof(h));
		if(fin.eof())
		{
			break;
		}
		h.disp();
	}
	planets();
	stars();
	setcolor(WHITE);
	setbkcolor(BLACK);
	setcolor(BLUE);
	line(620,0,620,500);
	line(20,0,20,500);
	line(0,20,650,20);
	line(0,460,650,460);
	getch();
}
void wr()
{
	fstream fout("quiz.dat",ios::binary|ios::app|ios::out);
	if(!fout)
	{
		cout<<"Error\n";
		return;
	}
	S.init();
	fout.write((char*)&S,sizeof(S));
	fout.close();
	return;
}
void modify()
{
	int check=0;
	int id;
	qa S;
	fstream fio("quiz.dat",ios::binary|ios::in|ios::out);
	if(!fio)
	{
		cout<<"Error in opening file";
	}
	cout<<"\n\tInput the id of record you want to modify-";
	cin>>id;
	while(fio.read((char*)&S,sizeof(S)))
	{
		if(S.retid()==id)
		{
			check++;
			lb:
			char ch;
			cout<<"\n\tDo you require to change the details?(y/n)-";
			cin>>ch;
			switch(ch)
			{
				case 'y':
				case 'Y':cout<<"\n\tInput the new details";
						 S.init();
						 fio.seekp(fio.tellp()-sizeof(S),ios::beg);
						 fio.write((char*)&S,sizeof(S));
						 break;
				case 'n':
				case 'N':return;
				default:cout<<"\n\tError";
				goto lb;
			}
		}
	}
	if(check==0)
	{
		cout<<"Not found!";
		return;
	}
	fio.close();
}
void del()
{
	qa temp,B;
	fstream fout("v.dat",ios::binary|ios::app|ios::in);
	fstream fin("quiz.dat",ios::binary|ios::in);
	if(!fin||!fout)
	{
		cout<<"\nUnable to access the file!";
	}
	int i,fl=0;
	char ch;
	cout<<"\n\tInput the id of question to be deleted- \n";
	gotoxy(52,17);
	cin>>i;
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		if(temp.retid()!=i)
		{
			B=temp;
			fout.write((char*)&B,sizeof(B));
		}
		else
		{
			fl=1;
		}

	}//end while
	fout.close();
	fin.close();
	if(fl==0)
	{
		cout<<"\nQuestion not found!";
	}
	else
	{
			lb:
			cout<<"\n\tDoes the user require to delete the question(y/n)?";
			gotoxy(8,30);
			cin>>ch;
			switch(ch)
			{
				case 'y':
				case 'Y':remove("quiz.dat");
						 rename("v.dat","quiz.dat");
						 break;
				case 'n':
				case 'N':break;
				default:cout<<"\n\tError!";
						delay(500);
						goto lb;
			}
	}
}
void planets()  //planets
{
	for(int i=0;i<900;i++)
	{
		for(int y=0;y<900;y++)
		{
			if(y%180==0&&i%180==0)
			   {
					int k=random(i),l=random(y),m=random(5);
					setcolor(k);
					setfillstyle(SOLID_FILL,k);
					fillellipse(k,l,0.005*i,0.005*i);
					setcolor(l);
			   }
		}
	}
}
void stars()
{
	for(int i=0;i<900;i++)   //<<STARS
	{
		setcolor(07);
		for(int y=0;y<900;y++)
		{
			if(y%30==0&&i%30==0)
			   {
					circle(random(i),random(y),0.002*i);
			   }
		}
	}
}
void credits()
{
	cleardevice();
	setbkcolor(0);
	stars();
	stars();
	planets();
	setcolor(GREEN);
	settextstyle(3,HORIZ_DIR,7);
	outtextxy(70,30,"CREDITS");
	settextstyle(3,HORIZ_DIR,5);
	setcolor(RED);
	outtextxy(180,250,"SAJAG");
	getch();
//	delay(3000);
	cleardevice();
}
int quiz()
{
	int score=0;
	cleardevice();
	int a=666;
	planets();
	stars();
	settextstyle(0,HORIZ_DIR,9);
	outtextxy(180,20,"QUIZ");
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(20,150,"Rules(to be read carefully)-");
	settextstyle(0,HORIZ_DIR,0);
	outtextxy(5,220,"1.Each correct answer gets you +1 points");
	outtextxy(5,250,"2.Each wrong answer gets you -1 points");
	outtextxy(5,280,"3.There's a time limit of 10s per question");
	outtextxy(5,310,"4.No points will be deducted for not attempting");
	outtextxy(5,340,"5.Bonus points will be awarded based on swiftness in answering");
	outtextxy(5,370,"6.For True/False questions.Press 1 for true and 2 for false");
	outtextxy(5,400,"7.Press any key to begin-");
	setcolor(BLUE);
	line(620,0,620,500);
	line(20,0,20,500);
	line(0,20,650,20);
	line(0,460,650,460);
	getch();
	fstream fin("quiz.dat",ios::binary|ios::in);
	while(!fin.eof())
	{
		fin.read((char*)&S,sizeof(S));
		if(fin.eof())
		{
			break;
		}
		score+=S.dispu();
	}
	return score;
}
void topic1();
void topic2();
void topic3();
//void topic4();  //black hole for future
void user()
{
		lb:
		cleardevice();
		gotoxy(1,1);
		stars();
		planets();
		settextstyle(3,HORIZ_DIR,6);
		setcolor(RED);
		outtextxy(100,100,"USER MENU");
		gotoxy(9,14);
		int ch,x=0;
		cout<<"1.Sunlight\n\t2.Red Giant/End of Earth.\n\t3.Dispersion of light.\n\t4.Quiz\n\t5.Highscore\n\t6.Exit";
		cout<<"\n\tInput your choice(1/2/3/4/5/6/7)- ";
		setcolor(BLUE);
		line(620,0,620,500);
		line(20,0,20,500);
		line(0,20,650,20);
		line(0,460,650,460);
		cin>>ch;
		switch(ch)
		{
			case 1:topic1();
				break;
			case 2:topic2();
				break;
			case 3:topic3();
				break;
			case 4:	x=quiz();
				cout<<"\nYour score was: ";
				cout<<x;
				h.init(x);
				hsi();
				hso();
				break;
			case 5:	hso();
				break;
			case 6: return;
			default:cout<<"\nError!Input again!";
				delay(500);
				goto lb;
		}
}
void admin()
{
	lb:
	cleardevice();
	stars();
	planets();
	settextstyle(3,HORIZ_DIR,5);
	setcolor(RED);
	outtextxy(100,60,"ADMIN MENU");
	gotoxy(12,10);
	int ch;
	cout<<"1.Display a question and answer.";
	gotoxy(12,11);
	cout<<"2.Add a question and answer.";
	gotoxy(12,12);
	cout<<"3.Delete a question and answer.";
	gotoxy(12,13);
	cout<<"4.Modify a question and answer.";
	gotoxy(12,14);
	cout<<"5.Go back to main menu.(Log out)";
	gotoxy(12,15);
	cout<<"Input your choice- ";
	setcolor(BLUE);
	line(620,0,620,500);
	line(20,0,20,500);
	line(0,20,650,20);
	line(0,460,650,460);
	cin>>ch;
	switch(ch)
	{
		case 1: fstream fin("quiz.dat",ios::binary|ios::in);
				while(!fin.eof())
				{
					fin.read((char*)&S,sizeof(S));
					if(fin.eof())
					{
						break;
					}
					S.dispad();
					cout<<"\n\tPress any key to continue-";
					getch();
				}
				cout<<"\n\n\tPress any key to continue-";
				getch();
				break;
		case 2:wr();
				break;
		case 3:del();
				break;
		case 4:modify();
				break;
		case 5:return;
		default:cout<<"\nWrong choice!Input again!";
				delay(500);
				goto lb;
	}
	goto lb;
}
void menu()
{
	lb1:
	settextstyle(3,HORIZ_DIR,6);
	cleardevice();
//	setbkcolor(RED);
	setcolor(BLUE);
	line(620,0,620,500);
	line(20,0,20,500);
	line(0,20,650,20);
	line(0,460,650,460);
	setcolor(RED);
	outtextxy(130,40,"SPACE & LIGHT");
	stars();
	planets();
	settextstyle(3,HORIZ_DIR,3);
	setcolor(63);
	outtextxy(100,165,"Login as-");
	outtextxy(100,195,"1.Student");
	outtextxy(100,225,"2.Admin");
	outtextxy(100,255,"Press 3 to Exit");
	outtextxy(100,293.5,"Input your choice(1/2/3)- ");
	gotoxy(55,20);
	int m;
	char pw[20];
	gotoxy(62,27);
	cin>>m;
	char ch;
	switch(m)
	{
		case 1:	user();
			break;
		case 2: cleardevice();
			cout<<"\nInput password- ";
			char str[]=" ";
			char ch=' ';
			int i=0;
			while(1)
			{
				ch=getch();
				str[i]=ch;
				i++;
				cout<<'*';
				if(getch()=='\r')
				break;
			}
			str[i]='\0';
			if(strcmp(str,"aDmIn")==0)
			admin();
			else
			{
				cout<<"\nInvalid password!";
				delay(800);
				goto lb1;
			}
			break;
		case 3: credits();   //////////////////////////////////////////////////////////
			exit(0);
			break;
			default:cout<<"\nERROR!INPUT YOUR CHOICE AGAIN!";
			delay(400);
			goto lb1;
	}
	goto lb1;
}
void topic1()
{
	cleardevice();
	setcolor(YELLOW);
	setbkcolor(BLACK);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(150,250,"SUNLIGHT");
	delay(1200);
	cleardevice();
	settextstyle(3, HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(160,80,"BIG BANG(13.7 Billion years B.C.)!");
	delay(900);
	outtextxy(160,100,"Formation of Milky way(13.6 Billion years ago)!");
	delay(900);
	cleardevice();
	stars();
	stars();
	outtextxy(250,40,"Sunlight-Facts");
	outtextxy(250,70,"Birth of Sun(4.6 Billion years ago)");
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);       //sun
	fillellipse(100,135,100,100);
	circle(100,135,100);
	delay(1000);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,5);
	cout<<"\n";
	line(100,245,620,245);
	outtextxy(97,237,"<");
	outtextxy(620,237,">");
	setcolor(0);
	outtextxy(90,130,"Sun");
	setcolor(62);
	outtextxy(320,225,"(Scale diagram)");
	outtextxy(320,250,"149,597,870 km");
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	circle(620,135,4);              //earth
	fillellipse(620,135,4,4);
	fillellipse(619,133,2,2.5);
	fillellipse(621,134,3,3);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(619,133,2,1);
	fillellipse(621,135,3,2);
	fillellipse(623,137,1,1);
	///////////////
	setfillstyle(SOLID_FILL,56);       //mercury
	setcolor(56);                     //mercury
	circle(241.8,135,1.538);
	fillellipse(241.8,135,1.538,1.538);
	/////////////////
	setcolor(20);
	setfillstyle(SOLID_FILL,20);  //venus
	circle(448.26,135,3.7);
	fillellipse(448.26,135,3.7,3.7);
	////////////////////
//	outtextxy(201,115,"sunlight");
//	outtextxy(201,125,"|");
	for(int i=0;i<=300.0;i++)
	{
		delay(50);
		setcolor(RED);
		line(201+i*(1.386),135,202,135);
		setcolor(WHITE);
		if(i==13)
		{
			outtextxy(220,160,"Mercury");

		}
		if(i==180)
		{
			outtextxy(430,160,"Venus");
		}
		if(i==300)
		{
			outtextxy(600,160,"Earth");
		}
	}
	////display data
	settextstyle(2,HORIZ_DIR,10);
	setcolor(GREEN);
	outtextxy(20,340,"Press any key to continue-");
	getch();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(BLUE);
	settextstyle(3,HORIZ_DIR,6);
	outtextxy(210,30,"DATA");
	char ch;
	int es=0;
	gotoxy(1,8);
	ifstream fin("sun1.txt",ios::in);
	if(!fin)
	{
		cout<<"\nBUG!!";
		return;
	}
	else
	while(!fin.eof())
	{
		delay(50);
		fin.get(ch);
		if(fin.eof())
		{
			break;
		}
		cout<<ch;
//		delay(105);
	}
	fin.close();
	cout<<"\n\n\t\tPress any key to continue- ";
	getch();
	user();
}
void topic2()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(RED);
	settextstyle(8,HORIZ_DIR,2);
	outtextxy(150,250,"RED GIANT/END OF SUN");
	delay(1200);
	cleardevice();
	outtextxy(60,80,"BIG BANG(13.7 Billion years B.C.)!");
	delay(900);
	outtextxy(50,100,"Formation of Milky way(13.6 Billion years ago)!");
	delay(900);
	cleardevice();
	stars();
	stars();
	outtextxy(230,70,"Birth of Sun(4.6 Billion years ago)");
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);       //sun
	fillellipse(100,135,100,100);
	circle(100,135,100);
	delay(1000);
	settextstyle(3,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(120,10,"RED GIANT/END OF SUN(5 Billion years from now)");
	delay(2000);
	settextstyle(2,HORIZ_DIR,4);
	setcolor(WHITE);
	cout<<"\n";
	setcolor(WHITE);
	outtextxy(600,160,"Earth");
	outtextxy(220,160,"Mercury");
	outtextxy(90,250,"Sun");
	outtextxy(430,160,"Venus");
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	circle(620,135,4);              //earth
	fillellipse(620,135,4,4);
	fillellipse(619,133,2,2.5);
	fillellipse(621,134,3,3);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(619,133,2,1);
	fillellipse(621,135,3,2);
	fillellipse(623,137,1,1);
	///////////////
	setfillstyle(SOLID_FILL,56);       //mercury
	setcolor(56);                     //mercury
	circle(241.8,135,1.538);
	fillellipse(241.8,135,1.538,1.538);
	/////////////////
	setcolor(20);
	setfillstyle(SOLID_FILL,20);  //venus
	circle(448.26,135,3.7);
	fillellipse(448.26,135,3.7,3.7);
	////////////////////
	setfillstyle(SOLID_FILL,RED);
	for(int i=0;i<=300;i++)
	{
		  delay(5);
		  setcolor(RED);
		 circle(100,135,100+1.6*i);
		fillellipse(100,135,100+1.6*i,100+1.6*i);
		if(i==240)
		{
			setcolor(WHITE);
			settextstyle(8,HORIZ_DIR,3);
			outtextxy(160,130,"END OF EARTH AS WE KNOW IT!");
			delay(800);
		}
	}
	delay(400);
	cleardevice();
	stars();
	stars();
	cout<<"\nThe sun has become a white dwarf!";
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);       //sun
	fillellipse(100,135,5,5);
	circle(100,135,5);
	gotoxy(32,16);
	cout<<"Press any key to continue- ";
	getch();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(BLUE);
	settextstyle(3,HORIZ_DIR,6);
	outtextxy(210,30,"DATA");
	char ch;
	gotoxy(1,8);
	ifstream fin("rg.txt",ios::in);
	if(!fin)
	{
		cout<<"\nBUG!!";
		delay(300);
		return;
	}
	else
	while(!fin.eof())
	{
		fin.get(ch);
		if(fin.eof())
		{
			break;
		}
		cout<<ch;
		delay(50);
	}
	fin.close();
	cout<<"\n\n\t\tPress any key to continue- ";
	getch();
	user();
}
void topic3()
{
	cleardevice();
	settextstyle(7,HORIZ_DIR,4);
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(200,200,"Dispersion of ");
	setcolor(RED);
	outtextxy(210,240,"L");
	setcolor(1);
	outtextxy(230,240,"I");
	setcolor(YELLOW);
	outtextxy(250,240,"G");
	setcolor(GREEN);
	outtextxy(270,240,"H");
	setcolor(61);
	outtextxy(300,240,"T");
	delay(2000);
	cleardevice();
	setbkcolor(7);
	settextstyle(4,HORIZ_DIR,3);
	setcolor(RED);
	setcolor(63);
	int poly[6];
	poly[0]=220;
	poly[1]=250;
	poly[2]=320;
	poly[3]=77.8;
	poly[4]=420;
	poly[5]=250;
	line(220,250,320,77.8);
	line(220,250,420,250);
	line(320,77.8,420,250);
	arc(320,77.8,240,300,25);
	setfillstyle(INTERLEAVE_FILL,WHITE);
	fillpoly(3,poly);
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(310,35,"A");
	outtextxy(190,240,"B");
	outtextxy(425,240,"C");
	delay(1000);
	settextstyle(2,HORIZ_DIR,4);
	setcolor(56);
	outtextxy(50,100,"REGION 1(VACCUM)");
	outtextxy(30,150,"Speed of light-300,000 km/s.");
	setcolor(63);
	for(int i=0;i<60;i++)
	{
		line(25,249.9,35+i*4.03,244.9-i*1.39);
		delay(60);
	}
	for(i=0;i<40;i++)
	{
		setcolor(56);
		outtextxy(280,189,"REGION 2(GLASS)");
		outtextxy(245,230,"Speed of light-225,000 km/s");
		setcolor(4);
		line(271,163.9,272+i*1.83,162.9-i*1.2);  //R
		setcolor(60);
		line(271,163.9,272+i*1.99,162.9-i*0.95);  //O
		setcolor(62);
		line(271,163.9,272+i*2.15,162.9-i*0.66);  //Y
		setcolor(2);
		line(271,163.9,272+i*2.37,162.9-i*0.3);  //G
		setcolor(57);
		line(271,163.9,272+i*2.48,162.9+i*0.0001);  //B
		setcolor(1);
		line(271,163.9,272+i*2.58,162.9+i*0.19);  //I
		setcolor(5);
		line(271,163.9,272+i*2.68,162.9+i*0.38); //V
		delay(80);
	}
	for(i=0;i<40;i++)
	{
		setcolor(56);
		outtextxy(450,100,"REGION 3(VACCUM)");
		outtextxy(420,150,"Speed of light-300,000 km/s");
		setcolor(4);
		line(345.2,115.9,346+i*4.13,114.9-i*1.1);  //r
		setcolor(60);
		line(350.6,126.9,351+i*3.6,125.9-i*0.7);    //o
		setcolor(62);
		line(358,136.5,356+i*3.3,135.5-i*0.3);
		setcolor(2);
		line(366.8,150.9,367.8+i*2.9,150.9-i*0.12);  //g
		setcolor(57);
		line(371.2,162.904,372.2+i*2.7,164+i*0.2);   //b                      //b
		setcolor(1);
		line(375.2,170.5,376.2+i*2.9,171+i*0.38);    //i
		setcolor(5);
		line(379.2,178.1,381+i*3.2,179.4+i*0.6);     //v
		delay(60);
	}
	delay(3000);
	setbkcolor(BLACK);
	cleardevice();
	cout<<"Press any key to continue- ";
	getch();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(BLUE);
	settextstyle(3,HORIZ_DIR,6);
	outtextxy(210,30,"DATA");
	char ch;
	gotoxy(1,8);
	ifstream fin("light.txt",ios::in);
	if(!fin)
	{
		cout<<"\nBUG!!";
		delay(300);
		return;
	}
	else
	while(!fin.eof())
	{
		fin.get(ch);
		if(fin.eof())
		{
			break;
		}
		cout<<ch;
		delay(50);
	}
	fin.close();
	cout<<"\n\n\t\tPress any key to continue- ";
	getch();
	user();
}
void main()
{
	int gd = DETECT,gm;
	initgraph( &gd, &gm,"C:\tc\bgi");
	clrscr();
	menu();
	getch();
}
