#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getMin=987654321;
bool check[60];

bool isOk(string str1, string str2)//str1이랑 str2의 알파벳 1개만 바꾸기 가능한지 여부
{
    //단어의 길이는 모두 같으니까 길이는 노상관
    int cnt=0;
    for(int i=0; i<str2.length(); i++)
    {
        if(str1[i]!=str2[i])    cnt++;
        
        if(cnt>1)   return false;
    }
    
    if(cnt>1)   return false;
    else
        return true;
}

void f(int cnt, string cur, string target, vector<string> w)//순열구하기로 재귀 돌려버리기
{
    if(cur==target)//기저조건 target이랑 일치하면 끝!
    {
        getMin=min(getMin,cnt);
        return;
    }
    
    for(int i=0; i<w.size(); i++)
    {
        if(!check[i])
        {
            if(isOk(cur,w[i]))
            {
                check[i]=true;
                f(cnt+1, w[i], target, w);
                check[i]=false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool flag=false;
    
    //일단 벡터 안에 있는 거 중에서 target이 있는지 확인해보자!
    for(int i=0; i<words.size(); i++)
    {
        if(words[i]==target)
        {
            flag=true;
            break;
        }
    }
    
    if(!flag)   answer=0;
    else
    {
        f(0,begin,target, words);
        answer=getMin;
    }
    
    return answer;
}