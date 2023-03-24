import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;
public class Retype {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

        for (int i = 1; i <= testcase; i++) {
            String testInput = input.nextLine();
            List<Long> ints = Arrays.stream(testInput.split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            long N = ints.get(0);
            long K = ints.get(1);
            long S = ints.get(2);
            // K + N || K-1 + K - S + (N-S+1)= N+ 2K-2S
            long result = Math.min(K+N,N+2*K-2*S);
            System.out.println("Case #" + i + ": " + result);

        }

    }
}
