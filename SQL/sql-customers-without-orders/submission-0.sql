SELECT c.name 
FROM customers AS c
LEFT OUTER JOIN orders AS o
ON c.id = o.customer_id
WHERE o.id IS NULL;