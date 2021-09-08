#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

// void split(const string& s, vector<string>& tokens, const string& delimiters = " ")
// {
//     string::size_type lastPos = s.find_first_not_of(delimiters, 0);
//     string::size_type pos = s.find_first_of(delimiters, lastPos);
//     while (string::npos != pos || string::npos != lastPos) {
//         tokens.emplace_back(s.substr(lastPos, pos - lastPos));
//         lastPos = s.find_first_not_of(delimiters, pos);
//         pos = s.find_first_of(delimiters, lastPos);
//     }
//     if(s[s.size()-1] == delimiters[0]){
//         tokens.emplace_back("");
//     }
// }

vector<string> split(const string &str, const char pattern)
{
    vector<string> res;
    stringstream input(str);   //读取str到字符串流中
    string temp;
    //使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
    //注意,getline默认是可以读取空格的
    while(getline(input, temp, pattern))
    {
        res.push_back(temp);
    }
    if(str[str.size()-1] == pattern){
        res.emplace_back("");
    }
    return res;
}

bool validIPV4Address(vector<string>& IPV4seg){
    if(IPV4seg.size() != 4){
        return false;
    }

    for(auto &e : IPV4seg){
        if(e == "" || (e.at(0) == '0' && e.size() > 1) || e < "0" || e > "255" || e.size() > 3){
            return false;
        }
    }
    return true;
}

bool validIPV6Address(vector<string>& IPV6seg){
    if(IPV6seg.size() != 8){
        return false;
    }

    for(auto &e : IPV6seg){
        if(e == "" || e.size() > 4 || e < "0" || e > "ffff"){
            cout << (e < "0") << " " <<(e > "ffff") << endl;
            cout << e << endl;
            return false;
        }
    }
    return true;
}

string validIPAddress(string IP){
    if(IP == "") return "Neither";

    vector<string>IPV4seg;
    IPV4seg = split(IP,  '.');
    if(validIPV4Address(IPV4seg)){
        return "IPv4";
    }

    for(auto &e : IP){
        if(e >= 'A' && e <= 'Z'){
            e += 32;
        }
    }
    vector<string>IPV6seg;
    IPV6seg = split(IP,  ':');
    if(validIPV6Address(IPV6seg)){
        return "IPv6";
    }

    return "Neither";
}

int main(void)
{
    string s = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    cout << validIPAddress(s) <<endl;
    return 0;
}


 