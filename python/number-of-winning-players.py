# Leetcode 3238 - Number of Winning Players

'''
Problem:
You are given an integer n representing the number of players in a game and a 2D array pick where pick[i] = [xi, yi] represents that the player xi picked a ball of color yi.

Player i wins the game if they pick strictly more than i balls of the same color. In other words,

Player 0 wins if they pick any ball.
Player 1 wins if they pick at least two balls of the same color.
...
Player i wins if they pick at leasti + 1 balls of the same color.
Return the number of players who win the game.

Note that multiple players can win the game.'''

class Solution:
    def winningPlayerCount(self, n: int, pick) -> int:
        r = 0
        cs = {}
        rs = [0]*n
        for i,k in pick:
            if i not in cs:
                cs[i]={}
            if k not in cs[i]: 
                cs[i][k]=0
            cs[i][k]+=1
            if cs[i][k]>i: 
                rs[i]=1
        return sum(rs)

