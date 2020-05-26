#扩展性非常强的方法，逻辑很简单
# Write your MySQL query statement below
select S1.Score, count(S2.Score) as 'Rank'
FROM Scores as S1,
(SELECT DISTINCT Score FROM Scores) S2
WHERE S1.Score<=S2.Score
GROUP BY S1.Id 
ORDER BY S1.Score DESC;