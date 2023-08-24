import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int test = Integer.parseInt(br.readLine());
        for (int i = 0; i < test; i++) {
            String str = br.readLine();
            String[] list = str.split(" ");
            String origin = list[0];
            char[] originArray = origin.toCharArray();
            String anagram = list[1];
            char[] anagramArray = anagram.toCharArray();
            Arrays.sort(originArray);
            Arrays.sort(anagramArray);
            if(Arrays.equals(originArray, anagramArray)) {
                System.out.println(origin + " & " + anagram + " are anagrams.");
            } else {
                System.out.println(origin + " & " + anagram + " are NOT anagrams.");
            }
        }
    }
}