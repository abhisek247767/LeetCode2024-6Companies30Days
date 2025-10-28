class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        n=len(board)
        if n<=1:
            return 0
        rows=[''.join(str(c) for c in r) for r in board]
        counter=collections.Counter(rows)
        keys=list(counter)
        if len(keys)!=2 or abs(counter[keys[0]]-counter[keys[1]])>1 \
            or abs(keys[0].count('1')-keys[0].count('0'))>1 \
            or any(a==b for a,b in zip(*keys)):
            return -1
        rowdiff=sum(board[0][i]!=(i%2) for i in range(n))
        coldiff=sum(board[i][0]!=(i%2) for i in range(n))
        rowdiff=n-rowdiff if rowdiff%2!=0 or (n%2==0 and (n-rowdiff)<rowdiff) else rowdiff
        coldiff=n-coldiff if coldiff%2!=0 or (n%2==0 and (n-coldiff)<coldiff) else coldiff
        return (rowdiff+coldiff)//2
