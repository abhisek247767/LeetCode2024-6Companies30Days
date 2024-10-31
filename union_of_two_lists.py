'''
Question : We have been given two sorted lists . We have to result a new list which is sorted 
and also the union of the two given lists .
Example  : input a = [1,1,2,3,4,5] , b= [1,2,7,8]
            Output r=[1,2,3,4,5,7,8]
Approach : We will use two pointers method for this , i for list a and j for list b.
           If a[i] is less than b[j], add a[i] to the result if it's not already added, then move i.
           If a[i] is greater than b[j], add b[j] to the result if it's not already added, then move j.
           If a[i] equals b[j], add one of them and move both pointers.
           After one of the arrays is exhausted, add the remaining unique elements from the other array.
           The result will be the sorted union of the two arrays with unique elements.


'''

class Solution:
    
    #Function to return a list containing the union of the two arrays.
    def findUnion(self,a,b):
        # code here 
        i, j = 0, 0
        result = []
    
        # Traverse both arrays
        while i < len(a) and j < len(b):
            # If the current element in a[] is smaller, add it to the result if unique and move pointer i
            if a[i] < b[j]:
                if len(result) == 0 or result[-1] != a[i]:
                    result.append(a[i])
                i += 1
            # If the current element in b[] is smaller, add it to the result if unique and move pointer j
            elif a[i] > b[j]:
                if len(result) == 0 or result[-1] != b[j]:
                    result.append(b[j])
                j += 1
            # If both elements are equal, add only one of them if unique and move both pointers
            else:
                if len(result) == 0 or result[-1] != a[i]:
                    result.append(a[i])
                i += 1
                j += 1
    
        # Add remaining elements from a[]
        while i < len(a):
            if result[-1] != a[i]:
                result.append(a[i])
            i += 1
    
        # Add remaining elements from b[]
        while j < len(b):
            if result[-1] != b[j]:
                result.append(b[j])
            j += 1
    
        return result
    