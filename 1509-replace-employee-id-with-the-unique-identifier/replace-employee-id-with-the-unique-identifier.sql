# Write your MySQL query statement below
SELECT a.unique_id, b.name
FROM Employees b
LEFT JOIN EmployeeUNI a ON a.id=b.id;
