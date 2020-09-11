import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        ArrayList<Integer> list = new ArrayList<Integer>();
        String[] temp = s.split(" ");
        
        for(int i=0; i<temp.length; i++)
            list.add(Integer.parseInt(temp[i]));
        
        answer = Collections.min(list)+" "+Collections.max(list);
        
        return answer;
    }
}