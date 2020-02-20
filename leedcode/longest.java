
import java.util.*; 
class Solution {
    Hashtable<String, Integer> val = new Hashtable<String, Integer>();
    Hashtable<String, Integer> tb = new Hashtable<String, Integer>();
    ArrayList<String>[] al; 
    public int longest(String st){
       if(val.containsKey(st)){
           return val.get(st);
       } 
       int rt = 1;
       for(int i = 0; i<al[tb.get(st)].size(); i++){
           rt = Math.max(rt,longest(al[tb.get(st)].get(i))+1);
       }
        val.put(st,rt);
        return rt;
    }
    public int longestStrChain(String[] words) {
        int ans = 0;
        al = new ArrayList[words.length]; 
        for (int i = 0; i < words.length; i++) { 
            al[i] = new ArrayList<String>(); 
        } 
        for(int i = 0 ; i< words.length;i++){
            tb.put(words[i],i);
        }
        for(int i = 0; i<words.length;i++){
            for(int j=0;j<words[i].length();j++){
                String tmp = words[i].substring(0,j)+words[i].substring(j+1);
                 if(tb.containsKey(tmp)){
                     al[tb.get(tmp)].add(words[i]);
                 }
            }
        }        
        for(int i = 0; i<words.length;i++){
            ans = Math.max(ans,longest(words[i]));
        }
         
        
        return ans;
    }
}