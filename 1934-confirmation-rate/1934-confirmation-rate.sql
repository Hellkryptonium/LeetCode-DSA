# Write your MySQL query statement below
select 
    s.user_id,
    coalesce(round(sum(c.action = 'confirmed')/nullif(count(c.action),0),2),0.00) as confirmation_rate
from Signups s 
left join Confirmations c 
    on s.user_id = c.user_id 
group by s.user_id;