-- 코드를 작성해주세요
select a.score, a.emp_no, b.emp_name, b.position, b.email from
(select sum(score) score, emp_no from hr_grade group by emp_no having score = (select sum(score) score from hr_grade group by emp_no order by score desc limit 1)) a join hr_employees b on a.emp_no=b.emp_no;