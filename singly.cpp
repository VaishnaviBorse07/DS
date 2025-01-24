#include <iostream>
using namespace std;

class emp {
    int id, sal;
    string name, add;
    emp *next;
public:
    void accept();
    void display();
    void ascen();
    void decen();
} *start = NULL,e;

void emp::accept() {
    emp *newnode, *temp;
    newnode = new emp;
    cout << "Enter Employee details (id name address salary): ";
    cin >> newnode->id >> newnode->name >> newnode->add >> newnode->sal;
    newnode->next = NULL;
    if (start == NULL) {
        start = newnode;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void emp::display() {
    emp *temp;
    temp = start;
    if (temp == NULL) {
        cout << "Employee details are empty" << endl;
    } else {
        while (temp != NULL) {
            cout << temp->id << "\t" << temp->name << "\t" << temp->add << "\t" << temp->sal << endl;
            temp = temp->next;
        }
    }
}

void emp::ascen() {
    if (start == NULL) {
        cout << "No employees to sort." << endl;
        return;
    }

    emp *i, *j;
    int tempId, tempSal;
    string tempName, tempAdd;

    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->sal > j->sal) {
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;
                
                tempName = i->name;
                j->name = tempName;
                i->name = j->name;
                
                tempAdd = i->add;
                i->add = j->add;
                j->add = tempAdd;
                
                tempSal = i->sal;
                i->sal = j->sal;
                j->sal = tempSal;    
            }
        }
    }

    display();
}

void emp::decen() {
    if (start == NULL) {
        cout << "No employees to sort." << endl;
        return;
    }

    emp *i, *j;
    int tempId, tempSal;
    string tempName, tempAdd;

    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->sal < j->sal) {
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;
                
                tempName = i->name;
                j->name = tempName;
                i->name = j->name;
                
                tempAdd = i->add;
                i->add = j->add;
                j->add = tempAdd;
                
                tempSal = i->sal;
                i->sal = j->sal;
                j->sal = tempSal;    
            }
        }
    }

    display();
}

int main() {
    int ch;
    do {
        cout << "\nMain Menu\n1.Accept\n2.Display\n3.Ascending\n4.Descending\nEnter Your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                e.accept();
                break;
            case 2:
                e.display();
                break;
            case 3:
                e.ascen();
                break;
            case 4:
                e.decen();
                break;
            default:
                break;
        }
    } while (ch != 0);

    return 0;
}

