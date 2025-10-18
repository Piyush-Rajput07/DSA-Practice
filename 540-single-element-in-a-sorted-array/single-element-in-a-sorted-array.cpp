class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int st = 0, end = nums.size() - 1;

        if(nums[0] != nums[1]) return nums[0];
        if(nums[end] != nums[end-1]) return nums[end];
        
        while(st <= end) {
            int mid = st + (end-st)/2;
            if((nums[mid-1] != nums[mid]) && (nums[mid] != nums[mid+1])) {
                return nums[mid];
            }
            else if(mid%2 == 0) {
                if(nums[mid-1] == nums[mid]) { //ele is on left
                    end = mid - 1;
                } else { //ele is on right
                    st = mid + 1;
                }
            }
            else {
                if(nums[mid-1] == nums[mid]) { //ele is on right
                    st = mid + 1;
                } else { //ele is on left
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};