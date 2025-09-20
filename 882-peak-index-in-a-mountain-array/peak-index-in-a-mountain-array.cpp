class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;
        
        while(st <= end) {
            int mid = st + (end - st)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])  
                return mid;
            
            if(arr[mid-1] < arr[mid]) // peak is on right
                st = mid + 1;
            else // peak is on left
                end = mid - 1;
        }

        return -1;
    }
};