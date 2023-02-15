#pragma once
using namespace std;
#include <iostream>
#include <string>

#ifndef __PERSON_H__  //if not define : __PERSON_H__가 정의되어있지 않다면 
#define __PERSON_H__ //_PERSON_H_를 정의한다 #endif가 나오기 전까지의 내용을 
class Person {
protected:
	string name;
	static int count;  //int형 변수를 static형으로 선언한 것  (객체와 독립적이다 )
	//static 은 일반클래스 개념이다 
public:
	static int get_count();
	static void static_method();
	Person();
	virtual ~Person();
	virtual void info();
	virtual void test();
	void set_name(string name);
	string get_name();
	
};
#endif;