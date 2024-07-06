-- 코드를 입력하세요
select a.cart_id
from (select * from cart_products where name='Milk') a
join (select * from cart_products where name='Yogurt') b on a.cart_id=b.cart_id
order by cart_id asc;