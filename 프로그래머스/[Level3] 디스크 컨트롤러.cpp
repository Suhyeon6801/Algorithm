#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

struct comp{//-> 이게 좀 난해했던것 같음..ㅠㅠㅠ
   bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int i=0, time=0;
    sort(jobs.begin(), jobs.end());//요청 시점으로 정렬
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    
    while(!pq.empty() || i<jobs.size())
    {
        if(jobs.size()>i && time>=jobs[i][0])
        {
            pq.push(jobs[i++]);
            continue;//if문 벗어나지 않도록
        }
        
        if(!pq.empty())
        {
            time+=pq.top()[1];
            answer+=(time-pq.top()[0]);
            pq.pop();
        }
        else
            time = jobs[i][0];
    }
    
    answer/=jobs.size();
    
    return answer;
}