# Michael Chang
# Program Number:cs199_assignment1_Guessing_Game
# This is a number guessing game, you would only get four chances to guess between 1-20.
# And each time the game will inform you if the guess is too high or too low.


#generate a random number between 1-20
import math
import random
answer = math.ceil(random.random()*20)#'answer' is the answer of the guessing game


print(answer)

attempt_counter = 1#'attempt_counter' would keep count of the attemps

# Welcom message
print("Welcome")

# Get the guess from the player
guess = int(input("Please enter your first guess: "))

if guess == answer:
    print("Amazing!\nYou got it on the first try!!")
else:
    if guess > answer:
        guess = int(input("Too high!\nPlease enter your second guess: "))
        if guess == answer:
            print("Congradulation!!\nYou got it on the second try!")
        else:
            if guess > answer:
                guess = int(input("Too high!\nPlease enter your third guess: "))
                if guess == answer:
                    print("Congradulation!!\nYou got it on the third try!")
                else:
                    if guess > answer:
                        guess = int(input("Too high!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
                    else:
                        guess = int(input("Too low!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
            else:
                guess = int(input("Too low!\nPlease enter your third guess: "))
                if guess == answer:
                    print("Congradulation!!\nYou got it on the third try!")
                else:
                    if guess > answer:
                        guess = int(input("Too high!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
                    else:
                        guess = int(input("Too low!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
    else:
        guess = int(input("Too low!\nPlease enter your second guess: "))
        if guess == answer:
            print("Congradulation!!\nYou got it on the second try!")
        else:
            if guess > answer:
                guess = int(input("Too high!\nPlease enter your third guess: "))
                if guess == answer:
                    print("Congradulation!!\nYou got it on the third try!")
                else:
                    if guess > answer:
                        guess = int(input("Too high!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
                    else:
                        guess = int(input("Too low!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
            else:
                guess = int(input("Too low!\nPlease enter your third guess: "))
                if guess == answer:
                    print("Congradulation!!\nYou got it on the third try!")
                else:
                    if guess > answer:
                        guess = int(input("Too high!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)
                    else:
                        guess = int(input("Too low!\nThis is your last chance: "))
                        if guess == answer:
                            print("Congradulation!!\nYou got it on the last try!")
                        else:
                            if guess > answer:
                                print("Sorry, too high, the answer was",answer)
                            else:
                                print("Sorry, too low, the answe was",answer)

   






