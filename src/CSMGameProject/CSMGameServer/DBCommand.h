
#include "ClientManager.h"

inline bool doQuery(const char* query)
{	
	if(GMYSQLConnection == NULL)
	{
		if(GMYSQLCONN == NULL)
			GMYSQLCONN = (MYSQL*)malloc(sizeof(GMYSQLCONN));
		if(mysql_init(GMYSQLCONN) == NULL)
		{
			printf("Mysql connection error : %s", mysql_error(GMYSQLCONN));
			return false;
		}
		GMYSQLConnection = mysql_real_connect(GMYSQLCONN, "125.209.199.224", "root", "qq!n?22GqAr8", "csm", 3306, (char*)NULL, 0);
		if(GMYSQLConnection == NULL)
		{
			printf("Mysql connection error : %s", mysql_error(GMYSQLCONN));
			return false;
		}
	}

	int query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf("Mysql connection error : %s", mysql_error(GMYSQLCONN));
		GMYSQLConnection = NULL;	
		return false;

	}
	return true;
}




