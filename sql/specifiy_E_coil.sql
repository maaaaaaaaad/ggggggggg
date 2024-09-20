WITH FIRST_GEN AS (
  SELECT ID
  FROM ECOLI_DATA
  WHERE PARENT_ID IS NULL
),
SECOND_GEN AS(
  SELECT ECOLI_DATA.ID, ECOLI_DATA.PARENT_ID
  FROM ECOLI_DATA JOIN FIRST_GEN ON ECOLI_DATA.PARENT_ID = FIRST_GEN.ID
)
SELECT ECOLI_DATA.ID
FROM ECOLI_DATA JOIN SECOND_GEN ON ECOLI_DATA.PARENT_ID = SECOND_GEN.ID