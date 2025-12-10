# Write your MySQL query statement below
SELECT p.product_name,SUM(q.unit) AS unit FROM Products p
JOIN Orders q ON p.product_id = q.product_id
WHERE q.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p.product_name, p.product_id
HAVING SUM(q.unit)>=100
