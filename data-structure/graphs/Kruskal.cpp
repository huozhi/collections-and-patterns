/*
+-----------------------------------------------------------------------+
| C++ Code Kruskal                                                      |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */
/*
 * kruskal (G, w)
 * A <- φ
 * for each vertex v ∈ V[G]
 *     do MAKE-SET(v)
 * sort the edges of E into nondecreasing order by weight w
 * for each edge(u, v) ∈ E, taken in nondercreasing order by weight
 *     do if FIND-SET(u) ≠ FIND-SET(v)
 *         then A <- A∪{(u, v)}
 *             UNION(u, v)
 * return A
 */

#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef pair< int, pair<int, int> > edge;
typedef priority_queue<edge> edge_set;

#define V    6
#define NC   (1<<30)

int W[V][V] = {
    {NC, 6, 1, 5, NC, NC},
    {6, NC, 5, NC, 3, NC},
    {1, 5,  NC, 5, 6,  4},
    {5, NC, 5, NC, NC, 2},
    {NC, 3, 6, NC, NC, 6},
    {NC, NC, 4, 2, 6, NC},
}

int main() {
    return 0;
}
