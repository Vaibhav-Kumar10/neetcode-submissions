SELECT sp.name
FROM sales_person AS sp
WHERE sp.sales_id NOT IN (
    SELECT o.sales_id 
    FROM orders AS o 
    JOIN company AS c 
    ON o.com_id = c.com_id
    WHERE c.name = 'CRIMSON'
);