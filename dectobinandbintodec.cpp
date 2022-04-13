#include <iomanip>
#include <iostream>

class BinToDec
{
private:
	int m_binary{};
	int m_decimal{};
public:
	BinToDec(int binary) : m_binary(binary) {}

	

	[[nodiscard]] int getBinary() const { return m_binary; }
	[[nodiscard]] int getDecimal() const { return m_decimal; }

	void convertBinaryToDecimal()
	{
		int temp{ m_binary };
		int sum{ 0 };
		int i{ 0 };
		while (temp > 0)
		{
			sum += temp % 10 * pow(2, i);
			temp /= 10;
			i++;
		}
		m_decimal = sum;
	}

	void print()
	{
		std::cout << "Binary: " << m_binary << " Decimal: " << m_decimal << std::endl;
	}

	~BinToDec() = default;
};

class DecToBin
{
private:
	int m_decimal{};
	int m_binary{};
public:
	DecToBin(int decimal) : m_decimal(decimal) {}

	[[nodiscard]] int getDecimal() const { return m_decimal; }
	[[nodiscard]] int getBinary() const { return m_binary; }

	void convertDecimalToBinary()
	{
		int temp{ m_decimal };
		int sum{ 0 };
		int i{ 0 };
		while (temp > 0)
		{
			sum += temp % 2 * pow(10, i);
			temp /= 2;
			i++;
		}
		m_binary = sum;
	}

	void print()
	{
		std::cout << "Decimal: " << m_decimal << " Binary: " << m_binary << std::endl;
	}
};

int askUser(bool choice)
{
	if ( choice == true )
	{
		std::cout << "Enter a binary number: ";
		int binary;
		std::cin >> binary;

		if ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return askUser(true);
		}
		else
		{
			return binary;
		}
	}
	else
	{
		std::cout << "Enter a decimal number: ";
		int decimal;
		std::cin >> decimal;

		if ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return askUser(false);
		}
		else
		{
			return decimal;
		}
	}
	
}

bool askUserWhatToConvert()
{
	std::cout << "What would you like to convert?\n";
	std::cout << "1. Binary to Decimal\n";
	std::cout << "2. Decimal to Binary\n";
	std::string choice{};
	std::cin >> choice;

	if (choice == "1")
	{
		return true;
	}
	else if (choice == "2")
	{
		return false;
	}
	else
	{
		std::cerr << "Invalid input. Please try again.\n";
		return askUserWhatToConvert();
	}	
}

int main()
{

	bool sus= askUserWhatToConvert();

	if (sus)
	{
		int binary{ askUser(sus) };
		BinToDec binToDec{ binary };
		binToDec.convertBinaryToDecimal();
		binToDec.print();
	}
	else
	{
		int decimal{ askUser(sus) };
		DecToBin decToBin{ decimal };
		decToBin.convertDecimalToBinary();
		decToBin.print();
	}

	return 0;
}
