#include <iostream>
using namespace std;
int count = 1;
class stud
{
public:
    stud *lc, *rc;
    int rollno;
    string name;
    string add;
    void create();
    void insert(stud *root, stud *next);
    void display(stud *root);
    void displayparent(stud *root);
    void displayleaf(stud *root);
    int height(stud *root);
    void displayinorder(stud *root);
    void displaypreorder(stud *root);
    void displaypostorder(stud *root);
    void mirrorimage(stud *root);
    void updatetree(stud *root);
} *root = NULL, t, *stack[100];
void stud::create()
{
    int ch;
    root = new stud;

    cout << "Enter the name of the student:";
    cin >> root->name;
    cout << "Enter the address of the student:";
    cin >> root->add;
    cout << "Enter the rollno of the student:";
    cin >> root->rollno;
    root->lc = NULL;
    root->rc = NULL;
    do
    {
        cout << "Do you want to insert another node press 1 or yes and 0 for no:";
        cin >> ch;
        if (ch == 1)
        {
            stud *next = new stud;
            cout << "Enter the name of the next student:";
            cin >> next->name;
            cout << "Enter the address of the student:";
            cin >> next->add;
            cout << "Enter the rollno of the next student:";
            cin >> next->rollno;
            next->lc = next->rc = NULL;
            insert(root, next);
            count++;
        }
    } while (ch == 1);
}
void stud::insert(stud *root, stud *next)
{
    char choice;
    cout << "Enter on which side of " << root->rollno << "do you want to insert new node(l/r)";
    cin >> choice;
    if (choice == 'l' || choice == 'L')
    {
        if (root->lc == NULL)
        {
            root->lc = next;
        }
        else
        {

            insert(root->lc, next);
        }
    }
    else if (choice == 'R' || choice == 'r')
    {
        if (root->rc == NULL)
        {
            root->rc = next;
        }
        else
        {
            insert(root->rc, next);
        }
    }
}
// void stud::display(stud *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     else
//     {
//         display(root->lc);
//         cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
//         display(root->rc);
//     }
// }
void stud::displayparent(stud *root)
{
    cout << root->name << "\t" << root->add << "\t" << root->rollno << endl;
}
void stud::displayleaf(stud *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lc == NULL && root->rc == NULL)
    {
        cout << root->name << "\t" << root->add << "\t" << root->rollno << endl;
    }
    displayleaf(root->lc);
    displayleaf(root->rc);
}
void stud::display(stud *root)
{
    stud *temp;
    temp = root;
    int top = -1;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                temp = temp->lc;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->rc;
            }
        }

        while (top != -1 || temp != NULL);
    }
}
void stud::displayinorder(stud *root)
{
    int top = -1;
    stud *temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                temp = temp->lc;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << endl;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}
void stud::displaypreorder(stud *root)
{
    int top = -1;
    stud *temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->lc;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}
void stud::displaypostorder(stud *root)
{
    int top = -1;
    stud *temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                temp = temp->lc;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->add << endl;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}
int stud::height(stud *root)
{
    int lht, rht, fht;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        lht = height(root->lc);
        rht = height(root->rc);
        if (lht > rht)
        {
            fht = lht + 1;
        }
        else
        {
            fht = rht + 1;
        }
    }
    return fht;
}
void stud::mirrorimage(stud *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorimage(root->lc);
        mirrorimage(root->rc);
        stud *temp = root->lc;
        root->lc = root->rc;
        root->rc = temp;
    }
}
void stud::updatetree(stud *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        int Rollno;
        string newname, newsurname;
        while (root != NULL)
        {
            if (root->rollno == Rollno)
            {
                cout << "Enter the new information for " << root->rollno;
                cin >> root->name >> root->add;
                root->name = newname;
                root->add = newsurname;
            }
            updatetree(root->lc);
            updatetree(root->lc);
        }
    }
}
int main()
{
    int ch;
    do
    {
        cout << "\n1.Insert a node\n2.Display\n3.Display parent only\n4.Display only leaf node\n5.Display the height of the tree\n6.Display by inorder\n7.Display by preorder\n8.Display post order\n9.Mirror image\n10.Update tree\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
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
            if (root != NULL)
            {
                int j = t.height(root);
                cout << "Height of the tree is " << j << endl;
            }
            break;
        case 6:
            t.displayinorder(root);
            break;
        case 7:
            t.displaypreorder(root);
            break;
        case 8:
            t.displaypostorder(root);
            break;
        case 9:
            t.mirrorimage(root);
            break;
        case 10:
            t.updatetree(root);
            break;
        }
    } while (ch != 0);
    return 0;
}