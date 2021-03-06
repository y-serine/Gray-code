#include "GrayCode.h"

#ifndef _GRAY_INT_IS_SIGNED
#define _GRAY_INT_IS_SIGNED
#endif

////////////////////////////////////////////////////////
#include<limits>
#define GetBit(a,b) (((a)>>(b))&1)
#define Bit(a) ((unsigned long long)1<<(a))
template<typename T>
int _GetBit_Mod2_slow_notused(T data){
	int ans = 0;
	const unsigned int _Size_T = std::numeric_limits<T>::digits;
	for (int i = 0; i < _Size_T; i++){
		ans ^= GetBit(data, i);
	}
	return ans;
}
template<typename T>
int _GetBit_Mod2(T data){
	unsigned int ans = data;
	const unsigned int _Size_T = std::numeric_limits<T>::digits;
	for (unsigned int shift = 1; shift < _Size_T; shift <<= shift){
		ans ^= (ans >> shift);
	}
	return ans & 1;
}

template<typename T>
int _GetBit_Max(T data){
	const unsigned int mx = ((std::numeric_limits<T>::digits - 1) / 2 * 2 + 1);
	if (data&(1 << mx))return mx;
	unsigned int tmp = (std::numeric_limits<T>::digits + 1) / 2;
	unsigned int ans = (std::numeric_limits<T>::digits + 1) / 2;
	unsigned int expi;
	while ((expi = (data >> ans)) != 1){
		if (expi > 0){ ans += (tmp >>= 1); }
		else{ ans -= (tmp >>= 1); }
	}
	return ans + 1;
}
int _GetBit_Max_uint(unsigned int data){
	if (!data)return 0;
	int ans = 0;
	if (!(data & 0x0000FFFF)){ ans += 16; data >>= 16; }
	if (!(data & 0x000000FF)){ ans += 8; data >>= 8; }
	if (!(data & 0x0000000F)){ ans += 4; data >>= 4; }
	if (!(data & 0x00000003)){ ans += 2; data >>= 2; }
	if (!(data & 0x00000001)){ ans += 1; data >>= 1; }
	return ans;
}


template<typename T>
const char* _ShowBit(T data){
	const unsigned int _Size_T = std::numeric_limits<T>::digits;
	static char _char_box[_Size_T + 1] = {};
	for (int i = 0; i < _Size_T; i++){
		_char_box[_Size_T - i - 1] = ((GetBit(data, i)) ? '1' : '0');
	}
	_char_box[_Size_T] = '\0';
	return (const char*)_char_box;
}
GRAY_INT _GetBit_g(const char* data){
	unsigned int ans = 0;
	int i = 0;
	while (data[i] != '\0'){
		switch (data[i]){
		case '1':ans <<= 1; ans |= 1; break;
		case '0':ans <<= 1; break;
		case '\0':goto end;
		default:return 0;
		}
		i++;
	}
end:
	GRAY_INT x;
	x.Set(ans);
	return x;
}
int _GetBit_i(const char* data){
	unsigned int ans = 0;
	int i = 0;
	while (data[i] != '\0'){
		switch (data[i]){
		case '1':ans <<= 1; ans |= 1; break;
		case '0':ans <<= 1;/*ans&=(~1);*/break;
		case '\0':goto end;
		default:return 0;
		}
		i++;
	}
end:
	return ans;
}

unsigned int INTtoGRAYINT(int inta){
	return (unsigned int)(inta^((unsigned int)inta >> 1));
}
unsigned int GRAYINTtoINT(unsigned int inta){
	unsigned int digit = 1;
	while (digit < std::numeric_limits<unsigned int>::digits){
		inta ^= (inta >> digit);
		digit *= 2;
	}
	return inta;

}
//without limits.h
unsigned int _GRAYINTtoINT(unsigned int inta){
	unsigned int digit = 1;
	unsigned int tmp;
	while (tmp = (inta >> digit)){
		inta ^= tmp;
		digit <<= 1;
	}
	return inta;

}

unsigned int _GRAYINTtoINT_fastest(unsigned int inta){
	inta ^= inta >> 1;
	inta ^= inta >> 2;
	inta ^= inta >> 4;
	inta ^= inta >> 8;
	inta ^= inta >> 16;
	return inta;

}


bool GRAY_INT::GetBitAt(int bit){
	return (value >> bit) & 1;
}
bool GRAY_INT::GetBitAt(const int bit)const{
	return (value >> bit) & 1;
}

int GRAY_INT::_GetBit(const char* data){
	unsigned int ans = 0;
	int i = 0;
	while (data[i] != '\0'){
		switch (data[i]){
		case '1':ans <<= 1; ans |= 1; break;
		case '0':ans <<= 1;/*ans&=(~1);*/break;
		case '\0':goto end;
		default:return 0;
		}
		i++;
	}
end:
	return ans;
}
GRAY_INT& GRAY_INT::Set(int a){
	value = a;
	return *this;
}
GRAY_INT& GRAY_INT::Int(int a){
	value = INTtoGRAYINT(a);
	return *this;
}
GRAY_INT& GRAY_INT::operator=(const unsigned int a){
	value = a;//INTtoGRAYINT(a);
	return *this;
}

GRAY_INT& GRAY_INT::operator=(double a){
	value = INTtoGRAYINT((int)a);
	return *this;
}

GRAY_INT& GRAY_INT::operator=(GRAY_INT& a){
	value = a.GetValueGray();
	return *this;
}


const GRAY_INT GRAY_INT::operator&(const unsigned int a)const{
	return GRAY_INT(value&a);
};
const GRAY_INT GRAY_INT::operator&(const GRAY_INT& a)const{
	return GRAY_INT(value&a.value);
};
GRAY_INT GRAY_INT::operator&=(const unsigned int a){
	value &= a;
	return *this;
};
GRAY_INT GRAY_INT::operator&=(const GRAY_INT& a){
	value &= a.value;
	return *this;
};
const GRAY_INT GRAY_INT::operator^(const unsigned int a)const{
	return GRAY_INT(value^a);
};
const GRAY_INT GRAY_INT::operator^(const GRAY_INT& a)const{
	return GRAY_INT(value^a.value);
};
GRAY_INT GRAY_INT::operator^=(const unsigned int a){
	value ^= a;
	return *this;
};
GRAY_INT GRAY_INT::operator^=(const GRAY_INT& a){
	value &= a.value;
	return *this;
};
const GRAY_INT GRAY_INT::operator|(const unsigned int a)const{
	return GRAY_INT(value | a);
};
const GRAY_INT GRAY_INT::operator|(const GRAY_INT& a)const{
	return GRAY_INT(value | a.value);
};
GRAY_INT GRAY_INT::operator|=(const unsigned int a){
	value |= a;
	return *this;
};
GRAY_INT GRAY_INT::operator|=(const GRAY_INT& a){
	value |= a.value;
	return *this;
};


const GRAY_INT GRAY_INT::operator<<(const unsigned int a)const{
	return GRAY_INT(value << a);
};
GRAY_INT GRAY_INT::operator<<=(const unsigned int a){
	value <<= a;
	return *this;
};
const GRAY_INT GRAY_INT::operator>>(const unsigned int a)const{
	return GRAY_INT((unsigned int)value >> a);
};
GRAY_INT GRAY_INT::operator>>=(const unsigned int a){
	(unsigned int)value >>= a;
	return *this;
};

int GRAY_INT::GetValueGray()const{
	return value;
}
int GRAY_INT::GetValueInt()const{
	return GRAYINTtoINT(value);
}

const char* GRAY_INT::ShowBit()const{
	return _ShowBit(value);
};


GRAY_INT::operator unsigned(){
	return value;
}
GRAY_INT::operator bool(){
	return (value != 0);
}

GRAY_INT& GRAY_INT::operator++(){
	if (_GetBit_Mod2(value)){
		value ^= (value&(unsigned int)(-((signed)value))) << 1;
	}
	else{
		value ^= 1;
	};
	return *this;
};
GRAY_INT GRAY_INT::operator++(int){
	GRAY_INT ans = *this;
	if (_GetBit_Mod2(value)){
		unsigned int tmp = 1;
		while (!(tmp&value)){
			tmp <<= 1;
		}
		value ^= (tmp << 1);
	}
	else{
		value ^= 1;
	};
	return ans;
};
GRAY_INT GRAY_INT::operator--(int){
	GRAY_INT ans = *this;
	if (_GetBit_Mod2(value)){
		value ^= 1;
	}
	else{
		if (value){
			unsigned int tmp = 1;
			while (!(tmp&value)){
				tmp <<= 1;
			}
			value ^= (tmp << 1);
		}
		else{
			value = INT_MIN;
		}
	};
	return ans;
};
GRAY_INT& GRAY_INT::operator--(){
	if (_GetBit_Mod2(value)){
		value ^= 1;
	}
	else{
		if (value){
			unsigned int tmp = 1;
			while (!(tmp&value)){
				tmp <<= 1;
			}
			value ^= (tmp << 1);
		}
		else{
			value = INT_MIN;
		}
	};
	return *this;
};
GRAY_INT GRAY_INT::operator-()const{
	return (++GRAY_INT((value ^ 0x80000000)));
}
GRAY_INT GRAY_INT::operator+()const{
	return GRAY_INT((value));
}
GRAY_INT GRAY_INT::operator~(){
	return GRAY_INT((~value));
}
bool GRAY_INT::operator!(){
	return !(value == 0);
}
bool GRAY_INT::operator==(const GRAY_INT& a)const{
	return (value == a.value);
}
bool GRAY_INT::operator==(int a){
	return (value == a);
}
bool GRAY_INT::operator!=(const GRAY_INT& a)const{
	return (value != a.value);
}
bool GRAY_INT::operator!=(int a){
	return (value != a);
}
bool GRAY_INT::operator||(const GRAY_INT& a)const{
	return (value || a.value);
}
bool GRAY_INT::operator||(bool a){
	return (value || a);
}
bool GRAY_INT::operator&&(const GRAY_INT& a)const{
	return (value && a.value);
}
bool GRAY_INT::operator&&(bool a){
	return (value && a);
}





#if _CALC_IN_GRAYCODE

const GRAY_INT GRAY_INT::operator+(const unsigned a)const{
#ifdef _GRAY_INT_IS_SIGNED
	bool vbit[2] = { a & (1 << (std::numeric_limits<unsigned int>::digits - 1)), value & (1 << (std::numeric_limits<unsigned int>::digits - 1)) };
#else
	bool vbit[2] = { 0, 0 };
#endif
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned ans = (a ^ value) & ((unsigned)(-1) >> 1);
#ifdef _GRAY_INT_IS_SIGNED
	for (register int bit = std::numeric_limits<unsigned int>::digits - 2; bit >= 0; bit--){
#else
	for (register int bit = std::numeric_limits<unsigned int>::digits -1; bit >= 0; bit--){
#endif
		if (a & unsigned(1 << bit)) {
			vbit[0] = !vbit[0];
			if (value & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans ^= 1 << (bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans ^= 1 << (prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (value & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans ^= 1 << (prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}



const GRAY_INT GRAY_INT::operator+(const GRAY_INT add)const{
#ifdef _GRAY_INT_IS_SIGNED
	bool vbit[2] = { add.value&(1 << (std::numeric_limits<unsigned int>::digits - 1)), value&(1 << (std::numeric_limits<unsigned int>::digits - 1)) };
#else
	bool vbit[2] = { 0, 0 };
#endif
	bool prevbit = 0;
	int prebit = (std::numeric_limits<unsigned int>::digits - 2);
	unsigned ans = (add.value ^ value)&((unsigned)(-1) >> 1);
#ifdef _GRAY_INT_IS_SIGNED
	for (register int bit = (std::numeric_limits<unsigned int>::digits - 2); bit >= 0; bit--){
#else
	for (register int bit = (std::numeric_limits<unsigned int>::digits - 1); bit >= 0; bit--){
#endif
		if (add.value & unsigned(1 << bit)) {
			vbit[0] = !vbit[0];
			if (value & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans ^= 1 << (bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans ^= 1 << (prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (value & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans ^= 1 << (prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}

const GRAY_INT GRAY_INT::operator-(const unsigned a)const{
	return (-(GRAY_INT)a) + *this;
}
const GRAY_INT GRAY_INT::operator-(const GRAY_INT a)const{
	return (-a) + *this;
}


GRAY_INT GRAY_INT::operator+=(const unsigned a){
	return (*this = *this + a);
}
GRAY_INT GRAY_INT::operator+=(const GRAY_INT a){
	return (*this = *this + a);
}
GRAY_INT GRAY_INT::operator-=(const unsigned a){
	return (*this = *this - a);
}
GRAY_INT GRAY_INT::operator-=(const GRAY_INT a){
	return (*this = *this - a);
}


const GRAY_INT GRAY_INT::operator*(const GRAY_INT a)const{
#ifdef _GRAY_INT_IS_SIGNED
	bool vbit[2] = { value&(1 << (std::numeric_limits<unsigned int>::digits - 1)), a.value&(1 << (std::numeric_limits<unsigned int>::digits - 1)) };
#else
	bool vbit[2] = { 0, 0 };
#endif
	unsigned times = ((a.value << 1) | _GetBit_Mod2(a.value));
	unsigned v = ((value << 1) | _GetBit_Mod2(value));
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	GRAY_INT ans = 0;
#ifdef _GRAY_INT_IS_SIGNED
	for (register int bit = std::numeric_limits<unsigned int>::digits - 2; bit >= 0; bit--){
#else
	for (register int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
#endif
		if (times & (1 << bit)) {
			if (vbit[0] = !vbit[0]){
				ans += v << (bit);
			}
			else{
				ans -= v << (bit);
			}
		}
	}
	return ans >> (unsigned)1;

}


#endif

int GRAY_INT::GetMaxBit(){
	if (!value)return 0;
	unsigned int data = value;
	int ans = 0;
	if (!(data & 0x0000FFFF)){ ans += 16; data >>= 16; }
	if (!(data & 0x000000FF)){ ans += 8; data >>= 8; }
	if (!(data & 0x0000000F)){ ans += 4; data >>= 4; }
	if (!(data & 0x00000003)){ ans += 2; data >>= 2; }
	if (!(data & 0x00000001)){ ans += 1; data >>= 1; }
	return ans;
}


GRAY_INT& GRAY_INT::SetBit(const char* a){ value = _GetBit(a); return *this; };
GRAY_INT SetBit(const char* a){ return _GetBit_g(a); };
GRAY_INT::GRAY_INT(void){};
GRAY_INT::GRAY_INT(int a){ value = a; };
GRAY_INT::GRAY_INT(int a, int){ *this = a; };
GRAY_INT::GRAY_INT(const GRAY_INT& a){ value = a.value; };



/////////////////////////////
GRAY_INT Addition1(const GRAY_INT a, const GRAY_INT b){
	return (GRAY_INT)(INTtoGRAYINT(a.GetValueInt() + b.GetValueInt()));
}
// 12 times slower than the int addition.
GRAY_INT Addition1s(const GRAY_INT a, const GRAY_INT b){
	unsigned int a1 = a.GetValueInt();
	unsigned int a2 = b.GetValueInt();
	while (a2){
		unsigned int a2tmp = (a1&a2) << 1;
		a1 ^= a2;
		a2 = a2tmp;
	}
	return (GRAY_INT)(INTtoGRAYINT(a1));
}
/*
// 8.5 times slower
GRAY_INT Addition2(const GRAY_INT a, const GRAY_INT b){
	unsigned int bi = b.GetValueInt();
	unsigned int shifted = std::numeric_limits<unsigned int>::digits;
	GRAY_INT target = a;
	do{
		shifted--;
		if ((bi >> shifted) & 1){
			GRAY_INT tmp = (target&unsigned(~(((-1) >> shifted) << shifted)));
			target >>= shifted;
			target++;
			target <<= shifted;
			target |= tmp;
			target ^= 1 << (shifted - 1);
		}
	} while (shifted > 0);

	return target;
}


//ten times slower
GRAY_INT Addition6(const GRAY_INT a, const GRAY_INT b){
	GRAY_INT val[2] = { a, b };
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 1 - 2;
	GRAY_INT ans = 0;

	for (int bit = std::numeric_limits<unsigned int>::digits - 2; bit >= 0; bit--){
		if (val[0].GetBitAt(bit)&&val[1].GetBitAt(bit)&&(vbit[0] != vbit[1])){
			vbit[0] = !vbit[0]; vbit[1] = !vbit[1];
		}
		else{
			if (val[0].GetBitAt(bit)) {
				ans.FlipBitAt(bit);
				if (prevbit == (vbit[0] = !vbit[0])){
					ans.FlipBitAt(prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
			if (val[1].GetBitAt(bit)) {
				ans.FlipBitAt(bit);
				if (prevbit == (vbit[1] = !vbit[1])){
					ans.FlipBitAt(prebit + 1);
				}
				prevbit = vbit[1];
				prebit = bit;
			}
		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans.FlipBitAt(prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans.FlipBitAt(0);
	}


	return ans;

}


// 8.5 times slower
GRAY_INT Addition7(const GRAY_INT a, const GRAY_INT b){

	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	GRAY_INT ans = a ^ b;

	for (int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){


		if (a.GetBitAt(bit)&&b.GetBitAt(bit)&&(vbit[0] != vbit[1])){
			vbit[0] = !vbit[0]; vbit[1] = !vbit[1];
		}
		else{
			if (a.GetBitAt(bit)) {
				if (prevbit == (vbit[0] = !vbit[0])){
					ans.FlipBitAt(prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
			if (b.GetBitAt(bit)) {
				if (prevbit == (vbit[1] = !vbit[1])){
					ans.FlipBitAt(prebit + 1);
				}
				prevbit = vbit[1];
				prebit = bit;
			}
		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans.FlipBitAt(prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans.FlipBitAt(0);
	}

	return ans;
}

//  6.5 times slower than addition1/1s, 100 times slower than the int addition.
GRAY_INT Addition8(const GRAY_INT a, const GRAY_INT b){
	GRAY_INT val[2] = { a, b };
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	GRAY_INT ans = a^b;

	for (int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
		if (val[0].GetBitAt(bit)) {
			vbit[0] = !vbit[0];
			if (val[1].GetBitAt(bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans.FlipBitAt(bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans.FlipBitAt(prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (val[1].GetBitAt(bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans.FlipBitAt(prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans.FlipBitAt(prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans.FlipBitAt(0);
	}

	return ans;
}
*/

//  as fast as addition1/1s, 10 times slower than the int addition.
GRAY_INT Addition8u(const GRAY_INT a, const GRAY_INT b){
	unsigned val[2] = { a.GetValueGray(), b.GetValueGray() };
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned ans = val[0] ^ val[1];

	for (register int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
		if (val[0] & (1 << bit)) {
			vbit[0] = !vbit[0];
			if (val[1] & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans ^= 1 << (bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans ^= 1 << (prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (val[1] & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans ^= 1 << (prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}

//this directly refers to the Gray coded value
//fastest, 7 times slower than int addition
unsigned Addition8ui(const unsigned a, const unsigned b){
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned ans = a ^ b;
	for (register int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
		if (a & (1 << bit)) {
			vbit[0] = !vbit[0];
			if (b & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans ^= 1 << (bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans ^= 1 << (prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (b & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans ^= 1 << (prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}



unsigned Addition8uis(const unsigned a, const unsigned b){
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned ans = a ^ b;
	for (register int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
		if (a & (1 << bit)) {
			vbit[0] = !vbit[0];
			if (b & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
#ifdef _GRAY_INT_IS_SIGNED
					ans ^= 1 << ((std::numeric_limits<unsigned int>::digits - 1 == bit) ? (std::numeric_limits<unsigned int>::digits - 1) : (bit + 1));
#else
					ans ^= 1 << (bit + 1);
#endif
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
#ifdef _GRAY_INT_IS_SIGNED
					ans ^= 1 << ((std::numeric_limits<unsigned int>::digits - 1 == prebit) ? (std::numeric_limits<unsigned int>::digits - 1) : (prebit + 1));
#else
					ans ^= 1 << (prebit + 1);
#endif
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (b & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
#ifdef _GRAY_INT_IS_SIGNED
				ans ^= 1 << ((std::numeric_limits<unsigned int>::digits - 1 == prebit) ? (std::numeric_limits<unsigned int>::digits - 1) : (prebit + 1));
#else
				ans ^= 1 << (prebit + 1);
#endif
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	else if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}

unsigned Addition8uic(const unsigned a, const unsigned b){
#ifdef _GRAY_INT_IS_SIGNED
	bool vbit[2] = { a&(1 << (std::numeric_limits<unsigned int>::digits - 1)), b&(1 << (std::numeric_limits<unsigned int>::digits - 1)) };
#else
	bool vbit[2] = { 0, 0 };
#endif
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned ans = (a ^ b)&((unsigned)(-1) >> 1);
#ifdef _GRAY_INT_IS_SIGNED
	for (register int bit = (std::numeric_limits<unsigned int>::digits - 2); bit >= 0; bit--){
#else
	for (register int bit = (std::numeric_limits<unsigned int>::digits - 1); bit >= 0; bit--){
#endif
		if (a & (1 << bit)) {
			vbit[0] = !vbit[0];
			if (b & (1 << bit)) {
				vbit[1] = !vbit[1];
				if (vbit[0] == vbit[1]) {
					ans ^= 1 << (bit + 1);
					prevbit = vbit[0];
					prebit = bit;
				}
			}
			else {
				if (prevbit == vbit[0]){
					ans ^= 1 << (prebit + 1);
				}
				prevbit = vbit[0];
				prebit = bit;
			}
		}
		else if (b & (1 << bit)) {
			vbit[1] = !vbit[1];
			if (prevbit == vbit[1]){
				ans ^= 1 << (prebit + 1);
			}
			prevbit = vbit[1];
			prebit = bit;

		}
	}


	if ((vbit[0] || vbit[1])& !prevbit){
		ans ^= 1 << (prebit + 1);
	}
	if (vbit[0] && vbit[1]){
		ans ^= 1;
	}

	return ans;
}


GRAY_INT Multiplication1(const GRAY_INT a, const GRAY_INT b){
	return (GRAY_INT)(INTtoGRAYINT(a.GetValueInt() * b.GetValueInt()));
}
unsigned Multiplication8f(const unsigned a, const unsigned b){
#ifdef _GRAY_INT_IS_SIGNED
	bool vbit[2] = { a&(1 << (std::numeric_limits<unsigned int>::digits - 1)), b&(1 << (std::numeric_limits<unsigned int>::digits - 1)) };
#else
	bool vbit[2] = { 0, 0 };
#endif
	bool prevbit = 0;
	int prebit = std::numeric_limits<unsigned int>::digits - 2;
	unsigned long ans = 0;
#ifdef _GRAY_INT_IS_SIGNED
	for (register int bit = std::numeric_limits<unsigned int>::digits - 2; bit >= 0; bit--){
#else
	for (register int bit = std::numeric_limits<unsigned int>::digits - 1; bit >= 0; bit--){
#endif
		if (a & (1 << bit)) {
			if (vbit[0] = !vbit[0]){
				ans += b << bit;
			}
			else{
				ans -= b << bit;
			}
		}
	}
	return ans;

}


GRAY_INT GRAY_INT::twice()const{
	return ((value << 1) & _GetBit_Mod2(value));
}


GRAY_INT& GRAY_INT::SetBitAt(int bit){
	value |= (1 << bit);
	return *this;
}
GRAY_INT& GRAY_INT::FlipBitAt(int bit){
	value ^= (1 << bit);
	return *this;
}
GRAY_INT& GRAY_INT::ResetBitAt(int bit){
	value &= !(1 << bit);
	return *this;
}
