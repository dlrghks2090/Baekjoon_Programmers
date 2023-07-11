-- 코드를 입력하세요



SELECT a.TITLE, a.BOARD_ID, b.REPLY_ID, b.WRITER_ID, b.CONTENTS, date_format(b.created_date, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD as a,  USED_GOODS_REPLY as b 
where a.BOARD_ID = b.BOARD_ID and date_format(a.CREATED_DATE, '%Y-%m') = "2022-10" 
order by b.CREATED_DATE asc, a.title asc;