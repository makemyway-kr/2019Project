#include <iostream>
#include "users.h"
#include "kakaopay.h"
#include "chats.h"
#include "kon.h"
#include "gift.h"
#include "calender.h"
#include "calender_dayinfo.h"
#include <string>
#include "MusicChart.h"
#include "friends.h"



int n = 1;
const int name_len = 20;
users* user[50];
KakaoPay* pay[50]; //포인터배열
Kon* KonAccoutNum[50];
calendar* CalNum[50];
int number;
Gift g;



//첫 메뉴
int menu()
{
	int j;
	cout << "카카오톡" << endl << "1.회원가입" << "2.로그인" << endl;
	cin >> j;
	return j;
}


//로그인 후 메인메뉴
int kakaomenu()
{
	int p;
	cout << "=====MENU=====" << endl << "0.종료" << endl << "1.프로필 설정" << endl << "2.친구목록" << endl << "3.채팅" << endl << "4.카카오페이" << endl << "5.콘" << endl << "6.선물하기" << endl << "7.캘린더" <<endl<< "8.뮤직차트" << endl;
	cin >> p;
	return p;
}



//카카오톡 회원가입 users
void Makeacc()//users
{
	char nam[name_len];
	int num;
	int mon;
	cout << "======회원가입======" << endl;
	cout << "성함을 입력해주십시오: ";
	cin >> nam;

	cout << "카카오페이 통장이 카카오톡 회원가입으로 인해 자동으로 개설되었습니다." << endl << "카카오페이 입금액을 입력해주십시오: ";
	cin >> mon;

	user[n] = new users; //동적 객체생성
	pay[n] = new KakaoPay; //동적 객체생성


	user[n]->NameDef(n, nam, user[n]);


	pay[n]->paymoney = mon;
	user[n]->paymoney = mon;

	pay[n]->name = new char[strlen(nam) + 1];
	strcpy_s(pay[n]->name, strlen(nam) + 1, nam);


	cout << "당신의 로그인 번호는 " << n << "번 입니다." << endl;
	n++;
}


//로그인화면
void login()
{
	cout << "회원가입시 할당받은 로그인 번호를 입력하세요" << endl;
	cin >> number;
}










//==================================== 프로필 ======================================//
//Show 프로필
void ShowData(const Profile& m)//call by Reference
{
	cout << "—나만의 프로필 생성—" << endl;
	cout << "이름 입력: " << m.name << endl;
	cout << "전화번호 입력: " << m.phone << endl;
	if (m.choosemusic == true)
		cout << "노래 제목: " << m.music << endl;
	cout << "이메일: " << m.email << endl;
}

//프로필 설정
Profile me;
void makeprofile()
{
	me.name = user[number]->name;
	cout << "이름 입력: ";
	cin >> me.name;

	cout << "전화번호 입력: ";
	cin >> me.phone;

	cout << "상태 메세지 입력: ";
	cin >> me.stmessage;
	getline(cin, me.stmessage);


	cout << "노래선택(OK:1/No:0):  ";
	int music;
	cin >> music;
	if (me.musicOX(music) == true)
	{
		me.choosemusic = true;
		cout << "노래 제목: ";
		cin >> me.music;
		getline(cin, me.music);
		cout << "이메일 입력: ";
		cin >> me.email; cout << endl;
	}
	else
	{
		me.choosemusic = false;
		cout << "이메일 입력: ";
		cin >> me.email; cout << endl;
	}
	ShowData(me);

	system("pause");
	me.k++;
}
//========================================-----=======================================//









void friendschart()
{

	friends f1("심원준", "드럼", "십이월이십오일의고백");
	friends f2("신형진", "난 갑이야 막이래", "을-기리보이");
	friends f3("한수찬", "수채화", "^^");
	cout << f1.name << endl << f1.message << endl << f1.music << endl;
	cout << f2.name << endl << f2.message << endl << f2.music << endl;
	cout << f3.name << endl << f3.message << endl << f3.music << endl;
}




//=================================== 카카오페이 ====================================//
//페이머니 메뉴
int paymenu()
{
	int k;
	cout << "===기능 안내===" << endl << "1.입금" << endl << "2.출금/결제" << endl << "3.잔액조회" << endl;
	cout << "원하시는 기능의 번호를 입력하세요";
	cin >> k;
	return k;
}


void insert()
{
	int money;
	cout << "충전할 페이머니 액수를 입력하십시오" << endl;
	cin >> money;
	pay[number]->AddMoney(money);
	user[number]->paymoney = pay[number]->paymoney;
	cout << "충전이 완료되었습니다." << endl << "===잔액: " << pay[number]->paymoney << "===" << endl;

}
void withdrawal()
{
	int money;
	cout << "결제할 액수를 입력하십시오" << endl;
	cin >> money;
	pay[number]->MinMoney(money);
	user[number]->paymoney = pay[number]->paymoney;
	cout << "결제가 완료되었습니다." << endl << "===잔액: " << pay[number]->paymoney << "===" << endl;
}
void Moneyleft()
{
	cout << "잔액: " << user[number]->GetMoney() << endl;
}



//카카오페이 기능 구성
int KAKAOPAYY()
{
	while (1)
	{
		cout << "카카오 페이입니다. 계속하시려면 1, 종료하시려면 0을 누르세요";
		int i;
		cin >> i;
		if (i == 0)
		{
			break;
		}
		else if (i == 1)
		{
			int k = paymenu();
			if (k == 1)
			{
				insert();
			}
			else if (k == 2)
			{
				withdrawal();
			}
			else if (k == 3)
			{
				Moneyleft();
			}
		}
		else
			cout << "식별되지않는 번호입니다." << endl;
	}
	return 0;
}
//==================================================================================//








//======================================  콘  ======================================//
enum { MAKE = 1, INQUIRE, EXIT };
int KonPrintMenu()
{
	int p;
	cout << "---ㅡMENU-------" << endl;
	cout << "1.통장 개설" << endl;
	cout << "2.통장 조회" << endl;
	cout << "3.프로그램 종료" << endl;
	cin >> p;
	return p;
}


void MakeKonAcc()
{
	if (user[number]->index == 0)
	{
		int a;
		char arr[20];
		cout << "콘 통장을 개설하시겠습니까? " << endl;
		cout << "1. 예 " << endl << "2. 아니요" << endl;
		cout << "선택 : ";
		cin >> a;
		if (a == 1)
		{
			cout << "비밀번호를 설정해주세요 : "; cin >> arr;
			cout << "사용자님의 콘통장이 개설되었습니다. 감사합니다. " << endl;

			KonAccoutNum[number] = new Kon(arr);
			user[number]->index++;
		}
		else if (a != 2)
			cout << "식별되지않는 번호입니다." << endl;
	}
	else
		cout << "이미 사용자님의 콘통장이 있습니다." << endl;
}


void KON()
{
	while (1)
	{
		int N = KonPrintMenu();
		if (N == 1)
		{
			MakeKonAcc();
			continue;
		}
		else if (N == 2)
		{
			if (user[number]->index == 0)
			{
				cout << "아직 콘 통장이 개설되지 않았습니다..." << endl;
				continue;
			}
			else
			{
				cout << "남은 콘 개수 : " << KonAccoutNum[number]->GetKonNum() << "개 있습니다." << endl;
				continue;
			}
		}
		else if (N == 3)
		{
			break;
		}
		else
		{
			cout << "식별되지않는 번호입니다." << endl;
			continue;
		}
	}
}
//=============================================================================//







//============================== 음악차트 표출 =============================//
void m(void)
{
	MusicChart* song[11];

	song[1] = new MusicChart("Blueming", "아이유");
	song[2] = new MusicChart("헤어진 우리가 지켜야 할 것들", "김나영, 양다일");
	song[3] = new MusicChart("Into the Unknown", "Idina Menzel,Aurora");
	song[4] = new MusicChart("Love poem", "아이유");
	song[5] = new MusicChart("HIP", "마마무");
	song[6] = new MusicChart("Obsession", "EXO");
	song[7] = new MusicChart("시발점", "BIG Naughty(서동현)");
	song[8] = new MusicChart("을", "기리보이");
	song[9] = new MusicChart("타투", "적재");
	song[10] = new MusicChart("Good Together", "HONNE");


	cout << "----Top10을 보여주세요---- " << endl;

	for (int i = 1; i < 11; i++)
	{
		cout << "top" << i << ' ' << song[i]->title << " - " << song[i]->singer << endl;
	}

	for (int j = 1; j < 11; j++)
	{
		delete song[j];
	}

}
//================================================================================//







//================================== 캘린더 ===================================//
void StartCal(void)
{
	while (1)
	{
		cout << "1.캘린더 실행" << endl;
		cout << "2.캘린더 종료" << endl;
		int choiceOX;
		cout << "선택:"; cin >> choiceOX;
		if (choiceOX == 1)
		{
			//윤년계산하고 배열생성
			int year; // 사용자 입력 변수
			int month; // 사용자 입력 변수
			cout << "1.출력할 년입력 ex)2019 : ";
			cin >> year;
			cout << "2.출력할 달입력 ex)12 : ";
			cin >> month;
			CalNum[number] = new calendar(year, month);

			while (1)
			{
				int a;
				cout << "몇 일의 일정을 확인하겠습니까?(뒤로:0입력) : "; cin >> a;
				if (a == 0)
					break;
				else if (a > CalNum[number]->basicyear[month - 1])
				{
					cout << month << "월은 " << CalNum[number]->basicyear[month - 1] << "일까지 있습니다." << endl;
					continue;
				}
				else
				{
					CalNum[number]->DayArr[a - 1]->ShowDayinfo();
					int AddOX;
					cout << "일정을 추가하시겠습니까? (Y:1,N:2) : "; cin >> AddOX;
					if (AddOX == 1)
					{
						CalNum[number]->DayArr[a - 1]->AddScedule();
					}
					else if (AddOX == 2)
					{
						cout << "일정 추가를 하지 않으셨습니다." << endl;
						continue;
					}
					else
					{
						cout << "식별되지 않는 번호입니다." << endl;
						continue;
					}
				}
			}
		}
		else
		{
			cout << "캘린더를 종료하였습니다." << endl;
			break;
		}
	}
}
//=============================================================================//








//=============================== 메인 구동 함수 ==============================//
int main()
{
	while (1)
	{
		int k;
		int o;
		k = menu();
		if (k == 1)
		{
			Makeacc();
			continue;
		}
		else if (k == 0)
		{

			for (int w = 0; w < 100; w++)
			{
				delete[]user[w];
				delete[]pay[w];
			}
			break;
		}
		else if (k == 2)
		{
			login();
			if (n == 1)
			{
				cout << "===가입된 사용자가 없습니다===." << endl;
				continue;
			}
			else if (n <= number)
			{
				cout << "==가입된 사용자가 아닙니다===" << endl;
				continue;
			}
			while (1)
			{
				o = kakaomenu();
				if (o == 0)
				{
					return 0;
				}
				if (o == 1)
				{
					makeprofile();
				}
				else if (o == 2)
				{
					if (me.k == 0)
					{
						cout << "*******프로필 설정을 하시기 전에는 친구 목록을 보실 수 없습니다**********" << endl;
						continue;
					}
					else
					{
						cout << "=======전화번호 연동이 자동으로 완료되었습니다=====." << endl;
						cout << "==" << me.name << endl << me.music << endl << me.stmessage << endl;
						friendschart();
						continue;
					}
				}
				else if (o == 3)
				{
					cout << "채팅" << endl;
					chats chat1;
					chat1.chatting();
					continue;
				}
				else if (o == 4)
				{
					KAKAOPAYY();
				}
				else if (o == 5)
				{
					KON();
					continue;
				}
				else if (o == 6)
				{
					g.ShowMenu();
				}
				else if (o == 7)
				{
					StartCal();
					continue;
				}
				else if (o == 8)
				{
					m();
					continue;
				}
				else
				{
					cout << "식별되지 않는 번호입니다." << endl;
					continue;
				}
			}
		}
	}
}
//============================================================================================================================//