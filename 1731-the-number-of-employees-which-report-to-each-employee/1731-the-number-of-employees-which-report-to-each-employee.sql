# Write your MySQL query statement below
select 
    m.employee_id,
    m.name,
    count(r.employee_id) as reports_count,
    round(avg(r.age), 0) as average_age
from Employees as m
JOIN Employees as r
    on r.reports_to = m.employee_id
group by m.employee_id, m.name
order by m.employee_id;