-- 코드를 입력하세요
with T as (
    select 
        HISTORY_ID, 
        car_type, 
        (datediff(end_date, start_date)+1)*daily_fee as fee,
        case 
            when datediff(end_date, start_date)+1 < 7 then null
            when datediff(end_date, start_date)+1 < 30 then '7일 이상' 
            when datediff(end_date, start_date)+1 < 90 then '30일 이상'
            else '90일 이상'
        end as duration_type
    from 
        CAR_RENTAL_COMPANY_RENTAL_HISTORY a 
        join 
        CAR_RENTAL_COMPANY_CAR b 
        on a.car_id=b.car_id
    where 
        car_type='트럭'
)

SELECT 
    history_id, 
    fee * (100-ifnull(discount_rate, 0)) div 100 fee
from 
    t left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN b 
    on t.car_type=b.car_type and t.duration_type=b.duration_type
order by 
    2 desc, 1 desc