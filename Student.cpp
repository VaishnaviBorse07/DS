#include <iostream>
#include <string> 
using namespace std;

class student {
    int rollno;
    string name, add;
    student* LC; 
    student* RC; 
public:
    void create();
    void insert(student* root, student* next);
    void display(student* root);
    void displayleaf(student* root);
    void displayroot(student* root);
} *root = NULL,*st[100],e;

void student::create() {
    int ch;
    root = new student; 
    cout << "Enter student Information (rollno name address): ";
    cin >> root->rollno >> root->name >> root->add;

    do {
        cout << "Do you want to continue (Yes=1/No=0): ";
        cin >> ch;
        if (ch == 1) {
            student* next = new student;
            cout << "Enter new student Information (rollno name address): ";
            cin >> next->rollno >> next->name >> next->add;
            insert(root, next); 
        }
    } while (ch == 1);
}

void student::insert(student* root, student* next) {
    char ch1;
    cout << "Where do you want to insert " << next->rollno<< " L or R: ";
    cin >> ch1;
    if (ch1 == 'L' || ch1 == 'l') {
        if (root->LC == NULL) { 
            root->LC = next;
        } else {
            insert(root->LC, next);
        }
    } else if (ch1 == 'R' || ch1 == 'r') { 
        if (root->RC == NULL) {
            root->RC = next;
        } else {
            insert(root->RC, next);
        }
    } else {
        cout << "Invalid choice! Please enter L or R." << endl;
    }
}

void student::display(student* root) {
    /*if (root == NULL) {
        return;
    } else {
        display(root->LC);
        cout << "\n" << root->id << "\t" << root->name << "\t" << root->add << "\t" << root->salary;
        display(root->RC);
    }*/
    int top=-1;
    student *temp;
    temp=root;
    if(root!=NULL)
    {
      do{
      while(temp!=NULL){
      top++;
      st[top]=temp;
      temp=temp->LC;
      }
      if(top!=-1)
      {
        temp=st[top];
        top--;
        cout<<"\n"<<temp->rollno<<"\t"<<temp->name<<"\t"<<temp->add;
        temp=temp->RC;
        }
        }while(top!=-1||temp!=NULL);
        }
        
}
void student::displayleaf(student* root) {
    int top=-1;
    student *temp;
    temp=root;
    if(root!=NULL)
    {
      do{
      while(temp!=NULL){
      top++;
      st[top]=temp;
      temp=temp->LC;
      }
      if(top!=-1)
      {
        temp=st[top];
        top--;
        if(temp->LC==NULL&&temp->RC==NULL){
        cout<<"\n"<<temp->rollno<<"\t"<<temp->name<<"\t"<<temp->add;}
        temp=temp->RC;
      }
     }while(top!=-1||temp!=NULL);
    }
        
}
void student::displayroot(student* root) {
    int top=-1;
    student *temp;
    temp=root;
    if(root!=NULL)
    {
      top++;
      st[top]=temp;
      cout<<"\n"<<temp->rollno<<"\t"<<temp->name<<"\t"<<temp->add;
    }
        
}
int main() {
    int choice;
    do {
        cout << "\nMenu\n1.Create\n2.Display\n3.Display Leaf node\n4.Display Leaf node\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                e.create();
                break;
            case 2:
                cout << "\n" << "Roll NO" << "\t" << "Name" << "\t" << "Address";	
                e.display(root);
                break;
            case 3:
                cout << "\n" << "Roll NO" << "\t" << "Name" << "\t" << "Address";	
                e.displayleaf(root);
                break;
            case 4:
                cout << "\n" << "Roll NO" << "\t" << "Name" << "\t" << "Address";	
                e.displayroot(root);
                break;
           case 5:
                exit(0);
                break;
            default:
                cout << "Invalid choice!" << endl; 
                break;
        }
    } while (choice != 5);
    return 0;
}
