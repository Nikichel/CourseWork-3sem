#include "vehicle.h"
int vehicle::count = 0;

void vehicle::setId(int id) {			//установить id
	this->id = id;
};	
void vehicle::setBrand(const char* brand) {		//установить марку
	strcpy_s(this->brand, 10, brand);
};
void vehicle::setPlace(int num, char sector) {		//установить место
	Place.setSector(sector);
	Place.setNum(num);
}

int vehicle::getId() {			//получить id
	return this->id;
};
char* vehicle::getBrand() {		//получить марку
	return this->brand;
};

place& vehicle::getPlace() {			//получить место
	return Place;
}

void vehicle::operator=(const vehicle& other) {		//оператор =
	this->id = other.id;
	strcpy_s(this->brand, 10, other.brand);
	this->Place = other.Place;					//копирование полей класса
};

bool vehicle::operator ==(vehicle& other) {			//оператор ==
	if (other.id)
		if (this->id != other.id)
			return false;
	if(!(other.Place.getTimeOfEntry().isNull()))
		if (!(other.Place.getTimeOfEntry() == this->Place.getTimeOfEntry()))
			return false;
	if (other.Place.getSector() != '\0')
		if (other.Place.getSector() != this->Place.getSector())
			return false;
	if (other.Place.getNum())
		if (this->Place.getNum() != other.Place.getNum())
			return false;
	if (strlen(other.brand))
		if (strcmp(this->brand, other.brand))				//сравнение не нуллевых полей класса
			return false;
	return true;
}

void vehicle::replace(vehicle& other) {			//замещение не нулеввых полей
	if (strlen(this->brand))
		strcpy_s(this->brand, 10, other.brand);
	if (this->Place.getNum())
		this->Place.setNum(other.Place.getNum());
	if (!(this->Place.getTimeOfEntry().isNull()))
		this->Place.setTimeOfEntry(other.Place.getTimeOfEntry());
	if (!(this->Place.getTimeOfExit().isNull()))
		this->Place.setTimeOfExit(other.Place.getTimeOfExit());			//если поле не пустое, помещаем новую информацию
};

vehicle vehicle::ChooseParams() {			//выбор поля сортировки
	vehicle SortParam;
	int var;
	cout << endl << "Сортировка по:" << endl << "1. Марке" << endl << "2. Номеру места" << endl << "3. Времени въезда" 
		<< endl<< "4. Времени выезда"<<endl;
	getNumWithBorders(var, 1, 4);			//выбор операции
	cout << endl;
	switch (var)
	{
	case 1: {
		strcpy_s(SortParam.brand, 10, this->brand);
		break;
	}
	case 2: {
		SortParam.Place.setNum(this->Place.getNum());
		break;
	}
	case 3: {
		SortParam.Place.setTimeOfEntry(this->Place.getTimeOfEntry());
		break;
	}
	case 4: {
		SortParam.Place.setTimeOfExit(this->Place.getTimeOfExit());			//заполнение поля
		break;
	}
	default:
		break;
	}

	return SortParam;
};

bool vehicle::operator >(vehicle& other) {			//операто >
	if (strlen(other.brand))
		if (strcmp(brand, other.brand) >= 0)
			return false;
	if (other.Place.getNum())
		if (this->Place.getNum() >= other.Place.getNum())
			return false;
	if (!(other.Place.getTimeOfEntry().isNull()))
		if (!(other.Place.getTimeOfEntry() < this->Place.getTimeOfEntry()))
			return false;
	if (!(other.Place.getTimeOfExit().isNull()))
		if (!(other.Place.getTimeOfExit() < this->Place.getTimeOfExit()))			//сравнение не нуллевых полей класса
			return false;
	return true;
}

void vehicle::tableHead() {			//вывод шапки класса
	cout.setf(ios::left);
	cout << setw(5) << "id" << setw(8) << "Место" << setw(10) << "Марка"<< setw(13) << "Дата въезда" <<setw(13) << "Дата выезда" <<"Оплата" << endl;
	cout << setw(50) << setfill('-') <<"" << endl;
	cout.unsetf(ios::left);

}

istream& operator>>(istream& in, vehicle& other) {			//ввод
	other.id=other.count++;		//уникаль id
	int num;
	rewind(stdin);
	cout << "Введите номер места: ";
	getPositivNum(num);
	other.Place.setNum(num);
	cout << "Введите марку: ";
	rewind(stdin);
	getStr("ENG", other.brand, 10);			//ввод полей класса
	cout << "Въезд: "<<endl;
	in >> other.Place.getTimeOfEntry();
	cout << "Ввести выезд?(0-нет, 1-да)" << endl;
	getNumWithBorders(num, 0, 1);
	if (num) {
		cout << "Выезд: " << endl;
		in >> other.Place.getTimeOfExit();
		other.Place.setPayment((other.Place.getTimeOfEntry() - other.Place.getTimeOfExit()));		//ввод полей класса Place
	}
	return in;
}

ostream& operator<<(ostream& out, vehicle& other) {			//вывод
	out.setf(ios::left);
	out << setw(5) << other.id << setw(2) << other.Place.getNum() << setw(6) << other.Place.getSector() 
		<< setw(15) << other.Place.getTimeOfEntry() << setw(2) << "" << other.Place.getTimeOfExit() << setw(3) << "" <<setw(9) 
		<< other.Place.getPayment() << setw(10) << other.brand;
	out.unsetf(ios::left);			//вывод полей класса
	return out;
}

ofstream& operator<<(ofstream& outf, vehicle& other) {		//запись в файл
	outf.setf(ios::left);
	outf << setw(5) << other.id << setw(2);
	outf << other.Place.getNum() << setw(6);
	outf << other.Place.getSector() << setw(15);
	outf << other.Place.getTimeOfEntry() << setw(2);
	outf << "" << other.Place.getTimeOfExit() << setw(3);
	outf << "" << setw(9) << other.Place.getPayment() << setw(10) << other.brand;			//запись полей в файл
	outf.unsetf(ios::left);
	return outf;
}

ifstream& operator>>(ifstream& inf , vehicle& other) {		//чтение из файла
	inf >> other.id;
	inf >> other.Place>>setw(10);
	inf >> other.brand;
	other.count = other.id;			//чтение полей из файла
	return inf;
}