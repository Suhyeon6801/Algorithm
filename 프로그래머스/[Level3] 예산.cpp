#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> temp, int x, int M)
{
    long long sum=0;//->2번효율성
    for(int i=0; i<temp.size(); i++)
    {
        if(x>temp[i])
            sum+=temp[i];
        else
            sum+=x;
    }
    
    if(sum>M)
            return false;
    else
        return true;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    
    sort(budgets.begin(), budgets.end());
    int size=budgets.size();
    int start=0;
    int end=budgets[size-1];
    
    if(check(budgets,end,M))
    {
        answer=end;
        return answer;
    }
    
    while(start+1<end)
    {
        int mid=(start+end)/2;
        if(!check(budgets,mid,M))
            end=mid;
        else
            start=mid;
    }
      answer=start;

    
    return answer;
}