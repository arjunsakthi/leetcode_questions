class Solution {
public:
    int numOfSubarrays(vector<int>& arr)
    {
        int e = 0;
        int o = 0;
        int ans = 0;
        int n = arr.size();
        int mod = (int)(1e9+7);
        vector<int> v(n,0);
        v[0] = arr[0];
        for(int i = 1;i<n;i++)
        {
            v[i] = arr[i] + v[i-1];
        }
        for(int i = 0;i<n;i++)
        {
            if(v[i]%2!=0)
            {
                ans = (ans +1 )%mod;
                ans = (ans +e )%mod;
                o++;
            }
            else
            {
                ans = (ans +o )%mod;
                e++;
            }
        }
        return ans;
    }
};