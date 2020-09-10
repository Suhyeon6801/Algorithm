import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        int count=0;
        Map<String, Integer> map = new HashMap<String, Integer>();
        
        for(int i=0; i<participant.length; i++)
        {
            count = map.containsKey(participant[i]) ? map.get(participant[i]) : 0;
            map.put(participant[i], count+1);
        }
        
        for(int i=0; i<completion.length; i++)
        {
            count = map.containsKey(completion[i]) ? map.get(completion[i]) : 0;
            map.put(completion[i], count-1);
        }
        
        for(String key : map.keySet())
        {
            int val = map.get(key);
            if(val==1)
                answer = key;
        }
        return answer;
    }
}