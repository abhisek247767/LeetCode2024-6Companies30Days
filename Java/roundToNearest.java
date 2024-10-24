import java.math.BigInteger;
class Solution {

    String roundToNearest(String str){
        StringBuilder st = new StringBuilder();
        int t = Integer.parseInt(String.valueOf(str.charAt(str.length() - 1)));
        for(int i=0;i<str.length()-2;i++){
            st.append(str.charAt(i));
        }
        if(t <= 5){
            st.append(str.charAt(str.length()-2));
            st.append('0');
        }else  if(t>5){
            st.append(str.charAt((str.length()-2))+1);
            st.append('0');
        }
        return st.toString();
    }
}
