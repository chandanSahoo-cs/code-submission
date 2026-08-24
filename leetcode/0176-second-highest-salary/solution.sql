# Write your MySQL query statement below
-- SELECT (SELECT DISTINCT salary  FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1) as  SecondHighestSalary;
SELECt MAX(salary) as SecondHighestSalary FROM Employee WHERE salary < (SELECT MAX(salary) FROM Employee);
