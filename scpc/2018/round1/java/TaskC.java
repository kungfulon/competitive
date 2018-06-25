import java.io.*;
import java.util.*;

public final class TaskC {
    int solution() {
        int n = cin.nextInt(), m = cin.nextInt();
        ArrayList<HashSet<Integer>> a = new ArrayList<>();
        LinkedList<Integer> l2 = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            a.add(new HashSet<>());
        }

        for (int i = 0; i < m; ++i) {
            int u = cin.nextInt() - 1, v = cin.nextInt() - 1;
            a.get(u).add(v);
            a.get(v).add(u);
        }

        for (int i = 0; i < n; ++i) {
            if (a.get(i).size() == 2) {
                l2.push(i);
            }
        }

        int ans = n;

        while (!l2.isEmpty()) {
            int u = l2.peekFirst();
            l2.removeFirst();

            if (a.get(u).size() != 2) {
                continue;
            }

            int i = 0;
            int v[] = new int[2];

            for (int vv : a.get(u)) {
                v[i++] = vv;
            }

            if (a.get(v[0]).contains(v[1])) {
                --ans;
                a.get(v[0]).remove(u);
                a.get(v[1]).remove(u);

                if (a.get(v[0]).size() == 2) {
                    l2.push(v[0]);
                }

                if (a.get(v[1]).size() == 2) {
                    l2.push(v[1]);
                }
            }
        }

        return ans;
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

    TaskC() {
        int t = cin.nextInt();

        for (int i = 1; i <= t; ++i) {
            int ans = solution();
            System.out.printf("Case #%d\n%d\n", i, ans);
        }

        cout.close();
    }

    public static void main(String args[]) {
        new TaskC();
    }
}
