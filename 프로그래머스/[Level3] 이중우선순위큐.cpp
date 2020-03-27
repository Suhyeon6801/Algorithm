#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstdlib>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> mul;
    string cmd, oper;
    int num;
    
    for(int i=0; i<operations.size(); i++)
    {
        oper=operations.at(i);
        cmd=oper[0];
        num=stoi(oper.substr(2));
        
        if(cmd=="I")
        {
            mul.insert(num);
        }
        else
        {
            if(!mul.empty())
            {
                if(num==1)
                {
                    auto it=mul.end();
                    it--;
                    mul.erase(it);
                }
                else
                    mul.erase(mul.begin());
            }
        }
    }
    
    if(mul.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        auto iter=mul.begin();
        auto it=mul.end();
        it--;
        
        answer.push_back(*it);
        answer.push_back(*iter);
    }
    
    
    return answer;
}