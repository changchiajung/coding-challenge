import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;

public class kick_start {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());
        String kick = "KICK";
        String start = "START";
        for (int i = 1; i <= testcase; i++) {
            String testInput = input.nextLine();
            int lastIndex = 0;
            int kicktmp = 0;
            int starttmp = 0;
            int count = 0;
            long ans = 0;

            while (lastIndex != -1) {
                kicktmp = testInput.indexOf(kick, lastIndex);
                starttmp = testInput.indexOf(start, lastIndex);
                if (kicktmp == -1 || starttmp < kicktmp) {
                    lastIndex = starttmp;
                    if (lastIndex != -1) {
                        lastIndex += 5;
                        ans += count;
                    } else {
                        break;
                    }
                } else if (starttmp == -1 || kicktmp < starttmp) {
                    lastIndex = kicktmp;
                    if (lastIndex != -1) {
                        lastIndex += 3; // Prevent overlap
                        count++;
                    } else {
                        break;
                    }
                }
            }
            System.out.println("Case #" + i + ": " + ans);

        }

    }
}
