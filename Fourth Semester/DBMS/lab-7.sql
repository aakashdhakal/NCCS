DROP TABLE  department
/
DROP TABLE employee
/
CREATE TABLE department(
    dept_id NUMBER PRIMARY KEY,
    dname VARCHAR(20) NOT NULL,
    dept_blocK_no NUMBER
);
/
INSERT INTO department VALUES(11,'CSIT',501);
INSERT INTO department VALUES(22,'BIT',601);
INSERT INTO department VALUES(33,'BCA',701);
INSERT INTO department VALUES(44,'BIM',801);
INSERT INTO department VALUES(55,'BBA',901);
INSERT INTO department VALUES(66,'BSW',1001);
/
DELETE FROM department WHERE dept_id=11;
/
SELECT * FROM department;
/
CREATE TABLE employee(
    eid NUMBER PRIMARY KEY,
    ename VARCHAR(20) NOT NULL,
    salary NUMBER,
    address VARCHAR(40),
    dept_no NUMBER,
    FOREIGN KEY(dept_no) REFERENCES department(dept_id) ON DELETE CASCADE
);
/
INSERT INTO employee VALUES(1001,'Aakash',40000,'Kathmandu',11);
INSERT INTO employee VALUES(1002,'Radib',50000,'Kathmandu',11);
INSERT INTO employee VALUES(1003,'Bharad',60000,'Kathmandu',22);
INSERT INTO employee VALUES(1004,'WaiWai',70000,'Kathmandu',33);
INSERT INTO employee VALUES(1005,'Umang',80000,'Kathmandu',44);
INSERT INTO employee VALUES(1006,'Susan',90000,'Kathmandu',55);
INSERT INTO employee VALUES(1007,'Swarup',100000,'Kathmandu',55);
INSERT INTO employee VALUES(1008,'Atullya',110000,'Kathmandu',11);
INSERT INTO employee VALUES(1009,'Manish',120000,'Kathmandu',11);
INSERT INTO employee VALUES(1010,'Pandey',140000,'Kathmandu',55);
/
DELETE FROM employee WHERE eid=1001;
/
SELECT * FROM employee;
/
SELECT * FROM department d INNER JOIN employee e ON (d.DEPT_ID = e.DEPT_NO);
/
SELECT * FROM department d LEFT OUTER JOIN employee e ON (d.DEPT_ID = e.DEPT_NO);
/
SELECT * FROM department d RIGHT OUTER JOIN employee e ON (d.DEPT_ID = e.DEPT_NO);
/
SELECT * FROM department d FULL OUTER JOIN employee e ON (d.DEPT_ID = e.DEPT_NO);

