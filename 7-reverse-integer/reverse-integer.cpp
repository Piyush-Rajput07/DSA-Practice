class Solution {
public:
    int reverse(int n) {
        int revNum = 0;

        while(n != 0) { // to run for -ve no.s too
            int dig = n % 10;
            if((revNum > INT_MAX/10) || (revNum < INT_MIN/10)) {
                return 0;
            }
            revNum = (revNum * 10) + dig; //rev no. can go outside range
            n /= 10;
        }
        return revNum;
    }
};