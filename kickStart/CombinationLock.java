import javax.swing.*;
import java.lang.reflect.Array;
import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;
import java.util.stream.Stream;

public class CombinationLock {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());
        for (int i = 1; i <= testcase; i++) {
            List<Long> ints = Arrays.stream(input.nextLine().split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            long W = ints.get(0);
            long N = ints.get(1);
            List<Long> inputData = Arrays.stream(input.nextLine().split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            long originSum = inputData.stream().mapToLong(Long::longValue).sum();
            long originAvg = Math.round((double)originSum / W);
            long originStep = 0;
            for(long item: inputData){
                originStep+=Math.abs(item-originAvg);
            }
            for (int j =0;j<W;j++){
                if (inputData.get(j)<=N/2){
                    inputData.set(j,inputData.get(j)+N);
                }
            }
            long processedSum = inputData.stream().mapToLong(Long::longValue).sum();
            long processedAvg = Math.round((double)processedSum / W);
            long processedStep = 0;
            for(long item: inputData){
                processedStep+=Math.abs(item-processedAvg);
            }
            System.out.println("Case #" + i + ": " +Math.min(originStep,processedStep));
        }

    }
}
