class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, actualSum = 0;
        unordered_map<int, int> dupl;

        for(int i=0; i<n; i++) {
            actualSum += nums[i];
            if(dupl.find(nums[i]) != dupl.end()) {
                a = nums[i];
            }
            dupl[nums[i]]++;
        }

        int expSum = (n * (n+1))/2;
        b = expSum - (actualSum - a);

        return {a, b};
    }
};