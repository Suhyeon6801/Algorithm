#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> mp;
vector<pair<string, int>> v;

bool comp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++)
    {
        if (mp.count(genres[i]) == 0)
        {
            mp.insert(make_pair(genres[i], plays[i]));
        }
        else
        {
            auto it = mp.find(genres[i]);
            int p = it->second + plays[i];

            mp.erase(it);
            mp.insert(make_pair(genres[i], p));
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back(*it);

    sort(v.begin(), v.end(), comp); //재생횟수가 많은 순으로 정렬

    //고유번호 찾기.
    for (int i = 0; i < v.size(); i++)
    {
        for (int k = 0; k < 2; k++) //두개씩
        {
            int idx = -1;
            int max = -1;
            for (int j = 0; j < genres.size(); j++)
            {
                if (genres[j].compare(v[i].first) == 0 && plays[j] > max)
                {
                    max = plays[j];
                    idx = j;
                }
            }

            if (idx != -1)
            {
                answer.push_back(idx);
                plays[idx] = -1;
            }
        }
    }

    return answer;
}