#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

    int maxProfit(vector<int>& prices,int time) {
        int len=prices.size();
        if(len==0) return 0;
        int max_k=time+1;
        vector<vector<int>> sun(max_k,vector<int>(2,0));
        vector<vector<vector<int>>> dp(len,sun);
        for(int i=0;i<len;++i)
        {
            for(int k=1;k<max_k;++k)
            {
                if(i==0)
                {
                    dp[0][k][0]=0;
                    dp[0][k][1]=-prices[0];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[len-1][2][0];
    }

    int main()
    {
        vector<int> prices;
        int x;
        int k=2;
        cout<<"enter the array of prices: ";
        for(int i=0;i<6;++i)
        {
            cin>>x;
            prices.push_back(x);
        }
        int res=maxProfit(prices,k);
        cout<<endl<<"the result is: "<<res<<endl;
        return 0;
    }