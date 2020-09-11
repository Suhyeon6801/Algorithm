import java.util.*;

public class Pair implements Comparable<Pair>{
    String genre;
    Integer play;
    public Pair(String genre, Integer play){
        this.genre = genre;
        this.play=play;
    }
    public String first(){
        return genre;
    }
    public Integer second(){
        return play;
    }
    public int compareTo(Pair p){
        return p.play-play;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        //int[] answer = {};
        HashMap<String,Integer> map = new HashMap<>();
        ArrayList<Pair> list = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        
        for(int i=0; i<genres.length; i++)
        {
            int count = map.containsKey(genres[i]) ? map.get(genres[i]) : 0;
            map.put(genres[i], count+plays[i]);
        }
        
        for(String key : map.keySet())
        {
            int value = map.get(key);
            Pair pair = new Pair(key, value);
            list.add(pair);
        }
        
        Collections.sort(list);//재생 횟수가 많은 순으로 정렬
        
        for(int i=0; i<list.size(); i++)
        {
            for(int j=0; j<2; j++)
            {
                int idx=-1;
                int getMax = -1;
                for(int k=0; k<genres.length; k++)
                {
                    if(genres[k].equals(list.get(i).first()) && plays[k]>getMax)
                    {
                        getMax=plays[k];
                        idx=k;
                    }
                }
                
                if(idx!=-1)
                {
                    result.add(idx);
                    plays[idx]=-1;
                }
            }
        }
        
        int[] answer = new int[result.size()];
        for(int i=0; i<result.size(); i++)
            answer[i]=result.get(i);
        
        return answer;
    }
}