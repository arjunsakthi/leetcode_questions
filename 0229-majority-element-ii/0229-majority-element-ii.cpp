class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,el1,el2;
        cout << el1 << el2 << endl;
        for(int i=0; i<nums.size();i++){
            if(cnt1==0 && el2 != nums[i]) {
                el1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && el1 != nums[i]) {
                el2=nums[i];
                cnt2++;
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else {cnt1--;cnt2--;}
        }
        int c1=0, c2=0; 
        cout << el1 << el2 << cnt1 << cnt2;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==el1) c1++;
            if(nums[i]==el2) c2++;
        }
        if(c1>nums.size()/3 && c2>nums.size()/3) {
            return {el1,el2};
        }
        else if(c1>nums.size()/3) {
            return {el1};
        }
        else if(c2>nums.size()/3) {
            return {el2};
        }
        else return {};
    }
};