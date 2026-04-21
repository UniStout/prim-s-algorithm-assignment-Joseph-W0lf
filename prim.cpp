//All procedures including main


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int n; // Number of nodes in the tree
int v; // Number of verticies on the nodes
vector<vector<int>> adjMatrix; // Spanning Tree Graph


int printGraph() {
    // Prints the Matrix to the Terminal
    cout << endl;
    cout << "    ";
    for (int x = 0; x < n; x++) {
        cout << x << " ";
    }
    cout << endl << "   ";
    for (int x = 0; x < n; x++) {
        cout << "--";
    }
    cout << "-" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " | ";
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


int printMST() {
    int root = 0;
    int left = 1;
    int right = 2;

    cout << endl;
    cout << "    " << static_cast<char>('A' + root) << endl;
    cout << "  " 
         << static_cast<char>('A' + left)
         << "   "
         << static_cast<char>('A' + right)
         << endl;

    return 0;
}

int main() {
    cout << "\n"; // Creates a gap between output and bash
    ifstream Input ("Input.txt");
    if (!Input) {
        cout << "File Not found" << endl;
    }
    Input >> n >> v;
    adjMatrix = vector<vector<int>>(n, vector<int>(n, 0)); 

    // Fills in the Matrix from Input.txt
    int x, y, w; 
    int max = 0;
    for (int i = 0; i < n; i++) {
        Input >> x;
        Input >> y;
        Input >> w;
        if (w > max) {
            max = w;
        }
        adjMatrix[x][y] = w;
        adjMatrix[y][x] = w;
    }

    printGraph();

    for (int i = 0; i < n; i++) {
        int low = max;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] != 0 && adjMatrix[i][j] < low) {
                low = adjMatrix[i][j];
            }
        }
        cout << "Row " << i + 1 << ": " << low << endl;
    }


    char currNode = 'A';

    printMST();

    cout << endl << "End of Code" << endl;
}

/* Prims algoirhtm
 - Take a tree
 - Start at node one
 - Loop Below Until Finished:
 - Check connections of node
 - Create link with lowest path value
 - Move to that node
 - If node has no unvisited nodes, check sequencially for new node
 */