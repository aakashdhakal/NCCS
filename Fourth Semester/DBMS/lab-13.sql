CREATE TABLE bank_account(
acc_no VARCHAR(20) PRIMARY KEY,
cust_name VARCHAR(20),
amount INT
);
/
INSERT INTO bank_account VALUES("A001","Crocodile",1000000);
INSERT INTO bank_account VALUES("A002","Manish",300000);
INSERT INTO bank_account VALUES("A003","Bharat",70000);
INSERT INTO bank_account VALUES("A004","Radib",2000000);
INSERT INTO bank_account VALUES("A005","Amardeep",4500000);
/
SELECT * FROM bank_account;
/
SAVEPOINT A;
/
BEGIN
UPDATE bank_account SET amount = amount + 1000 WHERE acc_no = "A001";
UPDATE bank_account SET amount = amount - 1000 WHERE acc_no = "A003"
END
/
ROLLBACK TO A;
/
