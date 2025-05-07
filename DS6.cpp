#include<iostream>
using namespace std;

int n, key[10], c[10];

class medical {
    int age, height, weight;
    string name, address;
public:
    void Table();
    void accept();
    void display();
    void update();
    void deletet();
} m[10];

medical h[10];

void medical::Table() {
    cout << "Enter number of Keys: ";
    cin >> n;
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> key[i];
    }
}

void medical::display() {
    cout << "\nloc\tname\taddress\tage\theight\tweight\n";
    for (int i = 0; i < 10; i++) {
        if (!h[i].name.empty()) { 
            cout << i << "\t" << h[i].name << "\t" << h[i].address << "\t" 
                 << h[i].age << "\t" << h[i].height << "\t" << h[i].weight << endl;
        }
    }
}

void medical::accept() {
    Table();
    int loc;
    cout << "Enter the details:\n";
    for (int i = 0; i < n; i++) {
        loc = key[i] % 10;
        while (!h[loc].name.empty()) { 
            loc = (loc + 1) % 10; 
        }
        cout << "Enter name: ";
        cin >> h[loc].name;
        cout << "Enter address: ";
        cin >> h[loc].address;
        cout << "Enter age: ";
        cin >> h[loc].age;
        cout << "Enter height: ";
        cin >> h[loc].height;
        cout << "Enter weight: ";
        cin >> h[loc].weight;
        key[loc] = key[i]; 
    }
}

void medical::update() {
    int k, loc, start;
    cout << "Enter the key to update: ";
    cin >> k;
    loc = k % 10;
    start = loc; 
    while (!h[loc].name.empty() && key[loc] != k) {
        loc = (loc + 1) % 10;
        if (loc == start) { 
            cout << "Record not found.\n";
            return;
        }
    }
    if (!h[loc].name.empty()) {
        cout << "Enter new details:\n";
        cout << "Enter name: ";
        cin >> h[loc].name;
        cout << "Enter address: ";
        cin >> h[loc].address;
        cout << "Enter age: ";
        cin >> h[loc].age;
        cout << "Enter height: ";
        cin >> h[loc].height;
        cout << "Enter weight: ";
        cin >> h[loc].weight;
    } else {
        cout << "Record not found.\n";
    }
}

void medical::deletet() {
    int k, loc, start;
    cout << "Enter the key to delete: ";
    cin >> k;
    loc = k % 10;
    start = loc; 
    while (!h[loc].name.empty() && key[loc] != k) { 
        loc = (loc + 1) % 10;
        if (loc == start) { 
            cout << "Record not found.\n";
            return;
        }
    }
    if (!h[loc].name.empty()) {
        h[loc] = medical();
        key[loc] = 0; 
        cout << "Record deleted.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    medical m;
    int choice;
    do {
        cout << "1. Accept details\n";
        cout << "2. Display details\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: m.accept();
                    break;
            case 2: m.display();
                    break;
            case 3: m.update();
                    break;
            case 4: m.deletet();
                    break;
            case 5: exit(0);
                    break;
            default: cout << "Invalid choice\n";
                     break;
        }
    } while (choice != 5);
    return 0;
}