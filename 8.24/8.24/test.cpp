#include <iostream>
using namespace std;

#include <set>

#include <map>

void test1()
{
	//map是KV模型
	map<string, string> dict;
	pair<string, string> kv1("insert", "插入");
	//pair类模板是map底层封装的成员变量

	//所以理论上map存储的也是pair类型的对象
	dict.insert(kv1);
	//这样是正常的
	dict.insert(pair<string, string>("run", "启动"));
	//匿名对象也是可以的

	//不过里有一个函数，make_pair(T,T);--->也经常使用
	//它会返回pair<T>类型的对象
	dict.insert(make_pair("string", "字符串"));

	//下面这个方法最常见
	dict.insert({ "int","整形" });//这里会将这个数组类型转化成pair类型，怎么转化的？调用pair的构造函数
	//隐射类型转化--->单参构造会u发生隐射类型转化--C++98；string.insert("hello")
	//多参数构造也会发生隐射类型转化--->C++11 

	for (auto& e : dict)
	{
		cout << e.first <<" :"<< e.second << endl;;
	}
	map<string, string>::iterator it = dict.begin();

	while (it != dict.end())
	{
		//it是迭代器就相当于指针
		//正常是*it就是解引用到要访问的对象了，但这里的对象是pair不可以直接打印

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
	kv.insert(make_pair("apple", "苹果"));
	kv.insert(make_pair("yellow", "黄色"));
	kv.insert(make_pair("insert", "插入"));

	//insert，如果插入相同的该怎么办？
	//key value map只会比较key的值，不会比较value的值，如果key值相同，那么就不插入了。
	//不插入，不覆盖
	kv.insert(make_pair("insert", "xxxxxx"));
	for (auto& e : kv)
	{
		cout << e.first << " :" << e.second << endl;;
	}


}
void test3()
{
	string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	
	//map的find查找特点：当找到要要的key值后，会返回对应key-value的迭代器
	//如果没找到就会返回最后一个位置的后一个迭代器即end()
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
		//实现的原理：
		//第一步先插入，第二部返回value值
		//如果不存在就插入，并且value值就是匿名对象对应类型的缺省值，然后++就变成1
		// 如果存在插入也没事，不会覆盖，返回value 
		//
	}
	for (auto e : count)
	{
		cout << e.first << ":" << e.second << endl;
	}
	
}
void  testmap()
{
	//map的[]与正常的[]不同，不是通过传下标，来返回对应值的引用
	//而是传key值，给你返回的是value值的引用
	//[]本质是通过insert王朝的
	//insert返回值pair<iterator,bool>
	//1.当key在树里面，返回的是pair<在树里面key对应结点的iterator，false>
	//2.当key不在树里面，返回的是pair<刚插入树里可以、对应的结点iterator，true>
	/*V& operator[](const K& key)
	{
		pair<iterator, bool> ret = insert(make_pair(key, V()));
		return ret.iterator->second;
	}*/

	map<string, string>kv;
	kv.insert(make_pair("apple", "苹果"));
	kv.insert(make_pair("yellow", "黄色"));
	kv.insert(make_pair("insert", "插入"));

	//[ ]具有读取value的功能
	//跟正常的[]类似，只不过map的[]读的是value值
	cout << kv["apple"] << endl;

	kv["sort"];//插入一个空value

	kv["sort"] = "排序";
	//修改
	kv["man"] = "男人";
	//插入+修改
}
int main()
{
	//test1();
	testmap();
}