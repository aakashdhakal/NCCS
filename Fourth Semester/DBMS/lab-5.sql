CREATE TABLE employee(
eid NUMBER PRIMARY KEY,
ename VARCHAR(20),
address VARCHAR(20),
salary INT CHECK(salary BETWEEN 17000 AND 100000)
);
/
DROP TABLE employee
/
INSERT INTO employee VALUES(1,"Bharad","Tokha",60000);
INSERT INTO employee VALUES(2,"Bharad","Tokha",70000);
INSERT INTO employee VALUES(3,"Bharad","Tokha",80000);
INSERT INTO employee VALUES(4,"Bharad","Tokha",90000);
INSERT INTO employee VALUES(5,"Bharad","Tokha",100000);
INSERT INTO employee VALUES(6,"Bharad","Tokha",865000);
INSERT INTO employee VALUES(7,"Bharad","Tokha",150000);
/
SELECT * FROM employee;
/
UPDATE employee
SET salary = salary*1.1
WHERE address LIKE 'K%';
/  
UPDATE employee
SET salary = 40000
WHERE address = 'Pokhara';
/
SELECT 
MAX(salary) AS maximum_salary,
MIN(salary) AS minimum_salary
FROM employee;
/
SELECT address, AVG(salary) FROM employee GROUP BY address;
/
SELECT * FROM employee ORDER BY salary;
/