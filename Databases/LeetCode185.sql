-- Write your MySQL query statement below
-- 用到了窗口函数，dense_rank()在3, 2, 2, 1的情况下得到的排序为1, 2, 2, 3 如果用rank()会得到1,2,2,4，也就是说rank()函数会跳号
-- LeetCode中使用select version() 会看到其mysql版本为8.0， mysql在8.0版本开始支持窗口函数，这在Oracle、PostgreSQL中早已支持
select D.Name Department, Employee, Salary
from
(select R1.Name as Employee, R1.Salary, R1.DepartmentId
from
(
    select dense_rank() over(partition by DepartmentId order by Salary desc) as row_num, Id, name, Salary, DepartmentId
    from Employee
)as R1
where R1.row_num <= 3) as S1, Department as D
where S1.DepartmentId = D.Id

