#include <iostream>
using namespace std;

class ps
{
    int v;
    string city[10];
    int adj[10][10];

public:
    void accept();
    void sp();
};

void ps::accept()
{
    cout << "Enter Number of locations: ";
    cin >> v;
    cout << "Enter Location names:\n";
    for (int i = 0; i < v; i++)
    {
        cin >> city[i];
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else if (i < j)
            {
                adj[i][j] = 999;
            }
            else
            {
                adj[i][j] = adj[j][i];
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            cout << "Enter distance between " << city[i] << " and " << city[j] << ": ";
            cin >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }
}

void ps::sp()
{
    int dist[10], visited[10];
    int start = 0;

    for (int i = 0; i < v; i++)
    {
        dist[i] = 999;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < v - 1; count++)
    {
        int minDist = 999, u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && adj[u][i] && dist[u] + adj[u][i] < dist[i])
            {
                dist[i] = dist[u] + adj[u][i];
            }
        }
    }
    cout << "\nShortest distances from " << city[start] << ":\n";
    for (int i = 0; i < v; i++)
    {
        cout << "To " << city[i] << ": " << dist[i] << endl;
    }
}

int main()
{
    ps p;
    int choice;
    do{
        cout << "Menu\n1. Accept\n2. Shortest Path\n3. Exit\nEnter your choice: "; 
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.accept();
            break;
        case 2:
            p.sp();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
