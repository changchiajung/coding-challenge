import java.util.stream.Collectors;
import java.util.*;
import java.lang.*;


public class Rugby {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

        for (int i = 1; i <= testcase; i++) {
            int testPerson = Integer.parseInt(input.nextLine());
            int tmpResult = 0;
            ArrayList<Long> listC = new ArrayList<>();
            ArrayList<Long> listR = new ArrayList<>();
            for (int j=1;j<=testPerson;j++){
                String testInput = input.nextLine();
                List<Long> ints = Arrays.stream(testInput.split(" "))
                        .map(Long::parseLong)
                        .collect(Collectors.toList());
                listC.add(ints.get(0));
                listR.add(ints.get(1));
            }
            Collections.sort(listR);
            for (int j=0;j<testPerson/2;j++){
                tmpResult += listR.get(j) - listR.get(testPerson-j);
            }
            Collections.sort(listC);
            int red = 0;
            for (int j=0;j<testPerson/2;j++){
                long tmp = listC.get(j) - listC.get(testPerson-j);
                if (tmp == 0){
                    red++;
                }
                tmpResult += tmp;
            }


            System.out.println("Case #" + i + ": " + result);

        }
}
