-- Write your MySQL query statement below
SELECT
	CASE
		WHEN seat.id % 2 <> 0 AND seat.id = (SELECT COUNT(*) FROM seat) THEN seat.id    -- 处理最后一行，如果是奇数则最后一行不变
		WHEN seat.id % 2 = 0 THEN seat.id - 1   -- 偶数行，则id-1
		ELSE   -- 奇数行，则id+1
			seat.id + 1
	END as id,  -- 该行的别名为id
	student 
FROM seat
ORDER BY id