class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int maxlen=0; //độ dài lớn nhất của chuỗi
        int left=0; //điểm bắt đầu

        for(int right = 0; right < s.size(); right++){
            char c=s[right];

            if(lastIndex[c] >= left){
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};