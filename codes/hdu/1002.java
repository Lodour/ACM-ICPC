import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int t, cnt = 0;
		t = cin.nextInt();
		for (int i = 1; i <= t; i++) {
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			BigInteger c = a.add(b);
			System.out.println("Case " + i + ":");
			System.out.println(a + " + " + b + " = " + c);
			if (i != t)
				System.out.println();
		}
	}
}
