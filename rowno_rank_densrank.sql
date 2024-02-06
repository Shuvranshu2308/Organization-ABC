 -- ROW NUMBER --
 -- RANK & DENSRANK --
  use demo;
   create table newemp( 
   firstname varchar(20),
   lastname varchar(20),
   age int,
   salary int,
   location varchar(20));
   
   insert into newemp values('sachin', 'sharma',28, 10000,'benglore');
   insert into newemp values('shane', 'warne',30, 20000,'benglore');
   insert into newemp values('rohit', 'sharma',32, 30000,'hydrabad');
   insert into newemp values('sikhar', 'dhawan',32, 25000,'hydrabad');
   insert into newemp values('rahul', 'dravud',31, 20000,'benglore');
   insert into newemp values('sourabh', 'ganguly',32, 15000,'punee');
   insert into newemp values('kapil', 'dev',34, 10000,'pune');
   select * from newemp;
 
 
   -- asigning row_number()
      select firstname, lastname, salary, row_number() over (order by salary desc) as rownum from newemp;
      select firstname, lastname, salary, rank() over (order by salary desc) as rownum from newemp
	  select firstname, lastname, salary, dense_rank() over (order by salary desc) as rownum from newemp;

   -- find nth heighest salary
    select * from  (select firstname, lastname, salary, row_number() over (order by salary desc) as rownum from newemp) as temptab where rownum= 2 ;
    select * from(select firstname, salary, row_number() over ( order by salary desc) as rownum from newemp) as temtab where rownum=5;
    
    
    
    -- partition by location
    select firstname,location, salary , row_number() over(partition by location order by salary desc) as rownum from newemp;
    
    -- find heigheat salary by location
    select * from (select firstname,location, salary, row_number() over( partition by location order by salary desc) as rownum from newemp) as temtab where rownum= 1;
    
    
   -- add two column -- 
    select concat(firstname, ' ', lastname) as fullname, salary from newemp;