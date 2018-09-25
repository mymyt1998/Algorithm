//十一届湖南省赛，聊天止于呵呵
//提取出对话的最后一句话，列表中的任何一个单词是 hehe,这段对话就算作“止于呵呵”。
#include <iostream>
#include <set>
#include <string>
using namespace std;
set<pair<string, string> > set1;//用set保存两个特定人名，需要用来查找
bool check(string s)//判断这个单词是否为呵呵
{
	if (s.length()<4)
		return false;
	string tmp = "he", s1 = "";
	int len = s.length() / 2;
	for (int i = 1; i <= len; ++i)
		s1 += tmp;
	if (s1 == s)
		return true;
	else
		return false;
}
int main()
{
	string s;
	double ans = 0;
	set1.clear();
	while (getline(cin, s))//结束条件ctrl+z
	{
		s += '#';
		string A = "", B = "";
		int i = 0, len = s.length();
		while (s[i] != '-')//第一个人名
		{
			A += s[i];
			i++;
		}
		i += 2;//跳过 ->
		while (s[i] != ':')//第二个人名
		{
			B += s[i];
			i++;
		}
		if (A<B)
			swap(A, B);//将较小人名放前面方便存入

		if (set1.find(make_pair(A, B)) == set1.end())//当前两人第一次对话
			set1.insert(make_pair(A, B));

		i += 2;//到达对话内容
		string word = "";
		for (; i<len; ++i)
		{
			if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z'))
				word += tolower(s[i]);//字母全部转为小写
			else
			{
				if (check(word))//有呵呵
				{
					ans++;
					break;
				}
				word = "";
			}
		}
	}
	ans = ans / set1.size();
	ans *= 100;
	ans += 0.5;
	cout<<int(ans)<<"%"<<endl;
	return 0;
}