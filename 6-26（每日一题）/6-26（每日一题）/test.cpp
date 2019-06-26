#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int page = atoi(argv[1]);
	// ����id�����±��⣬����ʱ�䣬����
	/*
	* SELECT
	*      articles.id,
	*      title,
	*      users.username,
	*      articles.published_at
	* FROM articles, users
	* WHERE articles.author_id = users.id
	* ORDER BY published_at DESC
	* LIMIT 20 OFFSET (page - 1) * 20
	*/

	MYSQL *mysql = mysql_init(NULL);
	// ���� MySQL
	mysql_real_connect(mysql,
		"127.0.0.1",   // ip ��ַ��д�� 127.0.0.1
		"root",        // ���ݿ���û���
		"123",         // ���ݿ������
		"blog_5051",   // ���ӵ������ݿ� database
		0, NULL, 0);
	// ָ���ַ�������
	mysql_set_character_set(mysql, "utf8");

	// 1. ƴ�� SQL ���
	char *sql = "SELECT \n" \
		"     articles.id, \n" \
		"     title, \n" \
		"     users.username, \n" \
		"     articles.published_at \n" \
		"FROM articles, users \n" \
		"WHERE articles.author_id = users.id \n" \
		"ORDER BY published_at DESC \n" \
		"LIMIT 20 OFFSET %d";
	char buffer[1024];
	sprintf(buffer, sql, (page - 1) * 20);
	printf("%s\n", buffer);

	// 2. ���� MySQL C API ִ�� SQL ���
	mysql_query(mysql, buffer);
	// 3. ��ȡ��������и�ʽ����ʾ
	MYSQL_RES *result = mysql_store_result(mysql);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result)) != NULL) {
		printf("%s, %s, %s, %s\n", row[0], row[1], row[2], row[3]);
	}
	mysql_free_result(result);

	// �ر���������
	mysql_close(mysql);
}
