#first select the maxsalary from each department from employee table
#second now join the table with employee to get the maxsalary employee from each department
select d.name as Department, e.name as Employee, e.salary as Salary
from (Employee e join (select departmentId, max(salary) as max_salary
                        from Employee
                        group by departmentId) as m
    on e.departmentId=m.departmentId and e.salary=m.max_salary)
join Department d
on e.departmentId=d.id 