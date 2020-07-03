//으...어렵다..
//N을 사용하면서 일어나는 경우의 수를 모두 생각하기!!

#include <string>
#include <vector>
using namespace std;

int getMin = 9;

void func(int N, int number, int cnt, long long result)
{
    if (getMin < cnt)
        return;
    if (number == result)
    {
        if (getMin > cnt)
            getMin = cnt;
        return;
    }

    if (cnt == 8)
        return;
    else
    {
        int temp = 8 - cnt;
        for (int i = 1; i <= temp; i++)
        {
            int tail_max = i / 2;

            for (int j = 0; j <= tail_max; j++)
            {
                int head = 0;
                for (int k = 1; k <= i - j; k++)
                    head = head * 10 + N;

                int next = head;
                int tail = 0;
                for (int k = 1; k <= j; k++)
                    tail = tail * 10 + N;

                if (tail > 0)
                    next /= tail;
                func(N, number, cnt + i, result + next);
                func(N, number, cnt + i, result - next);
                func(N, number, cnt + i, result * next);
                func(N, number, cnt + i, result / next);
                func(N, number, cnt + i, result * (-1) * (next));
                func(N, number, cnt + i, result * (-1) / (next));
            }

            if (i > 2)
            {
                func(N, number, cnt + i, result);
                func(N, number, cnt + i, 0);
            }
        }
    }
}

int solution(int N, int number)
{
    int answer = 0;
    func(N, number, 0, 0);

    if (getMin > 8)
        answer = -1;
    else
        answer = getMin;

    return answer;
}