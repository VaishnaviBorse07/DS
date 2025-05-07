/*A student record system is software application used to manage student record including student info ,its 10 and 12 result,
hash table can be udes as a data structure to efficiently store or retrive and student record*/

#include<iostream>
using namespace std;

int key[100],chain[100],n,hash_size;
class student{
    int per,prn;
    string name;

    public:
    void Table();
    void accept();
    void display();
    void search();
    void update();
    void delete_record();
}h[100];

void student :: Table()
{
    cout<<"\nEnter the number of keys:";
    cin>>n;

    cout<<"\nEnter the key (PRN number):";
    for(int i=0;i<n;i++){
        cin >> key[i];
    }
    cout <<"\nEnter size of hash table:";
    cin>> hash_size;

    for(int i=0;i<hash_size;i++)
    {
        h[i].prn = -1;
        chain[i] = -2;
    }
}

void student::display()
{
    cout<<"\nLoc\tPRN\tname\tPer\tchain\n";
    for(int i=0;i<hash_size;i++)
    {
        cout<<"\n"<<i<<"\t"<<h[i].prn<<"\t"<<h[i].name<<"\t"<<h[i].per<<"\t"<<chain[i];
    }
}

void student :: accept()
{
    int loc;
    for(int i=0;i<n;i++)
    {
        loc = key[i]%10;
        int originalLoc = loc;

        while (h[loc].prn != -1) 
        {
            loc = (loc + 1) % hash_size;
            if (loc == originalLoc) 
            {
                cout << "\nHash table is full!";
                return;
            }
        }

        h[loc].prn = key[i];
        cout << "\nEnter the details of student:";
        cin >> h[loc].name >> h[loc].per;

        int hashIndex = key[i] % hash_size;
        if (loc != hashIndex) {
            while (chain[hashIndex] != -2)
                hashIndex = chain[hashIndex];
            chain[hashIndex] = loc;
        }
}
}

void student ::search()
{
    int p,flag=0;
    cout<<"\nEnter the prn to search:";
    cin>>p;
   
    for(int i=0;i<hash_size;i++)
    {
        if(p == h[i].prn)
        {
            cout<<"\nLoc\tID\tname\tadd\n";
            flag = 1;
            cout<<"\n"<<i<<"\t"<<h[i].prn<<"\t"<<h[i].name<<"\t"<<h[i].per<<"\n";
            break;
        }
    }

    if(flag == 0)
    {
        cout<<"\nStudent record not found!\n";
    }
}

void student :: update()
{
    int p,flag=0;
    cout<<"\nEnter the prn of student whose record you want to update:";
    cin>>p;

    for(int i=0;i<hash_size;i++)
    {
        if(p == h[i].prn)
        {
            cout<<"\nLoc\tID\tname\tPer\n";
            flag = 1;
            cout<<"\n"<<i<<"\t"<<h[i].prn<<"\t"<<h[i].name<<"\t"<<h[i].per;

            cout<<"\nEnter the new details:";
            cin >> h[i].name >> h[i].per;
        }
    }

    if(flag == 0)
    {
        cout<<"\nStudent record not found!\n";
    }
}

void student::delete_record()
{
    int p, flag = 0;
    cout << "\nEnter the PRN of the student whose record you want to delete: ";
    cin >> p;

    for (int i = 0; i < hash_size; i++)
    {
        if (h[i].prn == p)
        {
            cout << "\nLoc\tPRN\tName\tPer\n";
            cout << i << "\t" << h[i].prn << "\t" << h[i].name << "\t" << h[i].per;

            // Clear student record
            h[i].prn = -1;
            h[i].name = "";
            h[i].per = 0;

            
            for (int j = 0; j < hash_size; j++) {
                if (chain[j] == i) {
                    chain[j] = -2; 
                    break;
                }
            }
            chain[i] = -2; // Reset own chain value

            cout << "\nRecord deleted successfully!\n";
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        cout << "\nStudent record not found!\n";
    }
}

int main()
{
    student s;
    int choice;

    do{
    cout<<"\n1.Accept The details\n2.display the hash table\n3.Apply the hash function\n4.search the student record\n5.Update the record student\n6.Delete the record\n";
    cout<<"\nEnter the choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        s.Table();
        break;

        case 2:
        s.display();
        break;

        case 3:
        s.accept();
        break;

        case 4:
        s.search();
        break;

        case 5:
        s.update();
        break;

        case 6:
        s.delete_record();
        break;
    }

    }while(choice != 0);

    return 0;

}