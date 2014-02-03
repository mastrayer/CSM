
#include "ClientManager.h"

inline void doQuery(const char* query)
{	
	while(true)
	{
		int query_stat = mysql_query(GMYSQLConnection, query);
		if( query_stat != 0)
		{
			while(true)
			{
				MYSQL conn;
				mysql_init(&conn);
				GMYSQLConnection = mysql_real_connect(&conn, "125.209.199.224", "root", "qq!n?22GqAr8", "csm", 3306, (char*)NULL, 0);
				if(GMYSQLConnection == NULL)
				{
					for(int i=0; i<100000000; i++);
				}
				else break;
			}
		}
		else
			break;
	}
}




