#include "Hash_Table.h"

int main(int argc, char *argv[]) 
{	
	Hash_Table table_str;
	std::cout << "Hash table is empty" << std::endl; 
	
	table_str.setPush("Всем");
	table_str.setPush("Привет");
	table_str.setPush("Я");
	table_str.setPush("Тестирую");
	table_str.setPush("Таблицу");
	table_str.setPush("А");
	table_str.setPush("Точнее");
	table_str.setPush("Хеш");
	table_str.setPush("Таблицу");
	
	table_str.getDump();
	
	return 0;
}
