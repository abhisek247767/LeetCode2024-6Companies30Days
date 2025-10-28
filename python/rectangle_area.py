#223. Rectangle Area

#Problem Statement: Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
# The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
# The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

#Time Complexity: O(1)
#Space Complexity: O(1)

class Solution:
    def computeArea(
        self,
        ax1: int,
        ay1: int,
        ax2: int,
        ay2: int,
        bx1: int,
        by1: int,
        bx2: int,
        by2: int,
    ) -> int:
        a = (ax2 - ax1) * (ay2 - ay1)
        b = (bx2 - bx1) * (by2 - by1)
        width = min(ax2, bx2) - max(ax1, bx1)
        height = min(ay2, by2) - max(ay1, by1)
        return a + b - max(height, 0) * max(width, 0)

# Input:
# ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 = -3, 0, 3, 4, 0, -1, 9, 2

# Output:
# 45

# Explanation:

# Area of A = (3 - (-3)) * (4 - 0) = 24

# Area of B = (9 - 0) * (2 - (-1)) = 27

# Overlap width = min(3, 9) - max(-3, 0) = 3

# Overlap height = min(4, 2) - max(0, -1) = 2

# Overlap area = 3 * 2 = 6

# Total = 24 + 27 - 6 = 45    