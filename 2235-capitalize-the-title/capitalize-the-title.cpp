class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        int start = 0;

        for(int i=0; i<=n; i++) {
            if(i == n || title[i] == ' ') {
                int len = i - start;

                if(len <= 2) {
                    for(int k=start; k<i; k++) {
                        title[k] = tolower(title[k]);
                    }
                }
                else {
                    title[start] = toupper(title[start]);
                    for(int k=start+1; k<i; k++) {
                        title[k] = tolower(title[k]);
                    }
                }
                start = i + 1;
            }
        }
        return title;
    }
};