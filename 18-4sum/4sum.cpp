class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
        
            if(i > 0 && nums[i] == nums[i-1])   continue;

            for(int j=i+1; j<n; ) {

                int p = j + 1, q = n - 1;
                while(p < q) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[p] + nums[q];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                        //duplicates
                        int lastP = nums[p], lastQ = nums[q];
                        while(p < q && nums[p] == lastP)    p++;
                    }
                    else if(sum < target) {
                        p++;
                    }
                    else {
                        q--;
                    }
                }

                j++;
                while(j < n && nums[j] == nums[j-1])    j++; 
            }
        }
        return ans;
    }
};