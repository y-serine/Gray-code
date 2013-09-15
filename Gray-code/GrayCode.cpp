#include "GrayCode.h"


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
GRAY_INT& GRAY_INT::operator=(int a){
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


const GRAY_INT GRAY_INT::operator&(int a)const{
	return GRAY_INT(value&a);
};
const GRAY_INT GRAY_INT::operator&(const GRAY_INT& a)const{
	return GRAY_INT(value&(a.GetValueGray()));
};
GRAY_INT GRAY_INT::operator&=(int a){
	value &= a;
	return *this;
};
GRAY_INT GRAY_INT::operator&=(const GRAY_INT& a){
	value &= a.GetValueGray();
	return *this;
};
const GRAY_INT GRAY_INT::operator^(int a)const{
	return GRAY_INT(value^a);
};
const GRAY_INT GRAY_INT::operator^(const GRAY_INT& a)const{
	return GRAY_INT(value^(a.GetValueGray()));
};
GRAY_INT GRAY_INT::operator^=(int a){
	value ^= a;
	return *this;
};
GRAY_INT GRAY_INT::operator^=(const GRAY_INT& a){
	value &= a.GetValueGray();
	return *this;
};
const GRAY_INT GRAY_INT::operator|(int a)const{
	return GRAY_INT(value | a);
};
const GRAY_INT GRAY_INT::operator|(const GRAY_INT& a)const{
	return GRAY_INT(value | (a.GetValueGray()));
};
GRAY_INT GRAY_INT::operator|=(int a){
	value |= a;
	return *this;
};
GRAY_INT GRAY_INT::operator|=(const GRAY_INT& a){
	value |= a.GetValueGray();
	return *this;
};


const GRAY_INT GRAY_INT::operator<<(int a)const{
	return GRAY_INT(value << a);
};
GRAY_INT GRAY_INT::operator<<=(int a){
	value <<= a;
	return *this;
};
const GRAY_INT GRAY_INT::operator>>(int a)const{
	return GRAY_INT((unsigned int)value >> a);
};
GRAY_INT GRAY_INT::operator>>=(int a){
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


GRAY_INT::operator int(){
	return value;//GRAYINTtoINT(value);
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
	GRAY_INT ans = GRAY_INT(value, 0);
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
	GRAY_INT ans = GRAY_INT(value, 0);
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
GRAY_INT GRAY_INT::operator-(){
	return (++GRAY_INT((value ^ 0x80000000)));
}
GRAY_INT GRAY_INT::operator+(){
	return GRAY_INT((value));
}
GRAY_INT GRAY_INT::operator~(){
	return GRAY_INT((~value));
}
bool GRAY_INT::operator!(){
	return !(value == 0);
}
bool GRAY_INT::operator==(const GRAY_INT& a)const{
	return (value == a.GetValueGray());
}
bool GRAY_INT::operator==(int a){
	return (value == a);
}
bool GRAY_INT::operator!=(const GRAY_INT& a)const{
	return (value != a.GetValueGray());
}
bool GRAY_INT::operator!=(int a){
	return (value != a);
}
bool GRAY_INT::operator||(const GRAY_INT& a)const{
	return (value || a.GetValueGray());
}
bool GRAY_INT::operator||(bool a){
	return (value || a);
}
bool GRAY_INT::operator&&(const GRAY_INT& a)const{
	return (value && a.GetValueGray());
}
bool GRAY_INT::operator&&(bool a){
	return (value && a);
}





#if _CALC_IN_GRAYCODE
GRAY_INT GRAY_INT::operator+(int a){
	return (GRAY_INT)(INTtoGRAYINT(GRAYINTtoINT(value) + a));
}
GRAY_INT GRAY_INT::operator+(GRAY_INT a){
	return (GRAY_INT)(INTtoGRAYINT(GRAYINTtoINT(value) + a.GetValueInt()));
}
GRAY_INT GRAY_INT::operator-(int a){
	return (GRAY_INT)(INTtoGRAYINT(GRAYINTtoINT(value) - a));
}
GRAY_INT GRAY_INT::operator-(GRAY_INT a){
	return (GRAY_INT)(INTtoGRAYINT(GRAYINTtoINT(value) - a.GetValueInt()));
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
//GRAY_INT::GRAY_INT(GRAY_INT& a){value=a.GetValueGray();};
GRAY_INT::GRAY_INT(const GRAY_INT& a){ value = a.GetValueGray(); };



/////////////////////////////
GRAY_INT Addition1(const GRAY_INT a, const GRAY_INT b){
	return (GRAY_INT)(INTtoGRAYINT(a.GetValueInt() + b.GetValueInt()));
}
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

GRAY_INT Addition2(const GRAY_INT a, const GRAY_INT b){
	unsigned int bi = b.GetValueInt();
	unsigned int shifted = std::numeric_limits<unsigned int>::digits;
	GRAY_INT target = a;
	do{
		shifted--;
		if ((bi >> shifted) & 1){
			GRAY_INT tmp = (target&(~(((-1) >> shifted) << shifted)));
			target >>= shifted;
			target++;
			target <<= shifted;
			target |= tmp;
			target ^= 1 << (shifted - 1);
		}
	} while (shifted > 0);

	return target;
}

//never-ending
GRAY_INT Addition4(const GRAY_INT a, const GRAY_INT b){

	GRAY_INT tmpa = a;
	GRAY_INT tmpb = b;
	GRAY_INT prea = a;
	GRAY_INT preb = b;
	if (a == b)return tmpa.twice();
	while (tmpa != 0 || tmpb != 0){
		prea = tmpa;
		preb = tmpb;
		tmpa = prea^preb^((prea | preb) >> 1);
		tmpb = (prea&preb)^((prea&preb) << 1);
	}
	return (tmpa != 0) ? tmpa : tmpb;
}

GRAY_INT Addition5(const GRAY_INT a, const GRAY_INT b){

	GRAY_INT tmpa = a;
	GRAY_INT tmpb = b;
	if (a == b)return tmpa.twice();
	return (tmpa != 0) ? tmpa : tmpb;
}


GRAY_INT Addition6(const GRAY_INT a, const GRAY_INT b){
	GRAY_INT val[2] = { a, b };
	bool vbit[2] = { 0, 0 };
	bool prevbit = 0;
	int prebit;// std::numeric_limits<int>::digits;
	GRAY_INT ans = 0;

	for (int bit = std::numeric_limits<int>::digits-1; bit >= 0; bit--){
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
	else if(vbit[0] && vbit[1]){
		ans.FlipBitAt(0);
	}
	

	return ans;

}

GRAY_INT& GRAY_INT::twice(){
	value <<= 1;
	value &= _GetBit_Mod2(value);
	return *this;

}


GRAY_INT& GRAY_INT::SetBitAt(int bit){
	if (bit > 0)value |= (1 << bit);
	return *this;
}
GRAY_INT& GRAY_INT::FlipBitAt(int bit){
	if (bit > 0)value ^= (1 << bit);
	return *this;
}
GRAY_INT& GRAY_INT::ResetBitAt(int bit){
	if (bit > 0)value &= !(1 << bit);
	return *this;
}