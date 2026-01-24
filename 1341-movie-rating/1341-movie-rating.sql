# Write your MySQL query statement below
select name as results from
(select user_id, name, COUNT(*)
from Users JOIN MovieRating USING(user_id)
group by 1, 2
order by 3 desc, 2 asc
limit 1) users

union all

select title as results from
(select movie_id, title, AVG(rating) 
from Movies JOIN MovieRating using(movie_id)
where DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
group by 1, 2
order by 3 desc, 2 asc
limit 1) movies

