#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < moves.size(); i++)
    {
        int y = moves[i] - 1;

        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][y] != 0)
            {
                int temp = board[j][y];

                if (!st.empty())
                {
                    if (st.top() == temp)
                    {
                        answer += 2;
                        st.pop();
                    }
                    else
                        st.push(temp);
                }
                else
                    st.push(temp);

                board[j][y] = 0;
                break;
            }
        }
    }
    return answer;
}