select * from highly_paid_employees;
/
alter table highly_paid_employees
add address varchar(20);
/
update highly_paid_employees set address =  'Kathmandu';
/
alter table highly_paid_employees
add phone_no int;
/
update highly_paid_employees set phone_no = 9841234;
/