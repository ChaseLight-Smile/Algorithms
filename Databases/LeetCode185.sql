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



-- mysql 5.x版本不支持window function，采用申明变量的方式执行
select D.name as Department, R1.Name as Employee, R1.Salary as Salary
from 
(select Name, Salary, DepartmentId
from
(
    select Name, Salary, DepartmentId,
-- 最重要的组内排序部分，@pdept存储上一个元组的DepartmentId，因此，如果DepartmentId和上一个元组不同，则从0开始重新编号；如果@pdept = DepartmentId，则如果@psal != Salary，则tmp+1；如果@pdept = DepartmentId，并且@psal = Salary， 则tmp不变
    @tmp := case when @pdept <> DepartmentId then 0 when @pdept = DepartmentId and @psal != Salary then @tmp+1 else @tmp end as row_num,
    @pdept := DepartmentId as pde,   -- 执行完比较操作之后，设置pdept为当前值
    @psal := Salary as sal    -- 执行完比较操作之后，设置psql为当前值
    from
        (select @tmp := -1) s,   -- 变量tmp存储排序后的编号
        (select @pdept := -1) c,  -- 变量pdept存储上一个元组的DepartmentId
        (select @psal := -1) d,   -- 变量psal存储上一个元组Salary
        (select Name, Salary, DepartmentId from Employee order by DepartmentId, Salary desc) t  -- @tmp在比较时，所有的元组都从该表中取出
) as T
where T.row_num < 3) as R1, Department as D
where R1.DepartmentId = D.Id   -- 优化SQL时，应该将整个投影操作先做
