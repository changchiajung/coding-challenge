import java.util.*;
import java.util.stream.Collectors;

public class BikeTour {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

		for(int i=1; i<=testcase;i++){
            int testLength = Integer.parseInt(input.nextLine());
            String testInput = input.nextLine();
            List<Integer> ints = Arrays.stream(testInput.split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            int ans =0;
            for(int j=1;j<testLength-1;j++){
                if(ints.get(j-1)<ints.get(j) && ints.get(j+1)<ints.get(j)){
                    ans++;
                }
            }
            System.out.println("Case #"+i+": "+ans);
        }

        
    }
}
