# Write your MySQL query statement below
select distinct Products.product_id, IFNULL(latest_prices.new_price, 10) as price

from Products

Left JOIN

#latest prices
(select product_id, new_price from Products
where (product_id, change_date) IN

#letest_price range
(select product_id, max(change_date) as change_date from Products
where change_date <= '2019-08-16'
group by product_id)) latest_prices

on Products.product_id = latest_prices.product_id;