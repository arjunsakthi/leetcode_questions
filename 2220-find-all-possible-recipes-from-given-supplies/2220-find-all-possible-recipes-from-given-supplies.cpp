class Solution {
public:


    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        set<string> available;
        available.insert(supplies.begin(), supplies.end());
        map<string, int> inDegree;
        map<string, int> mp;
        for (int i = 0; i < recipes.size(); i++) {
            mp[recipes[i]] = i;
        }
        map<string, vector<string>> adj;
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = 0;
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (find(recipes.begin(),recipes.end(),ingredients[i][j]) != recipes.end()) {
                    adj[ingredients[i][j]].push_back(recipes[i]);
                    inDegree[recipes[i]]++;
                }
            }
        }

        queue<int> qu;
        int loop = 1;
        for (auto i : inDegree) {
            if (i.second == 0) {
                qu.push(mp[i.first]);
                loop = 0;
            }
        }
        if (loop)
            return {};
        vector<string> ans;
        while (!qu.empty()) {
            int top = qu.front();
            qu.pop();
            int flag = 1;
            for (int j = 0; j < ingredients[top].size(); j++) {
                if (available.find(ingredients[top][j]) == available.end()) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                available.insert(recipes[top]);
                ans.push_back(recipes[top]);
                // if available, then only can be used by their neighbour
                for (auto i : adj[recipes[top]]) {
                    inDegree[i]--;
                    if (inDegree[i] == 0) {
                        qu.push(mp[i]);
                    }
                }
            }
        }
        return ans;
    }
};