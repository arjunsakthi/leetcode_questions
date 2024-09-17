class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        while(i<height.size() && height[i] == 0){
            i++;
        }
        if(i >= height.size())  return 0;
        int start = height[i];
        int stid = i;
        int tempc = 0;
        int ans = 0;
        int j=i;
        while(j<height.size()){
            if(height[j] >= start){
                start = height[j];
                stid = j;
                ans += tempc;
                tempc=0;
                j++;
                continue;
            }
            if(j == height.size()-1){
                start = start -1;
                j = stid +1;
                tempc=0;
                continue;
            }
            tempc += (start-height[j] > 0) ? start-height[j] : 0;
            j++;
        }
        return ans;
    }
};