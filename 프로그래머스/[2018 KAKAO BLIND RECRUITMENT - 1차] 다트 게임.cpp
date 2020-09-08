#include <string>
#include <iostream>
using namespace std;

int arr[110];

int solution(string dartResult) {
    int answer = 0;
    int num=0, idx=0;
    string temp="";
    
    for(int i=0; i<dartResult.length(); i++)
    {        
        char s = dartResult[i];
        if(s>='0'&&s<='9')  temp+=s;
        else if(s=='S')
        {
            num = stoi(temp);
            temp="";
            arr[idx++]=num;
        }
        else if(s=='D')
        {
            num = stoi(temp);
            temp="";
            arr[idx++]=num*num;
        }
        else if(s=='T')
        {
            num = stoi(temp);
            temp="";
            arr[idx++]=num*num*num;
        }
        else if(s=='*')
        {
            arr[idx-2]*=2;
            arr[idx-1]*=2;
        }
        else if(s=='#')
        {
            arr[idx-1]*=(-1);
        }
    }
    
    for(int i=0; i<idx; i++)
        answer+=arr[i];
    
    return answer;
}