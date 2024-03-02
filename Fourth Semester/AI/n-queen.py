
def is_safe (board,row,col,n):
    for c in range (col,-1,-1):
        if board[row][c]==1:
            return False

    i=row
    j=col
    while i>=0 and j>=0:
        if board[i][j]==1:
            return False
        i-=1
        j-=1

    i = row
    j = col
    while i<n and j>=0:
        if board[i][j]==1:
            return False
        i += 1
        j -= 1
    return True

def nqueen (board,col,n):
    if col >= n:
        return True
    for i in range(n):
        if is_safe(board,i,col,n):
            board[i][col]=1
            if nqueen(board,col+1,n):
                return True
            board[i][col]=0
    return False

n=int(input('enter the queen number ='))
board=[[0 for j in range(n)] for i in range(n)]
if nqueen(board,0,n)==True:
    for i in range (n):
        for j in range(n):
            print(board[i][j], end= ' ')
        print()
else:
    print("not impossible")

    

















        
        

    
