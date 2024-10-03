# Integer to Roman :-

[Problem Link] :--- (https://leetcode.com/problems/integer-to-roman/description/)

<h3>
Seven different symbols represent Roman numerals with the following values:<br><br>

Symbol	Value<br>
I	1<br>
V	5<br>
X	10<br>
L	50<br>
C	100<br>
D	500<br>
M	1000<br>
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:<br><br>

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.<br>
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).<br>
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.<br>
Given an integer, convert it to a Roman numeral.<br><br>

Example 1:<br>
Input: num = 3749<br>
Output: "MMMDCCXLIX"<br>
Explanation:<br>
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)<br>
 700 = DCC as 500 (D) + 100 (C) + 100 (C)<br>
  40 = XL as 10 (X) less of 50 (L)<br>
   9 = IX as 1 (I) less of 10 (X)<br>
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places<br><br>

Example 2:<br>
Input: num = 58<br>
Output: "LVIII"<br>
Explanation:<br>
50 = L<br>
 8 = VIII<br>
 
Example 3:<br>
Input: num = 1994<br>
Output: "MCMXCIV"<br>
Explanation:<br>
1000 = M<br>
 900 = CM<br>
  90 = XC<br>
   4 = IV<br>
 
Constraints:<br>
1 <= num <= 3999<br>
  
</h3>

***Solution***

```
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

```
