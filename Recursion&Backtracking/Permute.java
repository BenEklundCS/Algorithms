public class Permute {

    public static void main(String[] args) {
        String str = "BENJAMIN";
        permute(str);
    }

    public static void permute(String s) {
        permute(s, "");
    }

    private static void permute(String s, String chosen) {

        if (s.isEmpty()) {
            System.out.println(chosen);
        }

        else {
            // For each character in the original string
            for (int i = 0; i < s.length(); i++) {

                // Choose the ith character
                char c = s.charAt(i);

                // Build a subset of the String with the character missing/chosen
                String remaining = s.substring(0, i) + s.substring(i + 1); // eg. MORTY i = 1 | remaining = MRTY

                // Permute with the chosen character and the remaining characters
                permute(remaining, chosen + c); // "Explore"
            }
        }
    }
}

// Notes

// Exclude the chosen character and form a new string, add the chosen part to the "chosen" String
// first part            second part
// of the string      ||| i = 'a'
// BENJ              i       MIN == BENJMIN CHOSEN = "A"

// Pseudocode
// permute(s[1 .. i - 1] + s[i + 1], chosen + s[i]);

// One liner
//permute(s.substring(0, i) + s.substring(i + 1), chosen + s.charAt(i));

