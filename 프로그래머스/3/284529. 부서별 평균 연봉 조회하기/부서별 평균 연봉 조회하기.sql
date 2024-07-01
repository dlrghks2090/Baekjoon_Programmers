-- 코드를 작성해주세요
select a.dept_id, b.dept_name_en, round(avg(a.sal),0) avg_sal from hr_employees a left join hr_department b on a.dept_id=b.dept_id group by a.dept_id order by avg_sal desc;