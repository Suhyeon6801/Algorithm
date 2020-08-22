#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char mapArr1[20][20];
char mapArr2[20][20];

string makeBinary(int num, int n)
{
    string temp="";
    while(num>0)
    {
        if(num%2==1)    temp+="1";
        else    temp+="0";
        
        num/=2;
    }
    
    reverse(temp.begin(), temp.end());
    
    if(temp.length()<n)
    {
        string str="";
        for(int i=0; i<n-temp.length(); i++)
            str+="0";
        
        str+=temp;
        return str;
    }
    else
        return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<arr1.size(); i++)
    {
        string str=makeBinary(arr1[i],n);
        for(int j=0; j<str.length(); j++)
            mapArr1[i][j]=str[j];
        
        string str2 = makeBinary(arr2[i],n);
        for(int j=0; j<str2.length(); j++)
            mapArr2[i][j]=str2[j];
    }
    
    for(int i=0; i<n; i++)
    {
        string temp="";
        for(int j=0; j<n; j++)
        {
            if(mapArr1[i][j]=='0' && mapArr2[i][j]=='0')
                temp+=" ";
            else
                temp+="#";
        }
        answer.push_back(temp);
    }
    
    return answer;
}