class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int count = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                leftMax = max(height[left], leftMax);
                count += leftMax - height[left];
            } else {
                right--;
                rightMax = max(height[right], rightMax);
                count += rightMax - height[right];
            }
        }
        return count;
    }
};