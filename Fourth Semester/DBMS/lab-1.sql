CREATE TABLE student(
    sid INT,
    sname VARCHAR(20),
    slevel VARCHAR(20),
    age INT,
    sex VARCHAR(20),
    PRIMARY KEY(sid)
);
INSERT INTO student VALUES (101,'Aakash','Bachelor',19,'Male');
/
SELECT * FROM student;
/
CREATE TABLE instructor(
Iid INT,
Iname VARCHAR(20),
age INT,
sex VARCHAR(20),
PRIMARY KEY(Iid)
);
/
INSERT INTO instructor VALUES(501,'Bharad',31,'Male');
/
SELECT * FROM instructor;
/
CREATE TABLE course(
cid VARCHAR(20),
cname VARCHAR(100),
credit_hours INT,
PRIMARY KEY(cid)
);
/
INSERT INTO course VALUES('CSC317','Simulation and Modeling',3);
/