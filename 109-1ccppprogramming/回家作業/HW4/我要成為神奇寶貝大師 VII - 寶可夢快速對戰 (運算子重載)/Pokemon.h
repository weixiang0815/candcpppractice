#ifndef POKEMON_H
#define POKEMON_H 
#include<bits/stdc++.h>
using namespace std;
class Pokemon
{
public:
    Pokemon();
    Pokemon(string na, int lv, int hp);
    void ShowInfo();
    void Attack(Pokemon &Target);// 攻擊，請重載此方法
    void operator>>(Pokemon &Target);
    void Defence( int atkp );// 防御(被攻擊？)
    void Cure();// 治癒
	friend class PokemonHealthCenter;
private:
    void setData(string name, int lv, int hp);
    string Name;
    int Lv;
    int HpMax;
    int HpCur;       
};
typedef class PokemonHealthCenter
{
public:
    PokemonHealthCenter(string na);
    //設定神奇寶貝中心的名字
    void Cure(Pokemon &p);
    void operator<<(Pokemon &p);
    //將傳入的神奇寶貝回復滿血，請重載此方法
    //並印出在「xx神奇寶貝中心」恢復
private:
    string Name;
}PC;
#endif
