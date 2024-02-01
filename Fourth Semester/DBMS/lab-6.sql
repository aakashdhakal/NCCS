CREATE TABLE DEmployee(
    eid number PRIMARY KEY,
    ename varchar(20),
    salary NUMBER, 
    CONSTRAINT sal_check CHECK(salary BETWEEN 20000 AND 100000)
);
/
CREATE TABLE MEmployee(
    eid NUMBER PRIMARY KEY,
    ename varchar(20),
    salary NUMBER NOT NULL,
     CONSTRAINT msal_check CHECK(salary BETWEEN 20000 AND 100000) 
);
/
INSERT INTO DEmployee VALUES(101,"Aakash",20000);
INSERT INTO DEmployee VALUES(102,"Amardeep",200000);
INSERT INTO DEmployee VALUES(103,"Bharad",80000);
INSERT INTO DEmployee VALUES(104,"Bisan",70000);
INSERT INTO DEmployee VALUES(105,"Atullya",43000);
/
INSERT INTO MEmployee VALUES(101,"Aakash",20000);
INSERT INTO MEmployee VALUES(102,"Waiwab",100000);
INSERT INTO MEmployee VALUES(103,"Bharad",80000);
INSERT INTO MEmployee VALUES(104,"Pukar",76500);
INSERT INTO MEmployee VALUES(105,"Umang",94000);
/
SELECT * FROM DEmployee CROSS JOIN SELECT * FROM MEmployee;
/
-- SELECT * FROM DEmployee UNION MEmployee;
/
SELECT * FROM DEmployee INTERSECT MEmployee;
/





