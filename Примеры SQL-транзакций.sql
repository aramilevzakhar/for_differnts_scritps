

--������ ������� �����
CREATE TABLE book (
count_page NUMBER,
author varchar(234),
namebook varchar(32),
CONSTRAINT namebook_unique UNIQUE (namebook)
);

--������ ������� �������
CREATE TABLE female (
name varchar(20),
age NUMBER,
sex NUMBER
);

--��������� � ������� �������
INSERT INTO female (name, age, sex) VALUES ('Lera', 28, 1);
--��������� � ������� �����
INSERT INTO book (count_page, author, namebook) VALUES (333, '������ �������', '�� ���');

--������� ������� �������
DROP TABLE female;
--������� ������� �����
DROP TABLE book;


--INSERT INTO * females ()
--SELECT * FROM ALL_TABLES WHERE OWNER='SYS';
--SELECT * FROM ALL_ALL_TABLES;
SELECT * FROM ALL_TABLES WHERE TABLE_NAME='FEMALE';
SELECT * FROM female;
SELECT * FROM book;

DELETE FROM book WHERE count_page=333;

ALTER TABLE book ADD COLUMN id PRIMARY






