/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A-->B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
注意
You can assume that there is at least one topological order in the graph.
样例
For graph as follow: 

{0,1,2,3#1,4#2,4,5#3,4,5}

The topological order can be:

[0, 1, 2, 3, 4, 5]

or

[0, 2, 3, 1, 5, 4]

or

....

Special Test Case:

{0,1,4,5,7,8,9#1,3,4,6#2,8,3,4,5,7#3,6#4,3,6#5,1,3,4,6,9#6#7,9,3,4,5,1#8,9,3,4,6#9,3,4,6}

挑战
Can you do it in both BFS and DFS?

标签 Expand 
Search Breadth First Search Depth First Search LintCode Copyright


*/

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */

    typedef DirectedGraphNode node;

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_map<node *, int> indegree;

        // build indegree count
        for (int i = 0; i < graph.size(); i++) {
            vector<node *> &neb = graph[i]->neighbors;
            if (indegree.count(graph[i]) == 0) {
                indegree[ graph[i] ] = 0;
            }
            for (int j = 0; j < neb.size(); j++) {
                indegree[ neb[j] ]++;
            }
        }
        queue<node *> q;
        // find start nodes
        for (unordered_map<node *, int>::iterator it = indegree.begin();
        it != indegree.end(); ++it) {
            if (it->second == 0) {
                 q.push(it->first);
            }
        }
        vector<node *> answer;
        

        while (!q.empty()) {
            node *cur = q.front();
            answer.push_back(cur);
            q.pop();
            vector<node *> &neb = cur->neighbors;
            for (int i = 0; i < neb.size(); i++) {
                --indegree[ neb[i] ];
                if (indegree[ neb[i] ] == 0) {
                    q.push(neb[i]);
                }
            }
        }
        return answer;
    }
};