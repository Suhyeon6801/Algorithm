import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> st = new Stack<>();
        
        for(int i=0; i<s.length(); i++)
        {
            char temp = s.charAt(i);
            if(temp=='(')
                st.push(temp);
            else
            {
                if(st.empty())  return false;
                else
                {
                    if(st.peek()=='(')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        
        if(!st.empty()) return false;
        
        return answer;
    }
}