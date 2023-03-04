public class Hw {
    public static int fib(int n, int f0, int f1) {
        /** Return the nth fib sequence */
        int ans = f0 + f1;
        for (int i = 0; i < n - 3; ++i) {
            f0 = f1;
            f1 = ans;
            ans = f0 + f1;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(fib(4, 1, 1));
    }
}
