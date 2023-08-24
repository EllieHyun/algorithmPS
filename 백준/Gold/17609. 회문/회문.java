import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        for (int i = 0; i < test; i++) {
            String str = br.readLine();
            if (checkPalindrome(0, str.length() - 1, str)) System.out.println(0);
            else if (checkAfter(0, str.length() - 1, str)) System.out.println(1);
            else System.out.println(2);
        }
    }

    private static boolean checkPalindrome(int start, int end, String str) {
        while (start <= end) {
            if (str.charAt(start) != str.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }

    // 0 : 회문, 1 : 유사 회문, 2 : 아무것도 아님
    private static boolean checkAfter(int start, int end, String str) {

        while (start <= end) {
            if (str.charAt(start) != str.charAt(end)) {
                boolean flag1 = checkPalindrome(start + 1, end, str);
                boolean flag2 = checkPalindrome(start, end - 1, str);
                return flag1 || flag2;   // 둘 중 하나라도 회문을 만족하면 유사회문
            }
            start++;
            end--;
        }
        return true;
    }
}