CREATE TABLE bank_account(
acc_no VARCHAR(20) PRIMARY KEY,
cust_name VARCHAR(20),
amount NUMBER
);
/
INSERT INTO bank_account VALUES("A001","Crocodile",1000000);
INSERT INTO bank_account VALUES("A002","Manish",300000);
INSERT INTO bank_account VALUES("A003","Bharat",70000);
INSERT INTO bank_account VALUES("A004","Radib",2000000);
INSERT INTO bank_account VALUES("A005","Amardeep",4500000);
/
CREATE TABLE back_account(
acc_no VARCHAR(20) PRIMARY KEY,
cust_name VARCHAR(20),
amount INT
);
/
CREATE TRIGGER backup_trigger BEFORE DELETE ON ACCOUNT FOR EACH ROW
BEGIN
INSERT INTO back_account VALUES(:old.acc_no,:old.cust_name,:old.amount);
END
/
SELECT * FROM bank_account;
