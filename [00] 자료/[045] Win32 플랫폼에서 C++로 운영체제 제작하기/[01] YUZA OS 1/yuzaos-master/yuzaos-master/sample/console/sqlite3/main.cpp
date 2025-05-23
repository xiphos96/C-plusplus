#include <windef.h>
#include <sqlite3.h>
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include "GUIConsoleFramework.h"
#include <systemcall_impl.h>

extern "C" int sqlite_shell(int argc, char** argv);

using namespace std;


int TestSqlite()
{
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	sqlite3_stmt* stmt;
	int nCol;

	rc = sqlite3_open_v2("sample.db", &db, SQLITE_OPEN_READWRITE, NULL);
	if (rc == SQLITE_OK)
	{
		rc = sqlite3_exec(db, "DROP TABLE customer", NULL, 0, &zErrMsg);
		if (rc != SQLITE_OK)
			printf("SQL error: %s\n", zErrMsg);

		rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS customer (id INTEGER NOT NULL PRIMARY KEY, text VARCHAR(10))", NULL, 0, &zErrMsg);
		if (rc != SQLITE_OK) 
			printf("SQL error: %s\n", zErrMsg);

		rc = sqlite3_exec(db, "INSERT INTO customer VALUES (1, 'text1')", NULL, 0, &zErrMsg);
		if (rc != SQLITE_OK) 
			printf("SQL error: %s\n", zErrMsg);

		rc = sqlite3_exec(db, "INSERT INTO customer VALUES (2, 'text2')", NULL, 0, &zErrMsg);
		if (rc != SQLITE_OK) 
			printf("SQL error: %s\n", zErrMsg);

		rc = sqlite3_prepare_v2(db, "SELECT * FROM customer", -1, &stmt, 0);
		if (rc == SQLITE_OK) {
			int nCols = sqlite3_column_count(stmt);
			if (nCols)
			{
				for (nCol = 0; nCol < nCols; nCol++)
					printf("%s    ", sqlite3_column_name(stmt, nCol));
				printf("\n");
				while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
				{
					for (nCol = 0; nCol < nCols; nCol++)
						printf("%s    ", sqlite3_column_text(stmt, nCol));

					printf("\n");
				}
				
			}
			sqlite3_finalize(stmt);
		}
		sqlite3_close(db);
	}
	else {
		printf("Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}

	return 0;
}
int TestSqlite2()
{
	sqlite3 *conn;
	sqlite3_stmt *statement; // SQL Statement Object
		int ret = 0;
	int cols;

	// This routine opens a connection to an SQLite database file
		//  and returns a database connection object.
		ret = sqlite3_open_v2("sample.db", &conn, SQLITE_OPEN_READONLY, NULL);
	if (ret) {
		cout << "can not open database\n";
		return false;
	}

	ret = sqlite3_prepare_v2(conn, "SELECT * FROM customer", -1, &statement, NULL);
	if (ret != SQLITE_OK) {
		cout << "We did not get any data\n";
		return false;
	}

	cols = sqlite3_column_count(statement);

	for (int col = 0; col < cols; col++) {
		printf("  %s", sqlite3_column_name(statement, col));
	};
	printf("\n");

	while (true) {
		ret = sqlite3_step(statement);
		if (ret == SQLITE_ROW) {
			for (int col = 0; col < cols; col++) {
				switch (sqlite3_column_type(statement, col)) {
				case SQLITE_INTEGER:
					printf(" %d ", sqlite3_column_int(statement, col));
					break;
				case SQLITE_FLOAT:
					printf(" % f", sqlite3_column_double(statement, col));
					break;
				case SQLITE_TEXT:
					printf(" %s ", sqlite3_column_text(statement, col));
					break;
				case SQLITE_NULL:
					printf(" %s ", "NULL");
					break;
				}
			};
			printf("\n");
		}
		else if (ret == SQLITE_DONE) {
			//cout << "done" << endl;
			printf("done\n");
			
			break;
		}
		else {
			//cout << "ret:" << ret << endl;
			printf("ret: %d\n", ret);
			break;
		}
	}

	sqlite3_finalize(statement);
	sqlite3_close(conn);
	
	return true;
}

int main_impl(int argc, char** argv)
{
	sqlite_shell(argc, argv);	
	
	//TestSqlite();
	//TestSqlite2();
	return 0;
}


int main(int argc, char** argv)
{
	GUIConsoleFramework framework;
	return framework.Run(argc, argv, main_impl);

    return 0;
}



