
//*****************************************************************
//                 HEADER FILE USED IN PROJECT
//*****************************************************************

#include<iostream>
#include<windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
	
#define MAX_SIZE_USER_NAME 30

#define MAX_SIZE_PASSWORD 30

#define FILE_NAME "studentRecordSystem.bin"

# define MAX_STUDENT_DEP 60
#define MAX_STUDENT_NAME 60

#define FILE_HEADER_SIZE sizeof(sFileHeader)


using namespace std;

//*****************************************************************
//                 ADT USED
//*****************************************************************

struct FileHeader

{

char username[MAX_SIZE_USER_NAME];

char password[MAX_SIZE_PASSWORD];

} ;

class Node 
{
public:
    int roll;
    string Name;
    string Dept;
    int Marks;
    Node* next;
};
  
// Stores the head of the Linked List
Node* head = new Node();
  
// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
    // Base Case
    if (head == NULL)
        return false;
  
    Node* t = new Node;
    t = head;
  
    // Traverse the Linked List
    while (t != NULL) 
	{
        if (t->roll == x)
            return true;
        t = t->next;
    }
  
    return false;
}
  
// Function to insert the record
void Insert_Record(int roll, string Name,
                   string Dept, int Marks)
{
    // if Record Already Exist
    if (check(roll)) 
	{
        cout << "Student with this "
             << "record Already Exists\n";
        return;
    }
  
    // Create new Node to Insert Record
    Node* t = new Node();
    t->roll = roll;
    t->Name = Name;
    t->Dept = Dept;
    t->Marks = Marks;
    t->next = NULL;
  
    // Insert at Begin
    if (head == NULL
        || (head->roll >= t->roll)) 
		{
        t->next = head;
        head = t;
    }
  
    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->roll < t->roll)
			    {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
  
    cout << "Record Inserted "
         << "Successfully\n";
}
  
//*****************************************************************
//                 SEARCH RECORD
//*****************************************************************
// students Record with roll number
void Search_Record(int roll)
{
    // if head is NULL
    if (!head) 
	{
        cout << "No such Record "
             << "Avialable\n";
        return;
    }
  
    // Otherwise
    else 
	{
        Node* p = head;
        while (p) {
            if (p->roll == roll) 
			{
                cout << "Roll Nmuber\t"
                     << p->roll << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Department\t"
                     << p->Dept << endl;
                cout << "Marks\t\t"
                     << p->Marks << endl;
                return;
            }
            p = p->next;
        }
  
        if (p == NULL)
            cout << "No such Record "
                 << "Avialable\n";
    }
}
  
//*****************************************************************
//                 DELETE RECORD
//*****************************************************************
// record with given roll number
// if it exist
int Delete_Record(int roll)
{
    Node* t = head;
    Node* p = NULL;
  
    // Deletion at Begin
    if (t != NULL
        && t->roll == roll) 
		{
        head = t->next;
        delete t;
  
        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }
  
    // Deletion Other than Begin
    while (t != NULL && t->roll != roll) 
	{
        p = t;
        t = t->next;
    }
    if (t == NULL) 
	{
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
  
        delete t;
        cout << "Record Deleted "
             << "Successfully\n";
  
       
 
    }
     return 0;
}

/*void update_data()
{
	Node *t;
	int roll;
	int i,n1;
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		
	}
	else
	cout<<"Enter roll no to update "<<endl;
	fflush(stdin);

fgets(userName,MAX_SIZE_USER_NAME,stdin);

}*/
  
//*****************************************************************
//                 DISPLAY RECORD
//*****************************************************************
void Show_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record Available\n";
    }
    else {
        cout << "Index\tName\tCourse"
             << "\tMarks\n";
  
        // Until p is not NULL
        while (p != NULL) 
		{
            cout << p->roll << "    \t"
                 << p->Name << "\t"
                 << p->Dept << "\t"
                 << p->Marks << endl;
            p = p->next;
        }
    }
}
  
//****************************************************************
//          	 MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()

{

	
//****************************************************************
//              	INTRODUCTION 
//****************************************************************
	cout << "\n\n\t\t\t Date : ";
	       cout<<__DATE__<<"\n";                       
	       cout << "\n\t\t\t Time : ";
	       cout<<__TIME__<<endl;
	 char intro();
	 HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    
	  SetConsoleTextAttribute(h,1);
	  cout<<"\n\t\t\t===================================================";
	cout<<"\nt\t\t\t\t      STUDENT MANAGEMENT SYSTEM ";
	 cout<<"\n\t\t\t===================================================";
	  SetConsoleTextAttribute(h,9);
	cout<<"\n\n\t\t\t\t   PREPARED BY : FOUR GROUP MEMBERS";
	cout<<"\n\n\t\t\t\t\t\t SHAKILA BIBI ";
	cout<<"\n\n\t\t\t\t\t\t AYESHA SHABBIR ";
	cout<<"\n\n\t\t\t\t\t\t ABIDA BIB ";
	cout<<"\n\n\t\t\t\t\t\t RAFIA SHABAZ";
	cout<<"\n\n\t\t\t\t\t  LAHORE GARISON UNIVERSITY ";

	cin.get();
	system("cls");
cout<<"\n\n\n\n\n\n\n\n";
  SetConsoleTextAttribute(h,9);
cout<<"\t\t\t\t\tLoading ";
char x=219;   //ASCI character for loading
for(int i=0;i<35; i++)
{
	  SetConsoleTextAttribute(h,9);
	cout<<x;
	if(i<10)
	Sleep(300);
	
	if(i>=10&& i<20)
	Sleep(150);
	
	if(i>=10)
	Sleep(25);
}
system("cls");
 SetConsoleTextAttribute(h,7);
 

    head = NULL;
    char Name[MAX_STUDENT_NAME], Course[MAX_STUDENT_DEP];
    int Roll, Marks;
  
    
    while (true) 
	{
    cout<<"\n\t\t\t===================================================";
	cout<<"\n\n\t\t\t\t WELCOME TO STUDENT MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t===================================================";
    cout<<"\n\n\t\t\t\t   MAIN MENUE ";
	cout<<"\n\n\t\t\t\t\t1. ADD A STUDENT ";
	cout<<"\n\n\t\t\t\t\t2. DELETE STUDENT RECORD ";
	cout<<"\n\n\t\t\t\t\t3. SEARCH A STUDENT RECORD ";
	cout<<"\n\n\t\t\t\t\t4. VIEW ALL STUDENTS";
	cout<<"\n\n\t\t\t\t\t5. EXIT  ";

        cout << "\n\t\t\t\t\tEnter your Choice";
        int Choice;
  
        // Enter Choice
        cin >> Choice;
        if (Choice == 1)
		 {
            cout << "Enter Name of Student\n";
            cin.get(Name,MAX_STUDENT_DEP);
            cout << "Enter Roll Number of Student\n";
            cin >> Roll;
            cout << "Enter Department of Student \n";
            cin.get(Course,MAX_STUDENT_DEP);
            cout << "Enter Total Marks of Student\n";
            cin >> Marks;
            Insert_Record(Roll, Name, Course, Marks);
            /*ofstream outfile("E:\\ studentRecordSystem.text",ios::out);
	outfile<<Name<<endl;
    outfile<<Roll<<endl;
    outfile<<Course<<endl;
    outfile<<Marks<<endl;*/

   /* ifstream infile("E:\\ studentRecordSystem.text",ios::in);  //reading from file
    while(!infile.eof())// while loop to read a complete line from file
    {
    	infile.getline(Name,MAX_STUDENT_NAME);
    		infile.getline(Course,MAX_STUDENT_DEP);
    			infile>>Roll;
    				infile>>Marks;	
  
	}*/
        }
        else if (Choice == 2)
		 {
            cout << "Enter Roll Number of Student whose record is to be deleted\n";
            cin >> Roll;
            Delete_Record(Roll);
        }
        else if (Choice == 3)
		 {
            cout << "Enter Roll Number of Student whose record you want to Search\n";
            cin >> Roll;
            Search_Record(Roll);
        }
        else if (Choice == 4) 
		{
            Show_Record();
        }
        else if (Choice == 5)
		{
            exit(0);
        }
        else 
		{
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}

//*****************************************************************
//                    END OF PROJECT
//*****************************************************************
