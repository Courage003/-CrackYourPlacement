# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1
INNER JOIN Weather AS w2
WHERE w1.Temperature>w2.Temperature AND DATEDIFF(w1.recordDate, w2.recordDate)=1