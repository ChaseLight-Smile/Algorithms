/*
求中位数.
1. 对需要求中位数的列排序，并且求出row_number，一定要注意，行编号从0开始还是从1开始
2. 因为中位数就是排序后的中间位置，所以对于奇数来讲，直接取row_num的中间位置，对于偶数来讲，对中间位置两个位置求其平均值
DROP TABLE IF EXISTS worker;
CREATE TABLE worker (
  WORKER_ID int(11),
  FIRST_NAME char(25), 
  LAST_NAME char(25),
  SALARY int(15),
  JOINING_DATE datetime ,
  DEPARTMENT char(25)
);
*/
select avg(sal)
from
(
	select @tmp := @tmp + 1 as row_num , w.Salary as sal
	from
	(
		 (select @tmp := -1) as t,
		 (select SALARY from worker order by SALARY asc) as w
	)
) as E
where E.row_num in (FLOOR(@tmp/2), CEIL(@tmp/2));

select avg(E.salary)
from
(
	select @tmp := @tmp + 1 as row_num , Salary
	from worker as w, (select @tmp := -1) as t
  order by SALARY
) as E
where E.row_num in (FLOOR(@tmp/2), CEIL(@tmp/2));


set @tmp := -1;
select avg(E.salary)
from
(
	select @tmp := @tmp + 1 as row_num , Salary
	from worker as w
  order by SALARY
) as E
where E.row_num in (FLOOR(@tmp/2), CEIL(@tmp/2));