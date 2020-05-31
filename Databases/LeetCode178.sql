-- 扩展性非常强的方法，逻辑很简单
--  Write your MySQL query statement below
select S1.Score, count(S2.Score) as 'Rank'
FROM Scores as S1,
(SELECT DISTINCT Score FROM Scores) S2
WHERE S1.Score<=S2.Score
GROUP BY S1.Id 
ORDER BY S1.Score DESC;


-- 使用窗口函数
select S.Score, S.row_num as 'Rank'
from
(
    select Score, dense_rank() over(order by Score desc) as row_num
    from Scores
)as S



-- 声明变量
select R.Score, R.row_num as 'Rank'
from
(
select Score, @tmp := case when @preScore = Score then @tmp else @tmp + 1 end as row_num,
       @preScore := Score
from 
    (select @tmp := 0) as t,
    (select @preScore := -1) as p,
    (select Id, Score from Scores order by Score desc) as s
) as R