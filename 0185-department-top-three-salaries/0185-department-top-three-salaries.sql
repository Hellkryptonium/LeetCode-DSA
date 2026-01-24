# Write your MySQL query statement below
SELECT Department.Name as "Department", e.name as "Employee", e.salary FROM
(SELECT DepartmentId, name, salary, DENSE_RANK() OVER(PARTITION BY DepartmentId ORDER BY Salary DESC) AS r
From Employee) e
join Department on e.DepartmentId = Department.id
where r <= 3;