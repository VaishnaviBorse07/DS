#include<iostream>
using namespace std;

class emp
{
  public: 
  int id,name;
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
  cout<<"enter id and name of emp:";
  cin>>root->id>>root->name ;
  root->LC=root->RC=NULL;
  do{
  cout<<"do you want to continued (0/1):";
  cin>>ch;
 	if(ch==1) {
    next=new emp;
    cout<<"enter new info:";
    cin>>next->id>>next->name;
    next->RC=next->LC=NULL;
    insert(root,next);
    }
    }while(ch==1);
    }

void emp::insert(emp*root,emp*next)
{
int ch1;
cout<<"where you want to insert"<<root->id<<"\t L or R";
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
  
  else if (ch1='R'||ch1=='r'){
  
   if (root->RC==NULL) 
   {
   root->RC=next;
    } else 
  { 
   insert(root->RC,next);
 	 }
 	}
 	}
 
 void emp::display(emp*root)
  {
  if(root==NULL)

 return ;		

 else {
 	cout<<"\n"<<root->id<<"\t"<<root->name;
 	display(root->RC);
 	}
  }
  int main()
  {
  int choice;
  do{
  cout<<"\n1.create\n2.insert\n3.display";
  cout<<"enter your choice";
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
  }
  while(choice!=3);
 return 0;
 }
