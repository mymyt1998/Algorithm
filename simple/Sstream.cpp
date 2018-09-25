//输入文本，找出所有不同的单词，按字典序从小到大输出，不分大小写
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
int main()
{
	set<string> dict;
	string str, buf;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)
			if (isalpha(str[i]))//判断是字母
				str[i] = tolower(str[i]);//转为小写
			else
				str[i] = ' ';//用来分割
		stringstream ss(str);
		while (ss >> buf)
			dict.insert(buf);//直接存入
		set<string>::iterator it;
		for (it = dict.begin(); it != dict.end(); ++it)
			cout << *it << endl;
		dict.clear();
	}
	return 0;
}
