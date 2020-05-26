select D.name as Department , E.Name as Employee, E.Salary as Salary
from Employee as E,
(select DepartmentId, max(salary) as max
from Employee
group by DepartmentId ) as T,
Department as D
where E.salary = T.max and 
E.DepartmentId = D.Id and
E.DepartmentId = T.DepartmentId
