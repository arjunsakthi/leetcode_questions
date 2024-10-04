class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long totalsum = 0;
        for(int i=0;i<skill.size(); i++){
            totalsum += skill[i];
        }   
        long long productsum = 0;
        sort(skill.begin(),skill.end());
        int requiredsum = skill[0] + skill[skill.size()-1]; 
        for(int j=0; j<skill.size()/2;j++){
            if(skill[j] + skill[skill.size()-j-1] != requiredsum) return -1;
            productsum += skill[j]*skill[skill.size()-j-1];
        }
        return productsum;
    }
};