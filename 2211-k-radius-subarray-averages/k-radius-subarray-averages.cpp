class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        if(n < 2*k + 1) return ans;

        long long window = 0;
        int l = 0, r = 2*k;
        int i = k;

        for(int j=l; j<=2*k; j++) {
            window += nums[j];
        }

        long long avg = window / (2*k +1);
        ans[i] = avg;
        i++;
        r++;

        while(r < n) {
            int out_of_window = nums[l];
            int new_to_window = nums[r];

            window = window + new_to_window - out_of_window;
            ans[i] = window / (2*k + 1);
            i++;
            r++;
            l++;
        }
        
        return ans;
    }
};