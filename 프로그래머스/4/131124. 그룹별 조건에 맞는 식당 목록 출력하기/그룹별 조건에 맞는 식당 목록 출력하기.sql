-- 코드를 입력하세요
select d.member_name, c.review_text, c.review_date
from
(select a.member_id, a.review_text, date_format(a.review_date, '%Y-%m-%d') review_date from rest_review a
join
(select member_id, count(*) count from rest_review group by member_id order by count desc limit 1) b on a.member_id=b.member_id) c
join member_profile d on c.member_id=d.member_id
order by review_date, review_text asc;