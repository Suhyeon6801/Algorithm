#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

string make_upper(string s)
{
    string temp="";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='a'&&s[i]<='z')    temp+=s[i]-'a'+'A';
        else    temp+=s[i];
    }
    return temp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize==0)    return cities.size()*5;
    else
    {
        vector<string> v;
        for(int i=0; i<cities.size(); i++)
        {
            string temp = make_upper(cities[i]);

            auto it = find(v.begin(), v.end(), temp);
            if(it!=v.end())
            {
                answer+=1;
                v.erase(it);
            }
            else
            {
                answer+=5;
                if(v.size()!= 0 && v.size()==cacheSize)
                    v.erase(v.end());
            }
            
            v.insert(v.begin(), temp);
        }
        
    }
    
    return answer;
}