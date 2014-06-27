/*
+-----------------------------------------------------------------------+
| C++ Code TopSort                                                      |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <list>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class dir_graph {
private:
    struct node {
        int indgree;
        list<int> outdgree;
    };
private:
    vector<node> adj_list;
    queue<int> toplogic; // order of vertex

public:
    dir_graph(int _size) {

        adj_list.resize(_size);
        // initialize indgree
        for (int i = 0; i < _size; i++)
            adj_list[i].indgree = 0;
        int _next; // out vertex

        for (int i = 0; i < _size; i++) {
            // read in a graph by adjacency list
            cin >> _next;
            while (_next >= 0) {
                adj_list[_next].indgree++;
                adj_list[i].outdgree.push_back(_next);
                cin >> _next;
            }
        }
    }


    void print_graph() {
        for (unsigned int i = 0; i < adj_list.size(); i++) {
            list<int>::iterator iter = adj_list[i].outdgree.begin();
            cout << i << "(indgree: " << adj_list[i].indgree << "): ";
            for (; iter != adj_list[i].outdgree.end(); iter++) {
                cout << *iter << "--> ";
            }
            cout << endl;
        }
    }

    bool top_sort() {
        // if the graph contains cycle
        // the sort will return false
        while (true) {

            list<int>::iterator start, finish, it;
            int j = 0;
            for (; j < (int)adj_list.size(); j++) {
                start  = adj_list[j].outdgree.begin();
                finish = adj_list[j].outdgree.end();
                // check if a vertex contains itself
                for (it = start; it != finish; ++it)
                    if (*it == j)
                        return false;

                // get the vertex whose indgree is 0
                // push it into queue
                if (adj_list[j].indgree == 0) {
                    toplogic.push(j);
                    for (it = start; it != finish; it++) {
                        --adj_list[*it].indgree;
                    }
                    adj_list[j].indgree = -1; // in sort container

                }
            }
            if (j == (int)adj_list.size()) {
                 if (adj_list.size() == toplogic.size()) {
                    return true;
                 }
                 else {
                    cout << "size not same" << endl;
                    cout << toplogic.size() << endl;
                    return false;
                 }
            }
            else {
                cout << "j" << endl;
                return false;
            }
        }
    }

    void print_toplogic() {
        for (unsigned int i = 0; i < adj_list.size(); i++) {
            cout << toplogic.front() << "-->";
            toplogic.pop();
        }
        cout << endl;
    }
};

int main() {
//1 -1
//2 -1
//3 -1
//4 -1
//-1
/*
    cout << "----graph adj list----" << endl;
    dir_graph m_graph(5);
    m_graph.print_graph();
    cout << endl << endl << "----top sort----"  << endl;
    if (m_graph.top_sort())
        m_graph.print_toplogic();
    else {
        cout << "toplogic sort failed" << endl;
    }

    fclose(stdin);
*/
    return 0;
}

