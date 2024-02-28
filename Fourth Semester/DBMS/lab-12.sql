DROP TABLE employee;
/
CREATE TABLE employee
(
eid NUMBER PRIMARY KEY,
ename varchar2(20),
address varchar2(20),
salary NUMBER,
CHECK(salary BETWEEN 18000 AND 100000),
CHECK(address IN('Kathmandu','Lalitpur','Bhaktapur'))
);
/
INSERT INTO employee VALUES(101,'Crocodile',30000,'Kathmandu');
INSERT INTO employee VALUES(102,'kamala',40000,'Kathmandu');
INSERT INTO employee VALUES(103,'Bimala',40000,'Pokhara');
INSERT INTO employee VALUES(104,'Bhum',50000,'Biratnagar');
INSERT INTO employee VALUES(105,'Bhima',60000,'Dhandadhi');
/
CREATE materialized VIEW LOG ON enployee;
/
CREATE MATERIALIZED VIEW back_emp_recl 
REFRESH FAST ON DEMAND
NEXT TRUNC(SYSTIMESTAMP,'MI')+ INTERVAL '1' MINUTE
AS
SELECT * FROM employee
/
SELECT * FROM back_emp_recl 
