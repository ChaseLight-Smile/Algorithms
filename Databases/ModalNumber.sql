-- 求某一列的众数
select salary, E.sal_cnt
from 
(
	select salary, count(salary) as sal_cnt
	from worker 
	group by SALARY
) as E
order by E.sal_cnt desc
limit 1;