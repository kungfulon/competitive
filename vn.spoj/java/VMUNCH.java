    import java.io.*;
    import java.util.*;
    import java.util.concurrent.LinkedBlockingDeque;

    public final class VMUNCH {
        Scanner cin = new Scanner(System.in);
        PrintStream cout = System.out;

        final int[] XX = new int[] { 0, 0, -1, 1 };
        final int[] YY = new int[] { 1, -1, 0, 0 };

        VMUNCH() {
            int n = cin.nextInt(), m = cin.nextInt();
            char[][] a = new char[n][m];
            boolean[][] visited = new boolean[n][m];
            int sx = 0, sy = 0, ex = 0, ey = 0;

            for (int i = 0; i < n; ++i) {
                String line = cin.next();

                for (int j = 0; j < m; ++j) {
                    a[i][j] = line.charAt(j);

                    if (a[i][j] == 'B') {
                        sx = i;
                        sy = j;
                    }

                    if (a[i][j] == 'C') {
                        ex = i;
                        ey = j;
                    }
                }
            }

            LinkedBlockingDeque<int[]> q = new LinkedBlockingDeque<>();
            q.add(new int[]{sx, sy, 0});
            visited[sx][sy] = true;

            while (!q.isEmpty()) {
                int x = q.peekFirst()[0], y = q.peekFirst()[1], c = q.peekFirst()[2];
                q.removeFirst();

                if (x == ex && y == ey) {
                    cout.print(c);
                    break;
                }

                for (int i = 0; i < 4; ++i) {
                    int u = x + XX[i], v = y + YY[i];

                    if (u < 0 || u >= n || v < 0 || v >= m || a[u][v] == '*' || visited[u][v]) {
                        continue;
                    }

                    q.add(new int[]{u, v, c + 1});
                    visited[u][v] = true;
                }
            }
        }

        public static void main(String args[]) {
            new VMUNCH();
        }
    }
