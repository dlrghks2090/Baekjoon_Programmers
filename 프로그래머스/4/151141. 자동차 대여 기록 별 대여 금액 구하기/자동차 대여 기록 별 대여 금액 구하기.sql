-- 코드를 입력하세요
select c.history_id, if (d.discount_rate is null, c.day*c.daily_fee, round(c.day*c.daily_fee*(100-d.discount_rate)/100)) as fee
from (select a.car_type, a.daily_fee, b.history_id, datediff(b.end_date, b.start_date)+1 day
from CAR_RENTAL_COMPANY_CAR a join CAR_RENTAL_COMPANY_RENTAL_HISTORY b on a.car_id=b.car_id where a.car_type='트럭') c
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN d on c.car_type=d.car_type and 
case
when c.day between 7 and 29 then d.duration_type= '7일 이상'
when c.day between 30 and 89 then d.duration_type= '30일 이상'
when c.day >=90 then d.duration_type= '90일 이상'
end
order by fee desc, history_id desc;
