////  References  ////////////////////////////////////////////////////////
//                                                                      //
//   http://www.i.h.kyoto-u.ac.jp/~tsuiki/bit/gray.html                 //
//   http://www.i.h.kyoto-u.ac.jp/~tsuiki/sojinbot.pdf                  //
//                                                                      //
//////////////////////////////////////////////////////////////////////////



#pragma once
#define _CALC_IN_GRAYCODE 1

class GRAY_INT{

public:
	GRAY_INT& Set(int a);
	GRAY_INT& Int(int a);
	template<typename T>
	GRAY_INT& operator=(T a){ return(*this = (double)a); };
	GRAY_INT& operator=(int a);
	GRAY_INT& operator=(double a);
	GRAY_INT& operator=(GRAY_INT& a);
	const GRAY_INT operator&(int a)const;
	const GRAY_INT operator&(const GRAY_INT& a)const;
	GRAY_INT operator&=(int a);
	GRAY_INT operator&=(const GRAY_INT& a);
	const GRAY_INT operator^(int a)const;
	const GRAY_INT operator^(const GRAY_INT& a)const;
	GRAY_INT operator^=(int a);
	GRAY_INT operator^=(const GRAY_INT& a);
	const GRAY_INT operator|(int a)const;
	const GRAY_INT operator|(const GRAY_INT& a)const;
	GRAY_INT operator|=(int a);
	GRAY_INT operator|=(const GRAY_INT& a);
	const GRAY_INT operator<<(int a)const;
	GRAY_INT operator<<=(int a);
	const GRAY_INT operator>>(int a)const;
	GRAY_INT operator>>=(int a);
	GRAY_INT& operator++();
	GRAY_INT operator++(int);
	GRAY_INT& operator--();
	GRAY_INT operator--(int);
	GRAY_INT operator-()const;
	GRAY_INT operator+()const;
	GRAY_INT operator~();
	bool operator!();
	bool operator==(const GRAY_INT& a)const;
	bool operator==(int a);
	bool operator!=(const GRAY_INT& a)const;
	bool operator!=(int a);
	bool operator||(const GRAY_INT& a)const;
	bool operator||(bool a);
	bool operator&&(const GRAY_INT& a)const;
	bool operator&&(bool a);
#if _CALC_IN_GRAYCODE
	GRAY_INT operator+(int a);
	GRAY_INT operator+(GRAY_INT a);
	GRAY_INT operator-(int a);
	GRAY_INT operator-(GRAY_INT a);
#endif
	template<typename T>
	operator T(){ return static_cast<T>((int)*this); };
	operator int();
	operator bool();
	operator GRAY_INT();
	int GetValueGray()const;
	int GetValueInt()const;
	const char* ShowBit()const;
	GRAY_INT(void);
	GRAY_INT(int a);
	GRAY_INT(int a, int);
	GRAY_INT(const GRAY_INT& a);
	GRAY_INT& SetBit(const char* data);
	GRAY_INT& twice();
	bool GetBitAt(int bit);
	bool GetBitAt(const int bit)const;
	GRAY_INT& SetBitAt(int bit);
	GRAY_INT& FlipBitAt(int bit);
	GRAY_INT& ResetBitAt(int bit);
private:
	unsigned int value;
	int _GetBit(const char* data);
	int GetMaxBit();
protected:
};
GRAY_INT SetBit(const char* data);



