class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int oran = x;
        long rev=0;

        while(x>0){
            rev = rev *10 + (x % 10);
            x/=10;
        }
        if(oran == rev){
            return true;
        }else{
            return false;
        }
    }
};
