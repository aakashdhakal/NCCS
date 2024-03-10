import os

board = [' '] * 10
player = 1
winning_conditions = ((1, 2, 3), (4, 5, 6), (7, 8, 9), (1, 4, 7), (2, 5, 8), (3, 6, 9), (1, 5, 9), (3, 5, 7))
winner = None

def print_board():
    os.system('cls' if os.name == 'nt' else 'clear')
    print(" %c | %c | %c " % (board[1], board[2], board[3]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[4], board[5], board[6]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[7], board[8], board[9]))
    print("   |   |   ")

def check_win():
    global winner
    for row in winning_conditions:
        if all(board[i] == board[row[0]] for i in row) and board[row[0]] != ' ':
            winner = board[row[0]]
            return
    if all(x != ' ' for x in board):
        winner = 'Draw'

def turn():
    global player
    mark = 'X' if player % 2 == 1 else 'O'
    print(f"Player {player}'s turn ({mark})")
    while True:
        choice = int(input("Enter a position (1-9): "))
        if board[choice] == ' ':
            board[choice] = mark
            player = 1 if player == 2 else 2
            return

print("Tic-Tac-Toe")
print("Player 1 (X) - Player 2 (O)")

while not winner:
    print_board()
    turn()
    check_win()

print_board()

if winner == 'X':
    print("Player 1 Wins!")
elif winner == 'O':
    print("Player 2 Wins!")
elif winner == 'Draw':
    print("Game Drawn!")
