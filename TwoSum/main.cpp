// LeetCode Problem 1
// https://leetcode.com/problems/two-sum/

#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>

std::vector<int> twoSum(std::vector<int>& nums, int target);

int main(){
   
    int testcases;
    std::cin>>testcases;
    //std::cout<<"Total testcases: "<<testcases<<"\n"; 
    while(testcases--)
    {
        int n, target;
        std::cin>>n;
        std::vector<int> nums;
        int input;
        for(int i=0; i<n; i++){
            std::cin>>input;
            nums.push_back(input);
        }
        std::cin>>target;

        std::vector<int> ans(2, 0);
        ans = twoSum(nums, target);
        std::cout<<"\n Target sum: "<<target<<" ";
        for(auto a : ans){
            std::cout<<a<<" ";
        }
    }
}


std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::map<int, int> nmap;
    std::vector<int> ans(2, 0);
    int ele;
    for(int i=0; i<nums.size(); i++){
    //for(auto ele : nums){
        ele = nums[i];
        if (nmap.find(ele) == nmap.end()){  // Not present in map
            nmap[target-ele] = i;     
        }       
        else{
            ans[0]=nmap[ele];
            ans[1]=i;
            return ans;
        }
    }
    return ans;
}
