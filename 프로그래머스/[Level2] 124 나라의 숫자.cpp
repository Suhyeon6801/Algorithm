#include <string>
#include <vector>

using namespace std;

string numbers[3]={"4","1","2"};

string solution(int n) {
    string answer = "";
    int num=n;
    
    while(num>0)
    {
        int temp = num%3;
        num/=3;
        
        if(temp==0)
            num--;
           
        answer=numbers[temp]+answer;
    }
       
    return answer;
}