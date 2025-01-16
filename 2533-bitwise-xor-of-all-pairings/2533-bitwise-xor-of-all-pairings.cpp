class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n1or = 0;
        int n2 = nums2.size();
        int n2or = 0;
        for(int i=0; i<nums1.size(); i++){
            n1or ^= nums1[i];
        }
        for(int i=0; i<nums2.size(); i++){
            n2or ^= nums2[i];
        }
        if(n1%2 && n2%2)    return n1or^n2or;
        else if(n1%2)   return n2or;
        else if(n2%2) return n1or;
        else    return 0;
    }
};