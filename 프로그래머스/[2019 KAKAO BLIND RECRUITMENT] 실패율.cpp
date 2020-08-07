#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int check[510]={0,};

bool comp(pair<int,double> p1, pair<int, double>p2)
{
    if(p1.second>p2.second) return true;
    else if(p1.second==p2.second)   return p1.first<p2.first;
    else    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> v;
    map<int, double> mp;
    
    for(int i=0; i<stages.size(); i++)
        check[stages[i]]++;
    
    for(int i=1; i<=N; i++)
    {
        double p=(double)check[i];
        
        if(p==0.0)
            mp.insert(make_pair(i,0.0));
        else
        {
            double sum=0.0;
            for(int j=i; j<=N+1; j++)
                sum+=(double)check[j];
            
            mp.insert(make_pair(i,p/sum));
        }
    }
    
    for(auto it=mp.begin(); it!=mp.end(); it++)
        v.push_back(*it);
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++)
        answer.push_back(v[i].first);
    
    return answer;
}