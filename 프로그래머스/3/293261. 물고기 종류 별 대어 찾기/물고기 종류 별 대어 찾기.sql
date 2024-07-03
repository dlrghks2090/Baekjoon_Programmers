-- 코드를 작성해주세요
select c.id, d.fish_name, d.length
from fish_info c
join
(select a.fish_type, b.fish_name, a.length
from (select fish_type, max(length) length from fish_info group by fish_type) a
left join fish_name_info b on a.fish_type=b.fish_type) d
on c.fish_type=d.fish_type and c.length=d.length
order by id asc;