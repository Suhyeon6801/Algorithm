#include <string>
#include <vector>
#include <iostream>
using namespace std;

int order[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx=1;
    for(int i=0; i<skill.length(); i++)
    {
        int a = skill[i]-'A';
        order[a]=idx++;
    }
    
    for(int i=0; i<skill_trees.size(); i++)
    {
        int cur=1;
        bool flag=true;
        for(int j=0; j<skill_trees[i].length(); j++)
        {
            int next=skill_trees[i][j]-'A';
            if(order[next]>cur)
            {
                flag=false;
                break;
            }
            
            if(order[next]==cur)
                cur++;
        }
        
        if(flag)    answer++;
    }
    return answer;
}