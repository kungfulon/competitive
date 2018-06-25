import java.io.*;
import java.util.*;

public final class TaskB {
    ArrayList<Integer> palindromeNumbers = new ArrayList<>();

    boolean isPalindrome(int k) {
        String s = Integer.toString(k);

        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }

        return true;
    }

    void init() {
        for (int k = 1; k <= 10000; ++k) {
            if (!isPalindrome(k)) {
                continue;
            }

            palindromeNumbers.add(k);
        }
    }

    int[] solution() {
        int n = cin.nextInt();

        if (isPalindrome(n)) {
            return new int[] {n};
        }

        for (int i = 0; i < palindromeNumbers.size(); ++i) {
            for (int j = 0; j < palindromeNumbers.size(); ++j) {
                int u = palindromeNumbers.get(i), v = palindromeNumbers.get(j);

                if (u + v > n) {
                    break;
                }

                if (u + v == n) {
                    return new int[] {u, v};
                }
            }
        }

        for (int i = 0; i < palindromeNumbers.size(); ++i) {
            for (int j = 0; j < palindromeNumbers.size(); ++j) {
                int u = palindromeNumbers.get(i), v = palindromeNumbers.get(j);

                if (u + v > n) {
                    break;
                }

                for (int k = 0; k < palindromeNumbers.size(); ++k) {
                    int t = palindromeNumbers.get(k);

                    if (u + v + t > n)
                        break;

                    if (u + v + t == n) {
                        return new int[] {u, v, t};
                    }
                }
            }
        }

        return new int[] {};
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    InputReader cin = new InputReader(System.in);
    PrintWriter cout = new PrintWriter(System.out);

    TaskB() {
        init();
        int t = cin.nextInt();

        for (int i = 1; i <= t; ++i) {
            int[] ans = solution();
            System.out.printf("Case #%d\n%d", i, ans.length);

            for (int v : ans) {
                System.out.printf(" %d", v);
            }

            System.out.println();
        }

        cout.close();
    }

    public static void main(String args[]) {
        new TaskB();
    }
}
