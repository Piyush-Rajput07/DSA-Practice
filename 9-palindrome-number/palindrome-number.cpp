class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) 
            return false;

        long long n = x, ans = 0; // to prevent overflow (64 bits)
        while(n > 0) {
            int rem = n%10;
            ans = (ans * 10) + rem;
            n /= 10;
        }
        return ans == x;
    }
};