#pragma once
//template<typename T>
//const T& GetTop(std::stack<T>& s) {			//++++++++++++++////////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
//	return s.top();
//}
template<typename T>
const T& GetTop(std::queue<T>& s) {
	return s.front();
}
//template<typename T>
//const T& GetTop(std::priority_queue<T>& s) {
//	return (s.top());
//}
template<typename T>
const typename T::value_type& GetTop(T& s)
{
	return s.top();
}
template<typename T>
void PrintS(T s) {
	while (!s.empty()) {
		std::cout << GetTop(s) << std::endl;
		s.pop();
	}

}
template<typename C>
void PrintLeg(const C& cont) {
std::cout << typeid(cont).name() << std::endl << "Size: " << cont.size() << "   Maximal size: " << cont.max_size() << std::endl;
	auto itBeg = cont.begin();
	int size = cont.size();
	for (int i = 0; i < size; i++) {
		std::cout << *itBeg << std::endl;
		++itBeg;
	}
}
template<typename T1, typename  T2>
std::ostream& operator<<(std::ostream& os, const std::pair<const T1, T2>& s) {
	return os << s.first << "  " << s.second;
}
template<typename T1, typename  T2 >
std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& s) {
	auto itBeg = s.begin();
	int size = s.size();
	for (int i = 0; i < size; i++) {
		os << *itBeg << std::endl;
		++itBeg;
	}
	return os;
}
template<typename T1, typename  T2 >
std::ostream& operator<<(std::ostream& os, const std::map<const T2, std::pair<const T2, T1>>& s) {
	return os << s.first << "  " << s.second;
}
template<typename T1, typename  T2 >
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& s) {
	return os << s.first << "  " << s.second;
}
//template<typename C>
//std::ostream& operator<<(std::ostream& os, const C& cont) {
//	std::cout << typeid(cont).name() << std::endl << "Size: " << cont.size() << "   Maximal size: " << cont.max_size() << std::endl;
//	auto itBeg = cont.begin();
//	int size = cont.size();
//	for (int i = 0; i < size; i++) {
//		os << *itBeg << std::endl;
//		++itBeg;
//	}
//	return os;
//}
class CompareClass {
public:
	bool operator() (const char* a, const char* b) {
		if (strcmp(a,b) > 0)
			return true;
		return false;
	}
};