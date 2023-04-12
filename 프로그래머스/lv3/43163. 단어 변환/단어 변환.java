import java.util.*;

class Word {
    String thisWord;
    int thisCount;
    Word(String THISWORD, int THISCOUNT) {
        this.thisWord = THISWORD;
        this.thisCount = THISCOUNT;
    }
}

class Solution {
    boolean canChange(String begin, String word) {
        int length = begin.length();
        int diff = 0;
        for (int i = 0; i < length; i++) {
            if (begin.charAt(i) != word.charAt(i))
                diff++;
            if (diff >= 2)
                return false; // 서로 다른 문자가 두 개 이상이면 바꿀 수 없음
        }
        if (diff == 1)
            return true; // 서로 다른 문자가 하나일 때 바꿀 수 있음
        return false; // 서로 다른 문자가 없다면 바꿀 필요 없음
    }

    public int solution(String begin, String target, String[] words) {
        // 완성하려는 단어가 words에 없다면 0 반환
        if (!Arrays.asList(words).contains(target))
            return 0;

        int answer = 0;
        Queue<Word> q = new LinkedList<>();
        boolean[] visited = new boolean[50]; // 해당 단어를 사용했는지 확인

        for (int i = 0; i < words.length; i++) {
            if (canChange(begin, words[i])) {
                // 바꿀 수 있는 첫 번째 문자를 찾음
                q.offer(new Word(words[i], 1));
                visited[i] = true; // 해당 문자 방문
            }
        }

        while (!q.isEmpty()) {
            Word cur = q.poll();
            String curWord = cur.thisWord;
            int curCount = cur.thisCount;
            if (curWord.equals(target)) {
                answer = curCount;
                break;
            }
            for (int i = 0; i < words.length; i++) {
                if (!visited[i] && canChange(curWord, words[i])) {
                    q.offer(new Word(words[i], curCount + 1));
                }
            }
        }

        return answer;
    }
}
