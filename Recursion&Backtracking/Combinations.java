public class Combinations {

    /*
    "Combinations" accepts an integer n and an integer k as parameters
    and outputs all k-combinations of the first n positive integers.
    The arrangements can be output in any order.
     */

    public static void main(String[] args) {
        combinations(100, 5);
    }
    public static void combinations(int n, int k) {
        // need a base case

        combinations(n, k, "");

        // need to choose, explore, unchoose somehow
    }

    private static void combinations(int n, int k, String chosen) {
        // Once k is 0 we do not need to make any more choices
        if (k == 0) {
            System.out.println(chosen);
        }
        //
        else if (n > 0) {
            combinations(n - 1, k - 1, chosen + n + " ");
            combinations(n - 1, k, chosen);
        }
    }
}
