#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num[1000];
int cnt;

void check(int ques, int st, int ba)
{
    int arr[3]={0,};//ques쪼개서 담는 배열
    int arr2[3]={0,};//num쪼개서 담는 배열
    arr[0]=ques/100;
    arr[1]=(ques/10)%10;
    arr[2]=ques%10;

    cnt=0;

    for(int i=123; i<=987; i++)
    {
        if(num[i]!=ques&&num[i]!=0)
        {
            arr2[0]=num[i]/100;
            arr2[1]=(num[i]/10)%10;
            arr2[2]=num[i]%10;
        }
        
        int s=0, b=0;
        if(arr2[0]!=0&&arr2[1]!=0&&arr2[2]!=0)
        {
            if(arr2[0]!=arr2[1]&&arr2[0]!=arr2[2]&&arr2[1]!=arr2[2])
            {
                if(arr[0]==arr2[0]) s++;
                if(arr[1]==arr2[1]) s++;
                if(arr[2]==arr2[2]) s++;
                
                if(arr2[0]==arr[1]||arr2[0]==arr[2])    b++;
                if(arr2[1]==arr[0]||arr2[1]==arr[2])    b++;
                if(arr2[2]==arr[0]||arr2[2]==arr[1])    b++;
                        
                if(st==s&&ba==b&&num[i]!=0)
                {
                    cnt++;
                }
                else
                    num[i]=0;
            }
        }
    }
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int q, strike, ball;
    for(int i=123; i<=987; i++)
    {
        num[i]=i;
    }
    
    for(int i=0; i<baseball.size(); i++)
    {
        q=baseball[i][0];
        strike=baseball[i][1];
        ball=baseball[i][2];

        check(q,strike,ball);
    }
    
    answer=cnt;
    
    return answer;
}