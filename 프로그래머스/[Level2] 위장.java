import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        Map<String,Integer> map = new HashMap<String,Integer>();
        for(int i=0; i<clothes.length; i++)
        {
            String name = clothes[i][0];
            String type = clothes[i][1];
            
            int count = map.containsKey(type) ? map.get(type) : 0;
            map.put(type, count+1);
        }
        
        answer = 1;
        
        for(Integer value : map.values())
        {
            answer*=value+1;
        }
        
        answer-=1;
        
        return answer;
    }
}