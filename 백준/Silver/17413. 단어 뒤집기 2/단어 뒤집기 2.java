import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '<') {
                while (!stack.isEmpty()) {
                    Character c = stack.pop();
                    System.out.print(c);
                }
//                System.out.print(str.charAt(i));
                while (str.charAt(i) != '>') {
                    System.out.print(str.charAt(i));
                    i++;
                }
                System.out.print(str.charAt(i));
            } else if(str.charAt(i) == ' ') {
                // 공백을 만나면 이전 문자 출력
                while (!stack.isEmpty()) {
                    Character c = stack.pop();
                    System.out.print(c);
                }
                System.out.print(str.charAt(i));
            } else {
                stack.push(str.charAt(i));
            }
        }
        while (!stack.isEmpty()) {
            Character c = stack.pop();
            System.out.print(c);
        }
    }
}
