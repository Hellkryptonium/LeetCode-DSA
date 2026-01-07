# Write your MySQL query statement below
with 
    UniqueNumbers as (
        select 
            num
        from MyNumbers
        group by 1
        having count(num) = 1
)
select max(num) as num
from UniqueNumbers;