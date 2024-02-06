
create table student (full_name varchar(50));

insert into student values('Shuvranshu Samal');
insert into student values('Happy Rout');
insert into student values('Abhisek Sahoo');
select * from student;

-- using sub string find first_name and last_name from full_name --
select full_name, substring(full_name,1,(locate(' ', full_name)-1))as first_name,
reverse(substring(reverse(full_name),1, locate(' ', reverse(full_name))-1)) as last_name from student;



 -- find first name from full name by using sub string
 select full_name, substring( full_name, 1,( locate(' ',full_name) - 1 )) as firstname from student;

-- find the first name from full name by using left()
select full_name, left(full_name,locate(' ', full_name) -1 )as firstname from student;

-- find the last name from full name by substring
select full_name, reverse(substring(reverse(full_name),1, locate(' ', reverse(full_name))-1)) as lastname from student;

-- find the firstname and lastname from full name
SELECT full_name,
left(full_name, locate(' ', full_name) - 1) AS 'FirstName',
REVERSE(SUBSTRING(REVERSE(full_name), 1, locate(' ', REVERSE(full_name)) - 1))  AS 'LastName'
FROM student;

-- for decimal value --
  create table deciint (Id int ,
  name varchar (30),
  month decimal(3,1));
  
  insert into deciint values(1,'shubham', 12.5);
  insert into deciint values(2,'narayan', 4.5);
 select * from deciint;