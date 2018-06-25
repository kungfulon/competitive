import java.util.*;

public final class P992B {
    private ArrayList<Integer> divisors = new ArrayList<>();
    private int[] d = new int[1000005];
    private ArrayList<Integer> p = new ArrayList<>();

    private void init() {
        d[0] = d[1] = -1;

        for (int i = 2; i <= 1000000; ++i) {
            if (d[i] != 0) {
                continue;
            }

            d[i] = 1;
            p.add(i);

            for (int j = i + i; j <= 1000000; j += i) {
                d[j] = -1;
            }
        }
    }

    private HashMap<Integer, Integer> factorize(int x) {
        HashMap<Integer, Integer> fact = new HashMap<>();

        for (int k : p) {
            if (x == 1) {
                break;
            }

            int cnt = 0;

            while (x % k == 0) {
                x /= k;
                ++cnt;
            }

            if (cnt > 0) {
                fact.put(k, cnt);
            }
        }

        if (x > 1) {
            fact.put(x, 1);
        }

        return fact;
    }

    private void wtf(int l, int r, ArrayList<Integer> f, ArrayList<Integer> e, int i, long num) {
        if (num > r) {
            return;
        }

        if (i >= f.size()) {
            if (num >= l) {
                divisors.add((int)num);
            }

            return;
        }

        wtf(l, r, f, e, i + 1, num);

        for (int j = 1; j <= e.get(i); ++j) {
            num *= f.get(i);

            if (num > r) {
                break;
            }

            wtf(l, r, f, e, i + 1, num);
        }
    }

    private int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }

    P992B() {
        init();
        Scanner cin = new Scanner(System.in);
        int l = cin.nextInt();
        int r = cin.nextInt();
        int x = cin.nextInt();
        int y = cin.nextInt();
        HashMap<Integer, Integer> factorX = factorize(x);
        HashMap<Integer, Integer> factorY = factorize(y);
        factorY.forEach((k, v) -> factorX.merge(k, v, Integer::sum));
        ArrayList<Integer> factors = new ArrayList<>();
        ArrayList<Integer> exponents = new ArrayList<>();
        factorX.forEach((k, v) -> {
            factors.add(k);
            exponents.add(v);
        });
        long xd = (long)x * y;
        wtf(l, Math.min(r, (int)Math.sqrt(xd)), factors, exponents, 0, 1);
        int ans = 0;

        for (int k : divisors) {
            long k2 = xd / k;

            if (k2 > r) {
                continue;
            }

            if (gcd(k, (int)k2) == x) {
                ++ans;

                if (k != (int)k2) {
                    ++ans;
                }
            }
        }

        System.out.println(ans);
    }

    public static void main(String args[]) {
        new P992B();
    }
}
