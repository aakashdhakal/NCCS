DROP TABLE employee;
/
CREATE TABLE employee
(
eid NUMBER PRIMARY KEY,
ename varchar2(20),
address varchar2(20),
salary NUMBER,
CONSTRAINT sal_check CHECK(salary BETWEEN 18000 AND 100000),
CONSTRAINT add_check CHECK(address IN('kathmandu','Lalitpur','Bhaktapur'))
);
/
SELECT * FROM employee;
/
DELETE FROM employee
/
INSERT INTO employee VALUES(101,'kamal',30000,'Kathmandu');
INSERT INTO employee VALUES(102,'kamala',40000,'Kathmandu');
INSERT INTO employee VALUES(103,'Bimala',40000,'Pokhara');
INSERT INTO employee VALUES(104,'Bhum',50000,'Biratnagar');
INSERT INTO employee VALUES(105,'Bhima',60000,'Dhandadhi');
/
UPDATE employee
SET salary=CASE
WHEN salary BETWEEN 10000 AND 20000 THEN salary+5000
WHEN salary BETWEEN 20000 AND 30000 THEN salary+3000
WHEN salary BETWEEN 30000 AND 40000 THEN salary+2000
WHEN salary BETWEEN 40000 AND 50000 THEN salary+1000
ELSE 
salary+500
END
