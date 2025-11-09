class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow]; //moving forward in LL format by 1
            fast = nums[nums[fast]]; //moving by 2
        } while(slow != fast);

        slow = nums[0]; // reinitialising slow pointer to start

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};