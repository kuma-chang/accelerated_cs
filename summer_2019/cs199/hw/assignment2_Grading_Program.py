# Michael Chang
# Program Number:cs199_assignment2_Grading_Program
# This is a Grading program for a class that has:
#	assignments*3, midterm*1 and final*1

print("Welcome, this is a program to help you calculate grades.")

# First, get the percentage for each category
percentage_flag = False
while percentage_flag == False:
    assignment_percentage = (int(input("What percentage are for the assignments: ")))/100
    midterm_percentage = (int(input("What percentage is for the midterm: ")))/100
    final_percentage = (int(input("What percentage is for the final: ")))/100
    if (assignment_percentage + midterm_percentage + final_percentage) == 1:
        percentage_flag = True
    else: 
        print("The percentage does not sum to 100, please re-enter.")



# Get the number of the students in this class
student_number = int(input("How many student are there in this class: "))

# Get the grades of each student also keep track of the distrgution

student_counter = 0
a_counter = 0
b_counter = 0
c_counter = 0
d_counter = 0
f_counter = 0
class_total = 0

while student_counter < student_number:
    print("Please enter the grades the student number {}".format((student_counter + 1)))
    assignment_1_grade = int(input("Enter grade for assignment 1: "))
    assignment_2_grade = int(input("Enter grade for assignment 2: "))
    assignment_3_grade = int(input("Enter grade for assignment 3: "))
    midterm_grade = int(input("Enter grade for midterm: "))
    final_grade = int(input("Enter grade for final: "))
    
    # Calculate the student's grade
    student_grade = ((assignment_1_grade + assignment_2_grade + assignment_3_grade) / 3 * assignment_percentage) + (midterm_grade * midterm_percentage)+(final_grade * final_percentage)
    if student_grade >= 90:
        a_counter += 1
    elif student_grade >= 80:
        b_counter += 1
    elif student_grade >= 70:
        c_counter += 1
    elif student_grade >= 60:
        d_counter += 1
    else:
        f_counter += 1
    
    # Calculte the class average
    if student_counter == 0:
        class_total = student_grade
    else: 
        class_total = class_total + student_grade
    student_counter += 1


print("The class grades' distribution are: \nA: {}\nB: {}\nC: {}\nD: {}\nF: {}".format(a_counter,b_counter,c_counter,d_counter,f_counter))
print("The class average is {}".format(class_total/student_number))



