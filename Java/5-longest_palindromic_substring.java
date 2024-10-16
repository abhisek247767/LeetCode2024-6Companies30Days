class Solution {
    public String longestPalindrome(String s) {
    if (s.isEmpty()) {
	return null;
}

if (s.length() == 1) {
	return s;
}

String longest = s.substring(0, 1);
for (int i = 0; i < s.length(); i++) {
    
	String tmp = helper(s, i, i);
    	if (tmp.length() > longest.length()) {
		longest = tmp;
    	}
	
	tmp = helper(s, i, i + 1);
	    if (tmp.length() > longest.length()) {
		longest = tmp;
	    }
	}
return longest;}

public String helper(String s, int begin, int end) {
 
while (begin >= 0 && end <= s.length() - 1 && s.charAt(begin) == s.charAt(end)) {

	begin--;

	end++;

}

 return s.substring(begin + 1, end);
    }
}
