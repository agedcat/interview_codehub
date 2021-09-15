#include<iostream>
#include<string>
#include<map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<sstream>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int preMin=prices[0];
    int maxPro=INT32_MIN;

    for(int i=1;i<prices.size();++i)
    {
        int curPro=prices[i]-preMin;
        maxPro=max(curPro,maxPro);
        preMin=min(prices[i],preMin);
    }
    if(maxPro<0) return 0;
    return maxPro;
}

