-- 코드를 작성해주세요
select b.id, b.email, b.first_name, b.last_name from skillcodes a 
join developers b on a.code & b.skill_code = a.code
where a.category='Front End'
group by b.id, b.first_name, b.last_name, b.email
order by b.id;