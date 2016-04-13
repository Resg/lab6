#pragma once
#include <iostream>
using namespace std;
class schet
{
protected:
	char *FIO;
	double summ;
	double stavka;
	int gzh;
	int gOs;
public:
	schet(): summ(0), stavka(0), gzh(0), gOs(0)
	{
		FIO=new char[1000];
	}
	schet(const char *a, double s, double st, int g, int g1) : summ(s), stavka(st), gzh(g), gOs(g1)
	{
		int len = strlen(a);
		FIO = new char[len + 1];
		strcpy(FIO, a);
		
	}
	void proz(int g)
	{
		for (int i=0; i<g; i++)
		{
			summ*=stavka;
		}
		gzh+=g;
		if (g<gOs)
			gOs-=g;
		else
			gOs=0;
	}
	void printt()
	{
		std::cout<< "FIO - "<<FIO<<endl;
		std::cout<< "sum="<<summ<<endl;
		std::cout<< "stavka="<<stavka<<endl;
		std::cout<< gzh<< endl;
		std::cout<< gOs<<endl;
	}

	virtual ~schet()
	{
		delete[] FIO;
	}
};

class pschet : public schet
{
private:
	double credit;
public:
	pschet() : schet()
	{

	}
	pschet(const char *a, double s, double st, int g, int g1, double c) : schet(a,s,st,g,g1), credit(c)
	{

	}
	~pschet()
	{

	}
	double proz(int g)
	{
		schet.proz(g);
		return (summ*=credit);
	}
	void printt()  
	{
		schet.printt();
		std::cout<<"credit="<<credit<<endl;
	}


};

