# Write your MySQL query statement below
SELECT a.user_id ,ifnull(round(avg(if(b.action='confirmed',1,0)),2),0) as confirmation_rate
from Signups a
left join Confirmations b
on a.user_id = b.user_id 
group by a.user_id
;
