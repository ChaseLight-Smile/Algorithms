-- 传统方法，1414ms
select D.name as Department , E.Name as Employee, E.Salary as Salary
from Employee as E,
(select DepartmentId, max(salary) as max
from Employee
group by DepartmentId ) as T,
Department as D
where E.salary = T.max and 
E.DepartmentId = D.Id and
E.DepartmentId = T.DepartmentId



-- 传统方法 1413ms
select D.Name as Department, E.Employee, E.Salary
from Department as D,
(select E1.Id, E1.Name as Employee, E1.DepartmentId, E1.Salary
from Employee as E1,
(select max(Salary) as Salary, DepartmentId
from Employee
group by DepartmentId) as E2
where E1.DepartmentId = E2.DepartmentId  and E1.Salary = E2.Salary) as E
where D.Id = E.DepartmentId
order by Salary desc


-- 使用MySQL 8.0窗口函数 804ms  方法扩展性很强，能够解决一类型题目
select D.Name as Department, R1.Name as Employee, R1.Salary as Salary
from
(select E1.name, E1.salary, E1.DepartmentId 
from
(
    select Name, Salary, DepartmentId, dense_rank() over(partition by DepartmentId order by Salary desc) as row_num
    from Employee
)as E1
where row_num = 1) as R1, Department as D
where D.Id = R1.DepartmentId

