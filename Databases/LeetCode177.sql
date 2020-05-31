#该方法扩展性非常强，能够找到任意排名的工资，这算是SQL中的第n大问题的统一解决办法，参见LeetCode177, LeetCode178, LeetCode184
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- 方法一： 扩展性强，并且逻辑比较好
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


-- 方法二：扩展性较差
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

-- 方法三：使用窗口函数，MySQL 8.0以上，PostgreSQL和Oracle均支持
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select ifnull(E.Salary, NULL)
      from 
      (
        select dense_rank() over(order by Salary desc) as rank_num, Salary from Employee
      )as E
      where E.rank_num = N
      limit 1
  );
END

-- 采用变量sql解法
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select ifnull(Salary, null)
      from
      (
      select Salary, @tmp := case when @preSal = Salary then @tmp else @tmp+1 end as row_num,
             @preSal := Salary
      from
        (select @tmp := 0) as t,
        (select @preSal := -1)  as p,
        (select Id, Salary from Employee order by Salary desc) as s
      ) as R
      where R.row_num = N
      limit 1
  );
END