-- Last updated: 8/9/2026, 12:36:42 PM
# Write your MySQL query statement below
SELECT id, 
CASE WHEN p_id IS NULL THEN "Root"
 WHEN id in (SELECT p_id FROM Tree) THEN "Inner"
Else "Leaf"
END AS type
FROM tree