select id, if(flag is null, 0, count) as child_count
from (select a.id, count(a.id) count, sum(b.size_of_colony) flag from ecoli_data a left join ecoli_data b on a.id=b.parent_id group by a.id) c