#include "Hash_Table.h"

Hash_Table::Hash_Table()
{	
	size_t i = 0;
	
	table_ = new List_Main[size_];
	
	while(i <= size_)
	{	
		table_[i].hash = i;
		i++;
	}
}

Hash_Table::~Hash_Table()
{
	if(size_ == 0)
	{
			std::cout <<"Class named \"Hash\" empty"<<std::endl; 
	}
	
	delete [] table_; 
	size_ = 0;
}

int Search_Hash(char* word)
{
	size_t i = 0;
	int hash = 0;
	
	while(word[i] != '\0')
	{
		printf("%ld", size_t(word[i]) );
		hash =(int)(word[i])  + hash; 
		i++;
	}
	
	
	hash = hash % 100;
	
	printf("%d\n", hash);
	return hash;
}

bool Hash_Table::setPush(char *word)
{	
	int hash = Search_Hash(word);
	bool push = false;
	size_t k = 0;
	
	if(table_[hash].size == 0)//Если список ещё пуст добавляем новый элемент 
	{			  //Можно избавиться, если заполнить нулевой элемент списка, что не является сложным
		List_Insert(&table_[hash], word);
		
		push = true;
		return push;
	}
	
	List_Struct* list = table_[hash].tail;
	
	do
	{	
		if(strcmp(word, list->data) == 0)//Такой элемент уже существует в хеш-таблице
		{
			
			push = false;
			return push; 	
		}
		
		if(list->next != 0)
		{
			list = list->next;
		}
	}while(list->next != 0);
	
	List_Insert(&table_[hash], word);// Добавляем элемент в хеш-таблицу

	push = true;


	return push;
}

void Hash_Table::getDump()
{
	size_t i = 0;
	
	while(i < size_)
	{
		
		List_Dump(table_[i]);
		i++;
		
		std::cout<<std::endl;
	}	
}
