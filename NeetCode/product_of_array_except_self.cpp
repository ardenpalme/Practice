#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        long int prod = 1;
        int zero_idx = -1;
        int quotient;

        auto ct = count(nums.begin(), nums.end(), 0);
        if(ct > 1) {
            for(int i=0; i<nums.size(); i++) {
                result.push_back(0);
            }
            return result;
        }

        //@assert ct <= 1
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                zero_idx = i;
            }else{
                prod *= nums[i];
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(zero_idx != -1) {
                if(i == zero_idx) {
                    result.push_back(prod);
                }else{
                    result.push_back(0);
                }
            }else{
                quotient = prod / nums[i];
                result.push_back(quotient);
            }
        }

        return result;
    }

    void print_vec(vector<int> &vec) {
        cout << "[";
        auto iter = vec.begin();
        while(iter != vec.end()) {
            cout << *iter;
            if(next(iter) != vec.end()) cout << ", ";
            iter++;
        }
        cout << "]" << endl;
    }
    void test_productExceptSelf(vector<int> &nums)
    {
        cout << "Input: ";
        print_vec(nums);
        auto res = productExceptSelf(nums);

        cout << "Output: ";
        print_vec(res);
    }
};

int main()
{
    vector<int> nums = {1,2,4,6};
    vector<int> nums1 = {-1,0,1,2,3};

    Solution sol;
    sol.test_productExceptSelf(nums);
    sol.test_productExceptSelf(nums1);
    return 0;
}
