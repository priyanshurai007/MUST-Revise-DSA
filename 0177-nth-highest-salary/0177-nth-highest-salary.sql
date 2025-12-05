create function getNthhighestsalary(n int) returns int
begin
    declare m int;
    set m=n-1;
    return (
        select distinct salary 
        from Employee
        order by salary desc
        limit 1 offset m
    );
end

