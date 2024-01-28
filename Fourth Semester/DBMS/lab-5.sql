DROP TABLE employee;
/
CREATE TABLE employee(
eid INT PRIMARY KEY,
ename VARCHAR(20),
address VARCHAR(20),
salary INT CHECK(salary BETWEEN 17000 AND 100000)
);
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