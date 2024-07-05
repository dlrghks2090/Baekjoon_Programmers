-- 코드를 작성해주세요
select id, 
    case 
        when (row_number() over(order by size_of_colony desc))<=((select count(*) from ecoli_data)/4) then 'CRITICAL'
        when (row_number() over(order by size_of_colony desc))<=((select count(*) from ecoli_data)/2) then 'HIGH'
        when (row_number() over(order by size_of_colony desc))<=((select count(*) from ecoli_data)/4*3) then 'MEDIUM'
        else 'LOW'
        end as colony_name
from ecoli_data
order by id asc;