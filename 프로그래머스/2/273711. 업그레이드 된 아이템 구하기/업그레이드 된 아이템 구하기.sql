-- 코드를 작성해주세요

select c.item_id, c.item_name, c.rarity from item_info c join
(select b.item_id from (select * from item_info where rarity='rare') a left join item_tree b on a.item_id=b.parent_item_id where b.parent_item_id is not null) d
on c.item_id=d.item_id
order by c.item_id  desc;