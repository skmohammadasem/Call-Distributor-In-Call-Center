#include<iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include<string.h>
using namespace std;
int i=0;
struct call
{
   int phno;
   char date[100];
   char time[100];
   int id;
   char lan[100];
   struct call *link;
};
struct call * front=NULL,*rear=NULL;
class Queue
{
   public:
       void insert();
       void delcall();
       void status();
};

void Queue::insert()
{
   struct call *p=new call();
   srand (time(NULL));
   time_t curr_time;
   time_t my_time = time(NULL);
   tm * curr_tm;
   time(&curr_time);
   curr_tm = localtime(&curr_time);
   cout<<endl<<"Call Details Insertion in Queue : "<<endl;
   cout<<"Enter the phone number : ";
   cin>>p->phno;
strftime(p->date, 50, " %B %d, %Y", curr_tm);
   cout<<"Date is : " <<p->date<<endl;
   strcpy(p->time,ctime(&my_time));
   cout<<"Time is : " <<p->time;
   cout<<"Enter the language : ";
   cin>>p->lan;
   p->id=(rand() % 10 + 1)+i;
   i++;
   p->link=NULL;
   if(rear==NULL)
   {
   front=p;
   }
   else
   {
       rear->link=p;
   }
   rear=p;
}

void Queue::delcall()
{
   if(front==NULL)
   {
       cout<<endl<<"Presently No such call is there to be routed for the agent "<<endl;

   }
   else
   {
       cout<<endl<<"Recently routed call to agent is:" <<endl;
       cout<<"Phone No : "<<front->phno<<endl;
       cout<<"Date : "<<front->date<<endl;
       cout<<"Call Time : "<<front->time;
       cout<<"Caller id : "<<front->id<<endl;
       cout<<"Caller Language : "<<front->lan<<endl;
       if(front==rear)
       {
           front=rear=NULL;
       }
       else
       {
           front=front->link;
       }
   }
}
void Queue:: status()
{
   int j;
   struct call *temp=front;
   if(front==NULL)
   cout<<endl<<"Presently No such call related activity is there"<<endl;
   else
   {
       cout<<endl<<"Caller information details : "<<endl;
       do
       {
       cout<<endl<<"Storred call details are:"<<endl;
       cout<<"Phone No : "<<temp->phno<<endl;
       cout<<"Date : "<<temp->date<<endl;
       cout<<"Call Time : "<<temp->time;
       cout<<"Caller id : "<<temp->id<<endl;
       cout<<"Caller Language : "<<temp->lan<<endl;
       temp=temp->link;
       cout<<endl;
       }
       while(temp!=NULL);
   }
}

main()
{
   cout<<" : Automatic Call Distributor or ACD :";
   cout<<endl<<"-----------------------------------------------------------"<<endl;
   cout<<endl<<" a new call arrives to the queue :";
   cout<<endl<<"a call leaves the queue (call has been routed to an agent) :";
   cout<<endl<<"simply do nothing (the state of the system remains the same) :"<<endl;
   int p;
   char ch;
   Queue ob;
   do
   {
   p=(rand() % 3 + 1);
   switch(p)
   {
       case 1:
       ob.insert();
       break;

       case 2:
       ob.delcall();
       break;

       case 3:
       ob.status();
       break;

   }
   cout<<endl<<"Want to continue:[y/Y]:";
   cin>>ch;
}
while(ch=='y' || ch=='Y');

}
