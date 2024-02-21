import java.util.Arrays;

public class CountInversions {

    public static void main(String[] args) {
        int[] array = {2, 1, 0, 5, 10, 20};

        int count = countInv(array); // == 1
        int expected = countInvSlow(array);

        if (count == expected) {
            System.out.println("Test passed.");
        }
        else {
            System.out.println("Count: " + count);
            System.out.println("Expected: " + expected);
        }
    }

    private static int countInv(int[] array) {
        int[] a = Arrays.copyOf(array, array.length/2);
        int[] b = Arrays.copyOfRange(array, array.length/2, array.length);

        // sort a, count // A

        // sort b, count // B

        // merge, count // C

        // return A + B + C

        return 0;
    }

    private static int countInvSlow(int[] array) { // O(n^2)
        int count = 0;
        for (int i = 0; i <= array.length; i++) {
            for (int j = i+1; j < array.length; j++) {
                if (array[i] > array[j])
                    count++;
            }
        }
        return count;
    }
}
