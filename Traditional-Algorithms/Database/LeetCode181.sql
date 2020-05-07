# Write your MySQL query statement below
select E.name as Employee
from Employee as E,Employee as F
where E.ManagerId = F.Id and E.Salary > F.Salary