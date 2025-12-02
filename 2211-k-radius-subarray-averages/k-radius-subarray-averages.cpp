class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;

        int n = nums.size();
        
        vector<int> res(n, -1);

        if(n < 2*k+1) return res;

        int l = 0, r = 2*k;
        int i = k;
        long long window = 0;

        for(int p=l; p<=r; p++) {
            window += nums[p];
        }

        int temp = 2*k + 1;
        int avg = window/temp;

        res[i] = avg;
        i++; r++;

        while(r < n) {
            int newN = nums[r];
            int gone = nums[l];

            window = window - gone + newN;

            res[i] = window/temp;
            i++; r++; l++;
        }
        return res;
    }   
};