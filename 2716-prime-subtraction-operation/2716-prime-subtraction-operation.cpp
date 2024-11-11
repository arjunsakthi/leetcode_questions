class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime = primes(1000);
        int diff = 1000;
        if(bsearch(prime,nums[0]) != -1){
            nums[0] -= bsearch(prime,nums[0]);
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1] <= 0)  return false;
            else{
                int diff = nums[i] - nums[i-1];
                int bval = bsearch(prime, diff);
                if(bval != -1){
                    nums[i] -= bval;
                }
            }
        }
        return true;
    }

    private:
        int bsearch(vector<int> &primes, int k){
            int low = 0;
            int high = primes.size()-1;
            int ans=-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(primes[mid] < k){
                    ans = primes[mid];
                    low = mid+1;
                }
                else{
                    high = mid - 1;
                }
            }
            return ans;
        }

        vector<int> primes(int n){
            vector<bool> primess(n+1,false);
            vector<int> prime;
            for(int i=2; i<=n; i++){
                if(primess[i] == false){
                    for(int j=i*i; j<=n; j+=i){
                        primess[j] = true;
                    }
                    prime.push_back(i);
                }                
            }
            
            return prime;
        }
};