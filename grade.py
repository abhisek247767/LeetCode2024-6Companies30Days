#Question: Student Grade Management System
#Write a Python program to manage student grades.
#The program should:
#Accept details of n students — each with a name and marks (out of 100).
#Store the data in a dictionary where the key is the student’s name and the value is the marks.
#Display:
#The class average.
#The highest and lowest marks.
#The students who scored above average.


# Student Grade Management System
# Step 1: Input number of students
n = int(input("Enter number of students: "))

# Step 2: Create dictionary to store student data
students = {}

for i in range(n):
    name = input(f"Enter name of student {i+1}: ")
    marks = float(input(f"Enter marks of {name}: "))
    students[name] = marks

# Step 3: Calculate average, highest, and lowest
average = sum(students.values()) / n
highest = max(students.values())
lowest = min(students.values())

# Step 4: Display results
print("\n📊 Class Report 📊")
print(f"Class Average: {average:.2f}")
print(f"Highest Marks: {highest}")
print(f"Lowest Marks: {lowest}")

print("\n🏅 Students scoring above average:")
for name, marks in students.items():
    if marks > average:
        print(f"- {name}: {marks}")
