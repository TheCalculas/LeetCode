# Write your MySQL query statement below
select user_id, (concat(upper(substr(name, 1, 1)), lower(substr(name, 2)))) as Name
from Users 
Order by user_id;
