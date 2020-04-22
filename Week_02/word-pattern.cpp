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
            //"abba", str = "dog cat cat dog"
            // 1.  a对应的1，dog对应1
            // 2.  b对应的2，cat对应2
            // 3.  b对应的3，cat对应3
            // 4.  b对应的4，cat对应4

            // a出现多少次，dog也要出现多少次
            if (i == n || p2i[pattern[i]] != w2i[word])  // 如果a对应数值和word对应的数值不一样，那么肯定是错的
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return true;
    }
};

int main() {
    string pattern = "abba", str = "dog cat cat dog";
    Solution solution;
    solution.wordPattern(pattern, str);
    return 0;
}