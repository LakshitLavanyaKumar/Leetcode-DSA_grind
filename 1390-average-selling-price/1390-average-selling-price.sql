# Write your MySQL query statement below
SELECT a.product_id , ifnull(round(sum((a.price * b.units))/NULLIF(SUM(b.units), 0) , 2),0)  as average_price
from Prices a
left join UnitsSold b
on b.purchase_date>=a.start_date and b.purchase_date<=a.end_date and a.product_id=b.product_id
group by a.product_id;