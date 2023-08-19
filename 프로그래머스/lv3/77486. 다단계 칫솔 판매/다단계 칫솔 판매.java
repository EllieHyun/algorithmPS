import java.util.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int enrollLength = enroll.length;
        int[] answer = new int[enrollLength];
        // 직원 -> 추천한 사람
        HashMap<String, String> referralMap = new HashMap<String, String>();
        // 각 직원이 몇번째 인덱스를 가지는 사람인지
        HashMap<String, Integer> indexMap = new HashMap<String, Integer>();
        //
        for(int i=0; i<enroll.length; i++) {
            String child = enroll[i];
            String parent = referral[i];
            referralMap.put(child, parent);
            indexMap.put(child, i);
        }
        
        
        for(int i=0; i<seller.length; i++) {
            String now = seller[i];
            int profit = amount[i]  * 100;
            while(!now.equals("-")) {
                int profitForParent = profit / 10;   // 부모에게 줄 이득
                int nowProfit = profit - profitForParent;   // 내가 가질 이득
                answer[indexMap.get(now)] += nowProfit;   // 내가 먼저 이득을 가짐
                
                now = referralMap.get(now);  // 내가 이득을 줄 부모
                profit /= 10;   // 기존의 이득을 10으로 나눔
                
                if(profit < 1) {
                    break;
                }
            }
        }
        return answer;
    }
}