/*
Задание 1
Создайте класс Book
Необходимо хранить данные:
Автор, Название, Издательство, Год, Количество, страниц.
Создать массив объектов.
//Author, Title, Publisher, Year, Number, pages.
Вывести:
■ список книг заданного автора;
■ список книг, выпущенных заданным издательством;
■ список книг, выпущенных после заданного года.
a list of books by a given author;
a list of books published by a given publisher;
A list of books released after a given year.
Используйте explicit конструктор и константные функции-члены (например, для отображения данных о книге и т.д.)
*/
#include <iostream>
#include <windows.h>
using namespace std;
class Book
{
	char* m_Author;
	char* m_Title;
	char* m_Publisher;
	int m_Year;
	int m_Count;
	int m_Pages;
public:
	Book(const char* athr, const char* ttl, const char* pblshr, int yr, int cnt, int pgs) :
		m_Author(_strdup(athr)), m_Title(_strdup(ttl)), m_Publisher(_strdup(pblshr)),
		m_Year(yr), m_Count(cnt), m_Pages(pgs) {
	}
	Book();
	~Book();
	char* get_aut() { return m_Author; }
	char* get_pub() { return m_Publisher; }
	int get_year() { return m_Year; }
	const void show();
	void SeekOnAutor(const char* str, Book* ob, const int count_books);
	void SeekOnPublisher(const char* str, Book* ob, const int count_books);
	void SeekOnYear(int y, Book* ob, const int count_books);
};
Book::Book()
{
	m_Author = 0;
	m_Title = 0;
	m_Publisher = 0;
	m_Year = 0;
	m_Count = 0;
	m_Pages = 0;
}
Book::~Book()
{
	delete[] m_Author; //cout << "Деструктор для " << this << endl;
	delete[] m_Title;
	delete[] m_Publisher;
}

const void Book::show()
{
	cout << "Автор: " << m_Author << endl;
	cout << "Название книги: " << m_Title << endl;
	cout << "Издательство: " << m_Publisher << endl;
	cout << "Год издания: " << m_Year << endl;
	cout << "Изданное количество: " << m_Count << endl;
	cout << "Количество страниц книги: " << m_Pages << endl;
	cout << "/****************************************************" << endl;
}

void Book::SeekOnAutor(const char* str, Book* ob, const int count_books)
{
	cout << "\tСписок книг автора " << str << ": " << endl;
	for (int i = 0; i < count_books; i++) {

		if (strcmp(ob[i].get_aut(), str) == 0) ob[i].show();
	}
	cout << '\n';
}

void Book::SeekOnPublisher(const char* str, Book* ob, const int count_books)
{
	cout << "\tСписок книг издательства " << str << ": " << endl;
	for (int i = 0; i < count_books; i++) {

		if (strcmp(ob[i].get_pub(), str) == 0) ob[i].show();
	}
	cout << '\n';
}

void Book::SeekOnYear(int y, Book* ob, const int count_books)
{
	cout << "\tСписок книг, выпущенных после " << y << ": " << endl;
	for (int i = 0; i < count_books; i++) {

		if (ob[i].get_year() > y) ob[i].show();
	}
	cout << '\n';
}
int main()
{
	setlocale(LC_ALL, ""); //працює тільки з потоком виведення
	SetConsoleCP(1251); //встановлює потрібну кодову таблицю, на потік введення
	SetConsoleOutputCP(1251); //встановлює потрібну кодову таблицю, на потік виводу.
	const int count_books = 4;
	Book* A = new Book[count_books]{
		   {"Рей Брэдбери","451 градус по фаренгейту",  "Издательство Э", 2017 , 5000, 512 },
		   {"Джордж Оруэлл","1984",  "АСТ", 1999 , 10000, 318 },
		   {"Грегори Дэвид Робертс","Шантарам",  "Азбука СПб", 2018 , 25000, 608 },
		   {"Грегори Дэвид Робертс","Тень горы",  "Азбука СПб", 2016 , 2500, 832 }
	};
	A->SeekOnAutor("Грегори Дэвид Робертс", A, count_books);
	A->SeekOnPublisher("Азбука СПб", A, count_books);
	A->SeekOnYear(2017, A, count_books);
}
