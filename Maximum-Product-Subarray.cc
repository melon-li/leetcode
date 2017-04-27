/*
 * Find the contiguous subarray within an array 
 * (containing at least one number) which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6. 
 */
 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int pro = 1, maxPro = nums[0];
       int negative = 0;
       for (int i =0; i < nums.size(); i++) {
           if (nums[i] < 0) negative++;
       }
       for (int i = 0; i < nums.size(); i++) {
           if (nums[i] < 0) negative = max(negative--, 0);
           if (pro*nums[i] < 0 && negative%2 == 1) {
               pro *= nums[i];
           } else {
               pro = nums[i];
           }
           maxPro = max(maxPro, pro);
           if (pro == 0) pro = 1;
       }
       return maxPro;
    }
};
