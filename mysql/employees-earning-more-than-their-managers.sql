SELECT
    Emps1.Name AS Employee
FROM
    Employee AS Emps1,
    Employee AS Emps2
WHERE
    Emps1.ManagerId = Emps2.Id AND
    Emps1.Salary > Emps2.Salary;