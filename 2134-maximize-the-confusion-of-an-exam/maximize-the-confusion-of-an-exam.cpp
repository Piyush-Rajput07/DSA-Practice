class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0;

        //Case-1 => F -> T
        int CountF = 0;
        int i = 0, j = 0;

        while(j < n) {
            if(answerKey[j] == 'F') {
                CountF++;
            }

            while(CountF > k) {
                if(answerKey[i] == 'F')
                    CountF--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        //Case-2 => T -> F
        int CountT = 0;
        i = 0, j = 0;

        while(j < n) {
            if(answerKey[j] == 'T') 
                CountT++;

            while(CountT > k) {
                if(answerKey[i] == 'T')
                    CountT--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};