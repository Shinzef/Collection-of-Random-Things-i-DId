#include <string>

class RomanHelper{
  public:
    std::string to_roman(unsigned int n)
    {
        std::string m[] ={"", "M", "MM", "MMM" };
        std::string c[] ={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string x[] ={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string i[] ={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        std::string roman = m[n/1000] + c[(n%1000)/100] + x[(n%100)/10] + i[n%10];

        return roman;
    }
    int from_roman(std::string rn)
    {
        int result = 0;

        for ( int i { 0 }; i < rn.length(); ++i)
        {
            switch (rn[i])
            {
                case 'M':
                    result += 1000;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'C':
                    if (rn[i+1] == 'M')
                    {
                        result += 900;
                        ++i;
                    }
                    else if (rn[i+1] == 'D')
                    {
                        result += 400;
                        ++i;
                    }
                    else
                    {
                        result += 100;
                    }
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'X':
                    if (rn[i+1] == 'C')
                    {
                        result += 90;
                        ++i;
                    }
                    else if (rn[i+1] == 'L')
                    {
                        result += 40;
                        ++i;
                    }
                    else
                    {
                        result += 10;
                    }
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'I':
                    if (rn[i+1] == 'X')
                    {
                        result += 9;
                        ++i;
                    }
                    else if (rn[i+1] == 'V')
                    {
                        result += 4;
                        ++i;
                    }
                    else
                    {
                        result += 1;
                    }
                    break;
            }
        }

        return result;
    }
} RomanNumerals;
