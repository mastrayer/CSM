
#include "ClientManager.h"

inline bool ExcuteNonQuery(const char* query)
{	
	MYSQL* GMYSQLConnection = NULL;
	MYSQL GMYSQLCONN;

	//GMYSQLCONN = (MYSQL*)malloc(sizeof(GMYSQLCONN));
	if(mysql_init(&GMYSQLCONN) == NULL)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		return false;
	}
	GMYSQLConnection = mysql_real_connect(&GMYSQLCONN, "125.209.199.224", "root", "qq!n?22GqAr8", "csm", 3306, (char*)NULL, 0);
	if(GMYSQLConnection == NULL)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		mysql_close(GMYSQLConnection);
		return false;
	}

	int query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		mysql_close(GMYSQLConnection);
		return false;
	}

	mysql_close(GMYSQLConnection);
	return true;
}
inline bool ExcuteQuery(const char* query, MYSQL_RES **sql_result)
{	
	MYSQL* GMYSQLConnection = NULL;
	MYSQL GMYSQLCONN;

	//GMYSQLCONN = (MYSQL*)malloc(sizeof(GMYSQLCONN));
	if(mysql_init(&GMYSQLCONN) == NULL)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		return false;
	}
	GMYSQLConnection = mysql_real_connect(&GMYSQLCONN, "125.209.199.224", "root", "qq!n?22GqAr8", "csm", 3306, (char*)NULL, 0);
	if(GMYSQLConnection == NULL)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		mysql_close(GMYSQLConnection);
		return false;
	}

	int query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf("Mysql connection error : %s", mysql_error(&GMYSQLCONN));
		mysql_close(GMYSQLConnection);
		return false;
	}

	*sql_result = mysql_store_result(GMYSQLConnection);

	mysql_close(GMYSQLConnection);

	return true;
}




