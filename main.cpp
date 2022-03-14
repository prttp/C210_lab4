// ���������� STL: 
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

	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
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

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
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

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
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
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?  
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
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?) ����� ���������
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
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
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

	
		
		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
	{
		vector<string> vStr{"abc", "def", "ghi", "abc"};
		map<string, int>sMap;

		for_each(vStr.begin(), vStr.end(), [&sMap](string str) {sMap[str] += 1;});
		PrintLeg(sMap);
	}


	{
		//�) 
		//����� ������:
		const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Alfa" };
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������

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
		//�)
		//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
		//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
		//������� ����� �������������
		//���� ������ ���� ������ ���� ����������� �� ������
		//
		//������ 
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
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()
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

