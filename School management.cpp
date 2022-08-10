#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include<cstdlib>
#include<ctime>  
using namespace std;
void student_menu(void);
void student_input(void);
void student_display(void); 
//--------------------------------
void  teacher_menu(void);
void   teacher_input(void);
void   teacher_display(void);
void userlogin();
struct student
{
 string fname;//for student first name
 string lname;//for student last name
 string Registration;//for Registration No number
 string classes;
}
studentData;
//-----------------------
struct teacher
{
 string fst_name;//first name of teacher
 string lst_name;//last name of teacher
 string qualification;//Qualification of teacher
 string exp;//Experiance of the person
 string pay;//Pay of the Teacher
 string subj;//subject whos he/she teach
 string lec;//Lecture per Week
 string addrs;//Adders of teacher home
 string cel_no;//Phone number 
 string blod_grp;//Bool Group 
 string serves;//Number of serves in School

}
tech;
main()
{
   char choice;
	system("cls");//Clear screen

//Level 1-Display process
system("color 4E"); 
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\tSCHOOL MANAGEMENT PROGRAM\n\n";
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\tMAIN SCREEN\n\n";
 cout<<"Enter your choice: "<<endl;
 cout<<"1.Students information"<<endl;
 cout<<"2.Teacher information"<<endl;
 cout<<"3.Exit program"<<endl;
 cin>>choice;
 if(choice=='1')
        student_menu();
  else
  if(choice=='2') 
            teacher_menu();
		        
}


void student_menu()
{ system("cls");
char choice;
//Level-2 display
cout<<"\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.Create new entry\n";
cout<<"2.Find and display entry\n";
cout<<"3.Jump to main\n";
cin>>choice;


if(choice=='1')

          
        student_input();
else
if(choice=='2') 
        student_display();          
else
  main();

}

//---------------------------------
void student_input(void)
{ system("cls");

userlogin();

char b;
string find;//for sorting

	system("cls");
	{  ofstream f1("student.txt",ios::app);
   char choice;
 cout<<"Enter First name: ";
 cin>>studentData.fname;
cout<<"Enter Last name: ";
 cin>>studentData.lname;
 cout<<"Enter Registration number: ";
 cin>>studentData.Registration;
 cout<<"Enter class: ";
 cin>>studentData.classes;
 
 f1<<studentData.fname<<endl<<studentData.lname<<endl<<studentData.Registration<<endl<<studentData.classes<<endl;
 cout<<"Do you want to enter data: ";
 cout<<"Press Y for Continue and N to Finish:  ";
 cin>>b;
 
 if(b=='n')
 {   student_menu();}
 else
 {     
 student_input();
 }
 
f1.close();
}
}
//------------------------------------------
void  student_display(void)
{ system("cls");
int j;//f or processing usage 
char b;
string find;//for sorting
ifstream f2("student.txt"); 

cout<<"Enter First name to be displayed: ";
cin>>find;
cout<<endl;
int Found = 0;
for( j=0;(!f2.eof());j++)
{ 

getline(f2,studentData.fname);

if(studentData.fname==find)
{
 Found = 1;
 cout<<"First Name:      "<<studentData.fname<<endl;
 getline(f2,studentData.lname);
 cout<<"Last Name:       "<<studentData.lname<<endl;
 getline(f2,studentData.Registration);
 cout<<"Registration No: "<<studentData.Registration<<endl;
 getline(f2,studentData.classes);
 cout<<"Class:           "<<studentData.classes<<endl;
 cout<<endl;
}

}

if(Found == 0){

cout<<"No Record Found"<<endl;
}
f2.close();

cout<<"Press Y for Continue and N to Finish:  ";
 cin>>b;
 
 if(b=='Y')
 {   student_input();}
 else
 {     
 student_menu();
 }
getch();//To hold data on screen
getch();//To hold data on screen
}
//--------------------------------
void  teacher_menu(void)
{     system("cls");
char choice;
	cout<<"\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.Create new entry\n";
cout<<"2.Find and display\n";
cout<<"3.Jump to main\n";
cin>>choice;

if(choice=='1')
    
	 teacher_input();
else
  if(choice=='2')
     teacher_display();
else
    main();	      

}
//-----------------------------------
void  teacher_input(void)
{   userlogin();
char b;
	ofstream t1("teacher.txt",ios::app);


  cout<<"Enter First name: ";
  cin>>tech.fst_name;
  cout<<"Enter Last name:: ";
  cin>>tech.lst_name;
  cout<<"Enter qualification: ";
  cin>>tech.qualification;
  cout<<"Enter experiance(year): ";
  cin>>tech.exp;
  cout<<"Enter number of year in this School: ";
  cin>>tech.serves;
  cout<<"Enter Subject whos teach: ";
  cin>>tech.subj;
  cout<<"Enter Lecture(per Week): ";
  cin>>tech.lec;
  cout<<"Enter pay: ";
  cin>>tech.pay;
  cout<<"Enter Phone Number: ";
  cin>>tech.cel_no;
  cout<<"Enter Blood Group: ";
  cin>>tech.blod_grp;
  
  
  t1<<tech.fst_name<<endl<<tech.lst_name<<endl 
   <<tech.qualification<<endl<<tech.exp<<endl
   <<tech.serves<<endl<<tech.subj<<endl<<tech.lec
   <<endl<<tech.pay<<endl<<tech.cel_no<<endl<<tech.blod_grp<<endl;
  cout<<"Do you want to enter data: press Y and press n to go to teachers menu";
  cin>>b;
 if(b=='n')
 {   teacher_menu();}
 else
 {     
 teacher_input();
 }
system("cls");



t1.close();
}//case 1

//--------------------------------
void teacher_display(void)
{system("cls");
int j;//f or processing usage 
char b;
string find;//for sorting
	ifstream t2("teacher.txt"); 

cout<<"Enter name to be displayed: ";
cin>>find;

cout<<endl;
int Found = 0;
for( j=0;(!t2.eof());j++)
{ 
 
 getline(t2,tech.fst_name);
 
 if(tech.fst_name==find)
 {
  Found = 1;
  cout<<"First name: "<<tech.fst_name<<endl;
  getline(t2,tech.lst_name);
  cout<<"Last name: "<<tech.lst_name<<endl;
  getline(t2,tech.qualification);
  cout<<"Qualification: "<<tech.qualification<<endl;
  getline(t2,tech.exp);
  cout<<"Experience: "<<tech.exp<<endl;

  getline(t2,tech.serves);
  cout<<" number of year in this School: "<<tech.serves<<endl;

  getline(t2,tech.subj);
  cout<<"Subject whos teach: "<<tech.subj<<endl;

  getline(t2,tech.lec);
  cout<<"Enter Lecture(per Week): "<<tech.lec<<endl;
  getline(t2,tech.pay);
  cout<<"pay: "<<tech.pay<<endl;

  getline(t2,tech.addrs);
  cout<<"Address: "<<tech.addrs<<endl;

  getline(t2,tech.cel_no);
  cout<<"Phone Number: "<<tech.cel_no<<endl;

  getline(t2,tech.blod_grp);
  cout<<"Bool Group: "<<tech.blod_grp<<endl;
 }//if
 
}//for loop
t2.close();
if(Found == 0)
{

 cout<<"No Record Found"<<endl;
}
cout<<"Press Y for Continue and N to Finish:  ";
 cin>>b;
 
 if(b=='Y')
 {   student_input();}
 else
 {     
 student_menu();
 }
 }
 void userlogin()
{   
	string user;
	int ch;
	string pass;
		cout<<"\t \t   _____________\n";
		cout<<"\t \t  |Admin login |\n";
		cout<<"\t \t  _____________\n";  
		cout<<"enter admin  name and passward"<<endl;
		
	for(int i=1;i<=3;i++){

		cin>>user;
		cin>>pass;
				if(pass=="school123"&& user=="Admin")
				
				{
					cout<<"\n  welcome Admin";
					break;
					}
					
					{
					
				
				
				
			
				
				}
				if(i==3)
				{
					main();
				}
			}
		}
