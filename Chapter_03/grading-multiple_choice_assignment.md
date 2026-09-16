# grading-multiple_choice_assignment.cpp

Grades a multiple-choice test for 8 students and prints each student's score out of 10.

## OOP Concepts Used

This program does not use OOP. It's written in plain procedural style, everything happens inside `main` using arrays and loops. There are no classes or objects, so there's no encapsulation, inheritance, or polymorphism.

The closest thing to OOP here is `cout`, which is an object from the standard library. But the program itself does not define any classes.

## Algorithm

1. Store all student answers in a 2D array `answers[8][10]`. Each row is one student, each column is one question.
2. Store the correct answers in a 1D array `key[10]`.
3. Go through each student one at a time. For each student, set their score to 0, then check each of their 10 answers against `key`. Add 1 to the score for every match.
4. Print the student's number and score.

This uses two loops inside each other: one for students, one for questions. In total it checks 80 answers (8 students times 10 questions).

## Possible Error Points

Array size: the loops are hardcoded for 8 students and 10 questions. If you add more students or questions without changing the array size and loop limits, the program will break or read wrong data.

Student numbering: students are printed starting from 0, not 1. This is correct in the code but might confuse someone expecting the first student to be "Student 1".

Letter case: answers are compared with `==`, so `'a'` and `'A'` are treated as different. All the data needs to use the same case.

Fixed data: the answers and key are typed directly into the code. A real program would read this from a file or user input instead.

No checking for bad data: the program does not check if an answer is actually A, B, C, D, or E. A typo would just be counted as wrong instead of being caught.
