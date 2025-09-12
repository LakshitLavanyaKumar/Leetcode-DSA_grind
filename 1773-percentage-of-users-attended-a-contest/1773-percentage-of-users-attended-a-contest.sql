# Write your MySQL query statement below
select a.contest_id ,
round( ((count( distinct a.user_id))*100)/(select count(distinct user_id) from Users) ,2)  as percentage
from Register a
left join Users b
on a.user_id  = b.user_id
group by a.contest_id
order by percentage DESC , a.contest_id
;