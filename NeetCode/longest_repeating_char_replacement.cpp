#include<iostream>
#include<unordered_map>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
    void print_window(string s, int l, int r) 
    //@assert(l <= r < s.length())
    {
        int i=l;
        while(i <= r) {
            cout << s[i];
            i++;
        }
        cout << endl;
    }
    
    void print_map(unordered_map<char, int> &in_map) 
    {
        for(auto ele : in_map) {
            cout << "[" << ele.first << "] "
                 << ele.second << endl;
        }
        cout << "=======" << endl << endl;
    }
    
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> counts;

        int l = 0, r = 0;
        int prev_r = 0;
        while(r < s.length()) {
            int win_sz = r - l + 1;

            cout << "prev_r = " << prev_r << endl;
            cout << "(" << l << ", " << r << ") ";
            print_window(s, l, r);
            
            if((r == 0 && prev_r == 0) || (r > prev_r)) {
                auto iter = counts.find(s[r]);
                if(iter == counts.end()) {
                    counts.insert({s[r], 1});
                }else{
                    counts[s[r]]++;
                }
            }

            print_map(counts);

            int max_freq_char_ct = 0;
            for_each(counts.begin(), counts.end(), [&](auto ele){
                if(ele.second > max_freq_char_ct) {
                    max_freq_char_ct = ele.second;
                }
            });

            prev_r = r;
            if((win_sz - max_freq_char_ct) <= k) {
                if(win_sz > res) res = win_sz;
            }else{
                auto iter = counts.find(s[l]);
                if(iter != counts.end()) {
                    counts[s[l]]--;
                }
                l++;
                continue;
            }
            r++;
        }
        return res;
    }
    void test_characterReplacement(string s, int k) {
        int res = characterReplacement(s, k);
        cout << "Input: "<< s << " k = " << k << endl;
        cout << "output: "<< res << endl;
    }
};

int main() {
    Solution sol;
    // sol.test_characterReplacement("AAAA", 0);
    // sol.test_characterReplacement("ABABBA", 2);
    sol.test_characterReplacement("AAAA", 0);
    return 0;
}