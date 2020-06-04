-- Write your MySQL query statement below  也是一个比较常见的情景
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND
p1.Id > p2.Id