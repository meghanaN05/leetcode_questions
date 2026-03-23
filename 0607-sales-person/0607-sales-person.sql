SELECT s.name
FROM SalesPerson s
LEFT JOIN (
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'RED'
) AS red_orders ON s.sales_id = red_orders.sales_id
WHERE red_orders.sales_id IS NULL;