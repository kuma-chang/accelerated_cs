n_1 = int(input("Enter a number for list 1(enter -1 to terminate): "))
li_1 = []
li_1_size = 0

while n_1 != -1:
    li_1.append(n_1)
    li_1_size += 1
    n_1 = int(input("Enter a number for list 1(enter -1 to terminate): "))


n_2 = int(input("Enter a number for list 2(enter -1 to terminate): "))
li_2 = []
li_2_size = 0

while n_2 != -1:
    li_2.append(n_2)
    li_2_size += 1
    n_2 = int(input("Enter a number for list 2(enter -1 to terminate): "))
    
compare_counter = 0
compare_flag = True
if li_1_size != li_2_size:
    print("Two sets are not the same.")
else:
    while compare_counter < li_1_size:
        if li_1[compare_counter] != li_2[compare_counter]:
            compare_flag = False
        compare_counter += 1

if compare_flag:
    print("The two sets are the same!")
else:
    print("Two sets are not the same.")













