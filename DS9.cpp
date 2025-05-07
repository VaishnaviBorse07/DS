#include<iostream>
using namespace std;
#define n 10
int key[n];

class heap {
    public:
    int count = 0;

    void accept();
    void build(int value, int i, int key[]);
    void insert(int nkey);
    void display();
};

void heap::accept() {
    for (int i = 1; i <= n; i++) {
        cin >> key[i];
        count++;
        int value = key[i];
        build(value, count, key);
    }
}

void heap::build(int value, int i, int key[]) {
    key[i] = value;
    int loc = i;
    while (loc > 1) {
        int parent = loc / 2;
        if (key[parent] < key[loc]) {
            int temp = key[parent];
            key[parent] = key[loc];
            key[loc] = temp;
            loc = parent;
        } else {
            break;
        }
    }
}

void heap::display() {
    for (int i = 1; i <= count; i++) {
        cout << key[i] << "\t";
    }
    cout << endl;
}

void heap::insert(int nkey) {
    if (count >= n) {
        cout << "Heap is full, cannot insert more elements." << endl;
        return;
    }
    count++;
    key[count] = nkey;
    int loc = count;
    while (loc > 1) {
        int parent = loc / 2;
        if (key[loc] > key[parent]) {
            int temp = key[loc];
            key[loc] = key[parent];
            key[parent] = temp;
            loc = parent;
        } else {
            break;
        }
    }
}

int main() {
    heap h;
    int ch, value;
    do {
        cout << "1. Accept the keys\n2. Display the tree\n3. Insert one element in the key array\n4. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter " << n << " keys: ";
                h.accept();
                break;
            case 2:
                cout << "Heap elements: ";
                h.display();
                break;
            case 3:
                cout << "Enter the key to insert: ";
                cin >> value;
                h.insert(value);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (ch != 4);
    return 0;
}