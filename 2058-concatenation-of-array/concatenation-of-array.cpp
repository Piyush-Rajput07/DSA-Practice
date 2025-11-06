class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2*n, 0);
        int idx = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                res[idx] = nums[j];
                idx++;
            }
        }   
        return res;
    }
};