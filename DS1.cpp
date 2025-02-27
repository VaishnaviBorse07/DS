#include <iostream>
using namespace std;

class stud {
public:
    stud *lc, *rc;
    int rollno;
    string name;
    string surname;
    void create();
    void insert(stud *root, stud *next);
    void display(stud *root);
    void displayparent(stud *root);
    void displayleaf(stud *root);
    int calculatelength(stud *root);
    void displaypreorder(stud *root);
    void displaypostorder(stud *root);
    void mirrorimage(stud *root);
    void updatetree(stud *root);
    void search(stud *root, int k);
    void displayLeft(stud *root);
    void displayRight(stud *root);
} *root = NULL, t, *stack[100];

void stud::create() {
    int ch;
    root = new stud;
    cout << "Enter the name of the student:";
    cin >> root->name;
    cout << "Enter the surname of the student:";
    cin >> root->surname;
    cout << "Enter the rollno of the student:";
    cin >> root->rollno;
    root->lc = NULL;
    root->rc = NULL;

    do {
        cout << "Do you want to insert another node press 1 for yes and 0 for no:";
        cin >> ch;
        if (ch == 1) {
            stud *next = new stud;
            cout << "Enter the name of the next student:";
            cin >> next->name;
            cout << "Enter the surname of the student:";
            cin >> next->surname;
            cout << "Enter the rollno of the next student:";
            cin >> next->rollno;
            next->lc = next->rc = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}

void stud::insert(stud *root, stud *next) {
    char choice;
    cout << "Enter on which side of " << root->rollno << " do you want to insert new node (l/r):";
    cin >> choice;
    if (choice == 'l' || choice == 'L') {
        if (root->lc == NULL) {
            root->lc = next;
        } else {
            insert(root->lc, next);
        }
    } else if (choice == 'r' || choice == 'R') {
        if (root->rc == NULL) {
            root->rc = next;
        } else {
            insert(root->rc, next);
        }
    }
}

void stud::display(stud *root) {
    int top = -1;
    stud *temp = root;
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
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->surname << endl;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}

void stud::displayparent(stud *root) {
    if (root == NULL) {
        return;
    }
    if (root->lc != NULL || root->rc != NULL) {
        cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
    }
    displayparent(root->lc);
    displayparent(root->rc);
}

void stud::displayleaf(stud *root) {
    if (root == NULL) {
        return;
    }
    if (root->lc == NULL && root->rc == NULL) {
        cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
    }
    displayleaf(root->lc);
    displayleaf(root->rc);
}

void stud::displaypreorder(stud *root) {
    if (root == NULL) {
        return;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << endl;
    displaypreorder(root->lc);
    displaypreorder(root->rc);
}

void stud::displaypostorder(stud *root) {
    if (root == NULL) {
        return;
    }
    displaypostorder(root->lc);
    displaypostorder(root->rc);
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << endl;
}

int stud::calculatelength(stud *root) {
    if (root == NULL) {
        return 0;
    }
    int lht = calculatelength(root->lc);
    int rht = calculatelength(root->rc);
    return max(lht, rht) + 1;
}

void stud::mirrorimage(stud *root) {
    if (root == NULL) {
        return;
    }
    mirrorimage(root->lc);
    mirrorimage(root->rc);
    stud *temp = root->lc;
    root->lc = root->rc;
    root->rc = temp;
}

void stud::updatetree(stud *root) {
    if (root == NULL) {
        return;
    }
    int Rollno;
    string newname, newsurname;
    cout << "Enter rollno:";
    cin >> Rollno;
    cout << "Enter new name:";
    cin >> newname;
    cout << "Enter new surname:";
    cin >> newsurname;
    if (root->rollno == Rollno) {
        root->name = newname;
        root->surname = newsurname;
        return;
    }
    updatetree(root->lc);
    updatetree(root->rc);
}

void stud::search(stud *root, int k) {
    if (root == NULL) {
        return;
    }
    if (root->rollno == k) {
        cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\n";
        return;
    }
    search(root->lc, k);
    search(root->rc, k);
}

void stud::displayLeft(stud *root) {
    if (root == NULL) {
        return;
    }
    displayLeft(root->lc);
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\n";
}

void stud::displayRight(stud *root) {
    if (root == NULL) {
        return;
    }
    displayRight(root->rc);
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Insert a node\n2.Display\n3.Display Parent Nodes\n4.Display Leaf Nodes\n5.Display Tree Height\n6.Display Preorder\n7.Display Postorder\n8.Mirror Image\n9.Update Tree\n10.Search Node\n11.Display Left Nodes\n12.Display Right Nodes\nEnter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            t.create();
            break;
        case 2:
            t.display(root);
            break;
        case 3:
            t.displayparent(root);
            break;
        case 4:
            t.displayleaf(root);
            break;
        case 5:
            if (root != NULL) {
                int height = t.calculatelength(root);
                cout << "Height of the tree is " << height << endl;
            }
            break;
        case 6:
            t.displaypreorder(root);
            break;
        case 7:
            t.displaypostorder(root);
            break;
        case 8:
            t.mirrorimage(root);
            break;
        case 9:
            t.updatetree(root);
            break;
        case 10:
            int k;
            cout << "Enter roll number to search:";
            cin >> k;
            t.search(root, k);
            break;
        case 11:
            t.displayLeft(root);
            break;
        case 12:
            t.displayRight(root);
            break;
        }
    } while (ch != 0);
    return 0;
}