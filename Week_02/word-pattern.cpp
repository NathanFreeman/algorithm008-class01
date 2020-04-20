#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();

        if (n != str.size()) { // pattern长度和str长度不相等，不用看了
            return false;
        }

        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n; // 如果pattern比
    }
};

int main() {
    string pattern = "abba", str = "dog cat cat dog";
    Solution solution;
    solution.wordPattern(pattern, str);
    return 0;
}