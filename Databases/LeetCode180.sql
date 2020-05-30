# Write your MySQL query statement below
select distinct R1.Num as ConsecutiveNums
from
(
    select Id, Num,
       @tmp := case when @preNum <> Num then 1 when @preNum = Num then @tmp+1 end as row_num,
       @preNum := Num as pnum 
    from
        (select @preNum := -2) p,   -- 这里的初始值一定要注意，不能为-1，原题中包含了-1这个数据
        (select @tmp := -1) t,
        (select Id, Num from Logs) s
   
) as R1
where R1.row_num >= 3