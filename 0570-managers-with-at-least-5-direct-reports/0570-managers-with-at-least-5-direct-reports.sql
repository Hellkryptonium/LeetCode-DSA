SELECT e.name
FROM (
    SELECT managerId, COUNT(*) AS cnt
    FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) t
JOIN Employee e ON t.managerId = e.id;
