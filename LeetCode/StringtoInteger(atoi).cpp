class Solution {
public:
    int myAtoi(string s) {
        long long adj=0;
        int i=0;
        int sign = 1;

        while(i<s.length() && s[i]== ' '){
            i++;
        }

        if(i< s.length() && (s[i]== '+' || s[i] =='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }

        while(i< s.length() && s[i] >='0' && s[i] <='9'){
            adj = adj *10 + (s[i]-'0');

            if(sign==1  && adj > INT_MAX) return INT_MAX;
            if(sign==-1 && -adj < INT_MIN) return INT_MIN;
            i++;
        }
        return adj * sign;
    }
};