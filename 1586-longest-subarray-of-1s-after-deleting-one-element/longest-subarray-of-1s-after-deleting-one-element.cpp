class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int lastZeroIdx = -1;
        int maxLen = 0;

        while(j < n) {
            if(nums[j] == 0) {
                i = lastZeroIdx + 1;
                lastZeroIdx = j;
            }

            maxLen = max(maxLen, j-i);
            j++;
        }
        return maxLen;
    }
};