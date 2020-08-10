-- https://www.techbeamers.com/sql-query-questions-answers-for-practice/  修正blog中的错误

-- Q33/34 our solution 
select w.WORKER_ID
from
(select w1.WORKER_ID, count(w2.salary) as row_num
from worker as w1, (select distinct salary from worker) as w2
where w1.SALARY <= w2.salary
group by w1.WORKER_ID
) as w
where w.row_num = 2;

-- Q33/34 our solution 
SELECT WORKER_ID
FROM Worker W1
WHERE 5 = (
 SELECT COUNT( DISTINCT ( W2.Salary ) )
 FROM (select distinct salary from worker) as W2
 WHERE W2.Salary >= W1.Salary
 );

-- Q33/34
SELECT WORKER_ID
FROM Worker W1
WHERE 4 = (
 SELECT COUNT( DISTINCT ( W2.Salary ) )
 FROM Worker W2
 WHERE W2.Salary >= W1.Salary
 );  -- 方法错误

-- Q36 our solution
Select max(Salary) 
from Worker 
where Salary not in (
   Select max(Salary) from Worker
);

-- Q40 our solution
select DEPARTMENT, count(DISTINCT WORKER_ID) as num
from worker
group by DEPARTMENT
having count(distinct WORKER_ID) <= 5;


-- Q44  our solution 
select *
from worker 
order by WORKER_ID desc
limit 0, 5;

-- Q46
SELECT distinct Salary 
from worker a WHERE 3 >= 
(
SELECT count(distinct Salary) 
from worker b WHERE a.Salary <= b.Salary
) 
order by a.Salary desc;

-- Q46 our solution 
select distinct w.Salary
from
(select w1.Salary, count(w2.salary) as row_num
from worker as w1, (select distinct salary from worker) as w2
where w1.SALARY <= w2.salary
group by w1.WORKER_ID
) as w
where w.row_num <= 3;

-- Q46 our solution 
select distinct salary
from worker
order by SALARY desc
limit 0, 3;