-- Write your MySQL query statement below
select w2.Id
from Weather w1, Weather w2
where w1.Temperature < w2.Temperature and to_days(w2.RecordDate) - to_days(w1.RecordDate) = 1