import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int left=0, right=0, k=0;
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i=0; i<commands.length; i++)
        {
            left = commands[i][0]-1;
            right = commands[i][1]-1;
            k = commands[i][2]-1;
            
            for(int j=left; j<=right; j++)
                arr.add(array[j]);
            
            Collections.sort(arr);
            answer[i]=arr.get(k);
            
            arr.clear();
        }
        
        return answer;
    }
}