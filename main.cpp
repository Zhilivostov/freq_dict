#include <iostream>
#include "freq_dict.h"

using namespace std;

int main()
{
	dict_map a;
	a.add_dict("task.txt");
	a.get_dict("result_map.txt");
	dict_unordered_map b;
	b.add_dict("task.txt");
	b.get_dict("result_unordered_map.txt");
	dict_vector c;
	c.add_dict("task.txt");
	c.get_dict("result_vector.txt");
	dict_list d;
	d.add_dict("task.txt");
	d.get_dict("result_list.txt");
	dict_set e;
	e.add_dict("task.txt");
	e.get_dict("result_set.txt");
	dict_unordered_set f;
	f.add_dict("task.txt");
	f.get_dict("result_unordered_set.txt");
	//setlocale(LC_ALL, "ru");
	cout << "Finished" << endl;
	return 1;
}
// абстрактный класс с виртуальными функциями, переопределяемые в дочерних классах под лист вектор и тп. отдельный класс для чтения из файла и записи в файл.