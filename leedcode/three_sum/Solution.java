package three_sum;
import java.util.*;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testcase = Integer.parseInt(input.nextLine());
    }
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp  = new HashMap<Integer, Integer>();
        int index = 0;
        int[] rt = new int[2];
        for(;index<nums.length; index++){
            if(mp.containsKey(target-nums[index])){
                rt[0]=mp.get(target-nums[index]);
                rt[1]=index;
                break;
            }else{
                mp.put(nums[index],index);
            }
        }
        return rt;
    }
}
