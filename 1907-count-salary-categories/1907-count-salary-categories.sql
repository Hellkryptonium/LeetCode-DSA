# Write your MySQL query statement below
select 'Low Salary' as category,
    SUM(income < 20000) as accounts_count
from Accounts

union all

select 'Average Salary' as category,
    SUM(income between 20000 and 50000) as accounts_count
from Accounts

union all

select 'High Salary' as category,
    SUM(income > 50000) as accounts_count
from Accounts;
