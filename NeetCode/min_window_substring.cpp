#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<iterator>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string active_str;
        vector<string> substrs;

        if(t.length() > s.length()) return "";
        
        active_str = t;

        auto s_iter = s.begin();
        auto win_start = s.end();
        auto win_end = s.end();

        while(s_iter != s.end()) {
            //cout << "[" << *s_iter << "]" << endl;
            auto set_iter = find(active_str.begin(), active_str.end(), *s_iter);
            if(set_iter != active_str.end()) {
                if(win_start == s.end()) {
                    win_start = s_iter;
                }
                active_str.erase(set_iter);
            }
            if(active_str.length() == 0) {
                win_end = s_iter;
                int start_idx = distance(s.begin(), win_start);
                int end_idx = distance(s.begin(), win_end);
                string substr = s.substr(start_idx, (end_idx - start_idx + 1));
                //cout << substr << endl;
                substrs.push_back(substr);

                active_str = t;
                s_iter = next(win_start, 1);
                win_start = s.end();
                win_end = s.end();

                continue;
            } 
            s_iter++;
        }

        string min_substr = "";
        size_t min_substr_len = s.length();
        for(string str : substrs) {
            if(str.length() <= min_substr_len) {
                min_substr_len = str.length();
                min_substr = str;
            }
        }

        return min_substr;
    }

    void test_minWindow(string s, string t) {
        cout << "Input: " << "s = \"" << s <<"\" "
              << "t = \"" << t <<"\"" << endl;
        auto res = minWindow(s,t);
        cout << "Output: " << res << endl;;
    }
};

int main()
{
    Solution sol;
    sol.test_minWindow("OUZODYXAZV", "XYZ");
    sol.test_minWindow("xyz", "xyz");
    sol.test_minWindow("x", "xy");
    sol.test_minWindow("aa", "aa");
    return 0;
}