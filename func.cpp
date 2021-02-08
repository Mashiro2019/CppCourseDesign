#include"func.h"

vector<Data>Student;

bool  AscendingComparison::compByAverage(const Data& a, const Data& b) {
	return a.average < b.average;
}

bool AscendingComparison::compByMath(const Data& a, const Data& b) {
	return a.Math < b.Math;
}

bool AscendingComparison::compByEnglish(const Data& a, const Data& b) {
	return a.English < b.English;
}

bool AscendingComparison::compByPE(const Data& a, const Data& b) {
	return a.PE < b.PE;
}

bool DescendingComparison::compByAverage(const Data& a, const Data& b) {
	return a.average > b.average;
}

bool DescendingComparison::compByMath(const Data& a, const Data& b) {
	return a.Math > b.Math;
}

bool DescendingComparison::compByEnglish(const Data& a, const Data& b) {
	return a.English > b.English;
}

bool DescendingComparison::compByPE(const Data& a, const Data& b) {
	return a.PE > b.PE;
}

void txt_To_Vector() {
	Student.clear();
	fstream input;
	input.open("StudentInformation.csv", ios::in);
	Data object;
	string strLine;
	stringstream temp;
	while (getline(input, strLine)) {
		stringstream ss(strLine);
		string str;
		getline(ss, str, ',');
		object.num = str;
		getline(ss, str, ',');
		object.cla = str;
		getline(ss, str, ',');
		object.name = str;
		getline(ss, str, ',');
		object.sex = str;
		getline(ss, str, ',');
		object.major = str;
		getline(ss, str, ',');
		temp << str;
		temp >> object.Math;
		temp.clear();
		getline(ss, str, ',');
		temp << str;
		temp >> object.English;
		temp.clear();
		getline(ss, str, ',');
		temp << str;
		temp >> object.PE;
		temp.clear();
		getline(ss, str, ',');
		temp << str;
		temp >> object.average;
		temp.clear();
		Student.push_back(object);
	}
	input.close();
	return;
}

void Vector_To_txt() {
	fstream input;
	input.open("StudentInformation.csv", ios::out|ios::trunc);
	for (unsigned int i = 0; i < Student.size(); i++){
		input << Student[i].num << ',' << Student[i].cla << ',' << Student[i].name << ',' << Student[i].sex << ',' << Student[i].major
			<< ',' << Student[i].Math << ',' << Student[i].English << ',' << Student[i].PE << ',' << Student[i].average << endl;
	}
	input.close();
	return;
}

void CreateData() {
	int temp;
	cout << "������Ҫ��ӵ�ѧ������" << endl;
	cin >> temp;
	for (int i = 0; i < temp; i++){
		Data object;
		object = InputStudentInformation(object);
		Student.push_back(object);
	}
	return;
}

Data InputStudentInformation(Data& c) {
	cout << "����������ѧ����ѧ�ţ��༶���������Ա�רҵ" << endl;
	cin >> c.num >> c.cla >> c.name >> c.sex >> c.major;
	cout << "����������" << c.name << "ͬѧ����ѧ��Ӣ������ɼ�" << endl;
	cin >> c.Math >> c.English >> c.PE;
	c.average = (c.Math + c.English + c.PE) / 3;
	return c;
}

void DisplayStudentInformation(const vector<Data>& c) {
	system("cls");
	if (c.empty())
		cout << "Ŀǰ�������ѧ����Ϣ,������¼��" << endl;
	else {
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
	}
	return;
}

void DisplayStudentInformation(const Data& c) {
	cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
		<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
	cout << setw(10) << left << c.num << setw(10) << left << c.cla << setw(10) << left << c.name << setw(5) << left << c.sex << setw(15) << left << c.major
		<< setw(10) << left << c.Math << setw(10) << left << c.English << setw(10) << left << c.PE << setw(10) << left << c.average << endl;
	return;
}

void DisplayStudentRanking(vector<Data>& c,char a) {
	switch (a)
	{
	case '1':
		sort(c.begin(), c.end(), DescendingComparison::compByAverage);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '2':
		sort(c.begin(), c.end(), DescendingComparison::compByMath);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '3':
		sort(c.begin(), c.end(), DescendingComparison::compByEnglish);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '4':
		sort(c.begin(), c.end(), DescendingComparison::compByPE);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '5':
		sort(c.begin(), c.end(), DescendingComparison::compByAverage);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '6':
		sort(c.begin(), c.end(), AscendingComparison::compByMath);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '7':
		sort(c.begin(), c.end(), AscendingComparison::compByEnglish);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	case '8':
		sort(c.begin(), c.end(), DescendingComparison::compByPE);
		cout << setw(10) << left << "ѧ��" << setw(10) << left << "�༶" << setw(10) << left << "����" << setw(5) << left << "�Ա�" << setw(15) << left << "רҵ"
			<< setw(10) << left << "��ѧ�ɼ�" << setw(10) << left << "Ӣ��ɼ�" << setw(10) << left << "�����ɼ�" << setw(10) << left << "ƽ����" << endl;
		for (unsigned int i = 0; i < c.size(); i++) {
			cout << setw(10) << left << c[i].num << setw(10) << left << c[i].cla << setw(10) << left << c[i].name << setw(5) << left << c[i].sex << setw(15) << left << c[i].major
				<< setw(10) << left << c[i].Math << setw(10) << left << c[i].English << setw(10) << left << c[i].PE << setw(10) << left << c[i].average << endl;
		}
		break;

	default:
		break;
	}
	return;
}

Data findBySchoolNo(string num) {
	Data oj;
	oj.num = num;
	vector<Data>::iterator result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
	int temp = distance(Student.begin(), result);
	oj = Student[temp];
	return oj;
}

vector<Data> findByName(string name) {
	Data oj;
	oj.name = name;
	vector<Data>res;
	unsigned int i = 0, temp = 0;
	for (; i < Student.size(); i++) {
		vector<Data>::iterator result = find_if(Student.begin() + temp , Student.end(), std::bind2nd(DataFindByName(), oj));
		if (result == Student.end())
			break;
		temp = distance(Student.begin(), result);
		res.push_back(Student[temp]);
		temp++; //��֤����һλ��ʼ����
	}
	return res;
}

vector<Data> findByCla(string cla) {
	Data oj;
	oj.cla = cla;
	vector<Data>res;
	unsigned int i = 0, temp = 0;
	for (; i < Student.size(); i++) {
		vector<Data>::iterator result = find_if(Student.begin() + temp, Student.end(), std::bind2nd(DataFindByCla(), oj));
		if (result == Student.end())
			break;
		temp = distance(Student.begin(), result);
		res.push_back(Student[temp]);
		temp++; //��֤����һλ��ʼ����
	}
	return res;
}

void ModifyStudentGPA(string num) {
	Data oj;
	oj.num = num;
	vector<Data>::iterator result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
	int temp = distance(Student.begin(), result);
	int tmp = NULL, score = NULL;
	cout << "1.�޸���ѧ�ɼ� 2.�޸�Ӣ��ɼ� 3.�޸������ɼ�" << endl;
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		cout << "�޸ĵķ���Ϊ:" << endl;
		cin >> score;
		Student[temp].Math = score;
		Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3;
		break;

	case 2:
		cout << "�޸ĵķ���Ϊ:" << endl;
		cin >> score;
		Student[temp].English = score;
		Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3;
		break;

	case 3:
		cout << "�޸ĵķ���Ϊ:" << endl;
		cin >> score;
		Student[temp].PE = score;
		Student[temp].average = (Student[temp].Math + Student[temp].English + Student[temp].PE) / 3;
		break;

	default:
		break;
	}
	return;
}

void DeleteStudentInformation(string num) {
	Data oj;
	oj.num = num;
	vector<Data>::iterator result = find_if(Student.begin(), Student.end(), std::bind2nd(DataFindByNum(), oj));
	int temp = distance(Student.begin(), result);
	Student.erase(Student.begin() + temp);
	return;
}

void control()
{
	Main_interface();
	char m;
	char n;
	fflush(stdin);
	n = _getch();//GetOptions();
	switch (n)
	{
	case '1':
	{
		closegraph();
		system("cls");
		CreateData();
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}
	break;

	case '2':
	{
		closegraph();
		DisplayStudentInformation(Student);
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}

	case '3':
	{
		closegraph();
		Ranking_interface();
		fflush(stdin);
		n = _getch();
		closegraph();
		system("cls");
		DisplayStudentRanking(Student, n);
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}
	break;

	case '4':
	{
		closegraph();
		Find_interface();
		fflush(stdin);
		n = _getch();
		switch (n)
		{
		case '1':
		{
			closegraph();
			system("cls");
			cout << "��������Ҫ���ҵ�ѧ��" << endl;
			string num;
			cin >> num;
			DisplayStudentInformation(findBySchoolNo(num));
		}
		break;

		case '2':
		{
			closegraph();
			system("cls");
			cout << "��������Ҫ���ҵ�����" << endl;
			string name;
			cin >> name;
			DisplayStudentInformation(findByName(name));
		}
		break;

		case '3':
		{
			closegraph();
			system("cls");
			cout << "��������Ҫ���ҵİ༶" << endl;
			string cla;
			cin >> cla;
			DisplayStudentInformation(findByCla(cla));
		}
		break;

		case'7':
		{
			closegraph();
			control();
		}
		break;

		default:
			break;
		}
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}
	break;

	case '5':
	{
		closegraph();
		system("cls");
		cout << "��������Ҫ�޸ĳɼ���ѧ����ѧ��" << endl;
		string num;
		cin >> num;
		cout << "��ѧ����ǰ��ϢΪ��" << endl;
		DisplayStudentInformation(findBySchoolNo(num));
		cout << endl;
		ModifyStudentGPA(num);
		cout << endl;
		cout << "��ѧ���޸ĺ����ϢΪ��" << endl;
		DisplayStudentInformation(findBySchoolNo(num));
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}
	break;

	case '6':
	{
		closegraph();
		system("cls");
		cout << "��������Ҫɾ����Ϣ��ѧ����ѧ��" << endl;
		string num;
		cin >> num;
		DeleteStudentInformation(num);
		cout << "��ѧ����Ϣ��ɾ��" << endl;
		fflush(stdin);
		m = _getch();
		while (1)
		{
			switch (m)
			{
			case '7':
			{
				closegraph();
				control();
			}

			default:
				break;
			}
		}
	}
	break;

	case '8':
		Vector_To_txt();
		exit(0);
		break;

	default:
	{
		fflush(stdin);
		closegraph();
		control();
	}
	break;
	}
}