-- 방법1. 0~23 시간 컬럼만 있는 테이블생성하여 조인
-- 방법2. set을 사용한 루프문으로 처리
set @hour := -1;
select (@hour := @hour+1) hour, (select count(*) from animal_outs where hour(datetime)=@hour) count
from animal_outs where @hour < 23