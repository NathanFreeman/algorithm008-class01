#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        for (int i = 0, j = S.length(); i < j;) {
            if (!isalpha(S[i])) {
                i++;
            } else if (!isalpha(S[j])) {
                j--;
            } else {
                swap(S[i++], S[j--]);
            }
        }
    }
};

int main(){
    string S = "abc-sc-sd";
    Solution solution;
    solution.reverseOnlyLetters(S);
    cout << S << endl;
    return 0;
}