class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n+1,true);//质数
        flag[0]=flag[1]=false;
        for(int i=2;i<sqrt(n);i++)
        {
            if(flag[i])
            {
                for(int j=2;j*i<=n;j++)
                {
                    flag[j*i]=false;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(flag[i])
                ans++;
        return ans;
    }
};
