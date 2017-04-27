#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            int front = i + 1;
            int back = nums.size() - 1;
            int sum = nums[i];
            while (front < back) {
                sum = nums[i] + nums[front] + nums[back];
                cout<<"res"<<res<<"sum="<<sum<<"front="<<front<<"back="<<back<<endl;
                if (sum < target){
                    front++;
                }else if (sum > target){
                    back--;
                }else {
                    return target;
                }
                if (abs(sum - target) < abs(res - target)) res = sum;
            }
            if ((i+3) >= nums.size()) return res;
            
        }
        
        return res; 
    }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout<<threeSumClosest(nums, 100)<<endl;
}
