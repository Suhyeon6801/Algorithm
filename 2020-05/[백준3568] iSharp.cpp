#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	getline(cin,str);

	string var;
	int var_cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			var_cnt++;
			break;
		}
		var += str[i];
		var_cnt++;
	}

	vector<string> v;
	string temp = "";
	for (int i = var_cnt; i < str.length(); i++)
	{
		if (str[i] == ' '|| i==str.length()-1)
		{
			v.push_back(temp);
			temp = "";
		}
		else if (str[i] == ',')	continue;
		else
			temp += str[i];
	}

	for (int i = 0; i < v.size(); i++)
	{
		string alpha = "";
		string other = "";
		string result = "";
		for (int j = 0; j < v[i].length(); j++)
		{
			if (isalpha(v[i][j]))
				alpha += v[i][j];
			else
			{
				for (int k = v[i].length() - 1; k >= j; k--)
				{
					if (v[i][k]== ']')
					{
						other += v[i][k-1];
						other += v[i][k];
						k -= 1;
					}
					else
						other += v[i][k];
				}
				break;
			}
		}

		result += var;
		result += other;
		result += ' ';
		result += alpha;
		result += ';';

		cout << result << "\n";
	}
	
	return 0;
}