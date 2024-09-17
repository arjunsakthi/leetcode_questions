class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> time;
        for(int i=0; i<timePoints.size(); i++){
            string temp="";
            pair<int,int> tempint;
            for(int j=0; j<5; j++){
                if(timePoints[i][j] == ':'){
                    tempint.first = stoi(temp);
                    temp = "";
                    continue;
                }
                temp += timePoints[i][j];
            }
            tempint.second = stoi(temp);
            time.push_back(tempint);
        }

        sort(time.begin(),time.end());
        int mini = INT_MAX;
        for(int i=1; i<time.size(); i++){
            int one = time[i].first;
            int prevone = time[i-1].first;
            int two = time[i].second;
            int prevtwo = time[i-1].second;
            int mindiff = two-prevtwo;
            mini = min(abs(one-prevone)*60+mindiff,mini);
        }
        int one = time[time.size()-1].first;
        int prevone = time[0].first;
        int two = time[time.size()-1].second;
        int prevtwo = time[0].second;
        int hourdiff = 24 - (one-prevone);
        int mindiff = prevtwo-two;
        mini = min(hourdiff*60+mindiff,mini);
        return mini;
        }
};