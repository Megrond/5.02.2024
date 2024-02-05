#include <iostream>

using namespace std;

// описание паттрена Builder
class Product {
public:
	int part1;
	int part2;
};

class Bilder {
public:
	virtual void createProduct() {}
	virtual void bildPart1(int part1) {}
	virtual void bildPart2(int part2) {}
	virtual Product* getResult() { return nullptr; }
};

class ConcreteBilder :public Bilder{
private:
	Product* currentBilder;
public:
	ConcreteBilder() {
		currentBilder = nullptr;
	}
	void createProduct()
	{
		cout << "ConcreteBilder::CreateProduct" << endl;
		currentBilder = new Product();
	}
	virtual void bildPart1(int part1) {
		cout << "ConcreteBilder::bildPart1" << endl;
		currentBilder->part1 = part1;
	}
	virtual void bildPart2(int part2) {
		cout << "ConcreteBilder::bildPart2" << endl;
		currentBilder->part2 = part2;
	}
	Product* getResult() {
		return currentBilder;
	}
	~ConcreteBilder() {
		if (currentBilder != nullptr)
		{
			delete currentBilder;
		}
	}
};
class Director{
public:
	void Construct(Bilder& bilder)
	{
		bilder.createProduct();
		bilder.bildPart1(25);
		bilder.bildPart2(888);
	}
};


int main() 
{
	Product* product;
	ConcreteBilder B;
	Director D;
	D.Construct(B);

	product = B.getResult();

	cout << "product -> part1 = "<< product->part1 << endl;
	cout << "product -> part2 = " << product->part2 << endl;
	cout << " " << endl;


}