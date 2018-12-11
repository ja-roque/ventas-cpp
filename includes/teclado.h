/****************************************/
/* Libreria para manejo del teclado >:v */
/****************************************/

#if !defined(_TECLADO_H)
     #define _TECLADO_H

#if !defined(_CONIO_H)
     #include <conio.h>
#endif

//teclas de flechas
#define FARR 1072
#define FABA 1080
#define FDER 1077
#define FIZQ 1075

//teclas de función
#define F1 1059
#define F2 1060
#define F3 1061
#define F4 1062
#define F5 1063
#define F6 1064
#define F7 1065
#define F8 1066
#define F9 1067
#define F10 1068
#define F11 1133
#define F12 1134

//teclas combinadas de ctrl y función
#define CTF1 1094
#define CTF2 1095
#define CTF3 1096
#define CTF4 1097
#define CTF5 1098
#define CTF6 1099
#define CTF7 1100
#define CTF8 1101
#define CTF9 1102
#define CTF10 1103
#define CTF11 1137
#define CTF12 1138

//teclas de letras minusculas
#define AMINUS 97
#define BMINUS 98
#define CMINUS 99
#define DMINUS 100
#define EMINUS 101
#define FMINUS 102
#define GMINUS 103
#define HMINUS 104
#define IMINUS 105
#define JMINUS 106
#define KMINUS 107
#define LMINUS 108
#define MMINUS 109
#define NMINUS 110
#define OMINUS 111
#define PMINUS 112
#define QMINUS 113
#define RMINUS 114
#define SMINUS 115
#define TMINUS 116
#define UMINUS 117
#define VMINUS 118
#define WMINUS 119
#define XMINUS 120
#define YMINUS 121
#define ZMINUS 122

//teclas de letras mayusculas
#define AMAYUS 65
#define BMAYUS 66
#define CMAYUS 67
#define DMAYUS 68
#define EMAYUS 69
#define FMAYUS 70
#define GMAYUS 71
#define HMAYUS 72
#define IMAYUS 73
#define JMAYUS 74
#define KMAYUS 75
#define LMAYUS 76
#define MMAYUS 77
#define NMAYUS 78
#define OMAYUS 79
#define PMAYUS 80
#define QMAYUS 81
#define RMAYUS 82
#define SMAYUS 83
#define TMAYUS 84
#define UMAYUS 85
#define VMAYUS 86
#define WMAYUS 87
#define XMAYUS 88
#define YMAYUS 89
#define ZMAYUS 90

//teclas de numeros
#define NUM0 48
#define NUM1 49
#define NUM2 50
#define NUM3 51
#define NUM4 52
#define NUM5 53
#define NUM6 54
#define NUM7 55
#define NUM8 56
#define NUM9 57

//otras teclas
#define ENTER 13
#define BARRA 32
#define ESC 27
#define TAB 9
#define BACK 8
#define CTRL 17
#define SHIFT 16
#define DEL 46
#define SUPR 1083

int fxtecla() {
	int t;

	t = getch();

	if(t == 0)
		t = 1000 + getch();

	return t;
}

#endif //teclado
