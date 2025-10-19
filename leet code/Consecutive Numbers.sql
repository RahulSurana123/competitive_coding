

-- Solution By Rahul Surana
-- 
-- Table: Logs

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- In SQL, id is the primary key for this table.
-- id is an autoincrement column starting from 1.
 

-- Find all numbers that appear at least three times consecutively.

-- Return the result table in any order.

-- The result format is in the following example.


with lagtemp as (select id, num, Lag(num) over (order by id) as pnum from logs ),
grouptemp as( select id, num, sum(case when num <> pnum or pnum is null then 1 else 0 end) over (order by id) as gid from lagtemp)

-- select * from lagtemp;
-- select * from grouptemp;
select distinct num as ConsecutiveNums from grouptemp group by gid having count(num)>2 ; 
