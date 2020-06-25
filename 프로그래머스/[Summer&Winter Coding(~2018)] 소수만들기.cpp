#include <vector>
#include <cmath>
using namespace std;

const int MAX=50*1001;//50개가 모두 1000
int prime[MAX];

int solution(vector<int> nums) {
    int answer = -1;
    
    prime[0]=1;
    prime[1]=1;
    for(int i=2; i<=sqrt(MAX); i++)
    {
        for(int j=i*i; j<MAX; j+=i)
            prime[j]=1;
    }
    
    int sum=0, cnt=0;
    for(int i=0; i<nums.size() -2; i++)
    {
        for(int j=i+1; j<nums.size()-1; j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                sum+=(nums[i]+nums[j]+nums[k]);
                if(prime[sum]==0)
                    cnt++;
                sum=0;
            }
        }
    }
    answer=cnt;
    return answer;
}