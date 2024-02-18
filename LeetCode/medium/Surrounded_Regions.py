class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        def flood(i, j):
            if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
                return
            if board[i][j] == 'O':
                board[i][j] = 'I'
                flood(i-1, j)
                flood(i+1, j)
                flood(i, j-1)
                flood(i, j+1)
        
        for i in range(len(board)):
            flood(i, 0)
            flood(i, len(board[0])-1)
        for j in range(len(board[0])):
            flood(0, j)
            flood(len(board)-1, j)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'I':
                    board[i][j] = 'O'
