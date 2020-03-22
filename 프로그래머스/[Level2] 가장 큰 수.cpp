#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2)
{
	if (s1 == s2)	return false;

	string temp1 = s1 + s2;
	string temp2 = s2 + s1;

	if (temp1 > temp2)	return true;
	else
		return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    bool flag=false;
	for (int i = 0; i < numbers.size(); i++)
	{
        if(numbers[i]!=0) flag=true;
        
		string str = to_string(numbers[i]);
		v.push_back(str);
	}
    
    if(!flag)//모두 0일 경우   
    {
        answer="0";
    }
	else
    {
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < v.size(); i++)
            answer+=v[i];
    }
    
    return answer;
}