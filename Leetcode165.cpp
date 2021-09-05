#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compareVersion(string version1, string version2)
{
    int len1=version1.size();
    int len2=version2.size();
    int end=max(len1,len2);
    for(int index1=0,index2=0;index1<end||index2<end;++index1,++index2)
    {
        int value1=0;
        int value2=0;
        while(index1<len1&&version1[index1]!='.')
        {
            value1=value1*10+version1[index1]-'0';
            index1++;
        }
        while(index2<len2&&version2[index2]!='.')
        {
            value2=value2*10+version2[index2]-'0';
            index2++;
        }
        if(value1>value2)
        {
            return 1;
        }
        else if(value1<value2)
        {
            return -1;
        }
    }
    return 0;
}

int main(void)
{
    string version1="1.01";
    string version2="1.001";
    cout<<compareVersion(version1,version2)<<endl;
    return 0;
}