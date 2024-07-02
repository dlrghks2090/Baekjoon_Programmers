-- 코드를 작성해주세요
select c.item_id, d.item_name, d.rarity
from (select a.item_id item_id, b.item_id flag from item_tree a left join item_tree b on a.item_id=b.parent_item_id having b.item_id is null) c join item_info d on c.item_id=d.item_id order by item_id desc;