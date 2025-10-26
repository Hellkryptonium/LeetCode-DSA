# Write your MySQL query statement below
WITH process_times AS (
    SELECT 
        machine_id,
        process_id,
        timestamp - LAG(timestamp) OVER (
            PARTITION BY machine_id, process_id 
            ORDER BY activity_type
        ) AS duration,
        activity_type
    FROM Activity
)
SELECT 
    machine_id,
    ROUND(AVG(duration), 3) AS processing_time
FROM process_times
WHERE activity_type = 'end'
GROUP BY machine_id;
