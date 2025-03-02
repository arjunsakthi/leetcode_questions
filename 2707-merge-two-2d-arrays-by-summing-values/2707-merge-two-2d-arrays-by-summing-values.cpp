class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i1=0,i2=0;
       
        if(nums1[0][0] < nums2[0][0]){
 ans.push_back({nums1[0][0],nums1[0][1]});
        i1++;
        }
        else{
             ans.push_back({nums2[0][0],nums2[0][1]});
        i2++;
        }
        while(i1 < nums1.size() && i2<nums2.size()){
            if(nums1[i1][0] < nums2[i2][0]){
                if(ans.back()[0] == nums1[i1][0]){
                    ans[ans.size()-1][1] += nums1[i1][1];
                    
                }
                else{
                    ans.push_back({nums1[i1][0],nums1[i1][1]});
                }
                i1++;
            }
            else{
                if(ans.back()[0] == nums2[i2][0]){
                    ans[ans.size()-1][1] += nums2[i2][1];
                }
                else{
                    ans.push_back({nums2[i2][0],nums2[i2][1]});
                }
                i2++;
            }
        }
        while(i1<nums1.size()){
             if(ans.back()[0] == nums1[i1][0]){
                    ans.back()[1] += nums1[i1][1];
                    
                }
                else{
                    ans.push_back({nums1[i1][0],nums1[i1][1]});
                }
                i1++;
        }
         while(i2<nums2.size()){
              if(ans.back()[0] == nums2[i2][0]){
                    ans.back()[1] += nums2[i2][1];
                }
                else{
                    ans.push_back({nums2[i2][0],nums2[i2][1]});
                }
                i2++;
        }
        return ans;
    }
};