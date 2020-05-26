#扩展性非常强的方法，能够找到任意排名的工资
# Write your MySQL query statement below
select ifnull(
(select E.Salary
from
(select E1.Salary, count(E2.Salary) as 'Rank'
from Employee as E1,
(select distinct Salary from Employee) E2
where E1.Salary <= E2. Salary
group by E1.Id) E
where E.Rank = 2 limit 1), NULL)  as SecondHighestSalary


#方法二，直接采用limit offset语句完成，扩展性不如第一种方法强
# Write your MySQL query statement below
select ifnull(
(select Salary
from Employee
where Salary not in (select t.Salary from(
    select Salary
    from Employee
    order by Salary desc
    limit 1) as t)
order by Salary desc
limit 1), NULL
)  as SecondHighestSalary