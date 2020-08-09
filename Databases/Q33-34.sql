-- https://www.techbeamers.com/sql-query-questions-answers-for-practice/

-- Q-33/34 文章中的方法是错误的，改成下面的方法
select w.WORKER_ID
from
(select w1.WORKER_ID, count(w2.salary) as row_num
from worker as w1, (select distinct salary from worker) as w2
where w1.SALARY <= w2.salary
group by w1.WORKER_ID
) as w
where w.row_num = 5;

SELECT WORKER_ID
FROM Worker W1
WHERE 5 = (
 SELECT COUNT( DISTINCT ( W2.Salary ) )
 FROM (select distinct salary from worker) as W2
 WHERE W2.Salary >= W1.Salary
 );

SELECT WORKER_ID
FROM Worker W1
WHERE 4 = (
 SELECT COUNT( DISTINCT ( W2.Salary ) )
 FROM Worker W2
 WHERE W2.Salary >= W1.Salary
 );  -- 链接中错误的方法