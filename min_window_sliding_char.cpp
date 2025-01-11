#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    bool is_subset(unordered_set<char> &setA, unordered_set<char> &setB) {
        for(int ele : setA) {
            if(setB.find(ele) == setB.end()) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_set<char> str_set;
        unordered_set<char> substr_set;
        vector<string> substrs;

        if(t.size() > s.size()) return "";

        for(char ele : t) str_set.insert(ele);

        auto iter = s.begin();
        string::iterator saved_iter;
        bool recording = false;
        string substr;
        while(iter != s.end()) {
            cout << "checking: " << *iter << endl;
            cout << "(";
            for(auto ele : substr_set) cout << ele;
            cout << ")\n";
            cout << "[" << substr << "]\n";

            if(str_set.find(*iter) != str_set.end() 
                && substr.empty()){
                recording = true;
                saved_iter = iter;
            } 

            if(recording) {
                substr += *iter;
                substr_set.insert(*iter);

                if(is_subset(str_set, substr_set) && substr_set.size() >= str_set.size()){
                    substrs.push_back(substr);
                    substr_set.clear();
                    substr.clear();
                    recording = false;
                    iter = saved_iter;
                }
            }

            iter++;
        }

        cout << "total substrings:" << endl;
        string min_str;
        int min_len = max(s.size(), t.size());
        for(auto str : substrs) {
            cout << str << endl;
            if(str.size() <= min_len) {
                min_len = str.size();
                min_str = str;
            }
        }
        return min_str;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    //string s="ADOBECODEBANC", t="ABC";
    string s="OUZODYXAZV", t="XYZ";
    auto str = sol.minWindow(s,t);
    cout << "result: " << str << endl;

    return 0;
}