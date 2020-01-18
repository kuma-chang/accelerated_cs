n = str(input("Enter the string to reduct: "))

li_n = list(n)

size = len(n)
size_flag = True
first_search_flag = True
ind_1 = 0
ind_2 = 1
answer = []
print(li_n)
while ind_2 < size:
    if li_n[ind_1].islower() and li_n[ind_2].isupper():
        if n[ind_1] == n[ind_2].lower():
            print(ind_1,ind_2,"is a match")
            if size_flag:
                new_size = len(n)
            else:
                new_size = len(answer)
                print(new_size)
            new_ind_1 = 0
            index_counter = 0
            size_flag = False
            while index_counter < new_size:
                if first_search_flag:
                    if new_ind_1 != (ind_1-(size-new_size)) and new_ind_1 != (ind_2-(size-new_size)):
                        answer.append(li_n[new_ind_1])
                        first_search_flag = False
                        change_counter = 1
                else:
                    answer = []
                    if new_ind_1 != (ind_1-(size-new_size)) and new_ind_1 != (ind_2-(size-new_size)):
                        answer.append(li_n[new_ind_1])
                        change_counter += 1 
                new_ind_1 += 1
                index_counter += 1

    ind_1 += 1
    ind_2 += 1
    


print(answer)












