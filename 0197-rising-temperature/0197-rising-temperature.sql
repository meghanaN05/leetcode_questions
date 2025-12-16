# Write your MySQL query statement below
SELECT w.id FROM Weather w
JOIN Weather q
ON DATEDIFF(w.recordDate,q.recordDate)=1
WHERE w.temperature>q.temperature;