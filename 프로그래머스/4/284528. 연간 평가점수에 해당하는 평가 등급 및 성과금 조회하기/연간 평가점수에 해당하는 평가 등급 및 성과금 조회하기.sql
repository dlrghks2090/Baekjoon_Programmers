-- 코드를 작성해주세요
select c.emp_no, c.emp_name, c.grade,
    case
        when c.grade = 'S'
        then c.sal*0.2
        when c.grade = 'A'
        then c.sal*0.15
        when c.grade = 'B'
        then c.sal*0.1
        else c.sal*0
    end bonus
from (select a.emp_no, a.emp_name, 
    case
        when avg(b.score) >= 96
        then 'S'
        when avg(b.score) >= 90
        then 'A'
        when avg(b.score) >= 80
        then 'B'
        else 'C'
    end grade, 
    a.sal
from hr_employees a left join hr_grade b on a.emp_no=b.emp_no group by emp_no) c
order by emp_no asc;