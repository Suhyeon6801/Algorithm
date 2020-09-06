#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first>p2.first;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mp;
    vector<pair<int,int>> v;
    int len=s.length();
    string temp="";
    
    for(int i=1; i<len-1; i++)
    {
        if(s[i]=='{')
        {
            int j=i+1;
            while(1)
            {
                if(s[j]=='}')
                {
                    int n=stoi(temp);
                    temp="";
                    mp[n]++;
                    break;
                }
                else if(isdigit(s[j]))
                    temp+=s[j];
                else if(s[j]==',')
                {
                    int n=stoi(temp);
                    temp="";
                    mp[n]++;
                }
                
                j++;
            }
        }
    }
    
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        v.push_back({it->second, it->first});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++)
        answer.push_back(v[i].second);
    
    return answer;
}