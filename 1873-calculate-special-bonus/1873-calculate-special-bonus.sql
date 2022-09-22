# Write your MySQL query statement below
# bc how to calculate yaar
select employee_id,
case
    WHEN employee_id%2 != 0 and name NOT LIKE 'M%' then salary
    else 0
end as bonus
from Employees ORDER BY employee_id