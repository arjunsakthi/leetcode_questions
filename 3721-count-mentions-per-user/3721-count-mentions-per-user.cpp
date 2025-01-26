class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> activeTime(numberOfUsers, -1);
        sort(events.begin(), events.end(),
             [](vector<string>& s1, vector<string>& s2) {
                 if (stoi(s1[1]) == stoi(s2[1])) {
                     return s1[0][0] > s2[0][0];
                 }
                 return stoi(s1[1]) < stoi(s2[1]);
             });
        for (int i = 0; i < events.size(); i++) {

            vector<string> curr = events[i];
            string mType = curr[0];
            int timeStamp = stoi(curr[1]);
            if (mType == "MESSAGE") {
                if (curr[2] == "HERE") {
                    for (int j = 0; j < numberOfUsers; j++) {
                        if (activeTime[j] <= timeStamp) {
                            mentions[j]++;
                        }
                    }
                } else if (curr[2] == "ALL") {
                    for (int j = 0; j < numberOfUsers; j++) {
                        mentions[j]++;
                    }
                } else {
                    int j = 0;
                    while (j < curr[2].size()) {
                        if (curr[2][j] == 'd') {
                            j++;
                            string temp = "";
                            while (j < curr[2].size() &&
                                   curr[2][j] != ' ') {
                                temp.push_back(curr[2][j]);
                                j++;
                            }
                            int id = stoi(temp);
                            
                                mentions[id]++;
                         
                        }
                        j++;
                    }
                }
                for (int j = 0; j < numberOfUsers; j++) {
                        cout << mentions[j] << " ";
                    }
                    cout << endl;

            } else {
                int id = stoi(curr[2]);
                activeTime[id] = timeStamp + 60;
            }
        }
        return mentions;
    }
};