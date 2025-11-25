class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }

        int start=0;
        int maxlen=1;

        for(int i=0 ; i<s.length() ; i++){
            int R=i;
            int L=i;
            while(L>=0 && R<s.length() && s[L]==s[R]){
                L--;
                R++;
            }
           int len1 = R - L - 1;

           R=i;
           L=i+1;
           while(L>=0 && R<s.length() && s[L]==s[R]){
                L--;
                R++;
           }
           int len2 = R - L - 1;

           int len = max(len1,len2);

           if(len > maxlen){
                maxlen=len;
                start = i - (len - 1) / 2;
           }
        }
        return s.substr(start,maxlen);
    }
};