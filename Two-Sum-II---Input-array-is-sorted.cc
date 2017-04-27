//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

//You may assume that each input would have exactly one solution and you may not use the same element twice.

//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2 

// Drop replicate
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> re;
        int i = 0, j = 0;
        for (i = 0; i < numbers.size();) {
            for (j = i+1; j < numbers.size();) {
                if (numbers[i] + numbers[j] == target){
                    re.push_back(i + 1);
                    re.push_back(j + 1);
                    return re;
                }
                while (j + 1 < numbers.size() && numbers[j + 1] == numbers[j]) j++;
                j++;
            
            }
            while (i + 1 < numbers.size() && numbers[i + 1] == numbers[i]) i++;
            i++;
        }
    }
};


// Two way forward middle.
vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 0;
        int r = numbers.size() -1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                vector<int> res{l+1,r+1};
                return res;
            }
            else if(numbers[l] + numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
 };
