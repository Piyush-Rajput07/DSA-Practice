class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int penalty = 0;
        int minH = 0;

        for(int i=0; i<n; i++) {
            if(customers[i] == 'Y') {
                penalty++;
            }
        }
        
        int minPenalty = penalty;
        int i = 1;

        for(int i=1; i<=n; i++) {
            if(customers[i-1] == 'Y') {
                penalty--;
            }
            else
                penalty++;

            if(penalty < minPenalty) {
                minPenalty = penalty;
                minH = i;
            }
        }
        
        return minH;
    }
};