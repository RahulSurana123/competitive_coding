
-- Solution By Rahul Surana

-- Table: Employee

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | salary      | int  |
-- +-------------+------+
-- id is the primary key (column with unique values) for this table.
-- Each row of this table contains information about the salary of an employee.
 

-- Write a solution to find the nth highest distinct salary from the Employee table. If there are less than n distinct salaries, return null.

-- The result format is in the following example.


-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--   RETURN (
--       with high as (select distinct salary from employee order by salary desc),
--       high2 as (select salary, (row_number() over (order by salary desc)) as rn from high) 
--       select salary from high2 where rn = N 
--   );
-- END

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      DECLARE M INT;
      SET M = N-1;
  RETURN (
      select distinct salary from employee 
      order by salary desc limit M, 1
  );
END