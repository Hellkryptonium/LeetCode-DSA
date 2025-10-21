# Write your MySQL query statement below
select euni.unique_id, e.name from Employees e LEFT JOIN EmployeeUNI euni on e.id = euni.id;