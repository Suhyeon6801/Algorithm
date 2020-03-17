#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer_w, answer_h;

bool check(int width, int height, int b)
{
    if(width*2+height*2+4==b)
    {
        answer_w=width+2;
        answer_h=height+2;
        return true;
    }
    else
        return false;
}

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int temp=red;
    while(1)
    {
        int w=temp;
        int h;
        if(red%temp==0)
            h=red/temp;
        else
            h=red/temp+1;
        
        if(check(w,h,brown))
        {
            answer.push_back(answer_w);
            answer.push_back(answer_h);
            break;
        }
        
        temp--;
    }
    return answer;
}