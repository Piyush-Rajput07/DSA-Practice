class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;
        vector<int> result;

        for(int i=0; i<n; i++) {
            //step-1 make space for nums[i]
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }

            //step-2 no need to keep small elements in the deq
            while(!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }

            //step-3 push idx of nums[i]
            deq.push_back(i);

            //step-4 
            if(i >= k-1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};