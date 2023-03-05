#include <iostream>
#include <string>

using namespace std;

//string 是一个类，该类中包含了一个char数组

//string的构造函数
void test01()
{	
	string s1;
	char s[]= "hello c";
	s1 = s;
	cout << s1 << endl;
	
	string s2 = s1;
	cout << s2 << endl;
	
	string s3(s2);
	cout << s3 << endl;

	       //几个字符,字符
	string s4(5, '6');
	cout << s4 << endl;
	
}

//string的赋值操作
void test02()
{
	string s1;
	s1 = "hello";
	cout << s1 << endl;

	string s2;
	s2 = s1;
	cout << s2 << endl;

	string s3;
	s3.assign("c++ yes");
	cout << s3 << endl;

	string s4;
	s4.assign("12345678", 5);//将字符串"12345678"的前4个字符赋值给s4
	cout << "s4=" << s4 << endl;

	string s5;
	s5.assign(s3);
	cout << "s5=" << s5 << endl;

	string s6;
	s6.assign(3, '6');
	cout << "s6=" << s6 << endl;
}


//string 字符串拼接
void test03()
{
	string s1 = "I";
	s1 += " am";
	cout << "s1=" << s1 << endl;

	string s2 = " student";
	s1 += s2;
	cout << "s1=" << s1 << endl;

	s1 += '.';
	cout << "s1=" << s1 << endl;

	s1.append("我是一个学生");//将"我是一个学生"追加到s1的后面
	cout << "s1=" << s1 << endl;

	string s3 = "I";
	//将 " love game" 的前 sizeof(" love") - 1 个字符追加到s3的后面
	s3.append(" love game", sizeof(" love") - 1);
	cout << "s3=" << s3 << endl;

	//将s1从第4个位置(字符数组，0开始)开始截取7个字符到s3的末尾
	s3.append(s1, 4, 9);
	cout << "s3=" << s3 << endl;
}

//string查找和替换
void test04()
{
	string s1 = "0123aabc89aabc43210";
	int pos = -1;
	pos = s1.find("aabc");//左到右查找子串，返回匹配子串第一个字符对应的下标 -1表示没有找到对应的子串
	if (pos == -1)
	{
		cout << "未在s1中找到子串aabc" << endl;
	}
	else
	{
		cout << "find pos=" << pos << endl;
	}

	pos = s1.rfind("aabc");//右到左查找子串，返回匹配子串第一个字符对应的下标 -1表示没有找到对应的子串
	if (pos == -1)
	{
		cout << "未在s1中找到子串aabc" << endl;
	}
	else
	{
		cout << "rfind pos=" << pos << endl;
	}

	string s3 = "dcsgo@qq.com";
	//将s3中从下标为6开始的2个字符替换为"google"
	s3.replace(6, 2, "google");
	cout << "s3=" << s3 << endl;

	s3.replace(s3.find(".com"), 5, "aaaaaa");
	cout << "s3=" << s3 << endl;
	
}

//string比较
void test05()
{
	string s1 = "aaaaab";
	string s2 = "aaaabb";
	if (s1 == s2)
	{
		cout << "s1=s2" << endl;
	}
	else
	{
		cout << "s1!=s2" << endl;
	}

	string s3="abca";
	string s4 = "abcd";
	//逐一比较每一个元素(char)的ascii值
	int ret = s3.compare(s4);
	cout << ret << endl;

	if (s3.compare(s4) == 0)
		cout << "s3==s4" << endl;
	else
		cout << "s3!=S4" << endl;
}

//string字符存取
void test06()
{
	//[ ]访问单个字符
	string s1 = "0123456";
	for (int i = 0;i < s1.size();i++)
		cout << s1[i] << ' ';

	cout << endl;

	//at( )访问单个字符
	for (int i = 0;i < s1.size();i++)
		cout << s1.at(i) << ' ';

	//[ ]修改单个字符
	s1[5] = 'x';
	cout << endl << s1 << endl;

	//at()修改单个字符
	s1.at(6) = 'x';
	cout << s1 << endl;

}

//string插入与删除
void test07()
{
	string s1 = "hello";
	
	s1.insert(2, "xxxx");
	cout << s1 << endl;
	s1.erase(2, 4);
	cout << s1 << endl;

	string s2 = "111";
	s2.insert(0, s1);
	cout << s2 << endl;
	s2.erase(0, sizeof("hello")-1);
	cout << s2 << endl;
}

//string子串
void test08()
{
	string s1 = "dcsgo@qq.com";
	//                  开始位置  截取多少个字符
	string id = s1.substr(0, s1.find("@"));
	cout << id << endl;

	string dn = s1.substr(s1.find(".")+1,s1.size() - s1.find(".")-1);
	cout << dn << endl;
}

int main1()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	//test08();
	return 0;
}