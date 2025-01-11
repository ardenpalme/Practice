#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_substr_len = 0;
        string substr = "";
        unordered_set<char> seen_chars;
        string::iterator str_iter = s.begin();
        string::iterator substr_iter = s.begin();

        while(str_iter != s.end()) {
            auto it = seen_chars.find(*str_iter);
            if(it == seen_chars.end()) {
                //cout << "<< " << *str_iter << endl;
                seen_chars.insert(*str_iter);
                substr += *str_iter;
                str_iter++;
            }else{
                //cout << substr << endl;
                if(substr.length() > longest_substr_len) {
                    longest_substr_len = substr.length();
                }

                str_iter = find(substr_iter, str_iter, *str_iter);
                str_iter++;
                substr_iter = str_iter;

                substr.erase(0, substr.length());
                seen_chars.erase(seen_chars.begin(), seen_chars.end());
            }
        }

        // last substr not terminated by repeat char
        if(substr.length() > longest_substr_len) {
            longest_substr_len = substr.length();
        }

        return longest_substr_len;
    }

    void test(string test_str) {
        int len = lengthOfLongestSubstring(test_str);
        cout << "longest substr in " << test_str
             << " has " << len << " chars" << endl;
    }
};

int main(int argc, char *argv[]) 
{
    Solution sol;
    sol.test("zxyzxyz");
    sol.test("abcabcdefg");
    sol.test("xxxx");
    sol.test("dvdf");
}
