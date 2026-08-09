-- Last updated: 8/9/2026, 12:39:22 PM
SELECT C.name as Customers
FROM  Customers C
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders O
    WHERE O.customerId = c.id
);