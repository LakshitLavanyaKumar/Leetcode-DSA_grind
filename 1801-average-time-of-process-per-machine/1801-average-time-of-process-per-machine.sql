# Write your MySQL query statement below
SELECT a1.machine_id , round( avg(a2.timestamp -a1.timestamp ) , 3) as processing_time
FROM Activity a1
join Activity a2
on a1.machine_id= a2.machine_id 
where a1.activity_type="start" && a2.activity_type="end"
group by a1.machine_id;