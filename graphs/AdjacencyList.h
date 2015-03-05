/*
+-----------------------------------------------------------------------+
| C++ Code Adjancency List                                              |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <vector>
using namespace std;

// undirected graph
class AdjMatrix
{
private:
    int vCount;
    vector< vector<int> > adj;
public:
    AdjMatrix(int _vCount): vCount(_vCount) {
        adj.resize(_vCount);
    }

    ~AdjMatrix() {
        for (unsigned int i = 0; i < adj.size(); i++)
            adj[i].clear();
        adj.clear();
    }

    void addEdge(int v, int w) {
        adj[v].push_back(v);
        adj[w].push_back(w);
    }

    vector<int>& vList(int v) {
        return adj[v];
    }

    bool isConnected(int v, int w) {
        unsigned int i;
        for (i = 0; i < adj[v - 1].size(); i++)
            if (adj[v - 1][i] == w)
                return true;
        for (i = 0; i < adj[w - 1].size(); i++)
            if (adj[w - 1][i] == v)
                return true;
        return false;
    }

    int getvCount() const {
        return vCount;
    }
};

/*
int main() {
    int vCount = 14;
    AdjMatrix uGraph(vCount);
    uGraph.addEdge(1, 2);
    uGraph.addEdge(2, 3);
    uGraph.addEdge(3, 4);
    uGraph.addEdge(4, 5);
    uGraph.addEdge(6, 7);
    uGraph.addEdge(7, 8);
    uGraph.addEdge(8, 1);

    if (uGraph.isConnected(7, 6))
        cout << "6, 7 are connnected" << endl;
    else
        cout << "6, 7 are not connected" << endl;

    cout << "vCount: " << uGraph.getvCount() << endl;
    uGraph.~AdjMatrix();
	return 0;
}
*/
