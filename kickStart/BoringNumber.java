import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;

public class BoringNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

        for (int i = 1; i <= testcase; i++) {
            String testInput = input.nextLine();
            List<Long> ints = Arrays.stream(testInput.split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            long L = ints.get(0);
            long R = ints.get(1);
//            System.out.println("Case #" + i + ": " + result);
            
        }

    }
}
