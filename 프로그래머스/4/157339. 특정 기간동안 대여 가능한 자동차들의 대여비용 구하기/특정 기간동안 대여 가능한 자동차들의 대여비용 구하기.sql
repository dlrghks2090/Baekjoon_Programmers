-- 코드를 입력하세요

select c.car_id, c.car_type, round(c.daily_fee*(100-d.discount_rate)/100)*30 as fee from 
(select a.car_id, a.car_type, a.daily_fee from CAR_RENTAL_COMPANY_CAR a
join
(select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY where not car_id in (select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY where start_date <= '2022-11-30' and end_date >='2022-11-01') group by car_id) b 
on a.car_id=b.car_id where a.car_type in ('suv','세단')) c
join
(select * from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where car_type in('세단','suv') and duration_type='30일 이상') d
on c.car_type=d.car_type having fee >=500000 and fee < 2000000
order by fee desc, car_type asc, car_id desc;