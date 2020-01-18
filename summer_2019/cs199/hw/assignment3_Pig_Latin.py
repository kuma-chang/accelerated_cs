# Michael Chang
# Program Number: cs199_Assignment3_Pig_Latin 
# This is a program that could let user to enter a phrase and translter it in to Pig Latin

#import allowed functions
def is_vowel(c):
    return c.lower() in 'aeiou'

def is_consonant(c):
    return c.isalpha() and not is_vowel(c)

def is_puncc(c):
    return c in '.,?![]{}"\';:'

#let user enter phrase
phrase = input("Please enter the phrase you want to translate: ")

li_phrase = list(phrase)
phrase_size = len(li_phrase)
li_word = []
li_word_counter = 0
i = 0
j = 0
while i < phrase_size:
    if li_phrase[i] == " " or is_puncc(li_phrase[i]):
        if li_phrase[i] == "'" and  li_phrase[i+1].isalpha():
            i = i    
        elif j == 0:
            li_word.append("".join(li_phrase[:i]))
            li_word.append("".join(li_phrase[i]))
            j = i + 1
            i += 1
        else:
            li_word.append("".join(li_phrase[j:i]))
            li_word.append("".join(li_phrase[i]))
            j = i + 1
            i += 1
    elif i == phrase_size - 1:
        li_word.append("".join(li_phrase[j:]))
    i += 1


word_size = len(li_word)
word_counter = 0
while word_counter < word_size:
    ch_counter = 0
    if li_word[word_counter] != " " and not is_puncc(li_word[word_counter]):
        print(word_counter,"is a word: ", li_word[word_counter])
        x = 0
        before = li_word[word_counter] 
        pig_word = []
        change_flag = True
        while x < len(before):
            if is_vowel(before[x]) and change_flag:
                if x == 0:
                    if before[x].isupper():
                        print("is upper!")
                        pig_word.append(before[1].upper())
                        pig_word.append(before[1:])
                        pig_word.append(before[0].lower())
                        pig_word.append("way") 
                        li_word[word_counter] = "".join(pig_word)
                        change_flag = False
                        print("x = 0",pig_word)
                        print(before)
                    else:
                        pig_word.append(before[1:])
                        pig_word.append(before[0])
                        pig_word.append("way")
                        li_word[word_counter] = "".join(pig_word)
                        change_flag = False
                        print("x = 0",pig_word)
                        print(before)
                else:
                    pig_word.append(before[x:])
                    pig_word.append(before[:x])
                    pig_word.append("ay")
                    li_word[word_counter] = "".join(pig_word)
                    change_flag = False
                    print("x != 0",pig_word)
                    print(before)
            x += 1
    word_counter += 1

print(li_word)
print(li_phrase)
print("".join(li_word))




















