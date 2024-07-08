-- 코드를 입력하세요
-- select a.shipment_id, a.flavor, sum(a.total_order) total_order
select a.flavor
from
(select * from first_half
union all
select * from july) a
group by flavor
order by sum(a.total_order) desc
limit 3;