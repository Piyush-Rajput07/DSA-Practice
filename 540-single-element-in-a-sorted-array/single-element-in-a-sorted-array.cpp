class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st)/2;
            //handling edge cases when unique ele is on st or end
            if(mid == 0 && nums[0] != nums[1]) return nums[0];
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[n-1];
            
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])    
                return nums[mid];

            if(mid%2 == 0) { // even no. of elements on both sides
                if(nums[mid-1] == nums[mid])
                    end = mid - 1;
                else 
                    st = mid + 1;
            }
            else { // odd no. of elements on both sides
                if(nums[mid-1] == nums[mid])    
                    st = mid + 1;
                else 
                    end = mid - 1;
            }
        }
        return -1;
    }
};