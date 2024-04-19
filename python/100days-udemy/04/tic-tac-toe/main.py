# game list
board=[]
for i in range(3):
    board.append(([' ']*3).copy())

def printBoard():
    for row in board:
        print(row)
    return

import random
def computerTurn():
    row = random.randint(0,2)
    column = random.randint(0,2)
    
    if board[row][column] == ' ':
        board[row][column] = 'O'
        return
    else:
        computerTurn()

# insert X into middle
#   board[0][0] = 'X'

while True:
    printBoard()

    # check if game is over
    gameStatus = False
    for r in range(3):
        for c in range(3):
            if board[r][c] == ' ':
                gameStatus = True
                break
        break
    if gameStatus == False:
        break

    
    x = input("Coordinates (row,column):\n")

    if board[int(x[0])][int(x[2])] == ' ':
        board[int(x[0])][int(x[2])] = 'X'
    
    computerTurn()

