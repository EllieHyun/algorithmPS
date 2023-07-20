class Solution {
    public int[] solution(int[] sequence, int k) {
       int[] answer = new int[2];
        int start = 0;
        int end = 0;
        int min = 2000000000;
        int minStart = start;
        int minEnd = start;
        int sum = 0;
        while (start < sequence.length) {
            // System.out.println("sum : " + sum);
            if (sum == k) {
                // System.out.println("same - start : " + start + ", end : " + end);
                if (min > end - start - 1) {
                    min = end - start - 1;
                    answer[0] = start;
                    answer[1] = end - 1;
                }
                sum -= sequence[start];
                start++;
            } else if (sum > k || end == sequence.length) {
                // System.out.println("over - start : " + start + ", end : " + end);
                sum -= sequence[start];
                start++;
            } else {
                // System.out.println("less - start : " + start + ", end : " + end);
                sum += sequence[end];
                end++;
            }
        }
        // answer = new int[2];
        // answer[0] = minStart;
        // answer[1] = minEnd;
    
        return answer;
    }
}