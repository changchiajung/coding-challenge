import java.util.stream.Collectors;
import java.util.*;

public class BusRoute {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

        for (int i = 1; i <= testcase; i++) {
            String testPreInput = input.nextLine();
            String testInput = input.nextLine();
            int testLength = Integer.parseInt(testPreInput.split(" ")[0]);
            long goal = Long.parseLong(testPreInput.split(" ")[1]);
            List<Long> ints = Arrays.stream(testInput.split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            ArrayList<Long> restList = new ArrayList<Long>();
            long ans = 0;
            for (int j = 0; j < testLength; j++) {
                restList.add(goal % ints.get(j));
            }

            long tmpMax = restList.get(testLength - 1);
            for (int j = testLength - 2; j >= 0; j--) {
                if (tmpMax > restList.get(j)) {
                    long updateData = restList.get(j) + ((tmpMax- restList.get(j) + ints.get(j) - 1) / ints.get(j)) * ints.get(j);
                    tmpMax = updateData;
                    restList.set(j,updateData);
                }else{
                    tmpMax = restList.get(j);
                }
            }


            System.out.println("Case #" + i + ": " + (goal-tmpMax));
        }
    }
}
