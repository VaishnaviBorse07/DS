#include <iostream>
#include <string> 
using namespace std;

class emp {
    int id, salary;
    string name, add;
    emp* LC; 
    emp* RC; 
public:
    void create();
    void insert(emp* root, emp* next);
    void display(emp* root);
} *root = NULL,e;

void emp::create() {
    int ch;
    root = new emp; 
    cout << "Enter Employee Information (id name address salary): ";
    cin >> root->id >> root->name >> root->add >> root->salary;

    do {
        cout << "Do you want to continue (Yes=1/No=0): ";
        cin >> ch;
        if (ch == 1) {
            emp* next = new emp;
            cout << "Enter New Employee information (id name address salary): ";
            cin >> next->id >> next->name >> next->add >> next->salary;
            insert(root, next); 
        }
    } while (ch == 1);
}

void emp::insert(emp* root, emp* next) {
    char ch1;
    cout << "Where do you want to insert " << next->id << " L or R: ";
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

void emp::display(emp* root) {
    if (root == NULL) {
        return;
    } else {
        display(root->LC);
        
        cout << "\n" << root->id << "\t" << root->name << "\t" << root->add << "\t" << root->salary;
        display(root->RC);
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu\n1.Create\n2.Display\n3.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                e.create();
                break;
            case 2:
                cout << "\n" << "Id" << "\t" << "Name" << "\t" << "Address" << "\t" << "Salary";	
                e.display(root);
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid choice!" << endl; 
                break;
        }
    } while (choice != 3);
    return 0;
}
