# Write your MySQL query statement below
SELECt v1.id
FROM Weather v1
join Weather v2
on datediff(v1.recordDate , v2.recordDate)=1 && v1.temperature>v2.temperature;
