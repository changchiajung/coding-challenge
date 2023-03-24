import java.util.stream.Collectors;
import java.util.*;
// Use Log
public class WanderingRobot {
    public static int limitC, limitR, L, U, R, D;
    public static double ansProb;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());
        double initProb = 1;
        for (int i = 1; i <= testcase; i++) {
            String testInput = input.nextLine();
            List<Integer> ints = Arrays.stream(testInput.split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            ansProb = 0;
            limitC = ints.get(0);
            limitR = ints.get(1);
            L = ints.get(2);
            U = ints.get(3);
            R = ints.get(4);
            D = ints.get(5);

            System.out.println("Case #" + i + ": " + ansProb);

        }
    }

}
