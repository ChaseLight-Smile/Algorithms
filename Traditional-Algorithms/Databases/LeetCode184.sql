select D.name as Department , E.Name as Employee, E.Salary as Salary
from Employee as E,
(select DepartmentId, max(salary) as max
from Employee
group by DepartmentId ) as T,
Department as D
where E.salary = T.max and 
E.DepartmentId = D.Id and
E.DepartmentId = T.DepartmentId



# 传统方法
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

