-- 코드를 작성해주세요
select id, case
    when size_of_colony between 0 and 100
    then 'LOW'
    when size_of_colony between 101 and 1000
    then 'MEDIUM'
    else 'HIGH'
    end as size
    from ecoli_data
    order by id asc;