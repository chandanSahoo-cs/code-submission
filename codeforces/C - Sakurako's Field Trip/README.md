# [C. Sakurako's Field Trip](https://codeforces.com/contest/2033/problem/C)

---
Even in university, students need to relax. That is why Sakurakos teacher decided to go on a field trip. It is known that all of the students will be walking in one line. The student with index ii has some topic of interest which is described as aiai. As a teacher, you want to minimise the disturbance of the line of students.The disturbance of the line is defined as the number of neighbouring people with the same topic of interest. In other words, disturbance is the number of indices jj (1≤j<n1≤j<n) such that aj=aj+1aj=aj+1.In order to do this, you can choose index ii (1≤i≤n1≤i≤n) and swap students at positions ii and n−i+1n−i+1. You can perform any number of swaps.Your task is to determine the minimal amount of disturbance that you can achieve by doing the operation described above any number of times.

### Input
InputThe first line contains one integer tt (1≤t≤1041≤t≤104) — the number of test cases.Each test case is described by two lines.  The first line contains one integer nn (2≤n≤1052≤n≤105) — the length of the line of students.  The second line contains nn integers aiai (1≤ai≤n1≤ai≤n) — the topics of interest of students in line. It is guaranteed that the sum of nn across all test cases does not exceed 2⋅1052⋅105.

### Output
OutputFor each test case, output the minimal possible disturbance of the line that you can achieve.
NoteIn the first example, it is necessary to apply the operation to i=2i=2, thus the array will become [1,2,1,1,3], with the bold elements indicating those that have swapped places. The disturbance of this array is equal to 1.In the fourth example, it is sufficient to apply the operation to i=3, thus the array will become [2,1,2,1,2,4]. The disturbance of this array is equal to 0.In the eighth example, it is sufficient to apply the operation to i=3, thus the array will become [1,4,1,5,3,1,3]. The disturbance of this array is equal to 0.
