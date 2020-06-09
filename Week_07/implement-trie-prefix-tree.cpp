#include <map>
#include <string>

using namespace std;

class Trie {
    struct TrieNode {
        // 每个节点都连接了字符
        map<char, TrieNode *> child_table; // 哈希表存储字符
        int end;

        TrieNode() : end(0) {}
    };

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        for (char & i : word) {
            if (curr->child_table.count(i) == 0) {
                curr->child_table[i] = new TrieNode();
            }
            curr = curr->child_table[i];
        }
        curr->end = 1;
    }

    bool search(string word) {
        return find(word, 1);
    }

    bool startsWith(string prefix) {
        return find(prefix, 0);
    }

private:
    TrieNode *root;

    bool find(string s, int exact_match) {
        TrieNode *curr = root;
        for (char & i : s) {
            if (curr->child_table.count(i) == 0) {
                return false;
            } else {
                curr = curr->child_table[i];
            }
        }
        if (exact_match) {
            return (curr->end) ? true : false;
        } else {

            return true;
        }
    }
};