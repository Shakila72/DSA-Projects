#include<iostream>//This header file contains definitions to objects\
                    like cin, cout, cerr etc.
#include<fstream>//This header is used to create files, write information to files\
                   , and read information from files.
using namespace std;//using namespace std is used to prevent user from writing std::\
                      in various statements like std::endl,std::cout etc. 
fstream sample,quesbank;//sample , quesbank are two objects of type fstream.
//Below class is created for true false to store each true false in this list.
class QTF{ 
	public:
	string question,correct_answer,user_input,question_type;
	int question_points,point_gained;
	QTF *next;//this node will store the address of next node 
	QTF*prev;
}TF;
class QMC{//This class is created for MCQS to store each MCQ in this list.
	public:
	string question,correct_answer,user_input,question_type;
	int question_points,point_gained;
	string a,b,c,d;
	QMC *next;//this node will store the address of next node 
	QMC*prev;
}MC;
class QSA{//This class is created for Shorts to store each Short in this list.
	public:
	string question,correct_answer,user_input,question_type;
	int question_points,point_gained;
	QSA *next;//this node will store the address of next node
	QSA*prev;
}SA;
class quizzer{//Class is created here with name quizzer
	private://well this private accessor is not necessary beacuse \
	         by default members of a Class is private\
	        untill you write Public or protected.
	        
	QTF *First_TF,*Last_TF;//HEAD and TAIL of QTF linked list
	QMC *First_MC,*Last_MC;//HEAD and TAIL of QMC linked list
	QSA *First_SA,*Last_SA;//HEAD and TAIL of QSA linked list
	string questions,correct_ans,us_input,first,last,FileName,Type;
	int pints;//points of each question will be stored in it.\
	            value will update with every qusetion
	string A,B,C,D;//it will store each option i.e option A. for MCQS
	int rear,front,int_ques,size;
	string string_ques;
	
	public:
	int queue[15]/*que array*/,exam_total;
	quizzer()//conclassor
	{
		size = 15;//sizer of queue array is set as 15.
		front = - 1;
		rear = - 1;
//Below we are initializing first and last node of each linked list with NULL.
		First_TF=Last_TF=NULL;
		First_MC=Last_MC=NULL;
		First_SA=Last_SA=NULL;
	//rear and fornt of queue is initialized with -1 in the begning.
	rear=-1;
	front=-1;
	for(int i=0;i<15;i++)//to initialize each index of queue array (0 to 14) with zero.
		queue[i]=0;
	}
	void quiz_instructions(){
		cout<<endl<<"Quiz Instruction Read before Pressing  Enter";
	cout<<endl<<"1) In short answer, Answer should consist of one word and ";
	cout<<"each alphabets should  be small.";	
	cout<<endl<<"2) In true false, type true or false in small alphabets ";  
	cout<<"according to your choice. ";
	cout<<endl<<"3) In MCQS type correct option in captital letter i.e A,B,C,D. ";
	cout<<endl<<"4) If you want to skipp any question just type skip in small alphabets.";
	cin.get();
	cin.get();//it creats a blank  space ppress enter and continue.
	system("cls");
	}
	void user(){//this function is to input user information.
			cout<<"\nEnter Your First Name: ";
			cin>>first;//variable to store first name.
			//sample is decalared with fstream on top of program
			sample<<"\nWhat is your First name?"<<endl<<first;//we are storing this line in file.
			cout<<"\nEnter Your Last Name: ";
		    cin>>last;//variable to store last name.
			sample<<"\nWhat is your Last name?"<<endl<<last;//we are storing this line in file.	
			cout<<"\nWhat file stores your questions:  ";
			cin>>FileName;//variable to store File name.
			sample<<"\nWhat file stores your questions?"<<endl<<FileName; 
	        do{//Do While loop
			cout<<"\nHow many question would you like (Limit is 15): ";
	        sample<<"\nHow many questions would you like (Limit is 15)?"<<endl;
	        cin>>string_ques;//number of question are stored in string type.
	        sample<<string_ques;//storing the number in file
		if(string_ques>"0" && string_ques<="9"){//statement to verify input is valid or not.
		    //the below if else statements are basically storing the same number\
			 of string type  into int type.
			if(string_ques=="1"){
		    int_ques=1;
			break;
		}
		    else if(string_ques=="2"){
		    int_ques=2;
		    break;
		}
		    else if(string_ques=="3"){
		    int_ques=3;
		    break;
		}
		else if(string_ques=="4"){
		    int_ques=4;
		    break;
		}
		else if(string_ques=="5"){
		    int_ques=5;
		    break;
		}
		else if(string_ques=="6"){
		    int_ques=6;
		    break;
		}
		else if(string_ques=="7"){
		    int_ques=7;
		    break;
		}
		else if(string_ques=="8"){
		    int_ques=8;
		    break;
		}
		else if(string_ques=="9"){
		    int_ques=9;
		    break;
		}
		else if(string_ques=="10"){
		    int_ques=10;
		    break;
		}
		else if(string_ques=="11"){
		    int_ques=11;
		    break;
		}
		else if(string_ques=="12"){
		    int_ques=12;
		    break;
		}
		else if(string_ques=="13"){
		    int_ques=13;
		    break;
		}
		else if(string_ques=="14"){
		    int_ques=14;
		    break;
		}
		else if(string_ques=="15"){
		    int_ques=15;
		    break;
		}
		else{//if number is more or less than given range which is (1-15)
			cout<<"\nThat is too many: ";
			sample<<"\nSorry! That is too many: "<<endl;
			}
			
		}
		else{//if the input is invalid.
			cout<<"\nThat is not valid: ";
			sample<<"\nSorry!That is not valid: "<<endl;
			}	
		}while(1);//loop while continue untill find a break statement.
		system("cls");//this statement is to clear the entire screen.
		quiz_instructions();
	}
	
bool isFull(){
if(front == 0 && rear == size - 1){// size is the size of queue.
return true;
        }
return false;
    }
    
bool isEmpty(){
if(front == -1) 
return true;
else 
return false;
    }
    
void que(int value){//this function is storing the marks in queue\
	                 marks can be positive or negative.  
if(isFull()){
cout << endl<< "Queue is full!!";
        } 
else {
if(front == -1) front = 0;
rear++;
queue[rear] = value;
cout << value << " ";
        }
    }
int deQueue(){
int value;
if(isEmpty())
{
cout << "Queue is empty!!" << endl; 
return(-1); 
} 
else { 
value = queue[front]; 
if(front >= rear)
{      //only one element in queue
front = -1;
rear = -1;
            } 
else 
{
front++;
  }
cout << endl << "Deleted => " << value << " from queue";
return(value);
        }
    }
//the below function question is the most important function of this program\
this function is reading questions from file as well as\
 comparing user inputed answer with correct answer\
 also storing data in linked lists\
 as well as storing data in an other file for record purpose..
	void questios(){
	string blank;
		for (int i=1;i<=int_ques;i++){
		//loop iterations depend on the number of question selected by user.
		quesbank>>Type;//reading question typpe from file which might be TF for true false \
		SA for shorts or MC for MCQS.
		quesbank>>pints;//reading marks of question.
		exam_total=exam_total+pints;//adding each question marks in total.
		getline(quesbank,blank);
		getline(quesbank,questions);//reading question from file.
		cout<<endl<<questions;
		sample<<endl<<questions;
		if(Type=="SA")//if the question type is SA than this condition is true.
		{ 
		  QSA*ptr=new QSA;//node of QSA class is created to store question in short answers list
		  ptr->question_type=Type;//ptr is the pointer of the node.
		    getline(quesbank,correct_ans);
		    cout<<endl<<"Answer: ";
			cin>>us_input;
			sample<<endl<<us_input;
		if(us_input==correct_ans){//if the answer is correct 20 pointsa will be added.
		ptr->point_gained=20;
		que(20);
	}
		else if(us_input=="skip"){//if user type skip question will be skipped.
			ptr->point_gained=0;
			exam_total=exam_total-pints;
	}
		else{//if the answer is incorrect 20 points will be deducted from total.
		    ptr->point_gained=-20;
		    que(-20);
	}	
		ptr->question_points=pints;
		ptr->question=questions;
		ptr->correct_answer=correct_ans;
		ptr->user_input=us_input;
		ptr->next=NULL;//every time NULL will be stored in next of current node.
	if(First_SA==NULL){//if first node is empty data will b e stored in first node means head.
		First_SA=ptr;
		Last_SA=ptr;
		ptr->prev=First_SA;
		}
		else//if first node is not empty data will b e stored in next node .
		{
			ptr->next=NULL;
			ptr->prev=Last_SA;
			ptr->prev=NULL;
			Last_SA->next=ptr;
			Last_SA=ptr;
		}
	}
	if(Type=="TF")//every thing is same as of above if(Typpe=="SA").
		{ 
		
		  QTF*ptr=new QTF;
		  
		  ptr->question_type=Type;
		    getline(quesbank,correct_ans);
		    cout<<endl<<"Answer: ";
			cin>>us_input;
			sample<<endl<<us_input;
		if(us_input==correct_ans){
		ptr->point_gained=5;
		que(5);
	}
		else if(us_input=="skip"){
			ptr->point_gained=0;
			exam_total=exam_total-pints;
	}
		else{
		    ptr->point_gained=-5;
		    que(-5);
	}	
		ptr->question_points=pints;
		ptr->question=questions;
		ptr->correct_answer=correct_ans;
		ptr->user_input=us_input;
	if(First_TF==NULL){
		ptr->next=NULL;
		First_TF=ptr;
		Last_TF=ptr;
		ptr->prev=First_TF;
		}
		else
		{
			ptr->next=NULL;
			ptr->prev=Last_TF;
			ptr->prev=NULL;
			Last_TF->next=ptr;
			Last_TF=ptr;
		}
	}
	if(Type=="MC")//every thing is same as of above if(Typpe=="SA").
		{ 
		
		  QMC*ptr=new QMC;
		  ptr->question_type=Type;
		  //beacuse mcqs have 4 otions so we are reading   options here.
		    getline(quesbank,A);
			getline(quesbank,B);
			getline(quesbank,C);
			getline(quesbank,D);
		    getline(quesbank,correct_ans);
		    cout<<endl<<"A) "<<A;
		    cout<<endl<<"B) "<<B;
		    cout<<endl<<"C) "<<C;
		    cout<<endl<<"D) "<<D<<endl<<"Answer: ";
		    sample<<endl<<"A) "<<A;
		    sample<<endl<<"B) "<<B;
		    sample<<endl<<"C) "<<C;
		    sample<<endl<<"D) "<<D<<endl<<"Answer: ";
			cin>>us_input;
			sample<<endl<<us_input;
		if(us_input==correct_ans){
		ptr->point_gained=10;
		que(10);
	}
		else if(us_input=="skip"){
			ptr->point_gained=0;
			exam_total=exam_total-pints;
	}
		else{
		    ptr->point_gained=-10;
		    que(-10);
	}	
	    ptr->a=A;
	    ptr->b=C;
	    ptr->c=B;
	    ptr->d=D;
		ptr->question_points=pints;
		ptr->question=questions;
		ptr->correct_answer=correct_ans;
		ptr->user_input=us_input;
if(First_MC==NULL){
		ptr->next=NULL;
		First_MC=ptr;
		Last_MC=ptr;
		ptr->prev=First_MC;
		}
		else
		{
			ptr->next=NULL;
			ptr->prev=Last_MC;
			ptr->prev=NULL;
			Last_MC->next=ptr;
			Last_MC=ptr;
		}
	}
	if(us_input==correct_ans){
		sample<<endl<<"Correct! Answer you scored 10  points";
	}
		else if(us_input=="skip"){
	}
		else{
		    sample<<endl<<"Incorrect! Answer\nCorrect answer was  "<<correct_ans<<"\nYou scored -10  points";
	}
		
		}
	}
	void display(){//this function is to have a quick review \
	                which question is correct and which is incorrect\
					also which one is skippped.
    cout<<endl<<"REview: ";
    int i=0;
    QSA*ptr=new QSA;//a node is  created
    ptr=First_SA;//node is initilazied with first node o short answer link list.
    while(ptr!=NULL){//loop will continue untill it \
	                   crosses the last node which is storing null
    	i++;
    	if(ptr->correct_answer==ptr->user_input){
    	cout<<endl<<"Q no."<<i<<" is correct.(Short Answer +20 Marks)";	
		}
		else if(ptr->user_input=="skip"){
			cout<<endl<<"Q no."<<i<<" was skipped (Short Answer)";
		}
		else{
			cout<<endl<<"Q no."<<i<<" is incorrect.(Short Answer -20 Marks)";	
		}
		ptr=ptr->next;
	}
	QTF*ptr2=new QTF;//a node is  created
    ptr2=First_TF;//node is initilazied with first node o True False linked list.
    while(ptr2!=NULL){//loop will continue untill it \
	                   crosses the last node which is storing null
    	i++;
    	if(ptr2->correct_answer==ptr2->user_input){
    	cout<<endl<<"Q no."<<i<<" is correct.(True/False  +5 marks).";	
		}
		else if(ptr2->user_input=="skip"){
			cout<<endl<<"Q no."<<i<<" was skipped (True/False)";
		}
		else{
			cout<<endl<<"Q no."<<i<<" is incorrect.(True/False  -5 marks).";	
		}
		ptr2=ptr2->next;
	}
	QMC*ptr3=new QMC;//new node created
    ptr3=First_MC;//node is initilazied with first node of MCQS linked list.
    while(ptr3!=NULL){//loop will continue untill it \
	                   crosses the last node which is storing null
    	i++;
    	if(ptr3->correct_answer==ptr3->user_input){
    	cout<<endl<<"Q no."<<i<<" is correct.(MCQS  +10 marks).";	
		}
		else if(ptr3->user_input=="skip"){
			cout<<endl<<"Q no."<<i<<" was skipped (MCQS)";
		}
		else{
			cout<<endl<<"Q no."<<i<<" is incorrect.(MCQS  -10 marks).";	
		}
		ptr3=ptr3->next;
	}
}
		
		};//Here the class is ended
int main(){//Main function.
	sample.open("Exam Review.txt",ios::out);//this creats and opens the file with name sample.
quesbank.open("Question Bank.txt",ios::in);//this opens the existing file quesbank.which stores the questions.
			quizzer user1;//object of class quizzer is created with name user1.
			user1.user();//fuction calling.
			user1.questios();//another function calling
			cout<<endl;
			system("pause");//this statement is used to pause the screen untill \
			                user presses any key screen will ber paused
			user1.display();//Display function calling
cout<<endl<<"Total Points scored by User= ";
sample<<endl<<endl<<"\nTotal Points scored by User: ";
int total=0;
for(int i=0;i<15;i++)//loop is used to calculate the total sum  of points gained by the user.
 total=total+user1.queue[i];//each index of que is added in total.
 cout<<total<<" Out of "<<user1.exam_total;
 sample<<total<<" Out of "<<user1.exam_total;//exam total is the total sum of marks of all question\
                                              attempted by the user.
}

