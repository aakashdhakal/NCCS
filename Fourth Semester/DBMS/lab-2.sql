/
CREATE TABLE department(
 dno INT PRIMARY KEY,
 dname VARCHAR(20) NOT NULL,
 block_no INT 
);
/
INSERT INTO department VALUES(101, "BCA", 10);
INSERT INTO department VALUES(102, "BIM", 20);
INSERT INTO department VALUES(103, "CSIT", 30);
/
 SELECT * FROM department;
/
CREATE TABLE employee(
 eid VARCHAR(10) PRIMARY KEY,
 ename VARCHAR(20),
 address VARCHAR(100),
 salary INT,
 dno INT,
 FOREIGN KEY(dno) REFERENCES department(dno)
);
/
INSERT INTO employee VALUES("E01","Bharad","Tokha",15000,103);
INSERT INTO employee VALUES("E02","Rajib","Bhaktapur",25000,102);
INSERT INTO employee VALUES("E03","Aakash","Gothatar",150000,101);
INSERT INTO employee VALUES("E04","Amardeep","Kapan",5000,103);
/
SELECT * FROM employee;