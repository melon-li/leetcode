/*
 *You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

// Algorithm 1: Recursive
class Solution {
    public:
    int rob(vector<int>& nums) {
            int sum[nums.size()+1];
            memset(sum, -1, sizeof(int)*(nums.size()+1));
            return rob_(nums, nums.size()-1, sum);
        }

    int rob_(vector<int>& nums, int idx, int* sum) {
            if (idx < 0) return 0;
            if (sum[idx] != -1) return sum[idx];
            sum[idx] = max(nums[idx] + rob_(nums, idx-2, sum), rob_(nums, idx-1, sum));
            return sum[idx];
        }
};


// Algorithm 2: Increasing.
class Solution {
    public:
        int rob(vector<int>& nums){
            int evenPos = 0, oddPos = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i%2 == 0) evenPos = max(evenPos + nums[i], oddPos);
                else oddPos = max(evenPos, oddPos + nums[i]);
            }
            return max(evenPos, oddPos);
        }
};


