/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        map<std::pair<int, int> > m;
        for (int i = 0; i < nums.length(); i++)
            m.insert(std::make_pair(nums[i], i));
        for (map<std::pair<int, int> >::iterator it = m.begin();
                it != m.end(); it++){
            map<std::pair<int, int> >::iterator first = m.begin();
            map<std::pair<int, int> >::iterator last = m.end();
            map<std::pair<int, int> >::iterator middle;
            last--;
            if (m.size() < 3) break;
            int sum = (m.begin())->first + (m.rbegin())->first;
            first++;
            last--;
            if (sum > 0){
                while (sum + first->first > 0 
                        && first->first < 0
                        && first != m.end()) first++;
               middle = first; 
            }else if (sum < 0){
                while (sum + last->first < 0 
                        && last->first > 0
                        && last != m.begin()) last--;
                middle = last;
            }else if(sum == 0){
                while (first->first < 0
                        && first != m.end()) first++;
                middle = first;
            }

            if (sum + middle->first == 0){
            } 


        }
    }
};
