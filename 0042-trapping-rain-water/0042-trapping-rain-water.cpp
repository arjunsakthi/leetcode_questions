class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int count = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                
                leftMax = max(height[left], leftMax);
                count += leftMax - height[left];
                left++;
            } else {
                
                rightMax = max(height[right], rightMax);
                count += rightMax - height[right];
                right--;
            }
        }
        return count;
    }
};