#include <string>
#include <vector>

using namespace std;

int result=0;

void f(vector<int> numbers, int target, int sum, int len)
{
    if(len==numbers.size())
    {
        if(sum==target)
            result++;
        return;
    }
    
    f(numbers, target, sum+numbers[len], len+1);
    f(numbers, target, sum-numbers[len], len+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    f(numbers, target, 0, 0);
    
    answer=result;
    
    return answer;
}