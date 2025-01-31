#include<iostream>
using namespace std;

class emp
{ 
  int id,salary;
  string name,add;
  emp*LC,*RC;
  public:
  void create();
  void insert(emp*root,emp*next);
  void display(emp*root);
}*root,e;
  
void emp::create() 
{
 int ch;
 emp*next;
 root =new emp;
 cout<<"Enter Employee Information:";
 cin>>root->id>>root->name>>root->add>>root->salary;
 root->LC=root->RC=NULL;
 do{
    cout<<"Do you want to continue (Yes=1/No=0):";
    cin>>ch;
    if(ch==1) {
    next=new emp;
    cout<<"Enter New Employee information:";
    cin>>next->id>>next->name>>next->add>>next->salary;
    next->RC=next->LC=NULL;
    insert(root,next);
   }
   }while(ch==1);
}

void emp::insert(emp*root,emp*next)
{
  int ch1;
  cout<<"Where you want to insert"<<root->id<<"\t L or R";
  cin>>ch1;
  if(ch1=='L'||ch1=='l')
  {
    if(root->LC =NULL)
     { 
      root->LC=next;
     }
  else 
  {
    insert(root->LC,next);
  }
  }
  else if (ch1='R'||ch1=='r')
  { 
   if (root->RC==NULL) 
   {
   root->RC=next;
   }
   else 
   { 
   insert(root->RC,next);
   }
  }
}
 
void emp::display(emp*root)
{
  
}
int main()
{
  int choice;
  do{
  cout<<"\nMenu\n1.Create\n2.Display\n3.Exit";
  cout<<"Enter your choice";
  cin>>choice;
  switch(choice)
  {
  case 1:e.create();
  break;
  case 2:e.display(root);
  break;
  case 3:exit(0);
  break;
  }
  }while(choice!=3);
 return 0;
}

