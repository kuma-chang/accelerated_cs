import math


amount_of_change = int(input("Enter the amount of change in pannies: "))



dollar = math.floor(amount_of_change/100)
amount_of_change = amount_of_change-(dollar*100)

quater = math.floor(amount_of_change/25)
amount_of_change = amount_of_change-(quater*25)

nickel = math.floor(amount_of_change/5)
amount_of_change = amount_of_change-(nickel*5)

penny = math.floor(amount_of_change/1)
amount_of_change = amount_of_change-(penny*1)


if quater == 0 and nickel == 0 and penny == 0:
    if dollar > 1 :
        dollar_syntax = "{} dollars.".format(dollar)
    elif dollar == 1:
        dollar_syntax = "{} dollar.".format(dollar)
    else:
        dollar_syntax = ""
else:
    if dollar > 1 :
        dollar_syntax = "{} dollars,".format(dollar)
    elif dollar == 1:
        dollar_syntax = "{} dollar,".format(dollar)
    else:
        dollar_syntax = ""

if nickel == 0 and penny == 0:
    if quater > 1 :
        quater_syntax = "and {} quaters.".format(quater)
    elif quater == 1:
        quater_syntax = "and {} quater.".format(quater)
    else:
        quater_syntax = ""
else:
    if quater > 1 :
        quater_syntax = "{} quaters,".format(quater)
    elif quater == 1:
        quater_syntax = "{} quater,".format(quater)
    else:
        quater_syntax = ""

if penny == 0:
    if nickel > 1 :
        nickel_syntax = "and {} nickels.".format(nickel)
    elif nickel == 1:
        nickel_syntax = "and {} nickel.".format(nickel)
    else:
        nickel_syntax = ""
else:
    if nickel > 1 :
        nickel_syntax = "{} nickels,".format(nickel)
    elif nickel == 1:
        nickel_syntax = "{} nickel,".format(nickel)
    else:
        nickel_syntax = ""

if penny > 1 :
    penny_syntax = "and {} pennies.".format(penny)
elif penny == 1:
    penny_syntax = "and {} penny.".format(penny)
else:
    penny_syntax = ""



print("You get",dollar_syntax,quater_syntax,nickel_syntax,penny_syntax)











