
DROP TABLE student
/
DROP TRIGGER trig_resut1_compute;
/
CREATE TABLE student
(
sid INT PRIMARY KEY,
sname varchar2(20),
dbms INT,
toc INT,
cn INT,
os INT,
ai INT,
total INT,
percen INT,
division VARCHAR(20)
);
/
SET SERVEROUTPUT ON;
CREATE TRIGGER trig_resut1_compute
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
:new.total:=:new.dbms+:new.toc+:new.ai+:new.os+:new.cn;
:new.percen:=:new.total/5;
IF(:new.percen>=80) THEN
:new.div:='Distinction';
elsif(:new.percen>=60) THEN
:new.div:='First';
elsif(:new.percen>=45) THEN
:new.div:='Second';
elsif(:new.percen>=32) THEN
:new.div:='Third';
ELSE
:new.div:='Fail';
END IF;
dbms_output.put_line('Total marks='||:new.total);
dbms_output.put_line('Percentage='||:new.percen);
dbms_output.put_line('Division='||:new.div);
END;
/
INSERT INTO student(sid,sname,dbms,toc,ai,os,cn) VALUES (107,'Binita',99,60,45,60,70);
/
SELECT * FROM student;
