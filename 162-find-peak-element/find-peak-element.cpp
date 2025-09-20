class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int st = 0, end = nums.size() - 1;

        while(st <= end) {
            int mid = st + (end - st)/2;

            if(mid > 0 && mid < nums.size() - 1) { 
                if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])  
                    return mid;
                
                if(nums[mid-1] < nums[mid]) // peak is on right 
                    st = mid + 1;
                else // peak is on left
                    end = mid - 1; 
        }
        
            else if(mid == 0)   
                return (nums[0] > nums[1]) ? 0 : 1;
            else 
                return (nums[end] > nums[end-1]) ? end : end-1;
        }        
        return -1;
    }
};