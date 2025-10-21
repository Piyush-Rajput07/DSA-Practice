class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxAllowedSum) {
        int subArrays = 1, sum = 0;
        for(int val : nums) {
            if(sum + val <= maxAllowedSum) {
                sum += val;
            }
            else {
                subArrays++;
                sum = val;
            }
        }
        return (subArrays <= k) ? true : false;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        for(int val : nums) {
            sum += val;
        }

        int st = *max_element(nums.begin(), nums.end()), end = sum;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(isPossible(nums, k, mid)) { //we'll try to find the min -> move left
                ans = mid;
                end = mid - 1;
            }
            else { //we'll find the min value on right
                st = mid + 1;
            }
        }
        return ans;
    }
};