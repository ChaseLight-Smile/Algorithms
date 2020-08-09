-- 扩展性非常强的方法，能够找到任意排名的工资
select nullif(
(select e.Salary
from 
(select E1.Salary, count(E2.Salary) as row_num
from Employee as E1, (select distinct Salary from Employee) as E2
where E1.Salary <= E2. Salary
group by E1.Id) as e
Where e.row_num = 2 limit 1), null) as SecondHighestSalary 


-- 方法二，直接采用limit offset语句完成，扩展性不如第一种方法强
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


-- 窗口函数实现，并且使用ifnull判空设置默认值
select ifnull(
(select R.Salary
from 
(
    select dense_rank() over(order by Salary desc) as row_num, Salary
    from Employee
)as R
where row_num = 2
limit 1), null) as SecondHighestSalary


-- 注意：使用下面的ifnull得不到正确的结果，原因是ifnull使用不正确
select ifnull(R.Salary, null) as SecondHighestSalary
from 
(
    select dense_rank() over(order by Salary desc) as row_num, Salary
    from Employee
)as R
where row_num = 2
limit 1


-- 使用变量的方式得到结果
select ifnull(
(select R.Salary
from
(
    select Salary, @tmp := case when @preSal <> s.Salary then @tmp+1 else @tmp end as row_num,
                   @preSal := Salary as psal
        from
            (select @tmp := 0) as t,
            (select @preSal := -1) p,
            (select Id, Salary from Employee order by Salary desc) as s
) as R
where R.row_num = 2
limit 1), null) as SecondHighestSalary 


-- nullif使用方法
select nullif(
(select R.Salary
from 
(
    select dense_rank() over(order by Salary desc) as row_num, Salary
    from Employee
)as R
where row_num = 2
limit 1), null) as SecondHighestSalary



-- 将最大的从表中排除掉，就得到第二大
select ifnull((select max(Salary) 
from Employee
where Salary not in (select max(Salary) from Employee)), null) as SecondHighestSalary

-- 得到第三大工资，扩展性很差
select max(Salary) as ThirdHighestSalary
from Employee
where Salary <>
(select max(Salary)  -- 200
from Employee 
where Salary not in (select max(Salary) from Employee)  -- 排除了第二大工资
)
and 
Salary <> (select max(Salary) from Employee)  -- 同时排除了第三大工资