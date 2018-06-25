import java.io.*;
import java.util.*;

public final class VCOLDWAT {
    int n, c;
    int[] d;
    int[][] a;

    void solution() {
        n = cin.nextInt();
        c = cin.nextInt();
        d = new int[n + 1];
        a = new int[n + 1][2];

        for (int i = 0; i <= n; ++i) {
            d[i] = -1;
            a[i][0] = a[i][1] = -1;
        }

        for (int i = 0; i < c; ++i) {
            int u = cin.nextInt();
            a[u][0] = cin.nextInt();
            a[u][1] = cin.nextInt();
        }

        a[0][0] = 1;
        d[0] = 0;
        LinkedList<Integer> q = new LinkedList<>();
        q.add(0);

        while (!q.isEmpty()) {
            int u = q.peekFirst();
            q.removeFirst();

            for (int v : a[u]) {
                if (v == -1 || d[v] != -1) {
                    continue;
                }

                d[v] = d[u] + 1;
                q.add(v);
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout.println(d[i]);
        }
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

    VCOLDWAT() {
        solution();
        cout.close();
    }

    public static void main(String args[]) {
        new VCOLDWAT();
    }
}
