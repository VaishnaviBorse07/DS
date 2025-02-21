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
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << "\t" << temp->cet << "\n";
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}

int main() {
    int ch;
    do {
        cout << "\n1.Insert a node\n2.Display\nEnter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            t.create();
            break;
        case 2:
            t.display(root);
            break;
        }
    } while (ch != 0);
    return 0;
}