class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n-1;
        int lmax = 0;
        int rmax = 0;
        int water = 0;
        while(left < right){
                while(lmax >= rmax && left < right){
                    if(height[right] > rmax){
                        rmax = height[right];
                        break;
                    }
                    water += rmax-height[right];
                    right--;
                }
                while(lmax < rmax && left < right){
                    if(height[left] > lmax){
                        lmax = height[left];
                        break;
                    }
                    water += lmax-height[left];
                    left++;
                }     
        }
        return water;
    }
};
