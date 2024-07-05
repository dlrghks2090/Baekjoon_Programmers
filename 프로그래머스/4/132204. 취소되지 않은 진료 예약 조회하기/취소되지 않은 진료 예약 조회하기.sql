-- 코드를 입력하세요

select c.apnt_no, d.pt_name, c.pt_no, c.mcdp_cd, c.dr_name, c.apnt_ymd
from (select a.apnt_no, a.pt_no, a.mcdp_cd, b.dr_name, a.apnt_ymd
from (SELECT apnt_no, pt_no, mcdp_cd, mddr_id, apnt_ymd from appointment where date_format(APNT_YMD, '%Y-%m-%d')='2022-04-13' and mcdp_cd='cs' and apnt_cncl_yn='n') a
left join doctor b on a.mddr_id=b.dr_id) c
join patient d on c.pt_no=d.pt_no
order by apnt_ymd asc;