import java.util.*;

class Music implements Comparable<Music> {
    int index;
    int play;
    
    public Music(int index, int play) {
        this.index = index;
        this.play = play;
    }
    
    @Override
    public int compareTo(Music music) {
        if (music.play < play) {
            return -1;
        } else if(music.play > play) {
            return 1;
        } else {
            if(music.index < index) {
                return 1;
            } else {
                return -1;
            }
        }
    }
}

class Solution {

    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        HashMap<String, ArrayList<Music>> genreMap = new HashMap<>();
        HashMap<String, Integer> sumMap = new HashMap<>();
        
        for(int i=0; i<genres.length; i++) {
            String genre = genres[i];
            int play = plays[i];
            if(genreMap.containsKey(genre)) {
                ArrayList<Music> list = genreMap.get(genre);
                list.add(new Music(i, play));
                genreMap.put(genre, list);
                
                int newSum = sumMap.get(genre);
                newSum += play;
                sumMap.put(genre, newSum);
            } else {
                ArrayList<Music> list = new ArrayList<>();
                Music music = new Music(i, play);
                list.add(music);
                genreMap.put(genre, list);
                
                sumMap.put(genre, play);
            }
        }
        
        ArrayList<String> keys = new ArrayList<>(sumMap.keySet());
        Collections.sort(keys, (v1, v2) -> sumMap.get(v2).compareTo(sumMap.get(v1)));
        
        for(String key : keys) {
            // System.out.println(key + " : " + sumMap.get(key));
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        
        for(String key : keys) {
            // System.out.println("key : " + key);
            ArrayList<Music> musicList = genreMap.get(key);
            if(musicList.size() >= 2) {
                Collections.sort(musicList);
                list.add(musicList.get(0).index);
                list.add(musicList.get(1).index);
            } else {
                list.add(musicList.get(0).index);
            }
        }
        
        for(int l : list) {
            System.out.print(l + " ");
        }
        
        answer = new int[list.size()];
        
        for(int i=0; i<list.size(); i++) {
            answer[i] = list.get(i);
        }
        
    
        return answer;
    }
}