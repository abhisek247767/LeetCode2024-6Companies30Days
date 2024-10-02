/* Problem statement: 
42. Trapping Rain Water : Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.*/


//Solution
class TrappingRainwater {
    public int trap(int[] height) {
        int n = height.length;
        int leftind=0, rightind=n-1;  
        int leftMax=0, rightMax=0;  
        int total=0;  // Total water trapped

        while (leftind < rightind) {
            if (height[leftind] < height[rightind]) {
              
                if (height[leftind] >= leftMax) {
                    leftMax = height[leftind];  
                } else {
                    total += leftMax - height[leftind]; 
                }
                leftind++;  
            } else {
               
                if (height[rightind] >= rightMax) {
                    rightMax = height[rightind]; 
                } else {
                    total += rightMax - height[rightind];  
                }
                rightind--;  
            }
        }

        return total;  
    }

    public static void main(String[] args) {
        TrappingRainwater result = new TrappingRainwater();

        int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};


        int trappedWater = result.trap(height);
        System.out.println("Total water trapped: " + trappedWater);
    }
}



/*Output:
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 */