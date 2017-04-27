 //subarray within an array (containing at least one number) which has the largest maxSum.

 //For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 //the contiguous subarray [4,-1,2,1] has the largest maxSum = 6. 
 
/* 
 * Algorithm 1.
 * Make the following definition:
 *      sj = a[0] + a[1] + ... + a[j-1];
 *      si = a[0] + a[1] + ... + a[i-1].
 * Then, maxSum = sj+1 - si.
 */
class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int si = 0, sj = 0, maxSum = nums[0], minSi = 0;
        for (int idx = 1; idx < nums.size(); idx++) {
           sj += nums[idx - 1];
           if (si < minSi) minSi = si;
           if (sj - minSi > maxSum) maxSum = sj - minSi;
           si += num[idx - 1];
        }
        return maxSum;
    }
};


/* 
 * Algorithm 2.
 * Definition:
 *  sx = a[0] + a[1] + ... +[x-1];
 *  sy = a[0] + a[1] + ... +[y-1];
 * By increasing way, we calculate the maxSum.
 * To make maxSum maximum, we should assure the s[x] > 0, 
 * which can contribute to the maxSum.
 */
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = 0, maxSum = nums[0];
            for (int i = 0; i < nums.size(); i++){
                sum += nums[i];
                maxSum = max(maxSum, sum);
                sum = max(sum, 0);
            }
            return maxSum;
        }
};
