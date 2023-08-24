import java.util.*;

class Solution
{
    int max = -1;
    
    public int solution(String s)
    {
        int answer = 0;
        for(int i=s.length(); i>=0; i--) {
            // 팰린드롬의 길이
            for(int j=0; j + i <= s.length(); j++) {
                if(isPalindrome(j, j+i-1, s)) return i;
            }
            
        }    
        return 0;
    }
    
    
    private boolean isPalindrome(int start, int end, String str) {
        while(start <= end) {
            if(str.charAt(start) == str.charAt(end)) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
}