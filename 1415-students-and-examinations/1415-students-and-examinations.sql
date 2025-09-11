# Write your MySQL query statement below
Select a.student_id , a.student_name , b.subject_name  , count(c.student_id) as attended_exams
From Students a
cross join Subjects b
left join Examinations c
on a.student_id = c.student_id and b.subject_name=c.subject_name 
group  by a.student_id , a.student_name , b.subject_name
order by a.student_id , a.student_name;