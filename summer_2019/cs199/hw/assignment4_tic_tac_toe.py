# Michael Chang
# Program Number:cs199_assignment4_Tic_Tac_Toe
# This is a Tic-Tac-Toe game

status = ["0","1","2","3","4","5","6","7","8"]

player1 = [0,0,0,0,0,0,0,0,0]
player2 = [0,0,0,0,0,0,0,0,0]

# Function for printing out the status
def status_print(status):
    print("_{}_|_{}_|_{}_\n_{}_|_{}_|_{}_\n {} | {} | {} ".format(status[0],status[1],status[2],status[3],status[4],status[5],status[6],status[7],status[8]))

# Function for processing input
def store_input_player1(n):
    player1[n] = 1
def store_input_player2(n):
    player2[n] = 1

# Function for changing the status list
def status_change(n,m):
    status[n] = m

# Function for checking if someone win 
def game_check(n):
    if n[0]+n[1]+n[2] == 3:
        return True
    elif n[3]+n[4]+n[5] == 3:
        return True
    elif n[6]+n[7]+n[8] == 3:
        return True
    elif n[0]+n[3]+n[6] == 3:
        return True
    elif n[1]+n[4]+n[7] == 3:
        return True
    elif n[2]+n[5]+n[8] == 3:
        return True
    elif n[0]+n[4]+n[8] == 3:
        return True
    elif n[2]+n[4]+n[6] == 3:
        return True
    else:
        return False

# Check if the spot have been taken
def player_input_check(n):
    if player1[n] == 0 and player2[n] == 0:
        return True
    else:
        return False

# Function for getting input
def get_player1_input():
    input_flag = True
    while input_flag:
        o = int(input("Player1, please enter your choice: "))
        if player_input_check(o):
            return o
            input_flag = False
        else:
            print("That spot has been taken, please choose another spot.")

def get_player2_input():
    input_flag = True
    while input_flag:
        x = int(input("Player2, please enter your choice: "))
        if player_input_check(x):
            return x
            input_flag = False
        else:
            print("That spot has been taken, please choose another spot.")


# Flag for game to stop
game_flag = True 

# Flag for who win
player1_flag = False
player2_flag = False

# Round counter
round_counter = 0

# Print out the board and explain the way to play
status_print(status)
print("This is a Tic-Tac-Toe Game for player of two\nPlease enter each players' choice as the chart above\n(e.g.enter 0 for the upper left conner.)")

# Reset the chart
status = ["_","_","_","_","_","_"," "," "," "]


while game_flag:
    # Player1
    o = get_player1_input()
    store_input_player1(o)
    status_change(o,"O")
    status_print(status)
    round_counter += 1
    if game_check(player1):
        player1_flag = True
        game_flag = False

    if round_counter == 9 and not player1_flag:
        print("Tie!!")
        game_flag = False

    # Player2
    if game_flag:
        x = get_player2_input()
        store_input_player2(x)
        status_change(x,"X")
        status_print(status)
        round_counter += 1
        if game_check(player2):
            player2_flag = True
            game_flag = False


if player1_flag:
    print("Player1 won!")
if player2_flag:
    print("Player2 won!")
