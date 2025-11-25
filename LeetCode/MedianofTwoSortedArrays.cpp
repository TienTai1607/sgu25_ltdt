class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c;
        
        for(int x : nums1) c.push_back(x);
        for(int x : nums2) c.push_back(x);

        sort(c.begin(),c.end());
        int n=c.size();
        if(n % 2 == 1){
            return c[n/2];
        }else{
            return ((c[n/2 -1]) + (c[n/2])) / 2.0;
        }
    }
};
