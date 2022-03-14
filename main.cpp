// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <tchar.h>
#include <iostream>
#include "lab4/Print.h"
#include "lab4/Point.h"
using namespace std;

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{

	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	PrintS(st1);

	queue<int> qu1;
	qu1.push(1);
	qu1.push(2);
	qu1.push(3);
	qu1.push(4);
	PrintS(qu1);

	priority_queue<int> pq1;
	pq1.push(1);
	pq1.push(2);
	pq1.push(3);
	pq1.push(4);
	PrintS(pq1);
	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	{
		vector<char>vCh;
		vCh.push_back('a');
		vCh.push_back('b');
		vCh.push_back('c');
		vCh.push_back('d');

		PrintLeg(vCh);
		vector<char>::reverse_iterator itBeg = vCh.rbegin();
		vector<char>::reverse_iterator itEnd = vCh.rend();

		stack<char> st2(deque<char>(itBeg, itEnd));   //+++++++++++++++++/////////////////////////////////////////////////////////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
		
	/*	while (itBeg != itEnd) {
			st2.push(*itBeg);
			++itBeg;
		}*/

		PrintS(st2);
	}

	
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{queue<Point*> pqu1;
	pqu1.push(new Point(1, 1));
	pqu1.push(new Point(1, 2));
	pqu1.push(new Point(1, 3));
	pqu1.push(new Point(2, 1));
	PrintS(pqu1);
	* pqu1.front() = Point(4, 4);
	delete pqu1.back();
	pqu1.back() = new Point(5, 5);
	PrintS(pqu1);
	while (!pqu1.empty())
	{
		delete pqu1.front();
		pqu1.pop();
	}
	}






	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?  
	{
		const char* ar[] = { "abc","xyz","ghi","jkl" };
		
		priority_queue<const char*, vector<const char*>, CompareClass> pqCh(ar, ar + 4);
		
		//priority_queue<const char*> pqCh(ar, ar + 4);                //+++++++//////////////////////////////////////////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
		
		PrintS(pqCh);
		pqCh.pop();
		PrintS(pqCh);
		pqCh.pop();
		PrintS(pqCh);
	}
	




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?) дубли удаляются
	{
		
		set<Point> ptSet;
		ptSet.insert(Point(1, 1));
		ptSet.insert(Point(1, 2));
		ptSet.insert(Point(1, 3));
		PrintLeg(ptSet);
		//*(ptSet.begin()) = Point(3, 3); // const Point = Point
		set<int> iSet1{ 1,2,3,4 };
		set<int> iSet2{ 4,3,2,1 };
		iSet1.insert(iSet2.begin(), iSet2.end());
		stop
	}








	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	{
		map<const char*, int> Map;									
		Map["Ivanov"] = 100;
		Map["Sidorov"] = 90;
		Map.insert(pair<const char*, int>("Petrov", 200));
		Map.insert(pair<const char*, int>("Smirnov", 150));
		PrintLeg(Map);
		Map.insert(Map.erase(Map.find("Petrov")), pair<const char*, int>("Petrova", 120));
		PrintLeg(Map);
		stop
	}

	
		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	{
		vector<string> vStr{"abc", "def", "ghi", "abc"};
		map<string, int>sMap;

		for_each(vStr.begin(), vStr.end(), [&sMap](string str) {sMap[str] += 1;});
		PrintLeg(sMap);
	}


	{
		//е) 
		//задан массив:
		const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Alfa" };
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки

		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
		map<char, set<string>> mWords;
		for_each(words, words + 4, [&mWords](const string& str) {mWords[str.front()].insert(str); });
		//PrintLeg(mWords);
		map<char, set<string>>::iterator itBeg = mWords.begin(); //++++++++++++++++++++++++++++++++///////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
		map<char, set<string>>::iterator itEnd = mWords.end();

		
		map<char, set<string>>::iterator it = itBeg;
		for (it; it != itEnd; ++it)
		{
			cout << "\n " << (*it).first << " : " << '\n';
			PrintLeg((*it).second);
		}
		stop
	}
		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
	{
		multiset<string> g1{ "Petrov", "Ivanov", "Voronov" };
		multiset<string> g2{ "Sidorov", "Smirnov", "Ivanov" };
		map<int, multiset<string>>GMap;

		GMap[1]=g1;
		GMap[2]=g2;
		//PrintLeg(GMap);
		map<int, multiset<string>>::iterator itBeg = GMap.begin();
		map<int, multiset<string>>::iterator itEnd = GMap.end();
		map<int, multiset<string>>::iterator it = itBeg;
		for (it; it != itEnd; ++it)
		{
			cout << "\n " << (*it).first << " : " << '\n';
			PrintLeg((*it).second);
		}
		stop
	}



	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
		multimap<string, string>Dict;

		pair<string, string> trans[] = {
			{"strange","stranny"},
			{ "strange","chuzhoy" },
			{ "kind","dobry" },
			{ "kind","vid" },
			{ "dream","mechta" },
			{ "dream","son" },			
		};

		for_each(trans, trans + 6, [&Dict](pair<string, string> s) {
			Dict.insert(s);
			});
		stop
		PrintLeg(Dict);
	  
		multimap<string, string>::iterator itlow = Dict.lower_bound("kind");
		multimap<string, string>::iterator itup = Dict.upper_bound("kind");

		cout << "\n\nThis is the definitions of 'kind': ";
		for (multimap<string, string>::iterator it = itlow; it != itup; ++it)
		{
			cout << "\n\t " << (*it).second << '\n';
		}
	


   

  stop

	return 0;
}

