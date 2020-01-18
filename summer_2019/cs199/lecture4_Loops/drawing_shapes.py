from sprint import p_hash, p_space

n = int(input("Enter the width of the shape: "))

counter = 1
blank = " "
hashtag = "#"

'''
while counter < n:
    print(blank*(n-counter),hashtag*counter,hashtag*counter,sep = "")
    counter += 1
while counter > 0:
    print(blank*(n-counter),hashtag*counter,hashtag*counter,sep = "")
    counter -= 1
'''

outer = 0

while outer < n:
    inner = 0
    while inner < n-outer:
        p_space()
        inner += 1
    while inner < 





