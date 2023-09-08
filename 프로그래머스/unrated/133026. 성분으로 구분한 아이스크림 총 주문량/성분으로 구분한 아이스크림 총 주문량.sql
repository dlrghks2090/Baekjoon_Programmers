-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, sum(TOTAL_ORDER) as INGREDIENT_TYPE
from FIRST_HALF a
join ICECREAM_INFO b
on a.flavor = b.flavor
group by INGREDIENT_TYPE
order by TOTAL_ORDER ASC;