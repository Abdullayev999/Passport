#include <iostream>

/*
Задание 1: Паспорт
+ Реализуйте класс Passport (имя, номер паспорта)
+ Реализуйте на основе класса Passport класс ForeignPassport
  (загран.паспорт)
+ В классе ForeignPassport добавьте список посещенных стран
+ Перегрузите операторы ввода/вывода для классов Passport и
  ForeignPassport
+ Создайте экземпляры классов Passport и ForeignPassport, заполните
  их данными и распечатайте

*/


 class ForeignPassport;
 
 class Passport
 {
 public:
     Passport() {}
 
     void setName(const std::string& name)
     {
         m_name = name;
     }
 
     void setNumber(const int number)
     {
         m_num = number;
     }
 
     std::string getName()const
     {
         return m_name;
     }
 
     int getNumber()const
     {
         return m_num;
     }
 
     Passport(const std::string& name, const int number)
     {
         m_name = name;
         m_num = number;
     }
 private:
     friend std::ostream& operator<<(std::ostream& os,const Passport& n)
     {
         os << "Name   = " << n.m_name << '\n'
     	   << "Number = " << n.m_num  << '\n';
         return os;
     }
 
     friend std::istream& operator>>(std::istream& is, Passport& n)
     {
         std::cout << "Enter name\t=\t";
         is >> n.m_name;
         std::cout << "Enter number\t=\t";
         is >> n.m_num ;
          return is;
     }
     friend std::ostream& operator<<(std::ostream& os, const ForeignPassport& n);
     friend std::istream& operator>>(std::istream& is, ForeignPassport& n);
     int m_num;
     std::string m_name;
 };
 
 class ForeignPassport : public Passport
 {
 public:
 	
     ForeignPassport(const std::string& name, const int number, const std::string& places):Passport(name, number)
     {
         travel(places);
     }
 
     void travel(const std::string& name)
     {
         if (m_index == m_size)capacityUp();
 
         m_places[m_index++] = name;
     }
 
     ~ForeignPassport()
     {
         delete[] m_places;
     }
 	
 private:
     friend std::ostream& operator<<(std::ostream& os, const ForeignPassport& n)
     {
         os << "Name   = " << n.m_name << '\n'
             << "Number = " << n.m_num << '\n';
 
         for (int i = 0; i < n.m_index; ++i)
         {
             os << '\n' << i + 1 << ")  Travel  \t:\t"
                 << n.m_places[i];
         }
         os << "\n\n==================================\n\n";
         return os;
     }
 
     friend std::istream& operator>>(std::istream& is, ForeignPassport& n)
     {
         is >> n.m_name;
         is >> n.m_num;
           
 
         for (int i = 0; i < n.m_index; ++i)
         {
             std::cout <<'\n'<<i+1<< ")  Travel  \t:\t";
             is >> n.m_places[i];
         }
         return is;
     }
     void capacityUp()
     {
         m_size += m_capacity;
 
         std::string* tmp = new std::string[m_size];
         for (int i = 0; i < m_index; ++i)
         {
             tmp[i] = m_places[i];
         }
         delete[] m_places;
         m_places = tmp;
     }
 
 	
     int m_size = 5;
     int m_capacity = 5;
     int m_index = 0;
     std::string* m_places=new std::string[m_size];
 };
 
 int main()
 {
     ForeignPassport a("Farid",123456,"Russia");
     std::cout << a;
     a.travel("Norway");
     a.travel("Germany");
     a.travel("Paris");
     a.travel("USA");
     std::cout << a;
 	
 }
