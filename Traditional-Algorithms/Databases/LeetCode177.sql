#该方法扩展性非常强，能够找到任意排名的工资，这算是SQL中的第n大问题的统一解决办法，参见LeetCode177, LeetCode178, LeetCode184
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select ifnull(E.Salary, null) 
      from
      (select E1.Salary, count(distinct E2.Salary) as 'Rank'
      from Employee as E1,
      (select distinct Salary from Employee) as E2
      where E1.Salary <= E2.Salary
      group by E1.Id) as E
      where E.Rank = N
      limit 1
  );
END


#方法二：扩展性较差
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct ifnull(Employee.Salary, null)
      from Employee
      order by Salary desc
      limit 1
      offset N
  );
END