class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        int i = 0, j = 0;

        while(j < n) {
            if(nums[j] == 0) {
                i = j + 1;
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};