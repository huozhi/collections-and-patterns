#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 256; // ascii count

struct trie_node {
    int count;
    trie_node *next[MAXN];

    trie_node(): count(0) {
        for (int i = 0; i < MAXN; i++) next[i] = NULL;
    }
};

class tire {
private:
    trie_node *root;
public:
    tire(): root(new trie_node()) {}
    
    void insert(string s) {
        if (s.empty()) return;
        trie_node *cur = root;
        for (size_t i = 0; i < s.size(); i++) {
            if (cur->next[ s[i] ] == NULL) {
                cur->next[ s[i] ] = new trie_node();
            }
            cur->next[ s[i] ];
        }
        // word count increase
        cur->count++;
    }
};
