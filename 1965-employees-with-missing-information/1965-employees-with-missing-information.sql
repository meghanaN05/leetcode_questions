(
SELECT e.employee_id 
FROM Employees e  
LEFT  JOIN  salaries s on s.employee_id = e.employee_id
WHERE s.employee_id is null
UNION
SELECT s.employee_id 
FROM Employees e  
Right JOIN  salaries s on s.employee_id = e.employee_id
WHERE e.employee_id is null
)
ORDER BY employee_id ASC