#include <iostream>
#include <string>

using namespace std;

//string ��һ���࣬�����а�����һ��char����

//string�Ĺ��캯��
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

	       //�����ַ�,�ַ�
	string s4(5, '6');
	cout << s4 << endl;
	
}

//string�ĸ�ֵ����
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
	s4.assign("12345678", 5);//���ַ���"12345678"��ǰ4���ַ���ֵ��s4
	cout << "s4=" << s4 << endl;

	string s5;
	s5.assign(s3);
	cout << "s5=" << s5 << endl;

	string s6;
	s6.assign(3, '6');
	cout << "s6=" << s6 << endl;
}


//string �ַ���ƴ��
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

	s1.append("����һ��ѧ��");//��"����һ��ѧ��"׷�ӵ�s1�ĺ���
	cout << "s1=" << s1 << endl;

	string s3 = "I";
	//�� " love game" ��ǰ sizeof(" love") - 1 ���ַ�׷�ӵ�s3�ĺ���
	s3.append(" love game", sizeof(" love") - 1);
	cout << "s3=" << s3 << endl;

	//��s1�ӵ�4��λ��(�ַ����飬0��ʼ)��ʼ��ȡ7���ַ���s3��ĩβ
	s3.append(s1, 4, 9);
	cout << "s3=" << s3 << endl;
}

//string���Һ��滻
void test04()
{
	string s1 = "0123aabc89aabc43210";
	int pos = -1;
	pos = s1.find("aabc");//���Ҳ����Ӵ�������ƥ���Ӵ���һ���ַ���Ӧ���±� -1��ʾû���ҵ���Ӧ���Ӵ�
	if (pos == -1)
	{
		cout << "δ��s1���ҵ��Ӵ�aabc" << endl;
	}
	else
	{
		cout << "find pos=" << pos << endl;
	}

	pos = s1.rfind("aabc");//�ҵ�������Ӵ�������ƥ���Ӵ���һ���ַ���Ӧ���±� -1��ʾû���ҵ���Ӧ���Ӵ�
	if (pos == -1)
	{
		cout << "δ��s1���ҵ��Ӵ�aabc" << endl;
	}
	else
	{
		cout << "rfind pos=" << pos << endl;
	}

	string s3 = "dcsgo@qq.com";
	//��s3�д��±�Ϊ6��ʼ��2���ַ��滻Ϊ"google"
	s3.replace(6, 2, "google");
	cout << "s3=" << s3 << endl;

	s3.replace(s3.find(".com"), 5, "aaaaaa");
	cout << "s3=" << s3 << endl;
	
}

//string�Ƚ�
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
	//��һ�Ƚ�ÿһ��Ԫ��(char)��asciiֵ
	int ret = s3.compare(s4);
	cout << ret << endl;

	if (s3.compare(s4) == 0)
		cout << "s3==s4" << endl;
	else
		cout << "s3!=S4" << endl;
}

//string�ַ���ȡ
void test06()
{
	//[ ]���ʵ����ַ�
	string s1 = "0123456";
	for (int i = 0;i < s1.size();i++)
		cout << s1[i] << ' ';

	cout << endl;

	//at( )���ʵ����ַ�
	for (int i = 0;i < s1.size();i++)
		cout << s1.at(i) << ' ';

	//[ ]�޸ĵ����ַ�
	s1[5] = 'x';
	cout << endl << s1 << endl;

	//at()�޸ĵ����ַ�
	s1.at(6) = 'x';
	cout << s1 << endl;

}

//string������ɾ��
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

//string�Ӵ�
void test08()
{
	string s1 = "dcsgo@qq.com";
	//                  ��ʼλ��  ��ȡ���ٸ��ַ�
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