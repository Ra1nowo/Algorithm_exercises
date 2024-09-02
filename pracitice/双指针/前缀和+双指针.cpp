#include <iostream>
#include <vector>
using namespace std;
https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long a[n+1];
        long long res = 0;
        for (int i = 1; i <= n; ++i) a[i] = a[i-1] + nums[i-1];
        for (int i = 1, j = 1; i <= n; ++i) {
            while ((a[i] - a[j-1])*(i-j+1) >= k) j++;
            res += i-j+1;
        }
        return res;
    }
};