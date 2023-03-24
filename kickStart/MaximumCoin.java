import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;

public class MaximumCoin {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());
        for (int i = 1; i <= testcase; i++) {
            int testLine = Integer.parseInt(input.nextLine());
            ArrayList<List<Long>> inputData = new ArrayList<List<Long>>();
            for (int j = 0; j < testLine; j++) {
                inputData.add(Arrays.stream(input.nextLine().split(" "))
                        .map(Long::parseLong)
                        .collect(Collectors.toList()));
            }
            long ans = 0;
            long tmp = 0;
            for (int x = 0; x < testLine; x++) {
                tmp = 0;
                int r = x;
                int c = 0;
                for (; r < testLine; r++, c++) {
                    tmp += inputData.get(r).get(c);
                }
                ans = Math.max(ans, tmp);
            }
            for (int y = 1; y < testLine; y++) {
                tmp = 0;
                int r = 0;
                int c = y;
                for (; c < testLine; r++, c++) {
                    tmp += inputData.get(r).get(c);
                }
                ans = Math.max(ans, tmp);
            }
            System.out.println("Case #" + i + ": " + ans);

        }

    }
}
