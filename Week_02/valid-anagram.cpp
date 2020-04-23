#include <string>
#include <unordered_map>

using namespace std;

class Solution_1 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> counts;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            counts[s[i]]++;
            counts[t[i]]--;
        }

        for (auto count :counts) {
            if (count.second > 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int counts[26] = {0};

        int n = s.length();
        for (int i = 0; i < n; ++i) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for (int count : counts) {
            if(count != 0){
                return false;
            }
        }
        return true;
    }
};

