class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n < 3) {
            return {};
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) { //can't make it zero 
                break;
            }

            if(i > 0 && nums[i] == nums[i-1]) { //duplicate values
                continue;
            }

            int st = i + 1, end = n - 1;

            while(st < end) {
                int sum = nums[i] + nums[st] + nums[end];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[st], nums[end]});

                    //For removing duplicates -> check if next or last ele was same as current
                    int lastSt = nums[st], lastEnd = nums[end]; 
                    while(st < end && nums[st] == lastSt) st++;
                    while(st < end && nums[end] == lastEnd) end--;
                }
                else if(sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};