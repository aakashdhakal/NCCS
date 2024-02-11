DROP TABLE  department
/
DROP TABLE employee
/
CREATE TABLE department(
    dept_id NUMBER PRIMARY KEY,
    dname VARCHAR(20) NOT NULL,
    dept_block_no NUMBER
);
/
INSERT INTO department VALUES(101,'CSIT',10);
INSERT INTO department VALUES(102,'BCA',20);
INSERT INTO department VALUES(103,'BIM',30);
INSERT INTO department VALUES(104,'BHM',40);
INSERT INTO department VALUES(105,'BBA',50);
/
SELECT * FROM department;
/
CREATE TABLE employee(
    eid NUMBER PRIMARY KEY,
    ename VARCHAR(20) NOT NULL,
    salary NUMBER,
    address VARCHAR(40),
    dept_no NUMBER,
    FOREIGN KEY(dept_no) REFERENCES department(dept_id)
);
/
INSERT INTO employee VALUES(01,'Aakash',1000000,'Gothatar',102);
INSERT INTO employee VALUES(02,'Bharad',15000,'Jhapa',101);
INSERT INTO employee VALUES(03,'Radib',350000,'Bhaktapur',103);
INSERT INTO employee VALUES(04,'Manish',65000,'Asan',104);
INSERT INTO employee VALUES(05,'WaiWai',800000,'Kalanki',105);
/
SELECT * FROM employee;
/
