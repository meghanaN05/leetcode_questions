SELECT p.unique_id, q.name
FROM Employees q
LEFT JOIN EmployeeUNI p
    ON p.id = q.id;
