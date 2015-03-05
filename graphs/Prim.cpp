
/*
+-----------------------------------------------------------------------+
| C++ Code Prim                                                         |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#define INF     (1<<30)
#define V	    6
#define NC      1000 // not connected


#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

// we set that no cycle occurred
// assign NOT CONNECTED for every (vertex, vertex)

int graph[V][V] = {
	{NC, 6, 1, 5, NC, NC},
	{6, NC, 5, NC, 3, NC},
	{1, 5,  NC, 5, 6,  4},
	{5, NC, 5, NC, NC, 2},
	{NC, 3, 6, NC, NC, 6},
	{NC, NC, 4, 2, 6, NC},
};

int  cost[V]; // weight
int  edge[V]; // closest edge
bool mark[V]; // if marked

void prim(int n = 0) {
	for (int i = 0; i < V; i++) {
        cost[i] = graph[0][i];
        edge[i] = 0;
        mark[i] = false;
	}
	mark[0] = true;
	for (int i = 0; i < V; i++) {
        int mini_cost = INF;
        int next_edge = -1;
        for (int j = 0; j < V; j++) {
            if (!mark[j] && (cost[j] < mini_cost)) {
                mini_cost = cost[j];
                next_edge = j;
            }
        }
        if (next_edge != -1) {
            // check if has next edge
            mark[next_edge] = true;
            // push vertex j into mark vertex set
        }
        for (int k = 0; k < V; k++) {
            // let new vertex pushed be the start
            // compare weight of exsited two vertexes
            // to new ones, and get the less one
            if (!mark[k] && (graph[next_edge][k] < cost[k])) {
                cost[k] = graph[next_edge][k];
                edge[k] = next_edge; // miniest weight from next_edge to k
            }
        }
	}
}


int main() {
    prim();
    printf("----------cost----------\n");
    int total_cost = 0;
    for (int i = 0; i < V; i++) {
        if (cost[i] != NC)
            total_cost += cost[i];
    }
    printf("total: %d\n", total_cost);
    printf("----------mini edge----------\n");
    for (int i = 0; i < V; i++) {
        printf("%d -- %d\n", i + 1, edge[i] + 1);
    }

    return 0;
}
