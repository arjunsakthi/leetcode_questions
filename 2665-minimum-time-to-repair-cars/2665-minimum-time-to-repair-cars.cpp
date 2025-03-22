class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1e14;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(canBeOnTime(ranks,cars,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    private:
    bool canBeOnTime(vector<int> &ranks, int cars, long long time){
        for(int i=0; i<ranks.size(); i++){
            int div = sqrt(time/(ranks[i]*1.0));
            cars -= div;
            if(cars <= 0) break;
        }
        return cars <= 0;
    }
};