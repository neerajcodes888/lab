SELECT CASE WHEN grouping(QUARTER) = 1 
THEN 'All' 
ELSE QUARTER END AS QUARTER, 
CASE WHEN grouping(REGION) = 1 
THEN 'All' ELSE REGION END AS REGION, 
SUM(SALE) 
FROM SALES 
GROUP BY CUBE (QUARTER, REGION); 
