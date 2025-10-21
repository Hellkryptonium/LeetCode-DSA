/* Write your PL/SQL query statement below */
select euni.unique_id, e.name from Employees e LEFT JOIN EmployeeUNI euni on e.id = euni.id order by e.name;