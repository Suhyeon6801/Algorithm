#include <iostream>
#include <algorithm>
using namespace std;

struct Card
{
	char color;
	int num;
};

Card card[5];


bool comp(Card c1, Card c2)
{
	return c1.num < c2.num;
}

bool isSequence()
{
	sort(card, card + 5, comp);

	int val = card[1].num - card[0].num;

	for (int i = 1; i < 5; i++)
	{
		if (card[i].num - card[i - 1].num != val)	return false;
	}

	return true;
}

int findMax()
{
	int maxNum = -1;
	for (int i = 0; i < 5; i++)
	{
		if (maxNum < card[i].num)	maxNum = card[i].num;
	}

	return maxNum;
}

int findMin()
{
	int minNum = 10;
	for (int i = 0; i < 5; i++)
	{
		if (minNum > card[i].num)	minNum = card[i].num;
	}

	return minNum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	int n;
	int number[10] = { 0 };
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> c >> n;

		card[i].color = c;
		card[i].num = n;
	}

	//색깔 확인
	int R = 0, Y = 0, B = 0, G = 0;

	for (int i = 0; i < 5; i++)
	{
		if (card[i].color == 'R')	R++;
		else if (card[i].color == 'Y')	Y++;
		else if (card[i].color == 'B')	B++;
		else if (card[i].color == 'G')	G++;
	}

	//숫자 개수 확인
	for (int i = 0; i < 5; i++)
	{
		number[card[i].num]++;
	}

	int four = 0, three = 0, two1 = 0, two2 = 0;

	for (int i = 0; i < 10; i++)
	{
		if (number[i] == 4)	four = i;
		else if (number[i] == 3)	three = i;
	}

	for (int i = 0; i < 10; i++)
	{
		if (number[i] == 2)
		{
			two1 = i;
			
			for (int j = i + 1; j < 10; j++)
			{
				if (number[j] == 2)	two2 = j;
			}
			break;
		}
	}

	//cout << four << " " << three << " " << two1 << " " << two2 << endl;

	//1. 5장 모두 같은색 && 연속적 -> 가장 높은 숫자+900
	if ((R == 5 || Y == 5 || B == 5 || G == 5) && isSequence())
	{
		result = findMax() + 900;
	}
	//2. 5장 중 4장의 수가 같을 때 -> 같은 숫자+800
	else if (four != 0)
	{
		result = four + 800;
	}
	//3. 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 3장같은 숫자*10+두장 같은 숫자+700
	else if (three != 0 && two1 != 0)
	{
		result = three * 10 + two1 + 700;
	}
	//4. 5장의 카드 색깔만 같을 때 -> 가장 높은 숫자+600
	else if (R == 5 || Y == 5 || B == 5 || G == 5)
	{
		result = findMax() + 600;
	}
	//5. 5장의 숫자가 연속이기만 할 때 -> 가장 높은 수+500
	else if (isSequence())
	{
		result = findMax() + 500;
	}
	//6. 5장 중 3장의 숫자만 같을 때 -> 같은 수+400
	else if (three != 0 && two1 == 0)
	{
		result = three + 400;
	}
	//7. 2장만씩만 숫자가 같을 때 -> 같은 숫자 중 큰 수에*10+같은 숫자 중 작은 수 + 300
	else if (two1 != 0 && two2 != 0)
	{
		if (two1 > two2)	result = two1 * 10 + two2 + 300;
		else	result = two2 * 10 + two1 + 300;
	}
	//8. 2장의 숫자만 같을 때->숫자+200
	else if (two1 != 0 && two2 == 0)
	{
		result = two1 + 200;
	}
	//9. 어떤 경우도 해당 되지 않다면, 가장 큰 수+100
	else
	{
		result = findMax() + 100;
	}

	cout << result << "\n";
	return 0;
}
