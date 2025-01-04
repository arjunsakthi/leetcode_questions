class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left],  rightMax = height[right];
        int count = 0;
        while(left < right){
            if(height[left] < height[right]){
                left++;
                if(min(leftMax, rightMax) > height[left]){
                    count += min(leftMax, rightMax) - height[left];
                }
                leftMax = max(height[left], leftMax);
            }
            else{
                right--;
                if(min(leftMax, rightMax) > height[right]){
                    count += min(leftMax, rightMax) - height[right];
                }
                rightMax = max(height[right], rightMax);
            }
        }
        return count;
    }
};