-- 코드를 입력하세요
select year(a.sales_date) year, month(a.sales_date) month, b.gender, count(distinct a.user_id) users
from online_sale a left join user_info b on a.user_id=b.user_id 
where b.gender is not null
group by year, month, gender
order by year,month,gender asc;


/*
group by year and month and gender
*/