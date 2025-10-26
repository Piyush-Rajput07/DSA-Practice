class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int piv = -1;

        for(int i=n-2; i>=0; i--) { //Finding the pivot
            if(nums[i] < nums[i+1]) {
                piv = i;
                break;
            }
        }
        
        if(piv == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        else {
            for(int i=n-1; i>piv; i--) { //swapping with next greatest no.
                if(nums[i] > nums[piv]) {
                    swap(nums[i], nums[piv]);
                    break;
                }
            }
        }
        reverse(nums.begin() + piv + 1, nums.end());
    }
};