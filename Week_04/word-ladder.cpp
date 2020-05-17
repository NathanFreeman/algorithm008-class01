#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;

        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;

        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string word = *it;
                cout << word << endl;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail->find(word) != dict.end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "dog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution solution;
    cout << solution.ladderLength(beginWord, endWord, wordList) <<endl;
    return 0;
}

