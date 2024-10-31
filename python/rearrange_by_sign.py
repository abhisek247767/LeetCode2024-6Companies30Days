'''
Question : We have been given an array containing even number of elements , also same number of positive
           and negative elements are present , we have to make pairs of positive and negative elements in the array
           such that , the order of array should not be lost.
Example: Input= arr=[3,1,-2,-5,2,-4]
         Output=[3,-2,1,-5,2,-4]
Explanation:The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
            The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
            Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they 
            do not satisfy one or more conditions.    

Approach : we will separate the positive and negative numbers in different arrays so that the order is preserved
           then add them to a single array alternatively in the order .

'''


class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        # Separate positive and negative numbers
        positives = [num for num in nums if num > 0]
        negatives = [num for num in nums if num < 0]
    
        # Merge them by alternating between positive and negative numbers
        result = []
        for i in range(len(positives)):
            result.append(positives[i])
            result.append(negatives[i])
    
        return result