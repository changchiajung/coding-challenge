import java.util.stream.Collectors;
import java.util.*;

public class RobotPath {
    /*
    (w,h): column[W,E], row[N,S]
    N: (0,1)
    S: (0,-1)
    W: (-1,0)
    E: (1,0)
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());

        for (int i = 1; i <= testcase; i++) {
            String testInput = input.nextLine();
            String resultString = recPath(testInput, 0);
            long resultW = Long.parseLong(resultString.split(",")[0]);
            long resultH = Long.parseLong(resultString.split(",")[1]);
            resultW %= 1000000000;
            resultH %= 1000000000;
            if (resultH < 0) {
                resultH += 1000000001;
            } else {
                resultH += 1;
            }
            if (resultW < 0) {
                resultW += 1000000001;
            } else {
                resultW += 1;
            }
            System.out.println("Case #" + i + ": " + resultW + " " + resultH);
        }
    }

    private static String recPath(String command, int index) {
        long w = 0;
        long h = 0;
        for (int i = index; i < command.length(); i++) {
            if (command.charAt(i) == 'N') {
                h--;
            } else if (command.charAt(i) == 'S') {
                h++;
            } else if (command.charAt(i) == 'W') {
                w--;
            } else if (command.charAt(i) == 'E') {
                w++;
            } else if (command.charAt(i) == ')') {
                w %= 1000000000;
                h %= 1000000000;
                String str = new StringBuilder("").append(w).append(",").append(h).append(",").append(i).toString();
                return str;
            } else {
                // number
                int repeat = command.charAt(i) - '0';
                String rtString = recPath(command, i + 2);
                w += repeat * Long.parseLong(rtString.split(",")[0]);
                h += repeat * Long.parseLong(rtString.split(",")[1]);
                i = Integer.parseInt(rtString.split(",")[2]);
            }
        }

        w %= 1000000000;
        h %= 1000000000;
        String str = new StringBuilder("").append(w).append(",").append(h).append(",").append(command.length()).toString();
        return str;
    }
}