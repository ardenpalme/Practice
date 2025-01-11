#include<iostream>
#include<vector>
#include<string>

class Solution {
    std::string global_min_str= "";
    std::string min_str = "";
public:
    void check_lex(std::vector<int> &nums, std::string &cmp_str,
                   std::vector<int> &min_vec, 
                   std::vector<int> &global_min_vec) 
    {
        std::string nums_lex_str;
        for(int ele : nums){
            nums_lex_str += std::to_string(ele);
        }

        //std::cout << ">>" << nums_lex_str << std::endl;

        if(global_min_str.length() == 0){
            //std::cout << "!!" << nums_lex_str << std::endl;
            global_min_str = nums_lex_str;
            global_min_vec = nums;
        }else{
            //std::cout << "[global_min_str] " << global_min_str << std::endl;
            if(std::strcmp(global_min_str.c_str(), nums_lex_str.c_str()) > 0){
                global_min_str = nums_lex_str;
                global_min_vec = nums;
            }
        }

        if(std::strcmp(nums_lex_str.c_str(), cmp_str.c_str()) > 0){
            //std::cout << "> " << nums_lex_str << std::endl;

            if(min_str.length() == 0){
                min_str = nums_lex_str;
                min_vec = nums;
            }else{
                //std::cout << "[min_str] " << min_str << std::endl;
                if(std::strcmp(min_str.c_str(), nums_lex_str.c_str()) > 0){
                    min_str = nums_lex_str;
                    min_vec = nums;
                }
            }
        }
    }

    void get_permutations(std::vector<int> &nums, 
                          int length, 
                          std::string benchmark, 
                          std::vector<int> &min_vec, 
                          std::vector<int> &global_min_vec)
    //@requires length == nums.size()
    {
        if (length == 1) return;

        /*
        std::cout << "=========\n";
        std::cout << "1 [ ";
        for( int i : nums){
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
        */

        check_lex(nums, benchmark, min_vec, global_min_vec);

        int tmp_val = 0;
        for(int i=0; i<length; i++) {
            get_permutations(nums, length-1, benchmark, min_vec, global_min_vec);
            if(length % 2 == 0) {
                tmp_val = nums.at(i);
                nums[i] = nums.at(length-1);
                nums[length-1] = tmp_val;

            }else{
                tmp_val = nums.at(0);
                nums[0] = nums.at(length-1);
                nums[length-1] = tmp_val;
            }
        }

        /*
        std::cout << "2 [ ";
        for( int i : nums){
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
        */

        check_lex(nums, benchmark, min_vec, global_min_vec);
    }

    void nextPermutation(std::vector<int>& nums) {
        std::vector<int> saved_nums(nums);
        std::vector<int> min_vec;
        std::vector<int> global_min_vec;
        std::string cmp_str;

        if(nums.size() == 1) return;

        for(int ele : nums){
            cmp_str += std::to_string(ele);
        }

        get_permutations(nums, nums.size(), cmp_str, min_vec, global_min_vec);
/*
        std::cout << "saved nums: [";
        for(int ele : saved_nums){
            std::cout << ele << " ";
        }
        std::cout << "]" << std::endl;

        std::cout << "global_min_vec: [";
        for(int ele : global_min_vec){
            std::cout << ele << " ";
        }
        std::cout << "]" << std::endl;

        std::cout << "min_vec: [";
        for(int ele : min_vec){
            std::cout << ele << " ";
        }
        std::cout << "]" << std::endl;

*/
        if(min_vec.empty())
            nums = global_min_vec;
        else
            nums = min_vec;
    }
};

void test_sol(std::vector<int> &nums)
{
    std::cout << "=====TEST===\n";
    std::cout << "in: [ ";
    for( int i : nums){
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;

    Solution *sol = new Solution();
    sol->nextPermutation(nums);

    std::cout << "out: [ ";
    for( int i : nums){
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> vec1 = {1,2,3};
    test_sol(vec1);

    std::vector<int> vec2 = {3,2,1};
    test_sol(vec2);

    std::vector<int> vec3 = {2,0,4,0,0,4,4,1,4};
    test_sol(vec3);

    std::vector<int> vec4 = {4,1,4,1,4,3,3,3};
    test_sol(vec4);

    return 0;
}