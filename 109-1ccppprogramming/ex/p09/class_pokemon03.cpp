#include<iostream>
using namespace std;
class Pokemon{
	public:
		Pokemon(){
			Name="No Name";
			Lv=1;
			HpCur=0;
			HpMax=0;
			tools=new string[100];
		}
		Pokemon(string na,int lv,int hpc,int hpm){
			SetData(na,lv,hpc,hpm);
			tools=new string[100];
		}
		~Pokemon(){
			cout<<Name<<"已回歸大自然"<<endl;
			delete []tools;
		}
		void Show();
		void SetData(string na,int lv,int hpc,int hpm){
			if(hpc>hpm){
				cout<<"HpCur error"<<endl;
				return;
			}
			Name=na;
			Lv=lv;
			HpCur=hpc;
			HpMax=hpm;
		}
		void Attack(Pokemon &target){
			if(HpCur<=0){
				cout<<Name<<"無法攻擊"<<endl;
				return ;
			}
			if(target.HpCur<=0){
				cout<<"目標"<<"已失去戰鬥力，不可攻擊"<<endl;
				return ;
			}
			cout<<Name<<"攻擊"<<target.Name<<Lv<<"點"<<endl;
			target.Defence(Lv);
		}
		void Defence(int n){
			HpCur-=n;
			if(HpCur<=0){
				cout<<"失去戰鬥力"<<endl;
				HpCur=0;
			}
		}
		void Cure(){
			cout<<Name<<"恢復健康"<<endl;
			HpCur=HpMax; 
		}
	private:
		string Name;
		int Lv,HpCur,HpMax;
		string *tools;
};
void Pokemon::Show(){
	cout<<"Name: "<<Name<<endl;
	cout<<"LV: "<<Lv<<endl;
	cout<<"HP: "<<HpCur<<"/"<<HpMax<<endl;
}
int main(){
	Pokemon *p0=new Pokemon("傑尼龜",18,30,30);
	p0->Show();
	delete p0;
	Pokemon p1("皮卡丘",10,15,15),p2("小火龍",15,25,25);
	//p1.SetData("皮卡丘",10,15,15);
	//p2.SetData("小火龍",15,25,25);
	p1.Attack(p2);
	p2.Attack(p1);
	p1.Attack(p2);
	p2.Attack(p1);
	p1.Cure();
	p1.Show();
	p2.Show();
	return 0;
}
