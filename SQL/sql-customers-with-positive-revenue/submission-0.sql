-- Write your query below
SELECT DISTINCT(customer_id) FROM CUSTOMERS
WHERE REVENUE > 0
AND YEAR = 2020;