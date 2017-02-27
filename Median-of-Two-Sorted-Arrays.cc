// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> nums3;
        while (i < m || j < n) {
            if (i >= m && j < n) nums3.push_back(nums2[j++]);
            if (j >= n && i < m) nums3.push_back(nums1[i++]);
            if (i < m && j < n)
                nums3.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }
        if ((n + m) % 2 == 1) return nums3[(m + n) / 2];
        return double(nums3[(m + n) / 2 - 1] + nums3[(m + n) / 2]) / 2;
    }
};
