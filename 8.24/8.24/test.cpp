#include <iostream>
using namespace std;

#include <set>

#include <map>

void test1()
{
	//map��KVģ��
	map<string, string> dict;
	pair<string, string> kv1("insert", "����");
	//pair��ģ����map�ײ��װ�ĳ�Ա����

	//����������map�洢��Ҳ��pair���͵Ķ���
	dict.insert(kv1);
	//������������
	dict.insert(pair<string, string>("run", "����"));
	//��������Ҳ�ǿ��Ե�

	//��������һ��������make_pair(T,T);--->Ҳ����ʹ��
	//���᷵��pair<T>���͵Ķ���
	dict.insert(make_pair("string", "�ַ���"));

	//��������������
	dict.insert({ "int","����" });//����Ὣ�����������ת����pair���ͣ���ôת���ģ�����pair�Ĺ��캯��
	//��������ת��--->���ι����u������������ת��--C++98��string.insert("hello")
	//���������Ҳ�ᷢ����������ת��--->C++11 

	for (auto& e : dict)
	{
		cout << e.first <<" :"<< e.second << endl;;
	}
	map<string, string>::iterator it = dict.begin();

	while (it != dict.end())
	{
		//it�ǵ��������൱��ָ��
		//������*it���ǽ����õ�Ҫ���ʵĶ����ˣ�������Ķ�����pair������ֱ�Ӵ�ӡ

		//cout << (*it).first << (*it).second << endl;
		
		//it->first ="xxx";
		//it->second = "xxxx";
	    cout << it->first << it->second << endl;
		++it;
	}
	

}
void test2()
{
	
	map<string, string>kv;
	kv.insert(make_pair("apple", "ƻ��"));
	kv.insert(make_pair("yellow", "��ɫ"));
	kv.insert(make_pair("insert", "����"));

	//insert�����������ͬ�ĸ���ô�죿
	//key value mapֻ��Ƚ�key��ֵ������Ƚ�value��ֵ�����keyֵ��ͬ����ô�Ͳ������ˡ�
	//�����룬������
	kv.insert(make_pair("insert", "xxxxxx"));
	for (auto& e : kv)
	{
		cout << e.first << " :" << e.second << endl;;
	}


}
void test3()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	
	//map��find�����ص㣺���ҵ�ҪҪ��keyֵ�󣬻᷵�ض�Ӧkey-value�ĵ�����
	//���û�ҵ��ͻ᷵�����һ��λ�õĺ�һ����������end()
	map<string, int> count;
	/*for (auto e : arr)
	{
		auto ret = count.find(e);
		if (ret == count.end())
		{
			count.insert(make_pair(e, 1));
		}
		else
		{
			ret->second++;
		}
	}*/
	for (auto e : arr)
	{
		count[e]++;
		//ʵ�ֵ�ԭ��
		//��һ���Ȳ��룬�ڶ�������valueֵ
		//��������ھͲ��룬����valueֵ�������������Ӧ���͵�ȱʡֵ��Ȼ��++�ͱ��1
		// ������ڲ���Ҳû�£����Ḳ�ǣ�����value 
		//
	}
	for (auto e : count)
	{
		cout << e.first << ":" << e.second << endl;
	}
	
}
void  testmap()
{
	//map��[]��������[]��ͬ������ͨ�����±꣬�����ض�Ӧֵ������
	//���Ǵ�keyֵ�����㷵�ص���valueֵ������
	//[]������ͨ��insert������
	//insert����ֵpair<iterator,bool>
	//1.��key�������棬���ص���pair<��������key��Ӧ����iterator��false>
	//2.��key���������棬���ص���pair<�ղ���������ԡ���Ӧ�Ľ��iterator��true>
	/*V& operator[](const K& key)
	{
		pair<iterator, bool> ret = insert(make_pair(key, V()));
		return ret.iterator->second;
	}*/

	map<string, string>kv;
	kv.insert(make_pair("apple", "ƻ��"));
	kv.insert(make_pair("yellow", "��ɫ"));
	kv.insert(make_pair("insert", "����"));

	//[ ]���ж�ȡvalue�Ĺ���
	//��������[]���ƣ�ֻ����map��[]������valueֵ
	cout << kv["apple"] << endl;

	kv["sort"];//����һ����value

	kv["sort"] = "����";
	//�޸�
	kv["man"] = "����";
	//����+�޸�
}
int main()
{
	//test1();
	testmap();
}