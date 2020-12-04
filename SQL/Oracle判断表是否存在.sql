Oracle使用的是PL/SQL, 不支持IF NOT EXISTS 条件

    DECLARE
    i integer;
    BEGIN
    	SELECT count(*) INTO i FROM USER_ALL_TABLES WHERE TABLE_NAME='PRODUCT';
    	IF i>0 
    	THEN
    		EXECUTE immediate 'DROP TABLE PRODUCT';
    	ELSE
    		EXECUTE immediate 'CREATE TABLE PRODUCT
    		(
    			ID integer NOT NULL,
    			VERSION integer,
    			TITLE varchar (255),
    			SKU varchar (255),
    			PARENTSKU varchar (255),
    			COLOR varchar (255),
    			DESCRIPTION varchar (255),
    			PRICE varchar (255),
    			CONSTRAINT PK_PRODUCT_ID PRIMARY KEY(ID)
    		)';
    	END IF;
    END;


------创建TABNAME ----------
DECLARE
  TOTAL INT := 0;
BEGIN
  SELECT COUNT(1)
    INTO TOTAL
    FROM USER_TABLES A
   WHERE A.TABLE_NAME = 'TABNAME ';
  IF TOTAL > 0 THEN
    EXECUTE IMMEDIATE 'DROP TABLE TABNAME ';
  END IF;
END;
/
CREATE TABLE TABNAME (
  ---具体建表语句
);
 alter table TABNAMEadd constraint PK_TABNAME_ID primary key(id);







