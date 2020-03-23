#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<pair<int,int>> v[10010];

int solution(vector<int> citations) {
    int answer = 0;
    int n=citations.size();

    sort(citations.begin(), citations.end(), greater<int>());
    
    int idx=0;
    while(idx<n)
    {
        if(citations[idx]<=idx)    break;
        idx++;
    }
    
    answer=idx;
    
    return answer;
}