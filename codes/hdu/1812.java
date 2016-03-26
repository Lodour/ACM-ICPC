import java.math.*;
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n;
        BigInteger c;
        while (cin.hasNextInt()) {
            BigInteger ans = BigInteger.valueOf(0), tmp;
            n = cin.nextInt();
            c = cin.nextBigInteger();
            ans = ans.add(c.pow(n * n));            // 0
            ans = ans.add(c.pow((n * n + 3) / 4));  // 90
            ans = ans.add(c.pow((n * n + 1) / 2));  // 180
            ans = ans.add(c.pow((n * n + 3) / 4));  // 270
            ans = ans.add(c.pow((n + 1) / 2 * n));  // |
            ans = ans.add(c.pow((n + 1) / 2 * n));  // -
            ans = ans.add(c.pow(n * (n + 1) / 2));  // \
            ans = ans.add(c.pow(n * (n + 1) / 2));  // /
            ans = ans.divide(BigInteger.valueOf(8));
            System.out.println(ans);
        }
    }
}
