#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (auto str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }

        vector<vector<string>> result;
        for (auto p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};

