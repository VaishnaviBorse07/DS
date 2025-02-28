#include <iostream>
using namespace std;

class sms {
public:
    sms *lc, *rc;
    int rollno, cet;
    string name;
    string add;
    void create();
    void insert(sms *root, sms *next);
    void display(sms *root);
    void displayparent(sms *root);
    void displayleaf(sms *root);
    void postorder(sms *root);
    void displayLeft(sms *root);
    void displayRight(sms *root);
    void search(sms *root, int rollno);
    void deleteNode(sms *&root, int rollno);
    sms* minValueNode(sms *node);
} *root = NULL, t, *stack[100];

void sms::create() {
    int ch;
    root = new sms;
    cout << "Enter the name of the student:";
    cin >> root->name;
    cout << "Enter the address of the student:";
    cin >> root->add;
    cout << "Enter the rollno of the student:";
    cin >> root->rollno;
    cout << "Enter the cet of the student:";
    cin >> root->cet;
    root->lc = NULL;
    root->rc = NULL;

    do {
        cout << "Do you want to insert another node press 1 for yes and 0 for no:";
        cin >> ch;
        if (ch == 1) {
            sms *next = new sms;
            cout << "Enter the name of the next student:";
            cin >> next->name;
            cout << "Enter the address of the student:";
            cin >> next->add;
            cout << "Enter the rollno of the next student:";
            cin >> next->rollno;
            cout << "Enter the cet of the student:";
            cin >> next->cet;
            next->lc = next->rc = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}

void sms::insert(sms *root, sms *next) {
    if (next->cet > root->cet) {
        if (root->lc == NULL) {
            root->lc = next;
        } else {
            insert(root->lc, next);
        }
    } else {
        if (root->rc == NULL) {
            root->rc = next;
        } else {
            insert(root->rc, next);
        }
    }
}
void sms::displayparent(sms *root) {
    if (root == NULL) {
        return;
    }
    if (root->lc != NULL || root->rc != NULL) {
        cout << root->name << "\t" << root->add << "\t" << root->rollno <<"\t" << root->cet<< endl;
    }
    displayparent(root->lc);
    displayparent(root->rc);
}

void sms::displayleaf(sms *root) {
    if (root == NULL) {
        return;
    }
    if (root->lc == NULL && root->rc == NULL) {
         cout << root->name << "\t" << root->add << "\t" << root->rollno <<"\t" << root->cet<< endl;
    }
    displayleaf(root->lc);
    displayleaf(root->rc);
}
void sms::display(sms *root) {
    int top = -1;
    sms *temp = root;
    if (root != NULL) {
        do {
            while (temp != NULL) {
                top++;
                stack[top] = temp;
                temp = temp->lc;
            }
            if (top != -1) {
                temp = stack[top];
                top--;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << "\t" << temp->cet;
                if (temp->cet >= 90) {
                    cout << "\tIIT\n";
                } else {
                    cout << "\tNon-IIT\n";
                }
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}
void sms::postorder(sms *root){
sms *arr[100];
int top = -1,i=0,j=0;
    sms *temp = root;
    if (root != NULL) {
        do {
            while (temp != NULL) {
                arr[i]=temp;
                i++;
                top++;
                stack[top] = temp;
                temp = temp->rc;
            }
            if (top != -1) {
                temp = stack[top];
                temp = temp->lc;
                top--;   
            }
    } while (temp != NULL || top != -1);

    for(j=i-1;j>=0;j--)
    {
    cout <<"\n"<< arr[j]->rollno << "\t" << arr[j]->name << "\t" << arr[j]->add << "\t" << arr[j]->cet;
    }
  }
    
}
void sms::displayLeft(sms *root) {
    if (root == NULL) {
        return;
    }
    displayLeft(root->lc);
    cout << root->rollno << "\t" << root->name << "\t" << root->add << "\t" << root->cet << "\t";
    if (root->cet > 90) {
        cout << "IIT\n";
    } else {
        cout << "Non-IIT\n";
    }
}

void sms::displayRight(sms *root) {
    if (root == NULL) {
        return;
    }
    displayRight(root->rc);
    cout << root->rollno << "\t" << root->name << "\t" << root->add << "\t" << root->cet << "\t";
    if (root->cet > 90) {
        cout << "IIT\n";
    } else {
        cout << "Non-IIT\n";
    }
}

void sms::search(sms *root, int rollno) {
    if (root == NULL) {
        cout << "Student not found\n";
        return;
    }
    if (root->rollno == rollno) {
        cout << "Student found: " << root->name << "\n";
        return;
    }
    if (root->rollno < rollno)
        search(root->rc, rollno);
    else
        search(root->lc, rollno);
}

sms* sms::minValueNode(sms *node) {
    sms *current = node;
    while (current && current->lc != NULL)
        current = current->lc;
    return current;
}

void sms::deleteNode(sms *&root, int rollno) {
    if (root == NULL)
        return;
    if (rollno < root->rollno)
        deleteNode(root->lc, rollno);
    else if (rollno > root->rollno)
        deleteNode(root->rc, rollno);
    else {
        if (root->lc == NULL) {
            sms *temp = root->rc;
            delete root;
            root = temp;
        } else if (root->rc == NULL) {
            sms *temp = root->lc;
            delete root;
            root = temp;
        } else {
            sms *temp = minValueNode(root->rc);
            root->rollno = temp->rollno;
            root->name = temp->name;
            root->add = temp->add;
            root->cet = temp->cet;
            deleteNode(root->rc, temp->rollno);
        }
    }
}

int main() {
    int ch;
    do {
        cout << "\n1.Insert a node\n2.Display\n3.Display Left Nodes\n4.Display Right Nodes\n5.Search\n6.Delete\n7.Postorder\n8.display parent\n9.diplay leaf\nEnter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            t.create();
            break;
        case 2:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.display(root);
            break;
        case 3:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.displayLeft(root);
            break;
        case 4:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.displayRight(root);
            break;
        case 5: {
            int rollno;
            cout << "Enter roll number to search:";
            cin >> rollno;
            t.search(root, rollno);
            break;
        }
        case 6: {
            int rollno;
            cout << "Enter roll number to delete:";
            cin >> rollno;
            t.deleteNode(root, rollno);
            break;
        }
        case 7:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.postorder(root);
            break;
        case 8:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.displayparent(root);
            break;
        case 9:cout << "rollno" << "\t" << "name" << "\t" << "address" << "\t" << "cet"<< "\n";
            t.displayleaf(root);
            break;
        }
    } while (ch != 0);
    return 0;
}
