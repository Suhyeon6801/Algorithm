#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int NUM = 65536;
multiset<string> m1;
multiset<string> m2;

bool isAlpha(char c)
{
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')  return true;
    else    return false;
}

multiset<string> makeStr(string s)
{
    multiset<string> mul;
    for(int i=0; i<s.length()-1; i++)
    {
        string temp="";
        if(isAlpha(s[i]) && isAlpha(s[i+1]))
        {            
            temp+=toupper(s[i]);
            temp+=toupper(s[i+1]);

            mul.insert(temp);         
        }
    }
    return mul;
}

int solution(string str1, string str2) {
    int answer = 0;
    string str="";

    m1=makeStr(str1);
    m2=makeStr(str2);
    
    if(m1.size()==0 && m2.size()==0)
        answer=NUM;
    else
    {  
        double union_cnt=m2.size();
        double inter_cnt=0;
        double result;
        for(auto it=m1.begin(); it!=m1.end(); it++)
        {
            auto iter = find(m2.begin(), m2.end(), *it);
            if(iter!=m2.end())  
            {
                m2.erase(iter);
                inter_cnt++;
            }
            else    union_cnt++;
        }

        result=(inter_cnt/union_cnt);
        result*=NUM;

        answer=result;
    }
  
    return answer;
}