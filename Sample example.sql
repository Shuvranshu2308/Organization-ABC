use demo;
use demodb;

-- employee table --
create table employee(emp_id varchar(20),
	emp_name varchar(20),
	salary int,
	dept_id varchar(20),
	manager_id varchar(20));
    
    insert into employee values ('E1', 'rahul', '15000', 'D1', 'M1');
	insert into employee values ('E2', 'manoj', '15000', 'D1','M1');
	insert into employee values ('E3', 'james', '55000', 'D2', 'M2');
	insert into employee values ('E4', 'michel', '25000', 'D2', 'M2');
	insert into employee values ('E5', 'ali', '20000', 'D10', 'M3');
	insert into employee values ('E6', 'robin', '35000', 'D10', 'M3');
    select * from employee;
    
    
    
    -- department table --
    create table department(dept_id varchar(20), 
    dept_name varchar(20));
    
    insert into department values('D1', 'IT');
    insert into department values('D2', 'HR');
    insert into department values('D3', 'FINANCE');
    insert into department values('D4', 'ADMIN');
    select * from department;
    
    
    
    -- manager table --
    create table Manager(manager_id varchar(20),
	manager_name varchar(20),
	Dept_id varchar(20));

	insert into Manager values ('M1', 'Prem', 'D3');
	insert into Manager values ('M2', 'Sripadha', 'D4');
	insert into Manager values ('M3', 'Nick', 'D1'); 
    insert into Manager values ('M4', 'Carry', 'D1'); 
    select * from Manager;
    
    
    
    -- project table--
    create table Project(Project_id varchar (20), 
    Project_name varchar(20),
	Team_member_id varchar(20));
    
    insert into project values('P1', 'Data Migration', 'E1');
    insert into project values('P1', 'Data Migration', 'E2');
    insert into project values('P1', 'Data Migration', 'M3');
    insert into project values('P2', 'ETL Tool', 'E1');
    insert into project values('P2', 'ETL Tool', 'M4');
    select * from project;



select * from employee; 
select * from department;
select * from manager;
select * from project;

-- USING JOINS 
-- Fetch the employee name and department name they belong to 
 select e.emp_name, d.dept_name from employee e
 join department d
 on e.dept_id= d.dept_id;
 
 
 select * from employee e
 join department d
 on e.dept_id= d.dept_id;

 
 
select e.* , d.dept_name from employee e
 join department d
 on e.dept_id= d.dept_id;



    