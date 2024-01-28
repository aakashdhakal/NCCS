drop table employees;
/
drop table highly_paid_employees;
/
create table employees(
    eid int primary key,
    ename varchar(20),
    salary int
);
/
insert into employees values(101,'Kamal',120000);
insert into employees values(102,'Kamala',130000);
insert into employees values(103,'Bimala',12000);
insert into employees values(104,'Ramesh',1200);
insert into employees values(105,'Ram',170000);
/
select * from employees;
/
create table highly_paid_employees
as 
select * from employees
where salary >= 100000
/
