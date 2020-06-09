#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    bool is_end;
    vector<TrieNode *> children;

    TrieNode() {
        is_end = false;
        children = vector<TrieNode *>(26, nullptr);
    }
};

class Trie {
public:
    TrieNode *getRoot() {
        return root;
    }

    Trie(vector<string> &words) {
        root = new TrieNode();
        for (string &word : words) {
            addWord(word);
        }
    }

    void addWord(const string &word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->children[word[i] - 'a'] == nullptr) {
                cur->children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->children[word[i] - 'a'];
        }
        cur->is_end = true;
    }

private:
    TrieNode *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *trie = new Trie(words);
        TrieNode *root = trie->getRoot();
        unordered_set<string> result_set;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWords(board, i, j, root, "", result_set);
            }
        }

        vector<string> result;
        for (auto it : result_set) {
            result.push_back(it);
        }
        return result;
    }

private:
    void findWords(vector<vector<char>> &board, int i, int j, TrieNode *root, string word,
                   unordered_set<string> &result_set) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '@') {
            return;
        }

        if (root->children[board[i][j] - 'a'] != nullptr) {
            word = word + board[i][j];
            root = root->children[board[i][j] - 'a'];
            if (root->is_end) {
                result_set.insert(word);
            }

            char c = board[i][j];
            board[i][j] = '@';

            findWords(board, i + 1, j, root, word, result_set);
            findWords(board, i - 1, j, root, word, result_set);
            findWords(board, i, j + 1, root, word, result_set);
            findWords(board, i, j - 1, root, word, result_set);
            board[i][j] = c;
        }
    }
};

